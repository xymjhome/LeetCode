// 86. Partition List.cpp : 定义控制台应用程序的入口点。
//
//Given a linked list and a value x, partition(划分) it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve（保持） the original（原始的） relative（相对的） order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
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
时间：2016年5月18日   9点51分07秒
注释：Myself  思路：首先创建两个单链表的头结点，分别用来指向小于x的单链表，和大于等于x的单链表，最后把后者连接到前者的单链表上，这样原单链表的相对顺序也不会改变。   注意--第二个链表的末尾要置为NULL
***************************************************/
ListNode* partition(ListNode* head, int x) {
	if (head==NULL)
	{
		return NULL;
	}
	ListNode *p = head;
	ListNode tempHead1(-1);
	ListNode *temp1 = &tempHead1;
	ListNode tempHead2(-1);
	ListNode *temp2 = &tempHead2;
	while (p!=NULL)
	{
		if (p->val<x)
		{
			temp1->next = p;
			temp1 = temp1->next;
		}
		if (p->val >= x)
		{
			temp2->next = p;
			temp2 = temp2->next;
		}
		p = p->next;
	}
	temp2->next = NULL;//不置为空的话有可能还指向原链表中的元素，当和第一个链表连接起来的时候回造成环的出现，导致错误
	temp1->next = tempHead2.next;
	tempHead2.next = NULL;
	//delete(&tempHead2);
	return tempHead1.next;
}
int main()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals = { 1,4,3,2,5,2 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head1.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;


	auto partitionres = partition(head1.next, 3);
	for (auto itr = partitionres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

