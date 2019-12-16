#include "header.h"
#include <vector>
#include <ctime>
int outputtime = 0;
int s1 = 10;//空闲数
int s2 = 0;//产品数
int in = 0;
int out = 0;
int products[10];
ProInstruction PA[5] = { Produce, Ps1, Put, Vs2, GotoP0 };
ConInstruction SA[5] = { Ps2, Get, Vs1, Consume, GotoC0 };
//PCB* running_PCB = nullptr;//运行

vector<PCB> finished_pool;//完成池			可以不要
vector<PCB> runnable_pool;//就绪池
vector<PCB> producer_waiting_pool;//等待池
vector<PCB> consumer_waiting_pool;
const int stopTime = 100;
void handler() {
	while (outputtime < stopTime) {
		if (runnable_pool.size() == 0) {
			cout << "死锁！" << endl;
		}
		else {
			int index = rand() % runnable_pool.size();
			PCB runningPCB = runnable_pool[index];
			runningPCB.state = Running;
			erase(runningPCB.name, runnable_pool);
			if (runningPCB.type == Producer) {
				ProInstruction instruction = PA[runningPCB.PC];
				doProducer(runningPCB,instruction);
			}
			else if (runningPCB.type == Consumer) {
				ConInstruction instruction = SA[runningPCB.PC];
				doConsumer(runningPCB, instruction);
			}
		}
		output();
	}
}
void init() {
	for (int i = 0; i < 10; i++) {
		products[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		PCB p;
		p.name = "producer" + to_string(i);
		p.PC = 0;
		p.type = Producer;
		runnable_pool.push_back(p);
	}
	for (int i = 0; i < 5; i++) {
		PCB p;
		p.name = "consumer" + to_string(i);
		p.PC = 0;
		p.type = Consumer;
		runnable_pool.push_back(p);
	}
}
void P(int &s, PCB& p) {
	s = s - 1;
	if (s < 0)
	{
		p.state = Waiting;
		if (&s == &s1) {
			p.reason = S1;
		}
		else if (&s == &s2) {
			p.reason = S2;
		}
		if (p.type == Producer) {
			producer_waiting_pool.push_back(p);
		}
		else if (p.type == Consumer) {
			consumer_waiting_pool.push_back(p);
		}
	}
	else {
		p.state = Runnable;
		runnable_pool.push_back(p);
	}
}
void erase(string name,vector<PCB>& v) {
	vector<PCB>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		if ((*it).name.compare(name) == 0) {
			it = v.erase(it);
			return;
		}
	}
}
void V(int &s, PCB& p) {
	s = s + 1;
	if (s <= 0)
	{
		//将等待池中随机挑选一个进程唤醒，加入就绪池
		if (&s == &s1) {//生产者等待s1
			int index = rand() % producer_waiting_pool.size();
			PCB weakP = producer_waiting_pool[index];
			weakP.state = Runnable;
			erase(weakP.name, producer_waiting_pool);
			runnable_pool.push_back(weakP);
		}
		else if (&s == &s2) {//消费者等待s2
			int index = rand() % consumer_waiting_pool.size();
			PCB weakP = consumer_waiting_pool[index];
			weakP.state = Runnable;
			erase(weakP.name, consumer_waiting_pool);
			runnable_pool.push_back(weakP);
		}
	}
	p.state = Runnable;
	runnable_pool.push_back(p);
}
void doProducer(PCB& p, ProInstruction instruction) {
	p.PC = (p.PC + 1) % 5;
	if (instruction == Produce) {
		if (p.product == 0) {
			p.product = rand() % 100 + 1;//1-100
			p.state = Runnable;
			runnable_pool.push_back(p);
			cout << p.name << " has produced." << endl;
		}		
	}
	else if (instruction == Ps1) {
		P(s1, p);
		cout << p.name << " has done P" << endl;
	}
	else if (instruction == Put) {
		if (products[in] == 0 && p.product != 0) {//如果该处无商品并且p生产了商品
			products[in] = p.product;
			p.product = 0;
			in = (in + 1) % 10;
			cout << p.name << " has done Put" << endl;
		}
		p.state = Runnable;
		runnable_pool.push_back(p);
	}
	else if (instruction == Vs2) {
		V(s2, p);
		cout << p.name << " has done V" << endl;
	}
	else if (instruction == GotoP0) {
		p.state = Finished;
		cout << p.name << " has finished" << endl;		
		cout << p.name << " has goto 0" << endl;
		p.state = Runnable;
		runnable_pool.push_back(p);
	}	
}
void doConsumer(PCB& p, ConInstruction instruction) {
	p.PC = (p.PC + 1) % 5;
	if (instruction == Ps2) {
		P(s2, p);
		cout << p.name << " has done P" << endl;
	}
	else if (instruction == Get) {
		if (products[out] != 0 && p.product == 0) {//如果该处有商品
			p.product = products[out];
			products[out] = 0;
			out = (out + 1) % 10;
			cout << p.name << " has Get product " << p.product << endl;
		}
		p.state = Runnable;
		runnable_pool.push_back(p);
	}
	else if (instruction == Vs1) {
		V(s1, p);
		cout << p.name << " has done V" << endl;
	}
	else if (instruction == Consume) {
		if (p.product != 0) {
			p.product = 0;
		}
		cout << p.name << " has Consumed product " << p.product << endl;
		p.state = Runnable;
		runnable_pool.push_back(p);
	}
	else if (instruction == GotoC0) {
		p.state = Finished;
		cout << p.name << " has finished" << endl;
		cout << p.name << " has goto 0" << endl;
		p.state = Runnable;
		runnable_pool.push_back(p);
	}
}
void output() {
	outputtime++;
	cout << outputtime << endl;
	cout << endl;
	cout << "s1 = " << s1 << "\ts2 = " << s2 << endl;
	cout << "products:";
	for (int i = 0; i < 10; i++) {
		cout << products[i] << "  ";
	}
	cout << endl;
	cout << "runnable count:" << runnable_pool.size() << endl;
	cout << "waiting producer count:" << producer_waiting_pool.size() << endl;
	cout << "waiting consumer count:" << consumer_waiting_pool.size() << endl;
	cout << endl << endl;
}
