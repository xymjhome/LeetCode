// 206. Reverse Linked List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Reverse a singly linked list.(��������������������������������ת�������һ���ڵ���ͷ���)
//
//click to show more hints.
//Hint:
//
//A linked list can be reversed either iteratively(����) or recursively(�ݹ�).Could you implement both ?
//�ݹ飺ֱ�ӻ��߼�ӵĵ����Լ����㷨��   �ú��������������ĺ�����Ϊ�ݹ麯����
//������������Ҳ��շת������һ�ֲ����ñ����ľ�ֵ������ֵ�Ĺ���,�����������Ӧ����ֱ�ӷ������߳�Ϊһ�νⷨ������һ���Խ�����⡣�������ַ�Ϊ��ȷ�����ͽ��Ƶ����������ַ����͡�ţ�ٵ����������ڽ��Ƶ�������
//      �����㷨���ü������������һ�ֻ��������������ü���������ٶȿ졢�ʺ����ظ��Բ������ص㣬�ü������һ��ָ���һ�����裩�����ظ�ִ�У���ÿ��ִ������ָ�����Щ���裩ʱ�����ӱ�����ԭֵ�Ƴ�����һ����ֵ��
 
#include "stdafx.h"
#include <string>

#include<iostream>
using namespace std;



struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


//myself �ύ����ʱ����Run Code Status : Runtime Error   �Լ����İ�ֵ��ת  ��Ŀ����˼�ǰ���������ת����ͷ���
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	//ListNode tempHead(-1);
	ListNode *p = head;
	ListNode *tempfirst = head->next;
	ListNode *tempsecond = tempfirst->next;
	p->next = NULL;
	while (tempfirst !=NULL)
	{
		tempfirst->next = p->next;
		p->next = tempfirst;
		tempfirst = tempsecond;
		if(tempsecond!=NULL)
			tempsecond = tempsecond->next;
	}
	return p;
}


//����������������ʵ������������ķ�ת�����һ��Ԫ�ر�Ϊͷ���
//Myself+Internet   Iteration
ListNode* reverseList2(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *p = head;
	ListNode *tempfirst = head->next;
	ListNode *tempsecond = tempfirst->next;
	p->next = NULL;
	while (tempfirst != NULL)
	{
		tempfirst->next = p;
		//p->next = tempfirst;
		p = tempfirst;
		tempfirst = tempsecond;
		if (tempsecond != NULL)
			tempsecond = tempsecond->next;
	}
	return p;
}

//Myself+Internet    Recursion
//public ListNode reverseList(ListNode head) {
//	if (head == null) return null;
//	if (head.next == null) return head;
//
//	ListNode p = head.next;
//	ListNode n = reverseList(p);
//
//	head.next = null;
//	p.next = head;
//	return n;
//}
ListNode* reverseList3(ListNode* head) {
	if(head==NULL) 
		return NULL;
	if (head->next == NULL) 
		return head;
	ListNode *p = head->next;
	ListNode *n = reverseList3(p);

	head->next = NULL;
	p->next = head;

	return n;
}

/****************************************************************************************************************
���ߣ�������
ʱ�䣺2016��5��10��   15��53��41��
ע�ͣ��õ�����ĳ���
****************************************************************************************************************/
template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}
int main()
{
	//��ʼ��һ������
	ListNode head(-1);
	ListNode *p = &head;
	int val[] = { 1,2,3,4,5,6,7,8 };
	cout << getArrayLen(val) << endl;
	for (int i=0;i<getArrayLen(val);i++)
	{
		/*ListNode temp(val[i]);���뷨����ģ���Ϊ�㶨��ı������������������ڴ��ַ�����Կ��ܵ�ַ��ͬ��ֱ�ӱ�������
		p->next = &temp;*/
		p->next = new ListNode(val[i]);//��������½ڵ����ȷ����
		p = p->next;
	}

	for (auto itr = head.next;itr!=NULL;itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	auto reverselist = reverseList(&head);
	for (auto itr = reverselist->next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	cout << "*********************reverseList2*************************************" << endl;
	auto reverselist2 = reverseList2(&head);
	for (auto itr = reverselist2; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	cout << "*********************reverseList3*************************************" << endl;
	auto reverselist3 = reverseList3(&head);
	for (auto itr = reverselist2; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}


