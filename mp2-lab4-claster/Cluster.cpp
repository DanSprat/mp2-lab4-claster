#include "pch.h"
#include "Cluster.h"
#include <ctime>
#include <vector>
Cluster::Cluster(int NumProc, int WorkTime, double Chance)
{
	this->WorkTime = WorkTime;
	NumberProcessors = NumProc;
	ChanceOfNew = Chance;
	Proces = new Processor[NumberProcessors];
	srand(time(0));
	for (int i = 0; i < NumberProcessors; i++)
	{
		int b = 1 + rand() % 24;
		Proces[i].Cores = b;
		Proces[i].FreeCores = b;
	}
}

void Cluster::Start()
{
	std::vector<int> pos;
	Task a;
	bool CanInsert;
	for (int i = 0; i < WorkTime; i++)
	{
		srand(time(0));
		double p = ((0.01) *(rand() % 100));
		if (p > ChanceOfNew)
		{
			a.Rand(WorkTime, NumberProcessors, 24);
			Tasks.push(a);
		}
		CanInsert = 1;
		while (!Tasks.IsEmpty())
		{
			while (!ChanceToInsertTask())
				Tasks.pop();
			int Check = 0;
			for (int j = 0; j < NumberProcessors; j++)
			{
				if (Proces[j].FreeCores >= Tasks.front().NeedCores)
				{
					Check++;
					pos.push_back(j);
				}
				if (Check == Tasks.front().NeedProc)
					break;
				if (j == NumberProcessors - 1)
				{
					CanInsert = 0;
				}
			}
			if (CanInsert)
			{
				for (int j = 0; j < pos.size(); j++)
					Proces[pos[j]].FreeCores -= Tasks.front().NeedCores;
				Actives.push_back(Tasks.front());
				Tasks.pop();
			}
			else break;
		}
		for (int j = 0; j < Actives.size(); j++)
		{
			if (Actives[j].isComplited(i))
			{
				Complited.push_back(Actives[j]);
				Actives.erase(Actives.begin()+j-1);
			}
		}
	}
}

bool Cluster::ChanceToInsertTask()
{
	int a = Tasks.front().NeedProc;
	int b = Tasks.front().NeedCores;
	for (int i = 0; i < NumberProcessors; i++)
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
	NumberProcessors = 0;
	 WorkTime=0;
	 ChanceOfNew=0;
}


Cluster::~Cluster()
{
	delete[] Proces;
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
void Cluster::Task::Rand(int MT, int MC, int MP)
{
	srand(time(0));
	NeedCores = 1 + rand() % MC;
	NeedTakts = 1 + rand() % MT;
	NeedProc = 1 + rand() % MP;
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
