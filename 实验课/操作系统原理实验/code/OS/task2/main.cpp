#include <iostream>
//#include "functions.h"
#include <string>
using namespace std;
struct FreeZone
{
	int num;//��������
	int startAddress;//�׵�ַ
	int length;//����
	FreeZone * next;//ָ����һ����������ָ��
};
struct PCB
{
	int startAddress;//�׵�ַ
	string name;//������
	int length;//����
	PCB * next;//ָ����һ�����̵�ָ��
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
		cout << "����q�˳�������a������̣�����r���ս��̣�����s�鿴�ڴ�״��" << endl;
		cin >> c;		
		int length = 0;
		if (c == 'q') {
			break;
		}
		else if (c == 'a') {
			//string aname;
			
			cout << "������Ҫ����Ľ�������(������ʮ���ַ�)" << endl;
			//cin >> aname;
			//const char * aaname = aname.data();
			//const char * name = "";
			//scanf_s(name);
			string name;
			cin >> name;
			cout << "������Ҫ����Ľ��̳���" << endl;
			cin >> length;
			allocate(fHeader, pHeader, length, name);
		}
		else if (c == 'r') {
			// name;
			cout << "������Ҫ���յĽ�������(������ʮ���ַ�)" << endl;
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
			cout << "��������Ч�ַ�" << endl;
		}
	}
}
void showState(FreeZone * fHead, PCB * pHead) {
	cout << "��ǰ�ڴ�״����" << endl;
	cout << "**********************************************" << endl;
	cout << "�׵�ַ" << '\t' << "��С" << '\t' << "״̬" << '\t' << "��������/������" << endl;
	while (fHead->next != NULL && pHead->next != NULL) {
		if (fHead->next->startAddress < pHead->next->startAddress) {//��������ǰ
			fHead = fHead->next;
			cout << fHead->startAddress << '\t' << fHead->length << '\t' << "����" << '\t' << fHead->num << endl;
		}
		else {
			pHead = pHead->next;
			cout << pHead->startAddress << '\t' << pHead->length << '\t' << "�ѷ���" << '\t' << pHead->name << endl;
		}
	}
	if (fHead->next != NULL) {
		fHead = fHead->next;
		cout << fHead->startAddress << '\t' << fHead->length << '\t' << "����" << '\t' << fHead->num << endl;
	}
	if (pHead->next != NULL) {
		pHead = pHead->next;
		cout << pHead->startAddress << '\t' << pHead->length << '\t' << "�ѷ���" << '\t' << pHead->name << endl;
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
PCB * getPCB(PCB * pHead, string name) {//���������ҵ�����,���У���ɾ�������ظý���
	PCB *tp = pHead->next, *tbp = pHead;
	while (tp != NULL) {
		if ( tp->name == name) {//���
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
bool nameRepeated(PCB * pHead, string name) {//�ж������Ƿ��ظ�  true �ظ�  false ���ظ�
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
		cout << "�Ѵ��ڵĽ�����������ʧ��" << endl;
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
			cout << "����ʧ�ܣ��ڴ��������С����" << endl;
		}
	}
	else
	{
		cout << "����ʧ�ܣ��ڴ��޿�����" << endl;
		showState(fHead, pHead);
	}
}
void takeBack(FreeZone * fHead, PCB * pHead, string name) {
	PCB * p = getPCB(pHead, name);
	if (p == NULL) {
		cout << "���ճ�����������Ϊ\"" << name << "\"�Ľ���" << endl;
	}
	else {
		FreeZone * preOfPreF = searchPreOfPreZone(fHead, p);
		FreeZone * preOfNextF = searchPreOfNextZone(fHead, p);
		if (preOfPreF == NULL && preOfNextF == NULL) {//ǰ�󶼲�������
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
		else if (preOfPreF != NULL && preOfNextF != NULL) {//ǰ��Ҫ����
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
		else if (preOfPreF != NULL && preOfNextF == NULL) {//ֻ��ǰ������
			FreeZone * pre = preOfPreF->next;
			pre->length += p->length;
		}
		else {//ֻ�ͺ�������
			FreeZone * next = preOfNextF->next;
			next->startAddress = p->startAddress;
			next->length += p->length;
		}
		delete p;
	}
}