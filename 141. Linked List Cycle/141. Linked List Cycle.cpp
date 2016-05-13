// 141. Linked List Cycle.cpp : �������̨Ӧ�ó������ڵ㡣
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


//Myself      Submission Result: Runtime Error  ԭ��1��û���ж�����Ϊ�յ������   2�������˵�����pre->next->nextʱ����pre!=NULL�������
bool hasCycle(ListNode *head) {
	ListNode *pre = head, *last = head;
	int i = 0;
	while (pre!=NULL&&pre->next!=NULL)
	{
		i++;
		pre = pre->next->next;
		if (last == pre)
		{
			cout << "ѭ��������" << i << endl;
			return true;
		}
		last = last->next;
		
	}
	cout << "ѭ��������" << i << endl;
	return false;
}
int main()
{
	//��ʼ��һ������ͷ��������
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

