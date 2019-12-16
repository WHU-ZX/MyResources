#pragma once
struct PCB
{
	const char* name;//进程名称
	PCB* next;//下一个pcb首地址
	int runTime;//要求运行时间
	int priority;//优先级
	char state;//E 结束   R就绪
};
void insert(PCB* H, PCB* p);
PCB* pop(PCB* H);
bool isEmpty(PCB * H);