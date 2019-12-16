#include "MyQue.h"



MyQue::MyQue()
{
	front = rear = -1;
}
bool MyQue::deQueue(QuBox& box) {
	if (IsEmpty()) {
		return false;
	}
	else {
		front++;
		box.i = datas[front].i;
		box.j = datas[front].j;
		box.pre = datas[front].pre;
		return true;
	}	
}
bool MyQue::enQueue(QuBox box) {
	if (IsFull()) {
		return false;
	}
	else {
		rear++;
		datas[rear].i = box.i;
		datas[rear].j = box.j;
		datas[rear].pre = box.pre;
		return true;
	}
}
bool MyQue::IsEmpty() {
	return front == rear;
}
bool MyQue::IsFull() {
	return rear == MAX - 1;
}
MyQue::~MyQue()
{
}
