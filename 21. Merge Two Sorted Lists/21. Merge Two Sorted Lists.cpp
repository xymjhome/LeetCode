// 21. Merge Two Sorted Lists.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
#include "stdafx.h"
#include <vector>

#include <iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}

};


//Myself   �м�;�Ǻϲ�������ͬ�������������ܺϲ�ͬһ������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *p1, *p2,*tempHead,*pc;
	pc =tempHead = l1;
	p1 = l1->next;
	p2 = l2->next;
	while (p1&&p2)
	{
		if (p1->val<=p2->val)
		{
			pc->next = p1;
			pc = pc->next;
			p1 = p1->next;
		}
		else
		{
			pc->next = p2;
			pc = pc->next;
			p2 = p2->next;
		}
	}
	pc->next = p1 ? p1 : p2;
	//delete(l2);
	return tempHead;
	


}

int main()
{
	/****************************************************
	ʱ�䣺2016��5��12��   15��24��34��
	ע�ͣ���ʼ�������������� 
	***************************************************/
	vector<int> vals2 = { 1,5,7,9,11 };
	vector<int> vals1 = { 1,5,7,9,11 };

	ListNode head1(-1);
	ListNode head2(-1);
	ListNode *p1, *p2;
	p1 = &head1;
	p2 = &head2;

	for (int i=0;i<vals1.size();i++)
	{
		p1->next = new ListNode(vals1[i]);
		p1 = p1->next;
	}
	for (int i = 0; i < vals2.size(); i++)
	{
		p2->next = new ListNode(vals2[i]);
		p2 = p2->next;
	}

	auto mergeTwoListsRes = mergeTwoLists(&head1, &head2);
	for (auto itr = mergeTwoListsRes->next;itr!=NULL;itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl

	system("pause");
    return 0;
}

