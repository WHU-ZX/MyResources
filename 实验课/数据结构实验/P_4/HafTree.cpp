#include "HafTree.h"
HafTree::HafTree()//无参构造
{
	/*this->heavy = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;*/
}
HafTree::HafTree(int lchild, int rchild, int weight, char data, int parent)//完整参数构造
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
	for (int i = 0; i < 2 * n0 - 1;i++)//所有结点
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	for (int i = n0;i < 2 * n0 - 1;i++)//内部节点
	{
		min1 = min2 = 32767;//min1 记录最小的，min2记录第二小的
		lnode = rnode = -1;//lnode是min1的下标，rnode是min2的下标
		for (k = 0;k < i; k++)//获取前i个中的最小的两个结点
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)//min2变成min1
				{
					min2 = min1;rnode = lnode;
					min1 = ht[k].weight;lnode = k;
				}
				else if (ht[k].weight < min2)//min2变成ht[k]
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
			if (ht[f].lchild == c)//当前结点是左孩子
				hc.cd[hc.start--] = '0';
			else//当前结点是右孩子
				hc.cd[hc.start--] = '1';
			c = f; f = ht[f].parent;
		}
		hc.start++;hcd[i] = hc;
	}
}
HafTree::~HafTree()//以后释放HafTree的时候直接释放头指针
{
}
