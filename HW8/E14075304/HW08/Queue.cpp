// Queue.cpp
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// 預設建構子
Queue::Queue() : front(0), rear(0) {};

// 增加元素函式
void Queue::add_element(int element)
{
	cout << "add_element(" << element << ")" << endl;
	Element* current = new Element(element);
	
	if (is_empty())
		front = current;
	else
		rear->setNext(current);
	rear = current;
	print();
}

// 刪除元素函式
int Queue::delete_element()
{
	cout << "delete_element()" << endl;
	if (is_empty())
	{
		print();
		return 0;
	}
	else
	{
		front->getData();
		Element* temp = front->getNext();
		delete front;
		front = temp;
		print();
		if (is_empty())
			return 0;
		else
			return front->getData();
	}
}

// 列印佇列所有資料的函式
void Queue::print()
{
	Element* current = front;

	cout << "[ ";
	while (current)
	{
		cout << current->getData();
		current = current->getNext();
		if (current)
			cout << " , ";
	}
	cout << " ]" << endl;
}

// 判斷佇列是否有元素的函式
bool Queue::is_empty()
{
	return (front == 0);
}

// 除構子
Queue::~Queue()
{
	while (front)
	{
		Element* ptemp = front;
		front = front->getNext();
		delete ptemp;
	}
	rear = 0;
}

// 複製建構子
Queue::Queue(const Queue& queue)
{
	Element* current = queue.front;
	while (current)
	{
		int data = current->getData();
		Element* pnew = new Element(data);
		if (current == queue.front)
			front = pnew;
		else
			rear->setNext(pnew);
		rear = pnew;
		current = current->getNext();
	}
}