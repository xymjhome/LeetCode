// 203. Remove Linked List Elements.cpp : 定义控制台应用程序的入口点。
//
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given : 1 -- > 2 -- > 6 -- > 3 -- > 4 -- > 5 -- > 6, val = 6
//	Return: 1 -- > 2 -- > 3 -- > 4 -- > 5
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
时间：2016年5月23日   10点33分06秒
注释：
***************************************************/
ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL)
	{
		return NULL;
	}
	ListNode removeHead(-1);
	ListNode *tempHead = &removeHead;
	tempHead->next = head;
	ListNode *pre = head;
	while (pre != NULL)
	{
		if (pre->val == val)
		{
			tempHead->next = pre->next;
			pre->next = NULL;
			/*new     <-->  delete
			  new[]   <-->  delete[]
			  malloc  <-->  free
              C++中的new / delete是新实现的内存分配器，而malloc和free是C标准库实现的另一套内存分配器，他们走的是不同的算法，所以当然不能混用了.*/
			delete(pre);
			//free(pre);

			pre = tempHead->next;
		}
		else {
			pre = pre->next;
			tempHead = tempHead->next;
		}
	}
	return removeHead.next;
}

int main()
{

	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,6,3,4,5,6 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto removeElementsres = removeElements(head.next,6);
	for (auto itr = removeElementsres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

