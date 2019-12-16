#include "Stack.h"

bool Stack::push(char c)
{
	if (c == '\0' || isFull())
		return false;
	else {
		top++;
		datas[top] = c;
		return true;
	}
}
bool Stack::pop(char &c)
{
	if (isEmpty())
		return false;
	else {
		c = datas[top];
		top--;
		return true;
	}
}
bool Stack::getTop(char &c)
{
	if (isEmpty())
		return false;
	else {
		c = datas[top];
		return true;
	}
}
bool Stack::isFull()
{
	return top == Max-1;
}
bool Stack::isEmpty()
{
	return top == -1;
}
Stack::Stack()
{
	datas = new char[Max];
}
Stack::~Stack()
{
	delete datas;
	datas = nullptr;
}
