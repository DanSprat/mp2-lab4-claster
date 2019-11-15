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
		~Node()
	};
	int size;
	Node <T> * head;
	Node <T> * LastNode;
public:
	void push(T data);
	void pop();
	T &front();
	int lenght();
	queue();
	~queue();
};


