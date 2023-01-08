// HW08
// 許笙杰 E14075304 機械二乙
#include "Queue.h"

int main()
{
	Queue queue;	// 佇列
	queue.delete_element();
	queue.add_element(50);
	queue.add_element(21);
	queue.delete_element();
	queue.add_element(70);
	queue.delete_element();
	queue.delete_element();
	queue.delete_element();
	queue.add_element(50);
	return 0;
}