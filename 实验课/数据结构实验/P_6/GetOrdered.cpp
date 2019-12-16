#include "GetOrdered.h"
#include <iostream>
using namespace std;
void GetOrdered::BinInsertSort(int R[], int n)//折半插入排序
{
	int i, j, low, high, mid;
	int tmp;
	for (i = 1;i < n;i++)
	{
		if (R[i] < R[i - 1])
		{
			tmp = R[i];
			low = 0;high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp < R[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1;j >= high + 1;j--)
				R[j + 1] = R[j];
			R[high + 1] = tmp;
		}
	}
}
void GetOrdered::ShellSort(int R[], int n)//希尔排序
{
	int i, j, d;
	int tmp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d;i < n;i++)
		{
			tmp = R[i];
			j = i - d;
			while (j >= 0 && tmp < R[j])
			{
				R[j + d] = R[j];
				j -= d;
			}
			R[j + d] = tmp;
		}
		d /= 2;
	}
}
void GetOrdered::QuickSort(int R[], int s, int t)//快速排序
{
	int i;
	if (s < t)
	{
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);
		QuickSort(R, i + 1, t);
	}
}
int GetOrdered::partition(int R[], int s, int t)//一趟划分
{
	int i = s, j = t;
	int tmp = R[i];
	while (i < j)
	{
		while (i < j&&R[j] >= tmp)
			j--;
		R[i] = R[j];
		while (i < j&&R[i] <= tmp)
			i++;
		R[j] = R[i];
	}
	R[i] = tmp;
	return i;
}
void GetOrdered::Print(int R[],int length)//打印数组
{
	int j = 1;
	for (int i = 0; i < length ; i++,j++)
	{
		cout << R[i] << "\t";
		if (j == 10)
		{
			j = 0;
			cout << endl;
		}			
	}
}

GetOrdered::GetOrdered()
{
}
GetOrdered::~GetOrdered()
{
}
