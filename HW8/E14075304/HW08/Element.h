// Element.h
#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H
class Element
{
  public:
	Element(int element);	// 佇列元素建構子
	int getData();	// 獲取佇列元素函式
	Element* getNext();	// 獲取下個元素指標的函式
	void setNext(Element* nextElement);	// 設定下個元素指標的函式
	
  private:
	int data;	// 整數
	Element* next;	// 指向下一個元素的指標
};
#endif