#pragma once
#include "queue.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "windows.h"
#include <sstream>
#include <fstream>
#include <iostream>
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
	template <typename T>
	void PrintInfo(T &out,double a,double b);
	vector <Task> Failed; // ������ ������� �� ������� �� �������,���� ���� �� ���  �� ����� �� ����� ������
	vector <Task> Actives; // ������ �� ��������
	vector <Task> Complited; // ����������� ������
	TPQueue <Task> Tasks; // ������ �����
	vector <Processor> Proces; // ����������
	bool InfoF; // ���� �� ����� ������ ���������� 
	int WorkTime; // ����� ������
	double ChanceOfNew; // ����� ��������� ����� ������
public:
	void SetInfoMode(bool info); 
	Cluster(int NumProc=0, int WorkTime=0, double Chance=0,bool Info=false);
	void Start();
	bool ChanceToInsertTask();
     Cluster();
	~Cluster();
};

template<typename T>
inline void Cluster::PrintInfo(T & out,double a,double b)
{
	out << "================================================================" << endl;
	out << endl;
	out << "���������� � ��������: " << endl;
	out << endl;
	out << setw(35) << left << "\t���������� ����������� " << setw(8) << left << Proces.size() << endl;
	out << setw(35) << left << "\t����� ������ ��������" << setw(8) << left << WorkTime << endl;
	out << setw(35) << left << "\t����� ��������� ����� ������" << setw(8) << left << ChanceOfNew << endl;
	out << endl;
	out << setw(35) << left << "������� �������� ��������" <<  a * 100 << " %" << endl;
	out << setw(35) << left << "����� ����������� ����� " << setw(8) << left << b << endl;
	out << setw(35) << left << "����� ����� � ������� " << setw(8) << left << Tasks.lenght() << endl;
	out << setw(35) << left << "����� ����������� ����� " << setw(8) << left << Complited.size() << endl;
	out << endl;
	out << setw(35) << left << "�����  ����� �� ��������� �� ��������: " << Failed.size() << endl;
	out << endl;
	if (Failed.size() != 0)
	{
		out << "���������� � ���: " << endl;
		for (int i = 0; i < Failed.size(); i++)
		{
			out << setw(10) << Failed[i].ID << setw(25) << "requires processors: " << Failed[i].NeedProc << setw(20) << "requires cores: " << Failed[i].NeedCores << setw(18) << "requires time: " << Failed[i].NeedTakts << endl;
		}
	}
	out << "\t������� ����������� ����� " << Complited.size() * 100 / b << " %" << endl;
	out << "================================================================" << endl;
}
