#pragma once
template <typename T>
class PQueue
{
	template <typename T>
	class Node {
	public:
		double priority;
		Node * pNext;
		T data;
		Node(T data = T(),double prio=0)
		{
			priority = prio;
			this->data = data;
		}
		~Node() {}
	};
	int size;
	Node <T>  * head;
	Node  <T> * LastNode;
public:
	void pushsort(T data,double PrioValue); // Вставка в конец очереди
	void pop(); // Удаление первого элемента
	T & front(); // Доступ к первому элементу
	int lenght(); // Размер очереди
	bool IsEmpty();
	PQueue();
	~QQueue();
};

template<typename T>
inline void PQueue<T>::pushsort(T data, double PrioValue)
{
	if (head == nullptr)
	{
		head = new Node <T>(data,PrioValue);
		LastNode = head;

	}
	else {
		Node <T> *tmp = head;
		while (tmp->pNext!=nullptr)
		{
			if (PrioValue < tmp->priority)
				tmp = tmp->pNext;
			else
				tmp = new Node <T>(data, PrioValue);

		}
		LastNode->pNext = new Node <T>(data,PrioValue);
		LastNode = LastNode->pNext;
	}
	size++;
}
