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
				cout << "×Ö·û´®Ì«³¤£¬¼ì²âÊ§°Ü";
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
				cout << "ÓÒÀ¨ºÅ±È×óÀ¨ºÅ¶à";
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
		cout << "×Ö·û´®×óÓÒÀ¨ºÅÒ»Ñù¶à";
	else
		cout << "×óÀ¨ºÅ±ÈÓÒÀ¨ºÅ¶à";
	system("pause");
	return 0;
}