// 92. Reverse Linked List II.cpp : 定义控制台应用程序的入口点。
//
//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	Given m, n satisfy the following condition :
//  1 ≤ m ≤ n ≤ length of list.
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
时间：2016年5月24日   11点10分40秒
注释：Myself  自己又理解错误，from....to......是从什么到什么的意思，即从m到n之间的单链表反转，而不是m和n位置的元素之间进行交换。
***************************************************/
ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	int flags = n - m;
	ListNode* tempHead = new ListNode(-1);
	tempHead->next = head;
	m = m - 1;
	n = n - 1;
	ListNode *mPointer = tempHead;
	ListNode *nPointer = tempHead;
	while (m>0)
	{
		mPointer = mPointer->next;
		m--;
	}
	while (n>0)
	{
		nPointer = nPointer->next;
		n--;
	}
	ListNode *mReal = mPointer->next;
	ListNode *nReal = nPointer->next;

	if (flags == 0)
	{
		return head;
	}
	else if (flags==1)
	{
		mPointer->next = mReal->next;
		mReal->next = nReal->next;   
		nReal->next = mReal;
	}
	else {
		mPointer->next = mReal->next;
		mReal->next = nReal->next;
		nPointer->next = mReal;

		nReal->next = mPointer->next;
		mPointer->next = nReal;
	}
	

	return tempHead->next;
}
/****************************************************
时间：2016年5月25日   10点04分16秒
注释：前面的递归实现单链表的反转
***************************************************/
ListNode* reverseList(ListNode* head)
{
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *q = reverseList(p);
	head->next = NULL;
	p->next = head;
	return q;
}
//分为三段，把中间的一段进行反转
ListNode* reverseBetween2(ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	if (m==n)
	{
		return head;
	}
	ListNode *mPointer = head;
	ListNode *nPointer = head;
	ListNode *mPre = NULL;
	ListNode *nLater = NULL;
	while ((m-1))
	{
		mPre = mPointer;
		mPointer = mPointer->next;
		m--;
	}
	while ((n - 1))
	{
		nPointer = nPointer->next;
		n--;
	}
	if (nPointer->next!=NULL)
	{
		nLater = nPointer->next;
		nPointer->next = NULL;
	}
	ListNode *mHead = reverseList(mPointer);
	if (mPre!= NULL)
	{
		mPre->next = mHead;
	}
	else
	{
		head = nPointer;
	}
	while (mHead->next!=NULL)
	{
		mHead = mHead->next;
	}
	mHead->next = nLater;
	return head;
}
//Internet   直接在查找列表的过程中进行反转区域代码，这样比自己方法调用反转函数的好处是不用最后再找反转后的中间段的尾节点
//ListNode *reverseBetween(ListNode *head, int m, int n) {
//	if (head == NULL)
//		return NULL;
//
//	ListNode *q = NULL;
//	ListNode *p = head;
//	for (int i = 0; i < m - 1; i++)
//	{
//		q = p;
//		p = p->next;
//	}
//
//	ListNode *end = p;
//	ListNode *pPre = p;
//	p = p->next;
//	for (int i = m + 1; i <= n; i++)
//	{
//		ListNode *pNext = p->next;
//
//		p->next = pPre;
//		pPre = p;
//		p = pNext;
//	}
//
//	end->next = p;
//	if (q)
//		q->next = pPre;
//	else
//		head = pPre;
//
//	return head;
//}

//Internet + Myself     此方法的运行效率zui高些！！！！！！-----理解记忆 
ListNode* reverseBetween3(ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	if (m == n)
	{
		return head;
	}
	ListNode *endHead = NULL;
	ListNode *vPre = NULL;
	ListNode *v = head;
	ListNode *endReverse = NULL;
	int tempM = m;
	while ((tempM -1))
	{
		endHead = v;
		v = v->next;
		tempM--;
	}
	endReverse = v;
	vPre = v;
	v = v->next;
	for (int i = m+1;i<=n;i++)
	{
		ListNode *vNext = v->next;
		v->next = vPre;
		vPre = v;
		v = vNext;
	}
	endReverse->next = v;
	if (endHead)
	{
		endHead->next = vPre;
	}
	else
	{
		head = vPre;
	}
	return head;
}


/****************************************************
时间：2016年5月26日   15点04分20秒
注释：Internet  +Myself
***************************************************/
ListNode* recursionList(ListNode *head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *n = recursionList(p);
	head->next = NULL;
	p->next = head;
	return n;
}

ListNode* reverseBetween4(ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	if (m == n)
	{
		return head;
	}
	ListNode tempHead(-1);
	ListNode *pre = &tempHead;
	pre->next = head;
	ListNode *mPoint = NULL;
	ListNode *nPoint = NULL;
	ListNode *last = NULL;
	for (int i = 0;i<m-1;i++)
	{
		pre = pre->next;
	}
	mPoint = pre->next;
	ListNode *mToN = mPoint;
	for (int j = m;j<n;j++)
	{
		mToN = mToN->next;
	}
	nPoint = mToN;
	last = nPoint->next;
	nPoint->next = NULL;
	auto res = recursionList(mPoint);
	pre->next = res;
	mPoint->next = last;
	return tempHead.next;
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3,4,5,6};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	ListNode *res = reverseBetween4(head.next, 1, 4);
	//ListNode *res2 = reverseList(head.next);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

