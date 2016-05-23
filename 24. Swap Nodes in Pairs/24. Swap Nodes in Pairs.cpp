// 24. Swap Nodes in Pairs.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.
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
ʱ�䣺2016��5��13��   20��30��18��
ע�ͣ���ת�������ڵĽڵ�
***************************************************/


//Myself �����ύ������ΪLeetCode��û��ͷ���
//���´�����LeetCode����ȷ��
//ListNode* swapPairs(ListNode* head) {
//	ListNode tempHead(-1);
//	tempHead.next = head;
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	ListNode *p, *q, *temp;
//	temp = &tempHead;
//	p = tempHead.next;
//	q = p->next;
//	while (q != NULL&&p != NULL)
//	{
//		p->next = q->next;
//		q->next = p;
//		temp->next = q;
//
//		temp = p;
//		p = p->next;
//		if (p)
//			q = p->next;
//	}
//	return tempHead.next;
//}
ListNode* swapPairs(ListNode* head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *p, *q,*temp;
	temp = head;
	p = head->next;
	q = p->next;
	while (q != NULL&&p!=NULL)
	{
		p->next = q->next;
		q->next = p;
		temp->next = q;

		temp = p;
		p = p->next;
		if(p)
			q = p->next;
	}
	return head;
}


//Internet(��̫���)��������  ��������    û���Զ����head(-1)ͷ���
ListNode* swapPairs2(ListNode* head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;

	ListNode* temp = head->next;
	head->next = swapPairs2(temp->next);
	temp->next = head;

	return temp;
}

int main()
{

	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = {1,2,3,4,5};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next;itr!=NULL;itr = itr->next)
	{
		cout << itr << " ";
	}
	cout << endl;


	/*auto swapPairsRes=swapPairs(&head);
	for (auto itr = swapPairsRes->next; itr != NULL; itr = itr->next)
	{
		cout << itr << " ";
	}
	//cout << endl;
	for (auto itr = swapPairsRes->next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;*/



	ListNode *tempHead = head.next;
	auto swapPairsRes2 = swapPairs2(tempHead);

	for (auto itr = swapPairsRes2; itr != NULL; itr = itr->next)
	{
		cout << itr << " ";
	}
	cout << endl;
	for (auto itr = swapPairsRes2; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	system("pause");
    return 0;
}

