// 82. Remove Duplicates from Sorted List II.cpp : 定义控制台应用程序的入口点。
//
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


/****************************************************
时间：2016年5月28日   15点31分11秒
注释：Myself    此方法效率最高，比Internet上面的高一些，自己的方法就是找到相同的段，然后一起删除
***************************************************/
ListNode* deleteDuplicates(ListNode* head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode deleteHead(-1);
	ListNode *pPre = &deleteHead;
	pPre->next = head;
	ListNode *p = deleteHead.next;
	int counts = 1;
	while (p->next!=NULL)
	{
		ListNode *pNext = p->next;
		if (p->val==pNext->val)
		{
			counts++;
			p = p->next;
		}
		else
		{
			if (counts>1)
			{
				ListNode *tempHead = NULL;
				tempHead = pPre->next;
				pPre->next = pNext;
				p->next = NULL;
				delete(tempHead);
				p = pNext;
				counts = 1;
			}
			else
			{
				pPre = pPre->next;
				p = p->next;
			}
			
		}
	}
	if (counts>1)
	{
		pPre->next = NULL;
	}
	return deleteHead.next;
}


//Internet
ListNode* deleteDuplicates3(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	head = dummy;

	while (head->next != NULL && head->next->next != NULL) {
		if (head->next->val == head->next->next->val) {
			int val = head->next->val;
			while (head->next != NULL && head->next->val == val) {
				head->next = head->next->next;
			}
		}
		else {
			head = head->next;
		}
	}

	return dummy->next;
}

//Internet   +   Myself  此法是找到一个相等的就删除一个，直到不等。  自己写的代码还是没有网上的简洁。
ListNode* deleteDuplicates2(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode deleteHead(-1);
	ListNode *pPre = &deleteHead;
	pPre->next = head;
	ListNode *p = deleteHead.next;
	while (p!=NULL&&p->next!=NULL)
	{
		ListNode *pNext = p->next;
		if (p->val==pNext->val)
		{
			int val = p->val;
			while (p!=NULL&&p->val == val)
			{
				pPre->next = pNext;
				p = pNext;
				if (pNext!=NULL)
				{
					pNext = pNext->next;
				}	
			}
		}
		else
		{
			pPre = pPre->next;
			p = p->next;
		}
	}
	return deleteHead.next;
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3,3,4,4,5,6,6,6,6};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto res = deleteDuplicates2(head.next);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

