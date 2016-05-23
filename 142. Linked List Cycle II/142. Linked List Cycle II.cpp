// 142. Linked List Cycle II.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//	Follow up :
//Can you solve it without using extra space ?
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
ʱ�䣺2016��5��16��   22��07��45��
ע�ͣ�Myelf    �Լ�д�ķ����ǣ������������ڻ��������ÿ���ָ�룬����ָ�������ָ��ʱ֤���������ڣ����ʱ�������������㴦�жϣ���������������Ȼ��������count�ֱ��¼����������������ľ��룬������߾���Ȼ�󳤵�����ƶ���Ծ���ĳ��ȣ��������������һ������ߣ���ָ���ֻ������ͬʱ���ǻ�����ʼ�㡣-----------�Լ����ķ���û���ܽ���ɣ�̫��׾��@������
***************************************************/
ListNode *detectCycle(ListNode *head) {
	if (head==NULL||head->next==NULL)
	{
		return NULL;
	}
	ListNode *fast, *slow,*tempHead1;
	ListNode tempHead(-1);
	tempHead1 = &tempHead;
	fast = slow = head->next;
	while (true)
	{
		if (fast != NULL&&fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				tempHead.next = slow->next;
				slow->next = NULL;
				break;
			}
		}
		else
		{
			return NULL;
		}	
	}
	int count1=0, count2=0;
	for (auto itr1 = head->next;itr1!=NULL;itr1 = itr1->next)
	{
		count1++;
	}
	for (auto itr2 = tempHead.next; itr2 != NULL; itr2 = itr2->next)
	{
		count2++;
	}
	int distances=0;
	//distances = count1 >= count2 ? count1 - count2 : count2 - count1;
	if (count1 > count2)
	{
		distances = count1 - count2;
		for (int i=0;i<distances;i++)
		{
			head = head->next;
		}
	}
	if (count1 < count2)
	{
		distances = count2 - count1;
		for (int i = 0; i < distances; i++)
		{
			tempHead1 = tempHead1->next;
		}
	}
	while (head!=NULL&&tempHead1!=NULL)//��һ���ύ��������head->next!=NULL&&tempHead1->next!=NULL���󣬵��²�����ȷ�ķ��ػ�����ʼ��
	{
		if (head==tempHead1)
		{
			return head;
		}
		head = head->next;
		tempHead1 = tempHead1->next;
	}

}


/****************************************************
ʱ�䣺2016��5��16��   22��15��01��
ע�ͣ�Internet + Myself      ������ϵĴ����˼�룬��д������롣
	  ����˼�룺�Ե��������ָ�������������㵽����ʼ�㣬�Լ�������ͷ������ʼ��ľ�������ܽᣬ���Եõ����½��ۡ��������㵽����ʼ��ľ��������ͷ������ʼ��ľ�����ͬ����������ͷ��㣩�������㵽����ʼ��ľ��������ͷ������ʼ��ľ������1��������ͷ��㣬��ΪListNode head(-1);������1�����룩��
	  �мǴ˽����Ǵ������������𵽻���ʼ��ľ��룬�Լ���ָ������ָ���2���ƶ��ٶȡ�
	  �м�Ҫ��������Ⱦ��룬һ���Ӵ�������ʵֵ�ĵ�һ���ڵ���Ϊͷ��㡣



	  Example:
	  ͼ�У�        X     a      Y    b    Z
	                -------------|---------| 
                                 |         |
								 |---------| 
	                              c
	  X���������㡣   
	  Y�ǻ�����㡣
	  Z��fast��slow�״������ĵط�������ͬʱ��X������slowÿ���ƶ�һ����fastÿ���ƶ���������
	  a, b, c�ֱ��ʾXY����ɫ��, YZ����ɫ��, ZY����ɫ���ĳ��ȡ�

	  ��fast��slow��Z���״�����ʱ��

	  fast�ƶ��ľ����ǣ�a + b + c + b
	  slow�ƶ��ľ����ǣ�a + b

	  ��Ϊfast���ƶ��ٶ���slow�����������ԣ�

	  (a + b + c + d) == 2 * (a + b)

	  �ɴ˿����Ƴ���

	  a == c

	  ������Ҫ�������������Ѱ�һ�����㣨Y����

	  ��fast��slow�״�����ʱ�����Ǿ͵���Z�㡣

	  ����a == c��Ҳ����X��Y �� Z��Y�ľ�����ȡ�

	  ��ˣ����������ָ��p��q�ֱ��X��Z����������ÿ�ζ��ƶ�һ��������������ʱ��ǡ�þ��ǻ������Y��
***************************************************/

ListNode *detectCycle2(ListNode *head) {
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *fast, *slow;
	fast = slow = head;
	while (fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		while (fast==slow)
		{
			auto tempHead1 = head;
			auto  tempHead2 = slow;
			while (tempHead1!=tempHead2)
			{
				tempHead1 = tempHead1->next;
				tempHead2 = tempHead2->next;
				/*if (tempHead1== tempHead2)
				{
					return tempHead1;
				}*/
			}
			return tempHead1;
			
		}
	}
	return NULL;
}


int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 2};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	ListNode *three = &head;
	for (int j=0;j<1;j++)
	{
		three = three->next;
	}
	p->next = three;
	/*for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;*/


	//auto detectCycleres = detectCycle(&head);

	//cout <<"detectCycleres:: "<< detectCycleres->val << endl;

	ListNode *temphead = &head;
	auto detectCycleres2 = detectCycle2(temphead->next);

	cout << "detectCycleres2" << detectCycleres2->val << endl;

	system("pause");
    return 0;
}

