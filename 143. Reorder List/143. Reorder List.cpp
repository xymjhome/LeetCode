// 143. Reorder List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a singly linked list L : L0��L1������Ln - 1��Ln,
//reorder it to : L0��Ln��L1��Ln - 1��L2��Ln - 2����
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1,2,3,4 }, reorder it to{ 1,4,2,3 }.
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
ʱ�䣺2016��5��30��   20��58��31��
ע�ͣ�Myself   ֱ�����õݹ��˼�룬�ڵݹ��ڲ��Ѻ���Ľڵ���ӵ�ǰ�档
***************************************************/
//ListNode *lst = NULL;
//ListNode* reverseElement(ListNode* head) {
//	if (head==NULL||head->next==NULL)
//	{
//		return head;
//	}
//	ListNode *p = head->next;
//	ListNode *n = reverseElement(p);
//	if (lst->next == NULL)
//	{
//		return NULL;
//	}
//	else if (lst->next->next == NULL)
//	{
//		return NULL;
//	}
//	ListNode *pPre = lst->next;
//	lst->next = p;
//	p->next = pPre;
//	lst = pPre;
//	if (lst)
//	{
//		head->next = NULL;
//	}
//	return n;
//}
//
//void reorderList(ListNode* head) {
//	lst = head;
//	reverseElement(head);
//}

/****************************************************
ʱ�䣺2016��5��30��   22��18��56��
ע�ͣ�Internet  +  Myself   ���ҵ���������е㣬Ȼ��Ͽ����Ѻ�벿����ת���β���ǰ�벿�֡�
***************************************************/
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
void reorderList2(ListNode* head) {
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *lastHead = slow->next;
	slow->next = NULL;
	ListNode *n = reverseList(lastHead);
	while (n!=NULL)
	{
		ListNode *headPre = head->next;
		ListNode *nPre = n->next;
		head->next = n;
		n->next = headPre;
		head = headPre;
		n = nPre;
	}
}

/****************************************************
ʱ�䣺2016��5��31��   16��28��59��
ע�ͣ�Internet
***************************************************/
//void reorderList(ListNode head) {
//	reorderList(head, getListSize(head));
//}
//
//ListNode reorderList(ListNode head, int length) {
//
//	if (length == 0 || head == null) { // rare case
//		return null;
//	}
//	else if (length == 1) {
//		ListNode temp = head.next;
//		head.next = null;
//		return temp;
//	}
//	else if (length == 2) {
//		ListNode temp = head.next.next;
//		head.next.next = null;
//		return temp;
//	}
//	else {
//		ListNode forward = reorderList(head.next, length - 2);
//		ListNode temp = forward.next;
//		forward.next = head.next;
//		head.next = forward;
//		return temp;
//	}
//
//}



//Internet  +   Myself
//���õݹ���ִ��headָ���ǰ���ͺ��ˣ�����������head == midʱ�ݹ������head�����ƶ�������forward���պ��ε�ͷ��㣬Ȼ����������ƶ�ȡ�ڵ���뵽head�ĺ��档
ListNode *reorderList(ListNode *head,int counts) {
	if (head == NULL )
	{
		return NULL;
	}
	if (counts==1)//count�����ֵ��headָ�����Ҫ�Ͽ�ָ���λ�õĴ�С
	{
		ListNode *temp = head->next;
		head->next = NULL;
		return temp;
	}
	else if (counts==2)
	{
		ListNode *temp = head->next->next;
		head->next->next = NULL;
		return temp;
	}
	else
	{
		ListNode *forward = reorderList(head->next, counts - 2);
		ListNode *temp = forward->next;
		forward->next = head->next;
		head->next = forward;
		return temp;	
	}
}
void reorderList3(ListNode *head) {
	ListNode *slow = head;
	int counts = 0;//��������
	while (slow)
	{
		slow = slow->next;
		counts++;
	}
	reorderList(head,counts);

}

int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3,4,5,6};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	reorderList3(head.next);
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto res = reverseList(head.next);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	system("pause");
    return 0;
}

