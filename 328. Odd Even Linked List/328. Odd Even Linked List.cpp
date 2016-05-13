// 328. Odd Even Linked List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a singly linked list, group all odd(����) nodes together followed by the even��ż���� nodes.Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:������������ż��λ�õĽڵ���ǰ�棬�����ں���
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note :
//	The relative order inside both the even and odd groups should remain as it was in the input.
//	The first node is considered odd, the second node even and so on ...
//��Ŀ����:
//����һ������������ڵ���з��飬ʹ�����е������ڵ�������ǰ��ż���ڵ��ں���ע���������żָ���ǽڵ���Ŷ����ǽڵ��ֵ��
//��Ӧ�����ԡ��͵ء���ɴ����⡣����Ӧ������O(1)�Ŀռ临�ӶȺ�O(nodes)��ʱ�临�Ӷȡ�
//������������Ŀ������
//ע�⣺
//ż���������ڵ�����ڲ������˳��Ӧ�������뱣��һ�¡�
//��һ���ڵ�Ϊ�����ڵ㣬�ڶ����ڵ�Ϊż���ڵ㣬�Դ����ơ�

#include "stdafx.h"
#include <vector>

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}

};

/****************************************************************************************************************
���ߣ�������
ʱ�䣺2016��5��11��   10��14��19��
ע�ͣ�Myself   ���ύʱ�� 	Status: Runtime Error   ����
****************************************************************************************************************/
//������ǰ��ż���ں�
ListNode* oddEvenList(ListNode* head) {
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *evenHead,*p, *oddHead,*q;
	evenHead = head;
	p = head->next;
	oddHead = p->next;
	q = oddHead;
	ListNode *evenLast=NULL;
	int count = 0;
	while (q!=NULL)
	{
		count++;
		p->next = q->next;
		if (count%2==1)
		{
			evenLast = p;
		}
		p = q;
		if (q->next == NULL&&count % 2 == 0)
		{
			evenLast = q;
			q = q->next;
		}
		else
			q = q->next;	
	}
	evenLast->next = oddHead;
	return evenHead;

}

//ż����ǰ�������ں�    ���ύ��ȷ����һ���Լ���������Ϊû�ж������⡣�����Լ��ķ������ڿ������һ���ڵ�ָ�루evenLast�����鷳����ѧϰInternet  Method
ListNode* oddEvenList3(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode  *p, *oddHead, *q;
	//evenHead = head;
	p = head;
	q = p->next;
	oddHead = q;
	ListNode *evenLast = NULL;
	int count = 0;
	while (q != NULL)
	{
		count++;
		p->next = q->next;
		if (count % 2 == 1)
		{
			evenLast = p;
		}
		p = q;
		if (q->next == NULL&&count % 2 == 0)
		{
			evenLast = q;
			q = q->next;
		}
		else
			q = q->next;
	}
	evenLast->next = oddHead;
	return head;

}

//Internet
//public ListNode oddEvenList(ListNode head) {
//	if (head == null || head.next == null)
//		return head;
//	ListNode odd = head;
//	ListNode even = head.next;
//	ListNode evenhead = head.next;
//	while (even != null&&even.next != null) {   //����Ϊʲô������ж�����
//		odd.next = even.next;
//		odd = odd.next;
//		even.next = odd.next;
//		even = even.next;
//	}
//	odd.next = evenhead;
//	return head;
//}
//�˷����Ľڵ�Ľ�������ܺ�    ż����ǰ�������ں� 
ListNode *oddEvenList2(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *odd = head;
	ListNode *even = head->next;
	ListNode *evenhead = head->next;
	while (even != NULL&&even->next != NULL) {  
		//һ�ο��Խ�����������ڵ㣨�������ڵ��ż���ڵ�ͬʱ�������Ե������У�
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenhead;
	return head;
}

//Myself + Internet ʵ������λ�ýڵ���ǰ��ż���ڵ�λ���ں�
ListNode *oddEvenList4(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *p, *q, *evenHead;
	p = head->next;
	q = p->next;
	evenHead = q;
	while (q != NULL&&q->next!=NULL) {
		p->next = q->next;
		p = p->next;
		q->next = p->next;
		q = q->next;
	}
	p->next = evenHead;
	return head;
}


int main()
{
	//��ʼ��һ������
	ListNode head(-1);
	vector<int> vals = { 1,2,3,4,5,6,7};
	ListNode *p = &head;
	for (int i=0;i<vals.size();i++)
	{
		p->next = new ListNode(vals[i]);
		p = p->next;
	}

	for (auto itr = head.next;itr!=NULL;itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;


	ListNode *oddEvenListHead = oddEvenList4(&head);
	for (auto itr = oddEvenListHead->next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;




	system("pause");
    return 0;
}

