// 147. Insertion Sort List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Sort a linked list using insertion sort.
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
ʱ�䣺2016��5��18��   19��49��00��----- 21��09��03��(��ʱ����˼·������)
ע�ͣ�Myself   �о��˷����ܱ�������
***************************************************/

ListNode* insertionSortList(ListNode* head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode newHead(-1);
	ListNode *newq = &newHead;
	newq->next = head;
	ListNode *p = head->next;
	head->next = NULL;
	ListNode *tempFlag=NULL;
	while (p != NULL)
	{
		ListNode *pre = newHead.next;
		ListNode *last = &newHead;
		while (pre!=NULL)
		{
			if (p->val >= pre->val)
			{
				pre = pre->next;
				last = last->next;
				if (!pre)
				{
					last->next = p;
					p = p->next;
					last->next->next = NULL;
				}
			}
			else
			{
				last->next = p;
				p = p->next;
				last->next->next = pre;
				break;
			}
		}
	}
	return newHead.next;
}


/****************************************************
ʱ�䣺2016��5��19��   16��10��44��
ע�ͣ�Internet    ���Լ���˼·һ���ڱ���ÿ��Ԫ�ع����У����������򲿷ֽ��в��롣����˼·���Լ�������    ˼·�����Ƚ���һ����ʱ��ͷ��㣬Ȼ��ѭ���жϴ��������û��ȡ�����һ��Ԫ�أ��˷�����һ��˼·��������ǣ���1���ֱ�������ָ��ָ��ԭ����һ��ָ����Ƚϵ�Ԫ�أ�һ��ָ����Ƚ�Ԫ�ص���һ��Ԫ�ء���2��ÿ�δ�ͷ�ж��Ѿ���������������һ��ָ��ListNode *cur = sortedHead;��¼ÿ�ζ��Ǵ����������ͷ��㿪ʼ�Ƚϣ���curָ��ָ�����������д��Ƚ�Ԫ�ص�ǰ�棬��ԭֵ�����Ƚϵ�ֵС������curָ�����룬�����С����curָ������ƶ���
***************************************************/
//ListNode *insertionSortList(ListNode *head) {
//	ListNode *sortedHead = new ListNode(-1);
//	while (head != NULL)
//	{
//		//����headλ��
//		ListNode *temp = head->next;
//		ListNode *cur = sortedHead;
//		while (cur->next != NULL && cur->next->val < head->val)
//		{
//			cur = cur->next;
//		}
//		//����
//		head->next = cur->next;
//		cur->next = head;
//		//�ָ�head
//		head = temp;
//	}
//	return sortedHead->next;
//}
/****************************************************
ʱ�䣺2016��5��20��   10��09��24��
ע�ͣ�Internet  +  Myself
***************************************************/
ListNode* insertionSortList2(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *sortHead = new ListNode(-1);
	while (head!=NULL)
	{
		ListNode *temp = head->next;
		ListNode *cur = sortHead;
		while (cur->next!=NULL&&cur->next->val<head->val)
		{
			cur = cur->next;
		}
		head->next = cur->next;
		cur->next = head;
		head = temp;
	}
	return sortHead->next;
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,4,3,2,5,2 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	ListNode *tempHead = head.next;
	auto insertionSortListres = insertionSortList2(tempHead);
	for (auto itr = insertionSortListres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

