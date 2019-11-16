#include "pch.h"
#include "Task.h"
#include <vector>
processor::processor():Cores(0),FreeCores(0)
{

}
bool processor::isFull()
{
	return FreeCores == 0;
 }
void processor::Rand()
{
	srand(time(0));
	Cores = 1 + rand() % 24;
	FreeCores = Cores;
}
processor & processor::operator=(const processor a)
{
	return *this;
}
void processor::setCores(int C)
{
	Cores = C;
}
void processor::setFreeCores(int FC)
{
	FreeCores = FC;
}
Task::Task():NeedTakts(0),NeedCores(0),NeedProc(0),StartTime(0)
{
}
int processor::getFreeCores()
{
	return FreeCores;
}
 void Task::Rand(int MT,int MP,int MC)
{
	srand(time(0));
	NeedCores = 1 + rand() % MC;
	NeedTakts = 1 + rand() % MT;
	NeedProc = 1 + rand() % MP;
	StartTime = 0;
}
Task::~Task()
{
}
int Task::GetCores()
{
	return NeedCores;
}
int Task::GetProc()
{
	return NeedProc;
}
int Task::GetStartTime()
{
	return StartTime;
}
int Task::GetTakts()
{
	return NeedTakts;
}
bool Task::IsComplited(int Current)
{
	return Current - StartTime == NeedTakts;
}
void Task::SetStartTime(int ST)
{
	StartTime = ST;
}
Claster::Claster() :ChanceOfNew(0)
{
	Proces = new processor [0];
}
void Claster::setNumberProc(int n)
{
	
}
Claster::Claster(int Numb,double chance,int WorkTime)
{
	NumberProcessors = Numb;
	this->WorkTime = WorkTime;
	Proces = new processor[Numb];
	srand(time(0));
	for (int i = 0; i < NumberProcessors; i++)
	{
		int b = 1 + rand() % 24;
		Proces[i].setCores(b);
		Proces[i].setFreeCores(b);
	}
	ChanceOfNew = chance;
}

void Claster::setChance(double c)
{
	ChanceOfNew = c;
}
void Claster::Start()
{
	
	Task a;
	srand(time(0));
	double p = 1 / ((0.01) *(1 + rand() % 100));
	if (p > ChanceOfNew)
	{
		a.Rand(WorkTime, NumberProcessors, 24);
		Tasks.push(a);
	}
	
}
void Claster::PushTasks()
{
	std::vector<int> pos;
	bool CanInsert = 1;
	while (!Tasks.IsEmpty() && CanInsert == 1)
	{
		int Check = 0;
			for (int i = 0; i < NumberProcessors; i++)
			{
				if (Proces[i].getFreeCores() >= Tasks.front().GetCores())
				{
					Check++;
					pos.push_back(i);
				}
				if (Check == Tasks.front().GetProc())
					break;	
			}
			if (Check == Tasks.front().GetProc())
			{
				for (int j = 0; j < pos.size(); j++)
				{
					Proces[pos[j]].setFreeCores(Proces[pos[j]].getFreeCores() - Tasks.front().GetCores());
					Actives.push_back(Tasks.front());
					Tasks.pop();
				}
			}
			
	}
}