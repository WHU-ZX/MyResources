#include "HafTree.h"
HafTree::HafTree()//�޲ι���
{
	/*this->heavy = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;*/
}
HafTree::HafTree(int lchild, int rchild, int weight, char data, int parent)//������������
{
	this->weight = weight;
	this->lchild = lchild;
	this->rchild = rchild;
	this->data = data;
	this->parent = parent;
}
void HafTree::getTree(HafTree ht[], int n0)
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (int i = 0; i < 2 * n0 - 1;i++)//���н��
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	for (int i = n0;i < 2 * n0 - 1;i++)//�ڲ��ڵ�
	{
		min1 = min2 = 32767;//min1 ��¼��С�ģ�min2��¼�ڶ�С��
		lnode = rnode = -1;//lnode��min1���±꣬rnode��min2���±�
		for (k = 0;k < i; k++)//��ȡǰi���е���С���������
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)//min2���min1
				{
					min2 = min1;rnode = lnode;
					min1 = ht[k].weight;lnode = k;
				}
				else if (ht[k].weight < min2)//min2���ht[k]
				{
					min2 = ht[k].weight;rnode = k;
				}
			}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;ht[i].rchild = rnode;
		ht[lnode].parent = ht[rnode].parent = i;
	}
}
void HafTree::createHCode(HafTree ht[], HCode hcd[], int n0)
{
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0; i++)
	{
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (-1 != f)
		{
			if (ht[f].lchild == c)//��ǰ���������
				hc.cd[hc.start--] = '0';
			else//��ǰ������Һ���
				hc.cd[hc.start--] = '1';
			c = f; f = ht[f].parent;
		}
		hc.start++;hcd[i] = hc;
	}
}
HafTree::~HafTree()//�Ժ��ͷ�HafTree��ʱ��ֱ���ͷ�ͷָ��
{
}
