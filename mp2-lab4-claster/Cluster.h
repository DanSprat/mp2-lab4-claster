#pragma once
#include "TList.h"
#include "queue.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "windows.h"
#include <sstream>
#include <fstream>
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
	TPQueue <Task> Tasks; // Очереь задач
	vector <Processor> Proces; // Процессоры
	bool InfoF; // Флаг на вывод полной информации 
	int WorkTime; // Время работы
	double ChanceOfNew; // Порог появления новой задачи
public:
	void SetInfoMode(bool info); 
	Cluster(int NumProc=0, int WorkTime=0, double Chance=0,bool Info=false);
	void Start();
	bool ChanceToInsertTask();
     Cluster();
	~Cluster();
};

