#pragma once

class BTNode
{
public:
	BTNode * lchild;
	BTNode * rchild;
	char data;

	static BTNode* CreateBTree(const char * str);
	static void DestoryBTree(BTNode * b);

	static void PreOrder(BTNode * b);
	static void InOrder(BTNode * b);
	static void PostOrder(BTNode * b);

	static void PreOrder1(BTNode * b);

	BTNode();
	BTNode(char c);
	~BTNode();
};

