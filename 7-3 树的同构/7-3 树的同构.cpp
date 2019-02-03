// 7-3 树的同构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	char ch;
	char left;
	char right;
	Node *lSon;
	Node *rSon;
	bool isVisited;
	Node()
	{
		ch = '0';
		left = 0;
		right = 0;
		lSon = NULL;
		rSon = NULL;
		isVisited = false;
	}
};
vector<Node> Nodes1, Nodes2;
int *sons;
void Visite(Node &N, int number, vector<Node> &Nodes)
{
	if (N.left != '-')
	{
		int j = (int)N.left - 48;
		N.lSon = new Node();
		N.lSon = &Nodes[j];
		if (!Nodes[j].isVisited)
		{
			sons[number] += 1;
			Visite(Nodes[j], number, Nodes);
		}
		else {
			sons[number] = sons[number] + 1 + sons[j];
		}
	}
	if (N.right != '-')
	{
		int k = (int)N.right - 48;
		N.rSon = new Node();
		N.rSon = &Nodes[k];
		if (!Nodes[k].isVisited)
		{
			sons[number] += 1;
			Visite(Nodes[k], number, Nodes);
		}
		else {
			sons[number] = sons[number] + 1 + sons[k];
		}
	}
	N.isVisited = true;
}
bool Cmp(Node *N1, Node *N2)
{
	while (N1 != NULL && N2 != NULL)
	{
		if (N1->ch != N2->ch)
		{
			return false;
		}
		bool flag = false;
		if (!Cmp(N1->lSon, N2->lSon)) {
			if (!Cmp(N1->lSon, N2->rSon))
			{
				return false;
			}
			if (!Cmp(N1->rSon, N2->lSon)) {
				return false;
			}
			return true;
		}
		if (!Cmp(N1->rSon, N2->rSon)) {
			return false;
		}
		return true;
	}
	if (N1 != NULL || N2 != NULL)
	{
		return false;
	}
	return true;
}
int main()
{
	int n1, n2;
	cin >> n1;
	int root1 = 0;
	int root2 = 0;
	int max;
	if (n1 != 0)
	{
		sons = new int[n1] {0};

		for (int i = 0; i < n1; i++)
		{
			Node N;
			cin >> N.ch >> N.left >> N.right;
			sons[i] = 0;
			Nodes1.push_back(N);
		}
		max = 0;
		for (int i = 0; i < n1; i++)
		{
			Visite(Nodes1[i], i, Nodes1);
			if (max < sons[i])
			{
				root1 = i;
				max = sons[i];
			}
		}
	}

	cin >> n2;
	if (n1 != n2)
	{
		cout << "No" << endl;
		return 0;
	}
	if (n1 == 0 && n2 == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 0; i < n2; i++)
	{
		Node N;
		cin >> N.ch >> N.left >> N.right;
		sons[i] = 0;
		Nodes2.push_back(N);
	}
	max = 0;
	for (int i = 0; i < n2; i++)
	{
		Visite(Nodes2[i], i, Nodes2);
		if (max < sons[i])
		{
			root2 = i;
			max = sons[i];
		}
	}

	if (Cmp(&Nodes1[root1], &Nodes2[root2])) {
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
