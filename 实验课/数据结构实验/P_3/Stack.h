#pragma once

#define MAX 625
template <class T> 
class Stack
{
public:
	
	Stack();
	~Stack();
	bool Push(T e);
	bool Pop(T e);
	bool IsEmpty();
	bool IsFull();
private:
	T data[MAX];
	int top = -1;
};

