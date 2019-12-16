#pragma once
#define Max 100
class Stack
{
public:
private:
	int top = -1;
	char* datas;
public:
	Stack();
	~Stack();
	bool push(char c);
	bool pop(char &c);
	bool getTop(char &c);
	bool isFull();
	bool isEmpty();
};

