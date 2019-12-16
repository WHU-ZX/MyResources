#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct PCB
{
	vector<int> bit_num;//λ��
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
		cout << "����q�˳�������a������̣�����r�ͷŽ��̣�����p�鿴���н������������s�鿴λʾͼ״��" << endl;
		cin >> c;
		if (c == 'a') {
			cout << "�������������" << endl;
			string name;
			cin >> name;
			cout << "��������̳��ȣ�(��λ��λ)" << endl;
			int plength;
			cin >> plength;
			if (plength > free_bit_num) {
				cout << "ʣ��ռ�ֻ��" << free_bit_num << "bit,�����Է��䣡" << endl;
			}
			else if (map_PCB.count(name) == 1) {//�Ѵ��ڸý���
				cout << "�����Ѵ��ڣ�" << endl;
			}
			else {
				PCB p;
				p.length = plength;
				for (int i = 0; i < plength; i++) {
					int k = getFree();
					int cylinder_num = k / 8;//�����
					int track_num = k / 4;//�ŵ���
					int sector_num = k % 4;//������
					p.bit_num.push_back(k);
					free_bit_num--;
					bit_map[k / 8][k % 8] = false;
					cout << "���� --- ����ţ�" << cylinder_num << '\t' << "�ŵ��ţ�"
						<< track_num << '\t' << "�����ţ�" << sector_num << endl;
				}
				map_PCB[name] = p;
			}
		}
		else if (c == 'r') {
			cout << "������Ҫ�ͷŵĽ�������" << endl;
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
int getFree() {//����һ�����е�λ��  ���޿��У�����-1
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
	for (int i = 0; i < 19; i++) {//��һ��---------
		cout << '-';
	}
	cout << endl;
	cout << "| |";//�ڶ���ǰ��
	for (int i = 0; i < 8; i++) {//�ڶ��ź���
		cout << i << '|';
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 19; j++) {//�Ϸ�
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
	for (int i = 0; i < 19; i++) {//�·�
		cout << '-';
	}
	cout << endl;
}
void showPCB() {
	map<string, PCB>::iterator iter;
	iter = map_PCB.begin();
	while (iter != map_PCB.end()) {
		cout << "��������" << iter->first << '\t' << "��С��" << iter->second.length << "bit" << endl;
		iter++;
	}
}
void free(string p_name) {
	if (map_PCB.count(p_name) == 0) {//������
		cout << "�����ڸý��̣�" << endl;
	}
	else if (map_PCB.count(p_name) == 1) {
		PCB free_pcb = map_PCB[p_name];
		map_PCB.erase(p_name);
		for (int i = 0; i < free_pcb.bit_num.size(); i++) {
			int bit = free_pcb.bit_num[i];
			int byte = bit / 8;
			cout << "���� --- �ֽںţ�" << byte << '\t' << "λ��:" << bit << endl;
			bit_map[bit / 8][bit % 8] = true;
			free_bit_num++;
		}
	}
}