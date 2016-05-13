// 237. Delete Node in a Linked List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
//���������е�һ���ڵ㣬ɾ���ýڵ㡣
//
//��������������нڵ��ɾ������Ҫ֪����ɾ���ڵ��ǰһ���ڵ�ģ�����ǰһ���ڵ��nextָ��ָ��������һ���ڵ㣬����ڵ�ʹ�������ɾ���ˡ���������û���ṩǰһ���ڵ㣬�����ṩ�˵�ǰ�ڵ㡣
//
//һ�����ɾ�����������һ���ڵ��ֵ���ǵ�ǰ�ڵ��ֵ��Ȼ����һ���ڵ�ɾ�����������͵�Чɾ���˵�ǰ�ڵ㡣������Ҫע�����ַ�������ɾ��β�ڵ㣨��Ŀ��Ҳ�����������������


#include "stdafx.h"
#include <string>

#include <iostream>
using namespace std;



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

//myself��Ϊ�β��������ͷ��㣬ʵ����Ŀ��Ҫ���β���Ҫɾ���Ľڵ㣬������
void deleteNode(ListNode* node) {

	ListNode *p = node, *q;
	while (p->next!=NULL)
	{
		q = p->next;
		if (q->val==3)
		{
			p->next = q->next;
			delete(q);
		}
		else
		{
			p = p->next;
		}
	}
	
}



/****************************************************************************************************************
���ߣ�������
ʱ�䣺2016��5��10��   15��10��09��
ע�ͣ��������˼�Ǹ���һ���ڵ㣬ɾ�����ڵ㣬����ɾ�������еĽڵ���Ҫ֪����ǰһ���ڵ��ָ�룬��������û����ã�ֻ��	�ø��ƺ�һ��ֵ������ǰ�ڵ㣬ɾ������Ľڵ㣬ǰ���ǲ���ɾ�����һ���ڵ㡣
****************************************************************************************************************/
void deleteNode2(ListNode* node) {
	if (node == NULL)
		return;
	if (node->next == NULL)//����ɾ�����һ���ڵ�
		return;
	node->val = node->next->val;
	ListNode *temp = node->next;
	node->next = node->next->next;
	delete(temp);
}




int main()
{
	ListNode head(-1);
	ListNode *p1;
	p1 = &head;
	cout << "List ��ʼ����" << endl;
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		p1->next = new ListNode(temp);
		p1 = p1->next;
	}
	p1->next = NULL;
	cout << "*********************************************" << endl;
	for (auto itr = head.next;itr!=NULL;itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	//ɾ��ָ���ڵ�
	ListNode *three = NULL;
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		if (itr->val == 1)
			three = itr;
	}
	deleteNode2(three);
	cout << "ɾ��ָ���ڵ��"<<endl;
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;



	//ɾ��һ���ڵ�
	ListNode *p = &head,*q;
	while (p->next!=NULL)
	{
		if (p->next->val==2)
		{
			q = p->next;
			p->next = q->next;
			delete(q);
		}
		else
		{
			p = p->next;
		}
		
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

