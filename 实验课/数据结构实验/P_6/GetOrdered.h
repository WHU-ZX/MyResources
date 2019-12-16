#pragma once
class GetOrdered
{
private:
	static int partition(int R[], int s, int t);//一趟划分
public:
	static void BinInsertSort(int R[], int n);//折半插入排序
	static void ShellSort(int R[], int n);//希尔排序
	static void QuickSort(int R[], int s, int t);//快速排序
	static void Print(int R[],int length);//打印数组
	GetOrdered();
	~GetOrdered();
};

