#pragma once
#include "HCode.h"
class HafTree
{
public:
	char data;
	int lchild;
	int rchild;
	int weight;//ШЈжи
	int parent;
	HafTree(int lchild, int rchild,int weight,char data,int parent);
	HafTree();
	static void getTree(HafTree ht[],int n0);
	static void createHCode(HafTree ht[], HCode hcd[], int n0);
	~HafTree();
};

