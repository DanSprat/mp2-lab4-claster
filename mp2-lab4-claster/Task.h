#pragma once
#include <ctime>
#include <iostream> 
#include "Tlist.h"
#include "queue.h"
#include <vector>
class processor {
	int Cores;
	int FreeCores;
public:
	void setFreeCores(int a);
	void setCores(int a);
	processor& operator= (const processor a);
	processor();
	~processor() {}
	bool isFull();
	void Rand();
	int getFreeCores();
};
class Task
{
	int NeedTakts;
	int NeedCores;
	int NeedProc;
	int StartTime;
public:
	int GetTakts();
	int GetCores();
	int GetProc();
	int GetStartTime();
	void SetStartTime(int ST);
	bool IsComplited(int Current);
	void Rand(int MaxTakts, int MaxProc,int MaxCores);
	Task();
	~Task();
};
class Claster
{
	Tlist <Task> Actives;
	int NumberProcessors;
	int WorkTime;
	processor *Proces;
	queue <Task> Tasks;
	double ChanceOfNew;
public:
	void PushTasks();
	Claster(int NumberProc,double chance,int WorkTime);
	Claster();
	void Start();
	void setNumberProc(int n);
	void setChance(double c);
};

