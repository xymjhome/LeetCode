// 83. Remove Duplicates from Sorted List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;


/****************************************************
ʱ�䣺2016��5��11��   15��54��50��
ע�ͣ��������ṹ��
***************************************************/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

//Myself   ��һ��ָ��  Leetcode��  Status: Wrong Answer
ListNode* deleteDuplicates(ListNode* head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	while (p!=NULL&&p->next!=NULL)
	{
		while (p->val==p->next->val)
		{
			p->next = p->next->next;
			if (p->next == NULL)
			{
				break;
			}
		}
		p = p->next;
	}
	return head;
}

//Internet 1
//ListNode* deleteDuplicates(ListNode* head) {
//	if (head == NULL)return head;
//
//	ListNode* pre = head;
//	ListNode* cur = head->next;
//
//	while (cur != NULL)
//	{
//		if (cur->val == pre->val)
//		{
//			pre->next = pre->next->next;
//			cur = cur->next;
//			if (cur == NULL)return head;
//			//free(cur)û��free�ǲ��Եģ����������ڴ�й©;
//		}
//		else if (cur->val != pre->val)
//		{
//			pre = pre->next;
//			cur = cur->next;
//		}
//
//	}
//	return head;
//}
//Internet   2 
//ListNode* deleteDuplicates(ListNode* head) {
//	if (head == null) return head;
//
//	ListNode cur = head;
//	while (cur.next != null) {
//		if (cur.val == cur.next.val) {
//			cur.next = cur.next.next;
//		}
//		else cur = cur.next;
//	}
//	return head;
//
//}

//Myself   ������ָ��   û������Ϊɶ�˷�����leetCode�вⲻͨ   --------ԭ��LeetCode����������ͷ�����ָ���һ������Ԫ�ص�ָ�룬���������Լ������ͷ�����ָ��һ����ֵ����
ListNode* deleteDuplicates2(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *q = p->next;
	while (q!=NULL) {
		 if(p->val==q->val)
		 {
			 p->next = q->next;
			 q = p->next;
			 if (q==NULL)
			 {
				 return head;
			 }
		 }
		 else
		 {
			 p = p->next;
			 q = q->next;
		 }
		
	}
	
	return head;
}


//Myself + Internet   �˷�����
ListNode* deleteDuplicates3(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head;
	while (p->next!=NULL) {
		if (p->val==p->next->val)
		{
			p->next = p->next->next;
		}
		else {
			p = p->next;
		}
	}
	return head;
}
int main()
{
	//��ʼ������
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = {1,1,1,1,2,3,3,3};
	for (int i=0;i<vals.size();i++)
	{
		p->next = new ListNode(vals[i]);
		p = p->next;
	}

	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto deleteDuplicatesHead = deleteDuplicates2(&head);

	for (auto itr = deleteDuplicatesHead->next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

