#pragma once
class GetOrdered
{
private:
	static int partition(int R[], int s, int t);//һ�˻���
public:
	static void BinInsertSort(int R[], int n);//�۰��������
	static void ShellSort(int R[], int n);//ϣ������
	static void QuickSort(int R[], int s, int t);//��������
	static void Print(int R[],int length);//��ӡ����
	GetOrdered();
	~GetOrdered();
};

