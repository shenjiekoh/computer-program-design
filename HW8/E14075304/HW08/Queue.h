// Queue.h
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Element.h"
class Queue
{
  public:
	Queue();	// 預設建構子
	void add_element(int element);	// 增加元素函式
	int delete_element();	// 刪除元素函式
	void print();	// 列印佇列所有資料的函式
	bool is_empty();	// 判斷佇列是否有元素的函式

	~Queue();	// 除構子
	Queue(const Queue&);	// 複製建構子

  private:
	Element* front;	// 指向佇列前端的指標
	Element* rear;	// 指向佇列尾端的指標
};
#endif