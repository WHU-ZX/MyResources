#pragma once
struct PCB
{
	const char* name;//��������
	PCB* next;//��һ��pcb�׵�ַ
	int runTime;//Ҫ������ʱ��
	int priority;//���ȼ�
	char state;//E ����   R����
};
void insert(PCB* H, PCB* p);
PCB* pop(PCB* H);
bool isEmpty(PCB * H);