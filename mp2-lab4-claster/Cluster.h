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
		int NeedTakts;
		int NeedCores;
		int NeedProc;
		int StartTime;
		void Rand(int MT,int MC,int MP,int NumberInClaster);
		bool isComplited(int CurrentTakt);
		Task();
		~Task();
	};
	vector <Task> Failed; // ������ ������� �� ������� �� �������,���� ���� �� ���  �� ����� �� ����� ������
	vector <Task> Actives; // ������ �� ��������
	vector <Task> Complited; // ����������� ������
	queue <Task> Tasks;
	vector <Processor> Proces;
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

