// 328. Odd Even Linked List.cpp : 定义控制台应用程序的入口点。
//
//Given a singly linked list, group all odd(奇数) nodes together followed by the even（偶数） nodes.Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:（出错，题意是偶数位置的节点在前面，奇数在后面
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note :
//	The relative order inside both the even and odd groups should remain as it was in the input.
//	The first node is considered odd, the second node even and so on ...
//题目大意:
//给定一个单链表，将其节点进行分组，使得所有的奇数节点排列在前，偶数节点在后。请注意这里的奇偶指的是节点序号而不是节点的值。
//你应当尝试“就地”完成此问题。程序应当满足O(1)的空间复杂度和O(nodes)的时间复杂度。
//测试用例见题目描述。
//注意：
//偶数与奇数节点分组内部的相对顺序应当与输入保持一致。
//第一个节点为奇数节点，第二个节点为偶数节点，以此类推。

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
作者：刘江涛
时间：2016年5月11日   10点14分19秒
注释：Myself   在提交时有 	Status: Runtime Error   错误
****************************************************************************************************************/
//奇数在前，偶数在后
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

//偶数在前，奇数在后    在提交正确，第一次自己错误是因为没有读懂题意。但是自己的方法对于控制最后一个节点指针（evenLast）很麻烦，需学习Internet  Method
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
//	while (even != null&&even.next != null) {   //想想为什么是这个判断条件
//		odd.next = even.next;
//		odd = odd.next;
//		even.next = odd.next;
//		even = even.next;
//	}
//	odd.next = evenhead;
//	return head;
//}
//此方法的节点的交换处理很好    偶数在前，奇数在后 
ListNode *oddEvenList2(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *odd = head;
	ListNode *even = head->next;
	ListNode *evenhead = head->next;
	while (even != NULL&&even->next != NULL) {  
		//一次可以进行两个链表节点（即奇数节点和偶数节点同时并到各自的链表中）
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenhead;
	return head;
}

//Myself + Internet 实现奇数位置节点在前，偶数节点位置在后
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
	//初始化一个链表
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

