// 147. Insertion Sort List.cpp : 定义控制台应用程序的入口点。
//
//Sort a linked list using insertion sort.
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
时间：2016年5月18日   19点49分00秒----- 21点09分03秒(耗时长，思路不清晰)
注释：Myself   感觉此方法很笨！！！
***************************************************/

ListNode* insertionSortList(ListNode* head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode newHead(-1);
	ListNode *newq = &newHead;
	newq->next = head;
	ListNode *p = head->next;
	head->next = NULL;
	ListNode *tempFlag=NULL;
	while (p != NULL)
	{
		ListNode *pre = newHead.next;
		ListNode *last = &newHead;
		while (pre!=NULL)
		{
			if (p->val >= pre->val)
			{
				pre = pre->next;
				last = last->next;
				if (!pre)
				{
					last->next = p;
					p = p->next;
					last->next->next = NULL;
				}
			}
			else
			{
				last->next = p;
				p = p->next;
				last->next->next = pre;
				break;
			}
		}
	}
	return newHead.next;
}


/****************************************************
时间：2016年5月19日   16点10分44秒
注释：Internet    和自己的思路一样在遍历每个元素过程中，遍历已排序部分进行插入。但是思路比自己的清晰    思路：首先建立一个临时的头结点，然后循环判断传入的链表没有取到最后一个元素，此方法的一个思路清晰点就是，（1）分别用两个指针指向原链表，一个指向待比较的元素，一个指向待比较元素的下一个元素。（2）每次从头判断已经部分有序链表，用一个指针ListNode *cur = sortedHead;记录每次都是从有序链表的头结点开始比较，且cur指针指向有序链表中待比较元素的前面，若原值比所比较的值小，则在cur指针后插入，如果不小于则cur指针向后移动。
***************************************************/
//ListNode *insertionSortList(ListNode *head) {
//	ListNode *sortedHead = new ListNode(-1);
//	while (head != NULL)
//	{
//		//保存head位置
//		ListNode *temp = head->next;
//		ListNode *cur = sortedHead;
//		while (cur->next != NULL && cur->next->val < head->val)
//		{
//			cur = cur->next;
//		}
//		//插入
//		head->next = cur->next;
//		cur->next = head;
//		//恢复head
//		head = temp;
//	}
//	return sortedHead->next;
//}
/****************************************************
时间：2016年5月20日   10点09分24秒
注释：Internet  +  Myself
***************************************************/
ListNode* insertionSortList2(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *sortHead = new ListNode(-1);
	while (head!=NULL)
	{
		ListNode *temp = head->next;
		ListNode *cur = sortHead;
		while (cur->next!=NULL&&cur->next->val<head->val)
		{
			cur = cur->next;
		}
		head->next = cur->next;
		cur->next = head;
		head = temp;
	}
	return sortHead->next;
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,4,3,2,5,2 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	ListNode *tempHead = head.next;
	auto insertionSortListres = insertionSortList2(tempHead);
	for (auto itr = insertionSortListres; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

