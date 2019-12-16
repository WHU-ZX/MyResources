#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct PCB
{
	vector<int> bit_num;//位号
	int length;
	friend bool operator < (const struct PCB& p1, const struct PCB& p2);
};
inline bool operator < (const struct PCB& p1, const struct PCB& p2) {
	return p1.length < p2.length;
}
int free_bit_num = 64;
bool bit_map[8][8];
map<string, PCB> map_PCB;
void showBitMap();
int getFree();
void init();
void showPCB();
void free(string p_name);
int main() {
	init();
	char c = '\0';
	while (c != 'q') {
		cout << "输入q退出，输入a分配进程，输入r释放进程，输入p查看运行进程情况，输入s查看位示图状况" << endl;
		cin >> c;
		if (c == 'a') {
			cout << "请输入进程名：" << endl;
			string name;
			cin >> name;
			cout << "请输入进程长度：(单位：位)" << endl;
			int plength;
			cin >> plength;
			if (plength > free_bit_num) {
				cout << "剩余空间只有" << free_bit_num << "bit,不足以分配！" << endl;
			}
			else if (map_PCB.count(name) == 1) {//已存在该进程
				cout << "进程已存在！" << endl;
			}
			else {
				PCB p;
				p.length = plength;
				for (int i = 0; i < plength; i++) {
					int k = getFree();
					int cylinder_num = k / 8;//柱面号
					int track_num = k / 4;//磁道号
					int sector_num = k % 4;//扇区号
					p.bit_num.push_back(k);
					free_bit_num--;
					bit_map[k / 8][k % 8] = false;
					cout << "分配 --- 柱面号：" << cylinder_num << '\t' << "磁道号："
						<< track_num << '\t' << "扇区号：" << sector_num << endl;
				}
				map_PCB[name] = p;
			}
		}
		else if (c == 'r') {
			cout << "请输入要释放的进程名：" << endl;
			string p_name;
			cin >> p_name;
			free(p_name);
		}
		else if (c == 'p') {
			showPCB();
		}
		else if (c == 's') {
			showBitMap();
		}
	}
	
}
void init() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			bit_map[i][j] = true;
		}
	}
}
int getFree() {//返回一个空闲的位数  若无空闲，返回-1
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (bit_map[i][j]) {
				return i * 8 + j;
			}
		}
	}
	return -1;
}
void showBitMap() {
	for (int i = 0; i < 19; i++) {//第一排---------
		cout << '-';
	}
	cout << endl;
	cout << "| |";//第二排前面
	for (int i = 0; i < 8; i++) {//第二排后面
		cout << i << '|';
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 19; j++) {//上方
			cout << '-';
		}
		cout << endl;
		cout << '|' << i << '|';
		for (int j = 0; j < 8; j++) {
			if (bit_map[i][j]) {
				cout << 0;
			}
			else {
				cout << 1;
			}
			cout << '|';
		}
		cout << endl;
	}
	for (int i = 0; i < 19; i++) {//下方
		cout << '-';
	}
	cout << endl;
}
void showPCB() {
	map<string, PCB>::iterator iter;
	iter = map_PCB.begin();
	while (iter != map_PCB.end()) {
		cout << "进程名：" << iter->first << '\t' << "大小：" << iter->second.length << "bit" << endl;
		iter++;
	}
}
void free(string p_name) {
	if (map_PCB.count(p_name) == 0) {//不存在
		cout << "不存在该进程！" << endl;
	}
	else if (map_PCB.count(p_name) == 1) {
		PCB free_pcb = map_PCB[p_name];
		map_PCB.erase(p_name);
		for (int i = 0; i < free_pcb.bit_num.size(); i++) {
			int bit = free_pcb.bit_num[i];
			int byte = bit / 8;
			cout << "回收 --- 字节号：" << byte << '\t' << "位数:" << bit << endl;
			bit_map[bit / 8][bit % 8] = true;
			free_bit_num++;
		}
	}
}