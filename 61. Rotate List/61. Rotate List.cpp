// 61. Rotate List.cpp : 定义控制台应用程序的入口点。
//
//Given a list, rotate the list to the right by k places, where k is non - negative.

//rotate   vt.& vi. （使某物）旋转;  使转动;  使轮流，轮换;  交替
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.
//这道题是要求将单链表循环右移k次，每次移动一个结点。
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
时间：2016年5月31日   19点55分52秒
注释：Myself   这是效率最高的方法，就是组成一个环，查找要断开的点即可！！！！
***************************************************/
ListNode* rotateRight(ListNode* head, int k) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	int length=0;
	ListNode *p = head;
	ListNode *pPre = NULL;
	while (p)
	{
		length++;
		pPre = p;
		p = p->next;
	}
	pPre->next = head; 
	int distances = length - k % length;
	while (distances) {
		pPre = pPre->next;
		distances--;
	}
	ListNode *newHead = pPre->next;
	pPre->next = NULL;
	return newHead;
}
//Myself
//ListNode* reverseList(ListNode *head) {
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	ListNode *p = head->next;
//	ListNode *n = reverseList(p);
//	p->next = head;
//	head->next = NULL;
//	return n;
//}

//此方法太垃圾，不必在看！！！！！！！！！！！！！！！！！
ListNode* rotateRight2(ListNode* head, int k) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	int length = 0;
	ListNode *p = head;
	
	while (p)
	{
		length++;
		p = p->next;
	}
	int val = k%length;
	int distances = length - k%length;
	ListNode *pPre = head;
	while (distances!=1)
	{
		pPre = pPre->next;
		distances--;
	}
	
	ListNode *end = pPre->next;
	ListNode *temp = end;
	pPre->next = NULL;
	if (end)
	{
		while (end->next)
		{
			end = end->next;
		}
		end->next = head;


		return temp;
	}
	else
	{
		return head;
	}
	
	
}

int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto res = rotateRight2(head.next,1);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto res2 = reverseList(res);
	for (auto itr = res2; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	system("pause");
    return 0;
}

