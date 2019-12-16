#include "GetOrdered.h"
#include "head.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include <Windows.h>
using namespace std;
int main()
{	
	Get100();
	//Get1W();
	//Get10W();
	//Get100W();
	system("pause");
	return 0;
}
void Get100()
{
	int *num1 = new int[100], *num2 = new int[100], *num3 = new int[100];
	int length = 100;
	cout << "100个数据时：" << endl;
	getRandomData(num1, num2, num3, 0, length, length);//初始化三个数组
	cout << "最初:" << endl;	
	GetOrdered::Print(num1, length);
	//折半插入排序
	GetOrdered::BinInsertSort(num1, length);
	cout << "折半插入排序:" << endl;
	GetOrdered::Print(num1, length);
	delete num1;
	//希尔排序
	GetOrdered::ShellSort(num2, length);
	cout << "希尔排序:" << endl;
	GetOrdered::Print(num2, length);
	delete num2;
	//
	//快速排序
	GetOrdered::QuickSort(num3, 0,length-1);
	cout << "快速排序:" << endl;
	GetOrdered::Print(num3, length);
	delete num3;
}
void Get1W()
{
	int *num1 = new int[10000], *num2 = new int[10000], *num3 = new int[10000];
	int length = 10000;double start,end;
	getRandomData(num1, num2, num3, 0, length, length);//初始化三个数组
	cout << "1w个数据时：" << endl;
	cout << "折半插入排序时间差为:";
	//折半插入排序
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "希尔排序时间差为:";
	//希尔排序
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms"<<endl;
	delete num2;

	cout << "快速排序时间差为:";
	//快速排序
	start = GetTickCount();
	GetOrdered::QuickSort(num3, 0, length - 1);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num3;
}
void Get10W()
{
	int *num1 = new int[100000], *num2 = new int[100000], *num3 = new int[100000];
	int length = 100000;double start, end;
	getRandomData(num1, num2, num3, 0, length, length);//初始化三个数组
	cout << "10w个数据时：" << endl;
	cout << "折半插入排序时间差为:";
	//折半插入排序
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "希尔排序时间差为:";
	//希尔排序
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num2;

	cout << "快速排序时间差为:";
	//快速排序
	start = GetTickCount();
	GetOrdered::QuickSort(num3, 0, length - 1);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num3;
}
void Get100W()
{
	int *num1 = new int[1000000], *num2 = new int[1000000], *num3 = new int[1000000];
	int length = 1000000;double start, end;
	getRandomData(num1, num2, num3, 0, length, length);//初始化三个数组
	cout << "100w个数据时：" << endl;
	cout << "折半插入排序时间差为:";
	//折半插入排序
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "希尔排序时间差为:";
	//希尔排序
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num2;

	cout << "快速排序时间差为:";
	//快速排序
	start = GetTickCount();
	GetOrdered::QuickSort(num3, 0, length - 1);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num3;
}
void getRandomData(int data1[], int data2[], int data3[], int min, int max,int length)//获得n个随机数组
{
	srand((int)time(0));//使用系统时间作为随机种子
	for (int i = 0; i < length; i++) 
	{
		data1[i] = data2[i] = data3[i] = rand() % (max - min + 1) + min;
	}
}