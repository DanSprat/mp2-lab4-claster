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
template <typename T>
class TPQueue
{
	template <typename T>
	class Node {
	public:
		Node *pNext;
		T data;
		double Priority;
		Node(T data = T(), double prior = 0)
		{
			this->Priority = prior;
			this->data = data;
		}
		~Node() {}
	};
	int size;
	Node <T>  * head;
	Node  <T> * LastNode;
public:
	void push(T data, double pr); // Вставка в конец очереди
	void pop(); // Удаление первого элемента
	T & front(); // Доступ к первому элементу
	int lenght(); // Размер очереди
	bool IsEmpty();
	TPQueue();
	~TPQueue();
};

template<typename T>
void TPQueue<T>::push(T data, double pr)
{
	if (head == nullptr)
	{
		head = new Node <T>(data, pr);
		LastNode = head;
	}
	else
	{
		Node <T> *tmp = head;
		Node <T> *Pretmp = nullptr;
		while (tmp->pNext != nullptr)
		{
			if (pr < tmp->Priority)
			{
				Pretmp = tmp;
				tmp = tmp->pNext;
			}
			else break;
		}
		if (tmp == head)
		{
			if (pr < tmp->Priority)
			{
				tmp->pNext = new Node <T>(data, pr);
				LastNode = tmp->pNext;
			}
			else
			{
				tmp = new Node <T>(data, pr);
				tmp->pNext = head;
				head = tmp;
			}
		}
		else
		{
			if (tmp->pNext == nullptr)
			{
				if (pr < tmp->Priority)
				{
					tmp->pNext = new Node <T>(data, pr);
					LastNode = tmp->pNext;
				}
				else
				{
					tmp = new Node <T>(data, pr);
					tmp->pNext = Pretmp->pNext;
					Pretmp->pNext = tmp;
				}
			}
			else
			{
				tmp = new Node <T>(data, pr);
				tmp->pNext = Pretmp->pNext;
				Pretmp->pNext = tmp;
			}
		}
	}
	size++;
}

template<typename T>
void TPQueue<T>::pop()
{
	if (head == nullptr)
		throw 1;
	Node <T> *tmp = head->pNext;
	delete head;
	head = tmp;
	size--;
}

template<typename T>
T & TPQueue<T>::front()
{
	if (head == nullptr)
		throw 1;
	return head->data;
}

template<typename T>
int TPQueue<T>::lenght()
{
	return size;
}

template<typename T>
bool TPQueue<T>::IsEmpty()
{
	return head == nullptr;
}

template<typename T>
TPQueue<T>::TPQueue() :size(0), head(nullptr), LastNode(nullptr)

{

}

template<typename T>
TPQueue<T>::~TPQueue()
{
	while (head != nullptr)
	{
		Node <T> *p = head;
		head = head->pNext;
		delete p;
	}
}
