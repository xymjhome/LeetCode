// 2. Add Two Numbers.cpp : �������̨Ӧ�ó������ڵ㡣
//
//You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8

//������������Ϊ���룬���Ǳ�ʾ����������Ǹ���������������������ʾ����342��465��������������Ҫ�������ǵĺͲ�����ͬ���ķ�ʽ�����������342 + 465 = 807, ����Ҫ�ѽ�����Ϊ7 ->0 ->8
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//
//	Output : 7 -> 0 -> 8
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
ʱ�䣺2016��5��31��   21��41��33��
ע�ͣ�Myself   Ч�ʺܵͣ�You are here! Your runtime beats 5.04% of cppsubmissions
***************************************************/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1==NULL&&l2==NULL)
	{
		return NULL;
	}
	ListNode *p1 = l1;
	vector<int> val1;
	ListNode *p2 = l2;
	vector<int> val2;
	if (l1)
	{
		while (p1)
		{
			val1.push_back(p1->val);
			p1 = p1->next;
		}	
	}
	else
	{
		val1.push_back(0);
	}
	if (l2)
	{
		while (p2)
		{
			val2.push_back(p2->val);
			p2 = p2->next;
		}
	}
	else
	{
		val2.push_back(0);
	}
	long long sum1 = 0, sum2 = 0;
	for (int j = val1.size()-1;j>=0;j--)
	{
		sum1 += (val1[j] * pow(10.0, j));
	}
	for (int j = val2.size() - 1; j >= 0; j--)
	{
		sum2 += (val2[j] * pow(10.0, j));
	}
	long long sum = sum1 + sum2;
	vector<int> result;
	if (sum==0)
	{
		result.push_back(0);
	}
	while (sum)
	{
		int digit = sum % 10;
		result.push_back(digit);
		sum /= 10;
	}
	ListNode *head = new ListNode(result[0]);
	ListNode *temp = head;
	for (int i =1;i<result.size();i++)
	{
		temp->next = new ListNode(result[i]);
		temp = temp->next;
	}
	return head;
}

//Myself    Your runtime beats 67.40% of cppsubmissions.   Ч�ʸߣ�ʵ�ְ�λ�ļӷ������Ǵ����߼����á�
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	if (l1 == NULL&&l2 == NULL)
	{
		return NULL;
	}
	if (l1==NULL)
	{
		return l2;
	}
	if (l2==NULL)
	{
		return l1;
	}
	ListNode *p1 = l1;
	ListNode *p2 = l2;
	ListNode head(-1);
	ListNode *p = &head;
	int sum = 0;
	while (true)
	{
		if (p1&&p2)
		{
			sum += (p1->val + p2->val);
			if (sum>=10)
			{
				int val = sum % 10;
				p->next = new ListNode(val);
				p = p->next;
				sum = sum / 10;
			}
			else {
				p->next = new ListNode(sum);
				p = p->next;
				sum = 0;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1) 
		{
			sum += p1->val;
			if (sum >= 10)
			{
				int val = sum % 10;
				p->next = new ListNode(val);
				p = p->next;
				sum = sum / 10;
			}
			else {
				p->next = new ListNode(sum);
				p = p->next;
				sum = 0;
			}
			p1 = p1->next;
		}
		else if (p2)
		{
			sum += p2->val;
			if (sum >= 10)
			{
				int val = sum % 10;
				p->next = new ListNode(val);
				p = p->next;
				sum = sum / 10;
			}
			else {
				p->next = new ListNode(sum);
				p = p->next;
				sum = 0;
			}
			p2 = p2->next;
		}
		if (!p1&&!p2)
		{
			if (sum)
			{
				p->next = new ListNode(sum);
			}
			break;
		}
	}
	return head.next;
}

/****************************************************
ʱ�䣺2016��6��1��   15��04��20��
ע�ͣ�Internet  +  Myself   ������ϵ��߼����������Ϊѭ����ʼ����(l1 != null || l2 != null)�������Լ�����true��������ѭ����Ȼ������������и����жϡ�
***************************************************/
//ListNode result = new ListNode(0);
//int carry = 0;
//ListNode pointer = result;
//while (l1 != null || l2 != null) {
//	//������һ��û��ͷ���ͼ���
//	if (l1 != null) {
//		carry += l1.val;
//		l1 = l1.next;
//	}
//
//	if (l2 != null) {
//		carry += l2.val;
//		l2 = l2.next;
//	}
//
//	pointer.next = new ListNode(carry % 10);
//	carry /= 10;
//	pointer = pointer.next;
//
//}
//
//if (carry > 0) {//�ǵô������Ľ�λ������
//	 pointer.next = new ListNode(carry);
//}
//
//return result.next;
//�˷���˼·������࣬������
ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
	ListNode head(-1);
	ListNode *p = &head;
	int sum = 0;
	while (l1!=NULL||l2!=NULL)
	{
		if (l1!=NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2!=NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		p->next = new ListNode(sum % 10);
		sum /= 10;
		p = p->next;
	}
	if (sum)
	{
		p->next = new ListNode(sum);
	}
	return head.next;
}



int main()
{
	ListNode head(-1),head2(-1);
	ListNode *p = &head;
	ListNode *p2 = &head2;
	vector<int> vals = { 3,4,2 };
	vector<int> vals2 = { 4,6,5 };
	/*vector<int>  zz;
	zz.push_back(3);
	for (int i = 0; i < zz.size(); i++) {
		cout << zz[i] << endl;
	}*/
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (int i = 0; i < vals2.size(); i++) {
		p2->next = new ListNode(vals2[i]);
		p2 = p2->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	for (auto itr = head2.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	auto res = addTwoNumbers3(head.next, head2.next);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

