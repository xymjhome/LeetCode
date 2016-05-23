// 19. Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
//
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note :
//	Given n will always be valid.
//	Try to do this in one pass.
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
时间：2016年5月17日   19点28分09秒
注释：Myself    主要思路：先有一个指针pre按照给定的倒数第n个的你向后移动，当n==0时，last指针开始从头结点开始向后移动，当pre为空时，则last指针指向的是所删除元素的前一个元素，然后利用last删除元素，返回链表头结点。——特别注意n所指的元素刚刚好是链表的第一个元素的时候。
***************************************************/
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL) return NULL;
	ListNode *pre =  head, *last = head;
	while (pre !=NULL)
	{
		while (n)
		{
			pre = pre->next;
			n--;
		}
		if (!pre)//注意此判断条件，因为n说指向的元素干好事链表第一个元素的时候，按照下面的方法就会出错，因为n为第一个元素，则pre刚好移动到链表尾后空指针处，pre = pre->next;就会出错，所以要单独设立条件考虑。
		{
			return head->next;
		}
		pre = pre->next;
		if (pre!=NULL)
		{
			last = last->next;
		}
	}
	ListNode *tempNPoint = last->next;
	last->next = tempNPoint->next;
	tempNPoint->next = NULL;
	delete(tempNPoint);
	return head;
}

int main()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals = { 1,2 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head1.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto removeNthFromEndres = removeNthFromEnd(head1.next,2);
	for (auto itr = removeNthFromEndres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

