#include <iostream>
#include "HafTree.h"

using namespace std;

int main() {
	int datas[] = { 12 , 1 , 23 , 35 , 21 , 60 , 90 , 60 , 10 , 15, 25, 56 };
	const int length = sizeof(datas)/sizeof(int);
	HafTree nodes[2*length-1];
	for (int i = 0; i<length; i++)//��ʼ������
	{
		nodes[i].data = 'a'+i;
		nodes[i].weight = datas[i];
	}
	HafTree::getTree(nodes, length);
	HCode codes[length];
	HafTree::createHCode(nodes, codes, length);
	for (int i = 0;i < length;i++)
	{
		cout << "��" << i + 1 << "�����Ϊ:" << nodes[i].data << "   ����������Ϊ:" << endl;
		for (int j = codes[i].start; j < length; j++)
		{
			cout << codes[i].cd[j] << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}