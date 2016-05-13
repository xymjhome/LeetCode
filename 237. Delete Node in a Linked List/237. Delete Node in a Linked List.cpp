// 237. Delete Node in a Linked List.cpp : 定义控制台应用程序的入口点。
//
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
//给定链表中的一个节点，删除该节点。
//
//正常情况下链表中节点的删除是需要知道被删除节点的前一个节点的，将它前一个节点的next指针指向它的下一个节点，这个节点就从链表中删除了。但是这里没有提供前一个节点，而是提供了当前节点。
//
//一个技巧就是用它的下一个节点的值覆盖当前节点的值，然后将下一个节点删除掉，这样就等效删除了当前节点。但是需要注意这种方法不能删除尾节点（题目中也给出了这个条件）。


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

//myself认为形参是链表的头结点，实际题目的要求形参是要删除的节点，理解错误
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
作者：刘江涛
时间：2016年5月10日   15点10分09秒
注释：此题的意思是给定一个节点，删除本节点，但是删除链表中的节点需要知道其前一个节点的指针，但是这里没法获得，只能	用复制后一个值到到当前节点，删除后面的节点，前提是不能删除最后一个节点。
****************************************************************************************************************/
void deleteNode2(ListNode* node) {
	if (node == NULL)
		return;
	if (node->next == NULL)//不能删除最后一个节点
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
	cout << "List 初始化：" << endl;
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

	//删除指定节点
	ListNode *three = NULL;
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		if (itr->val == 1)
			three = itr;
	}
	deleteNode2(three);
	cout << "删除指定节点后"<<endl;
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;



	//删除一个节点
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

