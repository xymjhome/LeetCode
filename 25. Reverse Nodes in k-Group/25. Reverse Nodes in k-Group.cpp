// 25. Reverse Nodes in k-Group.cpp : 定义控制台应用程序的入口点。
//
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5
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
时间：2016年5月25日   15点46分14秒
注释：Myself
***************************************************/
//利用递归反转指定分组有点困难，不好实现!!!!
ListNode* reverseList(ListNode *head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *n = reverseList(p);
	head->next = NULL;
	p->next = head;

	return n;
}
//利用分组的转置能够实现，但是感觉过程过于繁琐，提交通过
ListNode* reverseKGroup(ListNode* head, int k) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *p = head;
	int sum = 0;
	
	while (p)
	{
		sum++;
		p = p->next;
	}
	int n = sum / k;
	ListNode *tempHead = head;
	ListNode *moveP = head;
	vector<ListNode*> vecListH;
	while (n)
	{
		int m = k;
		ListNode *patrH = NULL;
		while (m -1)
		{
			moveP = moveP->next;
			m--;
		}
		patrH = moveP->next;
		moveP->next = NULL;
		auto partE = reverseList(tempHead);
		tempHead = patrH;
		moveP = patrH;
		vecListH.push_back(partE);
		n--;
	}
	vecListH.push_back(moveP);
	head = vecListH[0];
	vector<ListNode*> vecListE;
	for (int i=0;i<vecListH.size();i++)
	{
		int counts = k;
		ListNode *tempEveryHead = vecListH[i];
		//ListNode *everyEnd = NULL;
		while (tempEveryHead !=NULL&&(counts-1)!=0)
		{
			tempEveryHead = tempEveryHead->next;
			counts--;	
		}
		vecListE.push_back(tempEveryHead);
	}
	for ( int j = 0; j < vecListH.size()-1; j++)
	{
		vecListE[j]->next = vecListH[j + 1];
	}
	return head;
}

//Internet 的思想利用建立头结点，在不达到k的值得时候进行表头插入，到达时进行表尾插入
ListNode* reverseKGroup2(ListNode* head, int k) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head;
	int sum = 0;
	while (p)
	{
		sum++;
		p = p->next;
	}
	ListNode reverseHead(-1);
	ListNode *reversePointer = &reverseHead;
	//把大于k先头插，满足k组的话把临时头结点移动到分组最后一个再进行头插，依次循环直到sum<k，组成成组链表
	while (sum>=k)//这个条件的控制方法很好
	{
		ListNode *tempH = NULL;
		//先进行头插法
		for (int i = 0; i < k; i++) {
			ListNode *pre = head;
			head = head->next;
			reversePointer->next = pre;
			pre->next = tempH;
			tempH = pre;
		}
		while (reversePointer->next)
		{
			reversePointer = reversePointer->next;
		}
		sum -= k;
	}
	reversePointer->next = head;
	return reverseHead.next;

}

//Internet  +   Myself
ListNode* reverseKGroup3(ListNode* head, int k) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head;
	int sum = 0;
	while (p)
	{
		sum++;
		p = p->next;
	}
	ListNode reverseHead(-1);
	ListNode *reversePointer = &reverseHead;
	//把大于k先头插，满足k组的话把临时头结点移动到分组最后一个再进行头插，依次循环直到sum<k，组成成组链表
	while (sum >= k)//这个条件的控制方法很好
	{
		ListNode *pre = head;
		for (int i=0;i<k-1;i++)
		{
			pre = pre->next;
		}
		ListNode *tempHead = pre->next;
		pre->next = NULL;
		auto everyHead = reverseList(head);
		head = tempHead;
		reversePointer->next = everyHead;
		while (reversePointer->next)
		{
			reversePointer = reversePointer->next;
		}
		sum -= k;
	}
	reversePointer->next = head;
	return reverseHead.next;
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3,4,5,6 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	//auto resRever = reverseList(head.next);
	//for (auto itr = resRever; itr != NULL; itr = itr->next)
	//{
	//	cout << itr->val << " ";
	//}
	//cout << endl;

	auto res = reverseKGroup3(head.next, 4);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

