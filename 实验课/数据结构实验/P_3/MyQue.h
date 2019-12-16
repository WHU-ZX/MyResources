#pragma once
#include "QuBox.h"
#include "def.h"
class MyQue
{
public:
	int front;
	int rear;
	QuBox datas[MAX];
	bool enQueue(QuBox box);
	bool deQueue(QuBox &box);
	bool IsEmpty();
	bool IsFull();
	MyQue();
	~MyQue();
};

