// 160. Intersection of Two Linked Lists.cpp : 定义控制台应用程序的入口点。
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists :
//
//  A:        a1 → a2
//	                   ↘
//	                     c1 → c2 → c3
//	                   ↗
//	B : b1 → b2 → b3
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
时间：2016年5月17日   11点20分44秒
注释：Myself   如果两个链表相交，先用 countA=0, countB=0统计两个单链表的长度，因为如果二者有交点的话，如example中所示，二者的后半部分是相同的，成“Y”字形，所以只要减去长的单链表中和短单链表相差的元素个数，然后再同时让两个单链表向后移动，则当二者相同时就是二者的交点。 
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
时间：2016年5月17日   18点39分00秒
注释：Internet + Myself   此方法的解题思路：不用整形变量值来记录哪个链表长，而是利用指针的移动差来重新设定除去长链表中的元素的头结点，然后再移动比较，当相等时就是要查找的第一个相同的节点。其实查找相同节点的方法是和上面一样的，但是找元素差不同。
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
//		if (p1 == p2) return p1; //当达到相遇点时，直接返回p1或者p2
//
//		if (p1 == NULL) p1 = headB; //当p1比p2先到达结尾时，重新将其移动到第二个链表的头部
//		if (p2 == NULL) p2 = headA; //当p2比p1先到达结尾时，重新将其移动到第二个链表的头部，这样的话，二者到相遇点的距离是相等的
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
			return pA;//这个条件也能控制把不想交的两个单链表结果返回为空
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
	return pA;//这个判断条件是为了满足第一个头结点开始就是相同节点的情况
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

