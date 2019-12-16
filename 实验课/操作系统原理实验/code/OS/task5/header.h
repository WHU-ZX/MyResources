#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum State{Running , Runnable ,Waiting ,Finished};//���� ���� �ȴ� ���
enum WaitReason{S1,S2,No};
enum ProInstruction { Produce, Ps1, Put, Vs2, GotoP0 };
enum ConInstruction { Ps2, Get, Vs1, Consume, GotoC0 };
enum Type{Producer,Consumer};
struct PCB
{
	string name;
	State state = Runnable;
	WaitReason reason = No;//����ͨ��reason�ж����������߻���������
	int PC;//�ϵ�
	Type type;
	int product = 0;
}; 
void init();
void doProducer(PCB& p, ProInstruction instruction);
void doConsumer(PCB& p, ConInstruction instruction);
void output();
void erase(string name, vector<PCB>& v);
void P(int& s, PCB& p);
void V(int& s, PCB& p);
void handler();
