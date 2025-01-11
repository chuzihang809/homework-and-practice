#include<iostream>
using namespace std;
class opera
{
	char name[30];//歌剧名称
	int ts[4];	// ts[0]：包厢的总数，ts[1]：一等座的总座位数
	//ts[2]：二等座的总座位数，ts[3]：三等座的总座位数
	int es[4];// es[0]：空包厢的数量，es[1]：一等座的空闲座位数
	//es[2]：二等座的空闲座位数，es[3]：三等座的空闲座位数
	int ps[4];// ps[0]：包厢的票价，ps[1]：一等座的票价
	//ps[2]：二等座的票价，，ps[3]：三等座的票价
	int income;//总收入

public:
	opera(); //默认构造函数，数据成员的初始值请参看输出样例
	void set_name(const char*);//更改剧名
	void set_ps(int[]);//更改座位价格
	void booking(int, int);//售票，如果余票小于订票数，
	//终止该次售票，并输出购票失败提示信息
	void refund(int, int);//退票，不收手续费
	void print();
	~opera(); //析构函数，完成票房统计，内容与格式请参看输出样例
};

opera::opera()
{
	int s[] = { 20,100,240,300 };
	for (int i = 0; i < 4; i++)
	{
		ts[i] = s[i];
		es[i] = s[i];
		ps[i] = 0;

	}
	strcpy_s(name, "未命名");
	income = 0;
}

void opera::set_name(const char* namein)
{
	strcpy_s(name, namein);
}

void opera::set_ps(int input[])
{
	for (int i = 0; i < 4; i++)
	{
		ps[i] = input[i];
	}
}

void opera::booking(int i, int time)
{
	int yupiao;
	yupiao = es[i];
	es[i] -= time;
	if (es[i] < 0)
	{
		cout << "余票" << '(' << yupiao << ')' << "不足，购买失败" << endl;
		es[i] = yupiao;
	}
	else
	{
		income += time * ps[i];
	}
}

void opera::refund(int i, int time)
{
	es[i] += time;
	income -= ps[i] * time;
}

void opera::print()
{
	const char line[20] = "------------------";
	cout << line << "戏曲名：" << name << line << endl;
	char st[4][20] = { "包厢","一等座","二等座","三等座" };
	for (int i = 0; i < 4; i++)
		cout << st[i] << "<" << "票价：" << ps[i] << 
		" /总数：" << ts[i] << " /可售：" << es[i] << ">" << endl;
	cout << line << "总收入：" << income << line << endl << endl;
}

opera::~opera()
{
	cout << name << "的总收入：" << income << endl;
	cout << "二进宫的票房如下：" << endl;
	cout << "包厢售出" << ts[0] - es[0] << endl;
	cout << "一等座售出" << ts[1] - es[1] << endl;
	cout << "二等座售出" << ts[2] - es[2] << endl;
	cout << "三等座售出" << ts[3] - es[3] << endl;
}

int main()
{
	opera p1;
	p1.print();
	p1.set_name("二进宫"); //void set_name(char *),更改剧名
	int p[] = { 700,380,180,80 };
	p1.set_ps(p);//void set_ps(int []),更改座位价格
	p1.booking(0, 9);//购买9张包厢票
	p1.booking(1, 15);//购买15张一等票
	p1.booking(3, 20);//购买20张三等票
	p1.print();
	p1.booking(0, 13);//购买13张包厢票
	p1.booking(2, 14);//购买14张二等票
	p1.refund(3, 6);//退6张三等票
	p1.print();
	return 0;

}
