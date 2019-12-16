#include <stack>
#include "def.h"
#include<iostream>
#include "StBox.h"
#include "QuBox.h"
#include "MyQue.h"
using namespace std;
int mg[M + 2][N + 2] ={	{1,1,1,1,1,1,1,1,1,1},
						{1,0,0,1,0,0,0,1,0,1},
						{1,0,0,1,0,0,0,1,0,1},
						{1,0,0,0,0,1,1,0,0,1},
						{1,0,1,1,1,0,0,0,0,1},
						{1,0,0,0,1,0,0,0,0,1},
						{1,0,1,0,0,0,1,0,0,1},
						{1,0,1,1,1,0,1,1,0,1},
						{1,1,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1}};
int main() 
{
	//bool f = getBySt(mg, 1, 1, 8, 8);//用栈求解
	bool f = getByQue(mg,1,1,8,8);//用队列求解
	if (f) 
	{
		cout << "find" << endl;
	}
	else 
	{
		cout << "not find" << endl;
	}
	system("pause");
	return 0;
}
bool getBySt(int mg[M+2][N+2], int xi, int yi, int xe, int ye) {
	StBox path[MAX], e;int i, j, di, i1, j1, k;bool find;//
	stack<StBox> st;
	e.i = xi;e.j = yi;e.di = -1;//e为入口
	st.push(e);
	mg[xi][yi] = -1;//入口设为-1
	while (!st.empty()) {//当栈不为空
		e = st.top();//获得栈顶元素
		i = e.i;j = e.j;di = e.di;
		if (i == xe && j == ye)
		{
			cout << "一条路径如下：";
			k = 0;
			while (!st.empty()) {
				e = st.top();
				st.pop();
				path[k++] = e;
			}
			while (k >= 1)
			{
				k--;
				printf("\t(%d,%d)", path[k].i, path[k].j);
				if ((k + 2) % 5 == 0)  	//每输出每5个方块后换一行
					printf("\n");
			}
			printf("\n");			    	
			return true;
		}
		find = false;
		while (di < 4 && !find) {
			di++;
			switch (di)
			{
			case 0:i1 = i - 1;	j1 = j;    break;
			case 1:i1 = i;		j1 = j + 1;  break;
			case 2:i1 = i + 1;	j1 = j;    break;
			case 3:i1 = i;		j1 = j - 1;  break;
			}
			if (mg[i1][j1] == 0)  find = true;
		}
		if (find) {//找到了一个相邻可走方块(i1,j1)
			st.top().di = di;
			e.i = i1; e.j = j1; e.di = -1;
			st.push(e);	     //相邻可走方块e进栈
			mg[i1][j1] = -1;
		}
		else {
			e = st.top();
			st.pop();
			mg[e.i][e.j] = 0;//让退栈方块的位置变为其他路径可走方块
		}
	}
	return false;
}
bool getByQue(int mg[M + 2][N + 2], int xi, int yi, int xe, int ye) 
{
	QuBox e;int i, j, di, i1, j1;
	MyQue *que = new MyQue();
	e.i = xi;e.j = yi;e.pre = -1;
	que->enQueue(e);
	mg[xi][yi] = -1;
	while (!que->IsEmpty())
	{
		que->deQueue(e);
		i = e.i;j = e.j;
		if (i == xe && j == ye)		//找到了出口,输出路径
		{
			e.i = xe;e.j = ye;e.pre = que->front;
			que->enQueue(e);
			print(que);	//调用print函数输出路径
			delete que;		//销毁队列
			return true;		//找到一条路径时返回真
		}
		for (di = 0;di < 4;di++) 
		{
			switch (di)
			{
			case 0:i1 = i - 1; j1 = j;   break;
			case 1:i1 = i;   j1 = j + 1; break;
			case 2:i1 = i + 1; j1 = j;   break;
			case 3:i1 = i;   j1 = j - 1; break;
			}
			if (mg[i1][j1] == 0)
			{//将i1，j1入队
				e.i = i1;  e.j = j1;
				e.pre = que->front;
				que->enQueue(e);	//(i1，j1)方块进队
				mg[i1][j1] = -1;	//将其赋值-1
			}
		}
	}
	delete que;
	return false;
}
void print(MyQue* que) {
	stack<QuBox> st;
	QuBox e = que->datas[que->rear];
	while (e.pre != -1) {
		st.push(e);
		e = que->datas[e.pre];
	}
	st.push(e);
	int k = 0;
	cout << "there is a path:" << endl;
	while (!st.empty()) {
		e = st.top();
		st.pop();
		k++;
		cout << "(" << e.i << "," << e.j << ")"<<"\t";
		if (k % 5 == 0) {
			k %= 5;
			cout << endl;
		}
	}
}
