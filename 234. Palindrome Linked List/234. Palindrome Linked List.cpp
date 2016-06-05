// 234. Palindrome Linked List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a singly linked list, determine if it is a palindrome(����).
//
//Follow up :
//Could you do it in O(n) time and O(1) space ?
#include "stdafx.h"
#include <ctime>
#include <time.h>
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
ʱ�䣺2016��5��23��   11��04��06��
ע�ͣ�Internet
	  �ⷨһ�� һ�α�����װ��vector��Ȼ����һ�α����жϻ��ġ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
	  �ⷨ�����ҵ������е㣬��ֺ���ת��������Ȼ����������ͬʱ˳�����һ�Ρ���������Ϊ��������ĩβ��Ԫ�ؿ��Ժ��ԡ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
	  �ⷨ�����ݹ��㷨������1���Ƚ����ص��㷨�����ڸ��������ݽṹ�ǵ�����Ҫ���������β��Ԫ�أ������ͷ��ʼ������Ϊ�˷����жϣ����ǿ�������һ������ջ�ṹ���洢��������ݣ���һ�α���������ڵ�ֵ������ջ���ڶ��α����Ƚ��ж��Ƿ�Ϊ���ġ�
	  ��2). ʱ��O(n)�Ϳռ�O(1)�ⷨ����Ȼ�õ���ջ�������뵽�ݹ�Ĺ��̱�����ǳ���ջ�Ĺ��̣����ǿ����ȵݹ���ʵ�����Ȼ�����Ƚϡ�������ʡȥ�˸����ռ䣬�Ӷ����ռ临�ӶȽ�ΪO(1)��
	  Myself
		������������һ������
***************************************************/


/****************************************************************************************************************
ʱ�䣺2016��5��23��   20��36��29��
ע�ͣ��Լ��뷨������Time Limit Exceeded  �����м��ѭ����������
****************************************************************************************************************/
bool isPalindrome(ListNode* head) {
	if (head==NULL|| head->next == NULL)
	{
		return true;
	}
	int counts = 0;
	ListNode *fast = head;
	while (fast->next!=NULL)
	{
		fast = fast->next;
		counts++;
	}
	fast->next = head;
	if (fast->val==head->val)
	{
		int mid = counts / 2;
		while (mid)
		{
			int falg = counts;
			head = head->next;
			while (falg)
			{
				fast = fast->next;
				falg--;
			}
			if (head->val == fast->val)
			{
				mid--;
				continue;
			}
			else
				return false;

		}
		return true;
	}
	else
	{
		return false;
	}
}

//�ⷨһ�� һ�α�����װ��vector��Ȼ����һ�α����жϻ��ġ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
bool isPalindrome1(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	vector<int> vals;
	ListNode *p = head;
	while (head)
	{
		vals.push_back(head->val);
		head = head->next;
	}
	
	for (auto itr = vals.rbegin();itr != vals.rend();itr++)
	{
		if (p->val!=(*itr))
		{
			return false;
		}
		p = p->next;
	}
	return true;
}


//�ⷨ�����ҵ������е㣬��ֺ���ת��������Ȼ����������ͬʱ˳�����һ�Ρ���������Ϊ��������ĩβ��Ԫ�ؿ��Ժ��ԡ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
ListNode *getMidLisNode(ListNode *head) {
	/*һ�α���, ���Ҳ����������е�:
		1. ʹ������ָ����б���, ��ָ��ÿ�β���2, ��ָ��ÿ�β���1.
		2. ����ָ�뵽������β����ʱ��, ��ָ��ָ��ľ���������е�*/
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		if (fast)
		{
			slow = slow->next;
		}	
	}
	return slow;
}
ListNode *reverseList(ListNode *head) {
	//���õݹ�ʵ������ķ�ת
	if (head->next==NULL||head==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *res = reverseList(p);

	head->next = NULL;
	p->next = head;
	return res;
}

bool isPalindrome2(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	//��ȡ��������е�
	ListNode *midLisNode = getMidLisNode(head);

	ListNode *secondHead = midLisNode->next;
	midLisNode->next = NULL;

	//��ת�ڶ�������
	ListNode *rList = reverseList(secondHead);

	while (head&&rList)
	{
		if (head->val!=rList->val)
		{
			return false;
		}
		head = head->next;
		rList = rList->next;
	}
	return true;
}

//�ⷨ�����ݹ��㷨������1���Ƚ����ص��㷨�����ڸ��������ݽṹ�ǵ�����Ҫ���������β��Ԫ�أ������ͷ��ʼ������Ϊ�˷����жϣ����ǿ�������һ������ջ�ṹ���洢��������ݣ���һ�α���������ڵ�ֵ������ջ���ڶ��α����Ƚ��ж��Ƿ�Ϊ���ġ�
//��2).ʱ��O(n)�Ϳռ�O(1)�ⷨ����Ȼ�õ���ջ�������뵽�ݹ�Ĺ��̱�����ǳ���ջ�Ĺ��̣����ǿ����ȵݹ���ʵ�����Ȼ�����Ƚϡ�������ʡȥ�˸����ռ䣬�Ӷ����ռ临�ӶȽ�ΪO(1)��

ListNode* listHead = NULL;
bool flag = true;
//Myself   ÿ�ζ�����ͷ��㣬���ֺ�ֱ�ӷ��س����������в�࣬Ӧ����Internet��һ����ֱ�Ӹ��ݸ��ݵݹ�Ӻ���ǰ�Ƚ�����Ԫ���Ƿ���ȵ����ֵ�����Ƶݹ麯���ĵݹ顣   �������ַ���������һ������ıȽϲ�����
ListNode* judgement(ListNode* head) {
	if (head->next == NULL||head==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode *n = judgement(p);
	head->next = NULL;
	if (listHead != NULL)
	{
		if (n->val != listHead->val)
		{
			flag = false;
		}
		listHead = listHead->next;
	}
	return head;
}

bool isPalindrome3(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	listHead = head;
	judgement(head);
	bool res = flag;
	return res;

}


////�ⷨ�����ݹ��㷨��Internet  +  Myself
bool judgementBool(ListNode* head) {
	if (head->next == NULL || head == NULL)
	{
		return true;
	}
	ListNode *p = head->next;
	bool tag = judgementBool(p);
	if (!tag)
	{
		return false;
	}
	if (p->val!=listHead->val)
	{
		return false;
	}
	listHead = listHead->next;
	//return true;//���Ӵ˾仰��ʾÿ�εݹ�ʱ����Ƚ�Ԫ�������û�з���ֵ������û�з���ֵ�Ǵ���ġ�Run Code Status: Compile Error��������� : control reaches end of non-void function [-Werror=return-type]
}

bool isPalindrome4(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	listHead = head;
	bool res = judgementBool(head);
	return res;

}
int main()
{
	time_t rawtime = time(0);
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
	string time_s = buffer;
	cout << time_s << endl;


	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 1,2,3,4,5,6,7,8,9,10,9,9,7,6,5,4,3,2,1};
	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	

	auto res = isPalindrome4(head.next);
	cout <<boolalpha<< res << endl;

	


	time_t rawtime1 = time(0);
	struct tm * timeinfo1;
	char buffer1[80];
	timeinfo1 = localtime(&rawtime);
	strftime(buffer1, 80, "%Y%m%d_%H%M%S", timeinfo1);
	string time_s1 = buffer1;
	cout << time_s1 << endl;

	system("pause");
    return 0;
}

