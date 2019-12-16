#include "BTNode.h"
#include<iostream>
using namespace std;


int main()
{
	const char * c = "A(B(E,F(G(H,I),J)),(C,D))";
	BTNode * BTree = BTNode::CreateBTree(c);
	cout << "µÝ¹éÏÈÐò±éÀú£º" << endl;
	BTNode::PreOrder(BTree);
	cout << endl << "·ÇµÝ¹éÏÈÐò±éÀú£º" << endl;
	BTNode::PreOrder1(BTree);
	BTNode::DestoryBTree(BTree);
	system("pause");
	return 0;
}