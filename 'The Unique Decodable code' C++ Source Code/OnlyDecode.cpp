#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct strings
{
	char *string;
	struct strings *next;
};
struct strings  Fstr, *Fh, *FP;
//输出当前集合
void outputstr(strings *str)
{
	do
	{
		cout << str->string << endl;
		str = str->next;
	} while (str);
	cout << endl;
}
inline int MIN(int a, int b)
{
	return a>b ? b : a;
}
inline int MAX(int a, int b)
{
	return a>b ? a : b;
}
#define length_a (strlen(CP))
#define length_b (strlen(tempPtr))
//判断一个码是否在一个码集合中，在则返回0，不在返回1
int comparing(strings *st_string, char *code)
{
	while (st_string->next)
	{
		st_string = st_string->next;
		if (!strcmp(st_string->string, code))
			return 0;
	}
	return 1;
}
//判断两个码字是否一个是另一个的前缀，如果是则生成后缀码
void houzhui(char *CP, char *tempPtr)
{
	if (!strcmp(CP, tempPtr))
	{
		cout << "!-----集合C和集合F中有相同码字:---!" << endl;
		cout << CP << endl << endl;
		cout << "!-----不是唯一可译码码组-------!" << endl << endl;
		getchar();
		getchar();
		exit(1);
	}
	if (!strncmp(CP, tempPtr, MIN(length_a, length_b)))
	{
		struct strings *cp_temp;
		cp_temp = new (struct strings);
		cp_temp->next = NULL;
		cp_temp->string = new char[abs(long(length_a - length_b)) + 1];
		char *longstr;
		longstr = (length_a>length_b ? CP : tempPtr);//将长度长的码赋给longstr
													 //取出后缀
		for (int k = MIN(length_a, length_b); k<MAX(length_a, length_b); k++)
			cp_temp->string[k - MIN(length_a, length_b)] = longstr[k];
		cp_temp->string[abs(long(length_a - length_b))] = NULL;
		//判断新生成的后缀码是否已在集合F里，不在则加入F集合
		if (comparing(Fh, cp_temp->string))
		{
			FP->next = cp_temp;
			FP = FP->next;
		}
	}
}
void main()
{
	//功能提示和程序初始化准备
	cout << "!------唯一可译码的判决实验-------!" << endl << endl;
	cout << "!-------姓名：高宇达--------!" << endl << endl;
	cout << "!-------学号：14070110007---!" << endl << endl;
	struct strings  Cstr, *Ch, *CP, *tempPtr;
	Ch = &Cstr;
	CP = Ch;
	Fh = &Fstr;
	FP = Fh;
	char c[] = "集合C :";
	Ch->string = new char[strlen(c)];
	strcpy(Ch->string, c);
	Ch->next = NULL;
	char f[] = "集合F :";
	Fh->string = new char[strlen(f)];
	strcpy(Fh->string, f);
	Fh->next = NULL;
	//输入待检测码的个数
	int Cnum;
	cout << "!----输入待检测码的个数:------!"<< endl;
	cin >> Cnum;
	cout << "!-----输入待检测码-----!" << endl;
	for (int i = 0; i<Cnum; i++)
	{
		cout << i + 1 << "：";
		char tempstr[10];
		cin >> tempstr;
		CP->next = new (struct strings);
		CP = CP->next;
		CP->string = new char[strlen(tempstr)];
		strcpy(CP->string, tempstr);
		CP->next = NULL;
	}
	outputstr(Ch);
	CP = Ch;
	while (CP->next->next)
	{
		CP = CP->next;
		tempPtr = CP;
		do
		{
			tempPtr = tempPtr->next;
			houzhui(CP->string, tempPtr->string);
		} while (tempPtr->next);
	}
	outputstr(Fh);
	struct strings *Fbegin, *Fend;
	Fend = Fh;
	while (1)
	{
		if (Fend == FP)
		{
			cout << "!-----是唯一可译码码组------!" << endl;
			getchar();
			getchar();
			exit(1);
		}
		Fbegin = Fend;
		Fend = FP;
		CP = Ch;
		while (CP->next)
		{
			CP = CP->next;
			tempPtr = Fbegin;
			for (;;)
			{
				tempPtr = tempPtr->next;
				houzhui(CP->string, tempPtr->string);
				if (tempPtr == Fend)
					break;
			}
		}
		outputstr(Fh);//输出F集合中全部元素
	}
}
