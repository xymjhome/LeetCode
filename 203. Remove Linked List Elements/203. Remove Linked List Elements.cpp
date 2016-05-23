// 203. Remove Linked List Elements.cpp : �������̨Ӧ�ó������ڵ㡣
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
ʱ�䣺2016��5��23��   10��33��06��
ע�ͣ�
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
              C++�е�new / delete����ʵ�ֵ��ڴ����������malloc��free��C��׼��ʵ�ֵ���һ���ڴ�������������ߵ��ǲ�ͬ���㷨�����Ե�Ȼ���ܻ�����.*/
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

