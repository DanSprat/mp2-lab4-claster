#include "pch.h"
#include "Cluster.h"
void Cluster::SetInfoMode(bool info)
{
	InfoF = info;
}
Cluster::Cluster(int NumProc, int WorkTime, double Chance,bool Info)
{
	InfoF = Info;
	this->WorkTime = WorkTime;
	ChanceOfNew = Chance;
	srand(time(0));
	Proces.resize(NumProc);
	for (int i = 0; i < Proces.size(); i++)
	{
		int b = 1 + rand() % 24;
		Proces[i].Cores = b;
		Proces[i].FreeCores = b;
	}
}

void Cluster::Start()
{
	double MiddleLoad = 0; // Переменная для вычисления средней загрузки на конец работы класетра
	int SummCores=0; // Общая сумма ядер
	int SummFreeCores=0; // Сумма свободныъ ядер
	for (int i = 0; i<Proces.size(); i++)
	{
		SummCores += Proces[i].Cores;
		SummFreeCores += Proces[i].Cores;
	}
	int NumberOfTasks=0; // Количество появившихся задач
	Task a;
	bool CanInsert; 
	for (int i = 1; i <= WorkTime; i++)
	{
		srand(time(0));
		cout << "ТАКТ "<<i << endl;
		cout << "==============================================================================" << endl;
		double p = 1;
		cout << "Появившиеся задачи" << endl;
		cout << endl;
		while (p >= ChanceOfNew) // Генерация новых задач
		{
			NumberOfTasks++;
			a.Rand(WorkTime,24, Proces.size(),NumberOfTasks);
			cout << setw(10) << a.ID << setw(25) << "requires processors: " << a.NeedProc << setw(20) << "requires cores: " << a.NeedCores << setw(18)<<"requires time: "<<a.NeedTakts << endl;
			Tasks.push(a);
			p = ((0.01) *(rand() % 100));
		}
		cout << endl;
		CanInsert = 1;
		while (!Tasks.IsEmpty())
		{
			while (!ChanceToInsertTask()) // Проверка на невыполняемые задачи
			{
				Failed.push_back(Tasks.front());
				Tasks.pop();
				if (Tasks.IsEmpty())
					break;
			}
			if (Tasks.IsEmpty())
				break;
			int Check = 0;  // Счетчик для кол-ва процессоров с необходимым числом ядер 
			for (int j = 0; j < Proces.size(); j++)  // В этом цикле проверяем можем ли положить задачу на кластер
			{
				if (Proces[j].FreeCores >= Tasks.front().NeedCores) 
				{
					Check++; 
					Tasks.front().Where.push_back(j); // Задача "запонимает" номера процессоров на которых  она лежит
				}
				if (Check == Tasks.front().NeedProc) 
					break;
				if (j == Proces.size() - 1)
				{
					CanInsert = 0;
					Tasks.front().Where.clear();
				}
			}
			if (CanInsert)
			{
				for (int j = 0; j < Tasks.front().Where.size(); j++)  // В цикле "вносим " задачу на кластер
				{
					Proces[Tasks.front().Where[j]].FreeCores -= Tasks.front().NeedCores; // Определяем новое количество свободных ядер
					Proces[Tasks.front().Where[j]].Tasks.push_back(Tasks.front().ID); // Процессор запонимает ID задачи
					SummFreeCores -= Tasks.front().NeedCores; 
				}
				Tasks.front().StartTime = i;
				Actives.push_back(Tasks.front()); // Вносим задачу в список исполняемых
				Tasks.pop(); // Выкидываем из очереди
			}
			else break;
		}
		for (int j = 0; j < Actives.size(); j++)
		{
			if (Actives[j].isComplited(i))
			{
				std::vector<string>::iterator it;
				for (int k = 0; k < Actives[j].Where.size(); k++)
				{
					it= find(Proces[Actives[j].Where[k]].Tasks.begin(), Proces[Actives[j].Where[k]].Tasks.end(), Actives[j].ID);
					Proces[Actives[j].Where[k]].Tasks.erase(it);
					Proces[Actives[j].Where[k]].FreeCores += Actives[j].NeedCores;
					SummFreeCores += Actives[j].NeedCores;
				}
				Complited.push_back(Actives[j]);
				Actives.erase(Actives.begin()+j);
				j--;
			}
		}
		double b = static_cast<double>(SummFreeCores) / static_cast<double>( SummCores);
		MiddleLoad += SummCores -SummFreeCores;
		cout << "Общая загрузка кластера : " << (1-b) * 100 << " %" << endl;
		if (InfoF == true)
		{
			for (int j = 0; j < Proces.size(); j++)
			{
				cout << endl;
				cout << "Загрузка процессора " << j + 1 << ": " << static_cast<double>(1 - (Proces[j].FreeCores) / static_cast<double>(Proces[j].Cores)) * 100 << " %" << endl;
				cout << "\tЗадачи на процессоре: ";
				if (Proces[j].Tasks.size() != 0) 
				{
					for (int k = 0; k < Proces[j].Tasks.size(); k++)
					{
						if (k == Proces[j].Tasks.size()-1)
						cout << Proces[j].Tasks[k]  << endl;
						else
							cout << Proces[j].Tasks[k]<<",";
					}
				}
				else cout << "null"<<endl;
				cout << "\t\tВсего ядер: " << Proces[j].Cores << endl;
				if (Proces[j].FreeCores < 0)
				{
					cout << "Blet";
				}
				cout << "\t\tСвободно ядер: " << Proces[j].FreeCores << endl;
			}
			cout << "==============================================================================" << endl;
		}                                     
		Sleep(1);
	}
	MiddleLoad = MiddleLoad / (SummCores * WorkTime);
	cout << "Средняя загрузка кластера:" << MiddleLoad * 100 << " %";
	cout << endl;
	cout << "Число появившихся задач: " << Actives.size() + Failed.size() + Complited.size() + Tasks.lenght() << endl;
	cout << "Число задач в очереди: " << Tasks.lenght() << endl;
	cout << "Число выполненных задач: " << Complited.size() << endl;
	cout << endl;
	cout << "Число  задач не прошедших по ресурсам: " << Failed.size() << endl;
	if (Failed.size() != 0)
	{
		cout << "Инофрмация о них: " << endl;
		for (int i = 0; i < Failed.size(); i++)
		{
			cout << setw(10) << Failed[i].ID << setw(25) << "requires processors: " << Failed[i].NeedProc << setw(20) << "requires cores: " << Failed[i].NeedCores << setw(18) << "requires time: " << Failed[i].NeedTakts << endl;
		}
	}
}

bool Cluster::ChanceToInsertTask()
{
	int a = 0;
	int b = Tasks.front().NeedCores;
	for (int i = 0; i < Proces.size(); i++)
	{
		if (Proces[i].Cores >= Tasks.front().NeedCores)
			a++;
	}
	if (a >= Tasks.front().NeedProc)
		return true;
	return false;
}

Cluster::Cluster()
{
	 WorkTime=0;
	 ChanceOfNew=0;
}


Cluster::~Cluster()
{
	
}

Cluster::Processor::Processor()
{
	Cores = 0;
	FreeCores = 0;
}

Cluster::Processor::~Processor()
{
}

bool Cluster::Processor::isFull()
{
	return FreeCores == 0;
}
void Cluster::Task::Rand(int MT, int MC, int MP,int NumberInClaster)
{
	ID = "T00000000";
	stringstream is;
	is << NumberInClaster;
	string word;
	is >> word;
	ID.replace(9 - word.size(), 9, word);
	NeedCores = 1 + (rand() % MC)/4;
	NeedTakts = 1 + (rand() % MT)/4;
	NeedProc = 1 + (rand() % MP)/2;
	StartTime = 0;
}
bool Cluster::Task::isComplited(int CurrentTakt)
{
	return CurrentTakt - StartTime == NeedTakts;
}

Cluster::Task::Task() :NeedTakts(0), NeedCores(0), NeedProc(0), StartTime(0)
{
}

Cluster::Task::~Task()
{
}
