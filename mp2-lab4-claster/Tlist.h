#include <iostream>
using namespace std;
template <typename T>
//////////////////   ЗВЕНО СПИСКА  /////////////////////////
struct Link
{
	Link * pNext;
	T data;
	Link(T data = T(), Link * pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
	~Link() {  }
};
/////////////////////////////////////////////////////////////////////////

template <typename T>

//////////////// ОДНОСВЯЗНЫЙ СПИСОК ////////////////////////
class Tlist
{
public:
	Tlist();
	~Tlist() { delete[] head; }
	void push_back(T); // Вставка в конец
	void push_first(T); // Вставка в начало
	void push_pos(T, int); // Вставка на позицию 
	void delete_elem(int pos); // Удаление n-ого элемента
	int len() { return size; } // Узнать длину
	Link <T> *  find_elem(T); // Поиск элемента
private:
	int size;
	Link <T> * head;
};
//////////////////////////////////////////////////////////////////////////

///////////////////// МЕТОДЫ ///////////////////////////////////
template <typename T>
Tlist <T>::Tlist()
{
	size = 0;
	head = nullptr;
}

template<typename T>
void Tlist<T>::push_back(T data) // Положить на "хвост"
{
	if (head == nullptr)  //Если "голова" пуста
	{
		head = new Link <T>(data); // Создаем ее
	}
	else
	{
		Link <T> *tmp = this->head;
		while (tmp->pNext != nullptr) // Мотаем до "хвоста"
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = new Link <T>(data); //Создаем в хвосте элемент
	}
	size++;
}

template<typename T>
void Tlist<T>::push_first(T data) // Положить в "голову"
{
	if (head == nullptr)
	{
		head = new Link <T>(data);
	}
	else
	{
		Link <T> *tmp;
		tmp = new Link <T>(data); // Создаем Звено со значением data
		tmp->pNext = head; // Следующее звено будет иметь адрес текущей головы 
		head = tmp; // меняем адрес "головы"
	}
	size++;
}

template<typename T>
void Tlist<T>::push_pos(const  T data, const int pos) // Положить на позицию
{
	if (pos > size)
		throw 1;
	if (pos == 0) {
		push_first(data);
		return;
	}
	if (pos == size) {
		push_back(data);
		return;
	}
	int i = 0;
	Link <T>* tmp;
	Link <T> * PreLink = head; // Сохраняем предыдущий индекс
	while (i != pos - 1)  // Доходим до звена с номером на 1 меньше и останавливаемся
	{
		PreLink = PreLink->pNext;
		i++;
	}
	tmp = new Link <T>(data); //Создаем звено со значением data
	tmp->pNext = PreLink->pNext;
	PreLink->pNext = tmp;
	size++;
}

template<typename T>
void Tlist<T>::delete_elem(int pos)
{
	try {
		if (pos >= size || pos < 0)
			throw 1;
	}
	catch (int i)
	{
		cout << "Ошибка №" << i << ": неверная позиция" << endl;
		return;
	}
	Link <T> * tmp = head;
	Link <T> * deleted;
	if (pos == 0)
	{
		if (head->pNext != nullptr)
		{
			tmp = tmp->pNext;
			delete[] head;
			head = tmp;
			size--;
			return;
		}
		tmp = tmp->pNext;
		deleted = head;
		delete[] deleted;
		head = tmp;
		size--;
		return;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		tmp = tmp->pNext;
	}
	deleted = tmp->pNext;
	if (deleted->pNext != nullptr)
	{
		if (deleted != head)
			tmp->pNext = deleted->pNext;
	}
	else
	{
		tmp->pNext = nullptr;
	}
	size--;
	delete[] deleted;
}

template<typename T>
Link <T> * Tlist<T>::find_elem(T data)
{
	Link <T> *back;
	Link <T> *tmp = head;
	if (size == 0)
		return tmp;
	for (int i = 0; i < size; i++)
	{
		if (tmp->data == data)
			return  tmp;
		tmp = tmp->pNext;
	}
	return tmp;
}
