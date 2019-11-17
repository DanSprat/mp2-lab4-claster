#pragma once
#include "TList.h"
#include "queue.h"
#include <vector>
using namespace std;
class Cluster
{
	class Processor 
	{	
	public:
		int Cores;
		int FreeCores;
		Processor();
		~Processor();
		bool isFull();
	};
	class Task
	{
	public:
		int NeedTakts;
		int NeedCores;
		int NeedProc;
		int StartTime;
		void Rand(int MT,int MC,int MP);
		bool isComplited(int CurrentTakt);
		Task();
		~Task();
	};
	vector <Task> Actives;
	vector <Task> Complited;
	queue <Task> Tasks;
	Processor *Proces;
	int NumberProcessors;
	int WorkTime;
	double ChanceOfNew;
public:
	Cluster(int NumProc, int WorkTime, double Chance);
	void Start();
	bool ChanceToInsertTask();
	Cluster();
	~Cluster();
};

