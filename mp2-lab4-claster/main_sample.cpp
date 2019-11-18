﻿// mp2-lab4-claster.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "Cluster.h"
#include "queue.h"
#include "TList.h"
using namespace std;
int main()
{
	
	setlocale(LC_ALL, "Russian");
	 char Info;
	int a, c;
	double b;
	cout << "Введите количество процессоров: ";
	cin >> a;
	cout << endl;
	cout << "Введите шанс появления новой задачи (от 0 до 1): ";
	cin >> b;
	cout << endl;
	cout << "Введите время работы кластера: ";
	cin >> c;
	cout << endl;
	Cluster Test(a,c,b);
	cout << "Выводить полную информацию на каждом такте? Y or N?" << endl;
	cin >> Info;
	if (Info == 'y' || Info == 'Y')
		Test.SetInfoMode(1);
	else 
		Test.SetInfoMode(0);
	Test.Start();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
