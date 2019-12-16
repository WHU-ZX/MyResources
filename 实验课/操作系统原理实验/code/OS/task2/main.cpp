#include <iostream>
//#include "functions.h"
#include <string>
using namespace std;
struct FreeZone
{
	int num;//空闲区号
	int startAddress;//首地址
	int length;//长度
	FreeZone * next;//指向下一个空闲区的指针
};
struct PCB
{
	int startAddress;//首地址
	string name;//进程名
	int length;//长度
	PCB * next;//指向下一个进程的指针
};
void showState(FreeZone * fHead, PCB * pHead);
FreeZone * searchPreOfPreZone(FreeZone * fHead, PCB * p);
FreeZone * searchPreOfNextZone(FreeZone * fHead, PCB * p);
PCB * getPCB(PCB * pHead, string name);
void insertPCB(PCB * pHead, PCB * p);
bool nameRepeated(PCB * pHead, string name);
void allocate(FreeZone * fHead, PCB * pHead, int length, string name);
void takeBack(FreeZone * fHead, PCB * pHead, string name);

int main() {
	FreeZone * fHeader = new FreeZone();
	PCB * pHeader = new PCB();
	pHeader->next = NULL;
	fHeader->next = new FreeZone();
	fHeader->next->next = NULL;
	fHeader->next->num = 1;
	fHeader->next->length = 128;
	fHeader->next->startAddress = 0;
	char c = '\0';
	while (c != 'q') {
		cout << "输入q退出，输入a分配进程，输入r回收进程，输入s查看内存状况" << endl;
		cin >> c;		
		int length = 0;
		if (c == 'q') {
			break;
		}
		else if (c == 'a') {
			//string aname;
			
			cout << "请输入要申请的进程名字(不超过十个字符)" << endl;
			//cin >> aname;
			//const char * aaname = aname.data();
			//const char * name = "";
			//scanf_s(name);
			string name;
			cin >> name;
			cout << "请输入要申请的进程长度" << endl;
			cin >> length;
			allocate(fHeader, pHeader, length, name);
		}
		else if (c == 'r') {
			// name;
			cout << "请输入要回收的进程名字(不超过十个字符)" << endl;
			//cin >> name;
			//const char * rname = name.data();
			string name;
			cin >> name;
			//const char * name = "";
			//scanf_s(name);
			takeBack(fHeader, pHeader, name);			
		}
		else if (c == 's') {
			showState(fHeader, pHeader);
		}
		else {
			cout << "请输入有效字符" << endl;
		}
	}
}
void showState(FreeZone * fHead, PCB * pHead) {
	cout << "当前内存状况：" << endl;
	cout << "**********************************************" << endl;
	cout << "首地址" << '\t' << "大小" << '\t' << "状态" << '\t' << "空闲区号/进程名" << endl;
	while (fHead->next != NULL && pHead->next != NULL) {
		if (fHead->next->startAddress < pHead->next->startAddress) {//空闲区在前
			fHead = fHead->next;
			cout << fHead->startAddress << '\t' << fHead->length << '\t' << "空闲" << '\t' << fHead->num << endl;
		}
		else {
			pHead = pHead->next;
			cout << pHead->startAddress << '\t' << pHead->length << '\t' << "已分配" << '\t' << pHead->name << endl;
		}
	}
	if (fHead->next != NULL) {
		fHead = fHead->next;
		cout << fHead->startAddress << '\t' << fHead->length << '\t' << "空闲" << '\t' << fHead->num << endl;
	}
	if (pHead->next != NULL) {
		pHead = pHead->next;
		cout << pHead->startAddress << '\t' << pHead->length << '\t' << "已分配" << '\t' << pHead->name << endl;
	}
	cout << "**********************************************" << endl;
}
FreeZone * searchPreOfPreZone(FreeZone * fHead, PCB * p) {
	FreeZone * tF = fHead->next;
	FreeZone * tPF = fHead;
	while (tF != NULL) {
		if (tF->startAddress + tF->length == p->startAddress) {
			break;
		}
		else {
			tF = tF->next;
			tPF = tPF->next;
		}
	}
	if (tF == NULL) {
		return NULL;
	}
	else {
		return tPF;
	}
}
FreeZone * searchPreOfNextZone(FreeZone * fHead, PCB * p) {
	FreeZone * tF = fHead->next;
	FreeZone * tPF = fHead;
	while (tF != NULL) {
		if (tF->startAddress == p->startAddress + p->length) {
			break;
		}
		else {
			tF = tF->next;
			tPF = tPF->next;
		}
	}
	if (tF == NULL) {
		return NULL;
	}
	else {
		return tPF;
	}
}
PCB * getPCB(PCB * pHead, string name) {//根据名字找到进程,若有，则删除并返回该进程
	PCB *tp = pHead->next, *tbp = pHead;
	while (tp != NULL) {
		if ( tp->name == name) {//相等
			break;
		}
		else {
			tp = tp->next;
			tbp = tbp->next;
		}
	}
	if (tp != NULL) {
		tbp->next = tp->next;
	}
	return tp;
}

void insertPCB(PCB * pHead, PCB * p) {
	PCB * pb = pHead;
	PCB * t = pHead->next;
	while (t != NULL)
	{
		if (t->startAddress < p->startAddress) {
			pb = pb->next;
			t = t->next;
		}
		else {
			break;
		}
	}
	p->next = t;
	pb->next = p;
}
bool nameRepeated(PCB * pHead, string name) {//判断名字是否重复  true 重复  false 不重复
	PCB *tp = pHead->next;
	while (tp != NULL) {
		if (tp->name == name) {
			return true;
		}
		tp = tp->next;
	}
	return false;
}
void allocate(FreeZone * fHead, PCB * pHead, int length, string name) {
	if (nameRepeated(pHead, name)) {
		cout << "已存在的进程名，申请失败" << endl;
		return;
	}
	if (fHead->next != NULL) {
		FreeZone * tF = fHead->next, *tBF = fHead;
		while (tF != NULL) {
			if (tF->length < length) {
				tF = tF->next;
				tBF = tBF->next;
			}
			else if (tF->length == length) {
				PCB * tPCB = new PCB();
				tPCB->length = length;
				tPCB->name = name;
				tPCB->startAddress = tF->startAddress;
				tPCB->next = NULL;
				insertPCB(pHead, tPCB);
				tBF->next = tF->next;
				tBF = tF->next;
				delete tF;
				while (tBF != NULL) {
					tBF->num--;
					tBF = tBF->next;
				}
				break;
			}
			else {
				PCB * tPCB = new PCB();
				tPCB->length = length;
				tPCB->name = name;
				tPCB->startAddress = tF->startAddress;
				tPCB->next = NULL;
				insertPCB(pHead, tPCB);
				tF->length -= length;
				tF->startAddress += length;
				break;
			}
		}
		if (tF == NULL) {
			cout << "分配失败，内存空闲区大小不足" << endl;
		}
	}
	else
	{
		cout << "分配失败，内存无空闲区" << endl;
		showState(fHead, pHead);
	}
}
void takeBack(FreeZone * fHead, PCB * pHead, string name) {
	PCB * p = getPCB(pHead, name);
	if (p == NULL) {
		cout << "回收出错，不存在名为\"" << name << "\"的进程" << endl;
	}
	else {
		FreeZone * preOfPreF = searchPreOfPreZone(fHead, p);
		FreeZone * preOfNextF = searchPreOfNextZone(fHead, p);
		if (preOfPreF == NULL && preOfNextF == NULL) {//前后都不可连接
			FreeZone * f = new FreeZone();
			f->length = p->length;
			f->startAddress = p->startAddress;
			f->next = NULL;
			f->num = 1;
			FreeZone * tF = fHead;
			while (tF->next != NULL && tF->next->startAddress < f->startAddress) {
				tF = tF->next;
				f->num++;
			}
			f->next = tF->next;
			tF->next = f;
			if (tF == fHead) {
				f->num = 1;
			}
			f = f->next;
			while (f != NULL) {
				f->num++;
				f = f->next;
			}
		}
		else if (preOfPreF != NULL && preOfNextF != NULL) {//前后都要连接
			FreeZone * pre = preOfPreF->next;
			FreeZone * minusPoint = preOfNextF->next->next;
			FreeZone * delP = preOfNextF->next;
			pre->length += p->length + preOfNextF->next->length;
			pre->next = minusPoint;
			while (minusPoint != NULL) {
				minusPoint->num--;
				minusPoint = minusPoint->next;
			}
			delete delP;
		}
		else if (preOfPreF != NULL && preOfNextF == NULL) {//只和前面连接
			FreeZone * pre = preOfPreF->next;
			pre->length += p->length;
		}
		else {//只和后面连接
			FreeZone * next = preOfNextF->next;
			next->startAddress = p->startAddress;
			next->length += p->length;
		}
		delete p;
	}
}