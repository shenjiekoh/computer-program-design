// Element.cpp
#include "Element.h"

// 佇列元素建構子
Element::Element(int element) : data(element), next(0) {};

// 獲取佇列元素值
int Element::getData()
{
	return data;
}

// 獲取下個元素的指標
Element* Element::getNext()
{
	return next;
}

// 設定下個元素的指標
void Element::setNext(Element* nextElement)
{
	next = nextElement;
}