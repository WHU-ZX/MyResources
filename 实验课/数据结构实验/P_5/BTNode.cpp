#include "BTNode.h"
#define MaxSize 100
#include <iostream>
#include <stack>
using namespace std;

BTNode* BTNode::CreateBTree(const char * str)
{
	BTNode * St[MaxSize], *p = nullptr;
	int top = -1, k, j = 0;
	char ch;
	BTNode *ret = nullptr;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(': top++;St[top] = p; k = 1;break;
		case ')': top--;break;
		case ',': k = 2;break;
		default:p = new BTNode(ch);
			if (ret == nullptr)  ret = p;//根节点
			else
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;break;
				case 2:St[top]->rchild = p;break;
				}
			}
			
		}
		j++;
		ch = str[j];
	}
	return ret;
}
void BTNode::PreOrder1(BTNode * b)//非递归先序
{
	BTNode *p;
	stack<BTNode*> st;
	if (b != nullptr)
	{
		st.push(b);
		while (!st.empty())
		{
			p = st.top();
			st.pop();
			cout << p->data << "  ";
			if (p->rchild != nullptr)			
				st.push(p->rchild);			
			if (p->lchild != nullptr)			
				st.push(p->lchild);			
		}
	}
}
void BTNode::PreOrder(BTNode * b)//递归先序
{
	if (b != nullptr)
	{
		cout << b->data << "  ";
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void BTNode::InOrder(BTNode * b)
{
	if (b != nullptr)
	{		
		InOrder(b->lchild);
		cout << b->data << "";
		InOrder(b->rchild);
	}
}
void BTNode::PostOrder(BTNode * b)
{
	if (b != nullptr)
	{
		PostOrder(b->lchild);		
		PostOrder(b->rchild);
		cout << b->data << "";
	}
}
void BTNode::DestoryBTree(BTNode * b)
{
	if (b != nullptr)
	{
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		delete b;
	}
}
BTNode::BTNode()
{
	lchild = nullptr;
	rchild = nullptr;
}
BTNode::BTNode(char c) :BTNode()
{
	this->data = c;
}
BTNode::~BTNode()
{
}
