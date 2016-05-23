// 160. Intersection of Two Linked Lists.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists :
//
//  A:        a1 �� a2
//	                   �K
//	                     c1 �� c2 �� c3
//	                   �J
//	B : b1 �� b2 �� b3
//
//	begin to intersect at node c1.
//
//	Notes :
//
//	If the two linked lists have no intersection at all, return null.
//	The linked lists must retain their original structure after the function returns.
//	You may assume there are no cycles anywhere in the entire linked structure.
//	Your code should preferably run in O(n) time and use only O(1) memory.

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
ʱ�䣺2016��5��17��   11��20��44��
ע�ͣ�Myself   ������������ཻ������ countA=0, countB=0ͳ������������ĳ��ȣ���Ϊ��������н���Ļ�����example����ʾ�����ߵĺ�벿������ͬ�ģ��ɡ�Y�����Σ�����ֻҪ��ȥ���ĵ������кͶ̵���������Ԫ�ظ�����Ȼ����ͬʱ����������������ƶ����򵱶�����ͬʱ���Ƕ��ߵĽ��㡣 
***************************************************/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA==NULL||headB==NULL)
	{
		return NULL;
	}
	ListNode *p=headA, *q=headB;
	int countA=0, countB=0;
	while (p !=NULL)
	{
		countA++;
		p = p->next;
	}
	while (q != NULL)
	{
		countB++;
		q = q->next;
	}
	int distances = countA >= countB ? countA - countB : countB - countA;
	
	while (distances)
	{
		if (countA >= countB)
			headA = headA->next;
		else
		{
			headB = headB->next;
		}
		distances--;
	}
	while (headA != NULL&&headB != NULL)
	{
		if (headA == headB)
		{
			return headA;
		}
		headA = headA->next;
		headB = headB->next;

	}
	return NULL;
}


/****************************************************
ʱ�䣺2016��5��17��   18��39��00��
ע�ͣ�Internet + Myself   �˷����Ľ���˼·���������α���ֵ����¼�ĸ���������������ָ����ƶ����������趨��ȥ�������е�Ԫ�ص�ͷ��㣬Ȼ�����ƶ��Ƚϣ������ʱ����Ҫ���ҵĵ�һ����ͬ�Ľڵ㡣��ʵ������ͬ�ڵ�ķ����Ǻ�����һ���ģ�������Ԫ�زͬ��
***************************************************/
//Internet
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//{
//	ListNode *p1 = headA;
//	ListNode *p2 = headB;
//
//	if (p1 == NULL || p2 == NULL) return NULL;
//
//	while (p1 != NULL && p2 != NULL && p1 != p2)
//	{
//		p1 = p1->next;
//		p2 = p2->next;
//
//		if (p1 == p2) return p1; //���ﵽ������ʱ��ֱ�ӷ���p1����p2
//
//		if (p1 == NULL) p1 = headB; //��p1��p2�ȵ����βʱ�����½����ƶ����ڶ��������ͷ��
//		if (p2 == NULL) p2 = headA; //��p2��p1�ȵ����βʱ�����½����ƶ����ڶ��������ͷ���������Ļ������ߵ�������ľ�������ȵ�
//	}
//
//	return p1;
//}
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	ListNode *pA = headA;
	ListNode *pB = headB;
	while (pA!=NULL&&pB!=NULL&&pA!=pB)
	{
		pA = pA->next;
		pB = pB->next;
		if (pA==pB)
		{
			return pA;//�������Ҳ�ܿ��ưѲ��뽻������������������Ϊ��
		}

		if (pA==NULL)
		{
			pA = headB;
		}
		if (pB==NULL)
		{
			pB = headA;
		}
	}
	return pA;//����ж�������Ϊ�������һ��ͷ��㿪ʼ������ͬ�ڵ�����
}
int main()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals = { 2,3,4,5,6 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	ListNode head2(-1);
	ListNode *q = &head2;
	vector<int> vals2 = { 1,2,3};
	for (int i = 0; i < vals2.size(); i++) {
		q->next = new ListNode(vals2[i]);
		q = q->next;
	}
	ListNode *three=head1.next;
	for (int i=0;i<2;i++)
	{
		three = three->next;
	}
	q->next = three;

	for (auto itr = head1.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	for (auto itr = head2.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	ListNode *tempHeadA = head1.next,*tempHeadB = head2.next;
	auto getIntersectionNoderes = getIntersectionNode2(tempHeadA, tempHeadB);
	cout << getIntersectionNoderes->val << endl;

	system("pause");
    return 0;
}

