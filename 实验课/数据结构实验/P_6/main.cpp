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
	cout << "100������ʱ��" << endl;
	getRandomData(num1, num2, num3, 0, length, length);//��ʼ����������
	cout << "���:" << endl;	
	GetOrdered::Print(num1, length);
	//�۰��������
	GetOrdered::BinInsertSort(num1, length);
	cout << "�۰��������:" << endl;
	GetOrdered::Print(num1, length);
	delete num1;
	//ϣ������
	GetOrdered::ShellSort(num2, length);
	cout << "ϣ������:" << endl;
	GetOrdered::Print(num2, length);
	delete num2;
	//
	//��������
	GetOrdered::QuickSort(num3, 0,length-1);
	cout << "��������:" << endl;
	GetOrdered::Print(num3, length);
	delete num3;
}
void Get1W()
{
	int *num1 = new int[10000], *num2 = new int[10000], *num3 = new int[10000];
	int length = 10000;double start,end;
	getRandomData(num1, num2, num3, 0, length, length);//��ʼ����������
	cout << "1w������ʱ��" << endl;
	cout << "�۰��������ʱ���Ϊ:";
	//�۰��������
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "ϣ������ʱ���Ϊ:";
	//ϣ������
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms"<<endl;
	delete num2;

	cout << "��������ʱ���Ϊ:";
	//��������
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
	getRandomData(num1, num2, num3, 0, length, length);//��ʼ����������
	cout << "10w������ʱ��" << endl;
	cout << "�۰��������ʱ���Ϊ:";
	//�۰��������
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "ϣ������ʱ���Ϊ:";
	//ϣ������
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num2;

	cout << "��������ʱ���Ϊ:";
	//��������
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
	getRandomData(num1, num2, num3, 0, length, length);//��ʼ����������
	cout << "100w������ʱ��" << endl;
	cout << "�۰��������ʱ���Ϊ:";
	//�۰��������
	start = GetTickCount();
	GetOrdered::BinInsertSort(num1, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num1;

	cout << "ϣ������ʱ���Ϊ:";
	//ϣ������
	start = GetTickCount();
	GetOrdered::ShellSort(num2, length);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num2;

	cout << "��������ʱ���Ϊ:";
	//��������
	start = GetTickCount();
	GetOrdered::QuickSort(num3, 0, length - 1);
	end = GetTickCount();
	cout << end - start << "ms" << endl;
	delete num3;
}
void getRandomData(int data1[], int data2[], int data3[], int min, int max,int length)//���n���������
{
	srand((int)time(0));//ʹ��ϵͳʱ����Ϊ�������
	for (int i = 0; i < length; i++) 
	{
		data1[i] = data2[i] = data3[i] = rand() % (max - min + 1) + min;
	}
}