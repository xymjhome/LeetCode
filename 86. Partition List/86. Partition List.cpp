// 86. Partition List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a linked list and a value x, partition(����) it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve�����֣� the original��ԭʼ�ģ� relative����Եģ� order of the nodes in each of the two partitions.
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
ʱ�䣺2016��5��18��   9��51��07��
ע�ͣ�Myself  ˼·�����ȴ��������������ͷ��㣬�ֱ�����ָ��С��x�ĵ������ʹ��ڵ���x�ĵ��������Ѻ������ӵ�ǰ�ߵĵ������ϣ�����ԭ����������˳��Ҳ����ı䡣   ע��--�ڶ��������ĩβҪ��ΪNULL
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
	temp2->next = NULL;//����Ϊ�յĻ��п��ܻ�ָ��ԭ�����е�Ԫ�أ����͵�һ����������������ʱ�����ɻ��ĳ��֣����´���
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

