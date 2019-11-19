#pragma once
template <typename T>
class queue
{
	template <typename T>
	class Node {
	public:
		Node *pNext;
		T data;
		Node(T data = T())
		{
			this->data = data;
		}
		~Node() {}
	};
	int size;
	Node <T>  * head;
	Node  <T> * LastNode;
public:
	void push(T data); // Вставка в конец очереди
	void pop(); // Удаление первого элемента
	T & front(); // Доступ к первому элементу
	int lenght(); // Размер очереди
	bool IsEmpty();
	queue(); 
	~queue();
};
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
queue <T>::queue() : size(0), head(nullptr), LastNode(nullptr)
{
}
template <typename T>
queue <T>::~queue()
{
	while (head != nullptr)
	{
		Node <T> *p = head;
		head = head->pNext;
		delete p;
	}
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
template <typename T>
void queue <T>::push(T  data)
{
	if (head == nullptr)
	{
		head = new Node <T>(data);
		LastNode = head;
	}
	else {
		LastNode->pNext = new Node <T>(data);
		LastNode = LastNode->pNext;
	}
	size++;
}
template <typename T>
T& queue <T>::front()
{
	if (head == nullptr)
		throw 1;
	return head->data;
}
template <typename T>
bool queue <T>::IsEmpty()
{
	return head == nullptr;
}

