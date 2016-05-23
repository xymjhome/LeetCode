// 19. Remove Nth Node From End of List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note :
//	Given n will always be valid.
//	Try to do this in one pass.
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

/****************************************************
ʱ�䣺2016��5��17��   19��28��09��
ע�ͣ�Myself    ��Ҫ˼·������һ��ָ��pre���ո����ĵ�����n����������ƶ�����n==0ʱ��lastָ�뿪ʼ��ͷ��㿪ʼ����ƶ�����preΪ��ʱ����lastָ��ָ�������ɾ��Ԫ�ص�ǰһ��Ԫ�أ�Ȼ������lastɾ��Ԫ�أ���������ͷ��㡣�����ر�ע��n��ָ��Ԫ�ظոպ�������ĵ�һ��Ԫ�ص�ʱ��
***************************************************/
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL) return NULL;
	ListNode *pre =  head, *last = head;
	while (pre !=NULL)
	{
		while (n)
		{
			pre = pre->next;
			n--;
		}
		if (!pre)//ע����ж���������Ϊn˵ָ���Ԫ�ظɺ��������һ��Ԫ�ص�ʱ�򣬰�������ķ����ͻ������ΪnΪ��һ��Ԫ�أ���pre�պ��ƶ�������β���ָ�봦��pre = pre->next;�ͻ��������Ҫ���������������ǡ�
		{
			return head->next;
		}
		pre = pre->next;
		if (pre!=NULL)
		{
			last = last->next;
		}
	}
	ListNode *tempNPoint = last->next;
	last->next = tempNPoint->next;
	tempNPoint->next = NULL;
	delete(tempNPoint);
	return head;
}

int main()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals = { 1,2 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head1.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto removeNthFromEndres = removeNthFromEnd(head1.next,2);
	for (auto itr = removeNthFromEndres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

