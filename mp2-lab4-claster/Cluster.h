#pragma once
#include "TList.h"
#include "queue.h"
#include <vector>
#include <algorithm>
using namespace std;
class Cluster
{
	class Processor 
	{	
	public:
		vector <string> Tasks;
		int Cores;
		int FreeCores;
		Processor();
		~Processor();
		bool isFull();
	};
	class Task
	{
	public:
		string ID;
		vector <int> Where;
		int NeedTakts;
		int NeedCores;
		int NeedProc;
		int StartTime;
		void Rand(int MT,int MC,int MP,int NumberInClaster);
		bool isComplited(int CurrentTakt);
		Task();
		~Task();
	};
	vector <Task> Failed; // Задачи которые не попадут на кластер,даже если на том  не будет ни одной задачи
	vector <Task> Actives; // Задачи на кластере
	vector <Task> Complited; // Выполненные задачи
	queue <Task> Tasks;
	vector <Processor> Proces;
	bool InfoF;
	int WorkTime;
	double ChanceOfNew;
public:
	void SetInfoMode(bool info);
	Cluster(int NumProc, int WorkTime, double Chance);
	void Start();
	bool ChanceToInsertTask();
	Cluster();
	~Cluster();
};

