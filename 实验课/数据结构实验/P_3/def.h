#pragma once
//#include "MyQue.h"
#define MAX 625
#define M 8
#define N 8
class MyQue;
/*typedef struct {
	int i;
	int j;
	int di;
}Box;
typedef struct {
	Box data[MAX];
	int top;
}StType;*/
bool getBySt(int mg[M+2][N+2],int xi,int yi,int xe,int ye);
bool getByQue(int mg[M + 2][N + 2], int xi,int yi,int xe, int ye);
void print(MyQue* que);
