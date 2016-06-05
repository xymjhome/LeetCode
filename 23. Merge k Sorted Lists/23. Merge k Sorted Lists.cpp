// 23. Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。
//
//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
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
时间：2016年6月4日   13点53分36秒
注释：Myself      运行时间过高，此法不好You are here!   Your runtime beats 3.58% of cppsubmissions.
***************************************************/
ListNode* mergeList(ListNode *l1, ListNode *l2) {
	ListNode newHead(-1);
	ListNode *p = &newHead;
	while (l1!=NULL&&l2!=NULL)
	{
		if (l1->val<l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	while (l1)
	{
		p->next = l1;
		l1 = l1->next;
		p = p->next;
	}
	while (l2)
	{
		p->next = l2;
		l2 = l2->next;
		p = p->next;
	}
	return newHead.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n==0)
	{
		return NULL;
	}
	ListNode *newHead = NULL;
	for (int i = 0; i < n; i++)
	{
		 newHead = mergeList(lists[i],newHead); 
	}
	return newHead;
}

int main()
{

	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals1 = { 0,1,2,3,4,5 };
	for (int i = 0; i < vals1.size(); i++) {
		p->next = new ListNode(vals1[i]);
		p = p->next;
	}
	ListNode head2(-1);
	ListNode *p2 = &head2;
	vector<int> vals2 = { 5,6,7,8,9,10 };
	for (int i = 0; i < vals2.size(); i++) {
		p2->next = new ListNode(vals2[i]);
		p2 = p2->next;
	}
	ListNode head3(-1);
	ListNode *p3 = &head3;
	vector<int> vals3 = { 10,11,12,13,14,15 };
	for (int i = 0; i < vals3.size(); i++) {
		p3->next = new ListNode(vals3[i]);
		p3= p3->next;
	}
	ListNode head4(-1);
	ListNode *p4 = &head4;
	vector<int> vals4 = { 15,16,17,18,19,20 };
	for (int i = 0; i < vals4.size(); i++) {
		p4->next = new ListNode(vals4[i]);
		p4 = p4->next;
	}
	ListNode head5(-1);
	ListNode *p5 = &head5;
	vector<int> vals5 = { 20,21,22,23,24,25 };
	for (int i = 0; i < vals5.size(); i++) {
		p5->next = new ListNode(vals5[i]);
		p5 = p5->next;
	}
	vector<ListNode*> sortList;
	sortList.push_back(head1.next);
	sortList.push_back(head2.next);
	sortList.push_back(head3.next);
	sortList.push_back(head4.next);
	sortList.push_back(head5.next);
	
	auto res = mergeKLists(sortList);
	for (auto itr = res;itr!=NULL;itr= itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

