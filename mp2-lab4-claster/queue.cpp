#include "pch.h"
#include "queue.h"
template <typename T>
queue <T>::queue()
{
	size = 0;
	head = nullptr;
}

template <typename T>
queue <T>::~queue()
{

}
template <typename T>
int queue <T>::lenght()
{
	return size;
}
template <typename T>
void queue <T>::pop()
{
	if (head == nullptr)
		throw 1;
	Node <T> *tmp = head->pNext;
	delete head;
	head = tmp;
	size--;
}
