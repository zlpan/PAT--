// 7-2 一元多项式的乘法与加法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Polynomial
{
public:
	int deep = 0;
	int element = 0;
	Polynomial() :deep(0), element(0)
	{

	}
	Polynomial(int d, int e) :deep(d), element(e)
	{

	}
	bool operator < (const Polynomial &a) const {
		return deep > a.deep;
	}
};

vector< Polynomial> Merge(vector< Polynomial> Q);
void print(vector<Polynomial> V);

int main()
{
	int n1, n2;
	std::cin >> n1;
	Polynomial *P1 = new Polynomial[n1];
	vector<Polynomial> R_Multi, R_Plus;
	for (int i = 0; i < n1; i++)
	{
		int e, d;
		std::cin >> e >> d;
		P1[i].deep = d;
		P1[i].element = e;
		R_Plus.push_back(P1[i]);
	}
	std::cin >> n2;
	Polynomial *P2 = new Polynomial[n2];

	for (int i = 0; i < n2; i++)
	{
		int e, d;
		std::cin >> e >> d;
		P2[i].deep = d;
		P2[i].element = e;
		R_Plus.push_back(P2[i]);
		for (int j = 0; j < n1; j++)
		{
			Polynomial T1;
			T1.element = e * P1[j].element;
			T1.deep = d + P1[j].deep;
			R_Multi.push_back(T1);
		}
	}
	sort(R_Multi.begin(), R_Multi.end());
	sort(R_Plus.begin(), R_Plus.end());
	vector<Polynomial> V1 = Merge(R_Multi);
	vector<Polynomial> V2 = Merge(R_Plus);
	print(V1);
	print(V2);
	return  0;
}

void print(vector<Polynomial> V)
{
	if (V.size() == 1)
	{
		if (V[0].element == 0)
			cout << "0 0" << endl;
		else {
			cout << V[0].element << " " << V[0].deep << endl;
		}
		return;
	}
	int count = 0;
	for (int i = 0; i < V.size(); i++)
	{
		if (V[i].element != 0) {
			if (i != V.size() - 1) {
				cout << V[i].element << " " << V[i].deep << " ";
			}
			else
			{
				cout << V[i].element << " " << V[i].deep << endl;
			}
		}
		else {
			count++;
			continue;
		}
	}
	if (count == V.size())
	{
		cout << "0 0" << endl;
	}
}

vector< Polynomial> Merge(vector< Polynomial> Q)
{
	vector< Polynomial> V;
	Polynomial T;
	int count = 0;
	for (int i = 0; i < Q.size(); i++)
	{
		T = Q[i];
		for (int j = i + 1; j < Q.size(); j++)
		{
			if (T.deep == Q[j].deep)
			{
				T.element += Q[j].element;
				i = j;
			}
			else {
				break;
			}
		}
		if (T.element == 0)
		{
			count++;
			continue;
		}
		V.push_back(T);
	}
	if (count == Q.size())
	{
		T.deep = 0;
		T.element = 0;
		V.push_back(T);
	}
	return V;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
