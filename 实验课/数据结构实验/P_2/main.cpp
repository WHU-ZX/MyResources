#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack* st = new Stack();
	//cout << "please enter a String";
	char * p = NULL;
	char a[]="((((a(a)a)s)sa))sd)";
	p = a;
	while (*p != '\0')
	{
		if (*p == '(')
		{
			bool notFull;
			notFull = st->push('(');
			p++;
			if (!notFull)
			{
				cout << "�ַ���̫�������ʧ��";
				system("pause");
				return 1;
			}
		}
		else if (*p == ')')
		{
			bool notEmpty;
			char c;
			notEmpty = st->pop(c);
			if (!notEmpty)
			{
				cout << "�����ű������Ŷ�";
				system("pause");
				return 0;
			}
			p++;
		}
		else 
		{
			p++;
		}
	}
	if (st->isEmpty())
		cout << "�ַ�����������һ����";
	else
		cout << "�����ű������Ŷ�";
	system("pause");
	return 0;
}