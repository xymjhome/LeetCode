// 141. Linked List Cycle.cpp : 定义控制台应用程序的入口点。
//
////Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?



#include "stdafx.h"
#include <vector>

#include <iostream>
using namespace std;

struct  ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//Myself      Submission Result: Runtime Error  原因：1、没有判断链表为空的情况。   2、忽略了当出现pre->next->next时可能pre!=NULL的情况。
bool hasCycle(ListNode *head) {
	ListNode *pre = head, *last = head;
	int i = 0;
	while (pre!=NULL&&pre->next!=NULL)
	{
		i++;
		pre = pre->next->next;
		if (last == pre)
		{
			cout << "循环次数：" << i << endl;
			return true;
		}
		last = last->next;
		
	}
	cout << "循环次数：" << i << endl;
	return false;
}
int main()
{
	//初始化一个不带头结点的链表
	vector<int> vals = { 1,2,3,4,5,6,7 };
	ListNode *p = NULL,*b=NULL;
	p = new ListNode(vals[0]);
	b = p;
	for (int i=1 ; i<vals.size();i++)
	{
		b->next = new ListNode(vals[i]);
		b = b->next;
	}
	b->next = p;
	/*for (auto itr = p;itr !=NULL;itr=itr->next)
	{
		cout << itr->val << " ";
	}*/
	cout << endl;

	auto res = hasCycle(p);
	cout <<"Result:"<< res << endl;
	system("pause");
    return 0;
}

