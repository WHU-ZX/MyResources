#include <iostream>
#include "functions.h"
#include <string>
using namespace std;
int main() {
	PCB * head = new PCB();
	head->name = "head";
	head->next = NULL;
	for (int i = 0; i < 5; i++) {
		PCB * p = new PCB();
		cout << "�������" << i + 1 << "�����̵�����ʱ��(����)" << endl;
		cin >> p->runTime;
		cout << "�������" << i + 1 << "�����̵����ȼ�(����)" << endl;
		cin >> p->priority;
		switch (i)
		{
		case 0:
			p->name = "P1";
			break;
		case 1:
			p->name = "P2";
			break;
		case 2:
			p->name = "P3";
			break;
		case 3:
			p->name = "P4";
			break;
		case 4:
			p->name = "P5";
			break;
		default:
			p->name = "ERROR";
			break;
		}
		p->state = 'R';
		insert(head, p);
	}
	while (!isEmpty(head)) {
		PCB * runningPCB = pop(head);
		cout << runningPCB->name << " is running..." << endl;
		runningPCB->priority--;
		runningPCB->runTime--;
		if (runningPCB->runTime == 0) {
			runningPCB->state = 'E';
			delete runningPCB;
		}
		else {
			insert(head, runningPCB);
		}
	}
	delete head;
	system("pause");
	return 0;
}
PCB* pop(PCB* H) {
	if (H->next != NULL) {
		PCB * ret = H->next;
		H->next = H->next->next;
		return ret;
	}
	else {
		return NULL;
	}
}
void insert(PCB* H,PCB* p) {//��p��������H�У������Ӵ�С��˳���Ŷ�
	PCB * pb = H;
	PCB * t = H->next;
	while (t != NULL)
	{
		if (t->priority > p->priority) {
			pb = pb->next;
			t = t->next;
		}
		else {// ���ʱp��ǰ��
			break;
		}
	}
	p->next = t;
	pb->next = p;
}
bool isEmpty(PCB * H) {
	return H->next == NULL;
}