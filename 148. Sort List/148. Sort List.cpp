// 148. Sort List.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Sort a linked list in O(n log n) time using constant space complexity.
#include "stdafx.h"

#include <ctime>
#include <fstream>
#include <sstream>
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
ʱ�䣺2016��6��2��   14��52��13��
ע�ͣ�Myself + Internet     ��������ʱ�临�Ӷȹ��ߣ������������
***************************************************/
//�����Ͽ����ܹ���O(n lgn)ʱ�临�Ӷȵ��㷨Ϊ���������򣬶����򣬹鲢�������ߵĿռ临�Ӷȷֱ�ΪO(1), O(N), O(N)
//����һ��ʼ���������ÿ�������ķ�������������Ƿ��ִ������д�������������Ͽ���һ����ʾ��������ʵ����ѡ���ˡ�Ӧ��ʹ�õķ����ǹ鲢����
//
//ͨ�����ԣ�Ҳ�������������ԣ��鲢����Ŀռ临�Ӷ�ΪO(N), ����Ҫ����O(N)�Ķ���ռ����������飬����ʾ�鲢���˳�򡣵��ǣ�����������ԣ������ʡ���ⲿ�ֿռ�Ŀ�������ֻ��Ҫ�ı�ڵ��nextָ���ָ�򣬾Ϳ��Ա�ʾ�µĹ鲢���˳���ˣ����Կռ临�Ӷȶ�Ȼ������O(1)��

//����һ�£�����˵������������Ԫ�ش洢�������У���ô����������Թ鲢�����������ԭ����졣һ�ǣ����Ժܿ�ؽ���Ԫ�صĶ�ȡ(��������������Ԫ����˳��ڷŵģ��������Ԫ��������ڷŵ�)�������partion�ⲽ�ͱ������partion�ⲽ�졣���ǣ��鲢������merge�׶���Ҫ�������飬��Ҫ����O(N)�Ŀռ䣬����ռ�Ҳ����Ҫʱ��ġ������Ų���Ҫ��������ռ䡣����������Ԫ�ش洢�������У����ŵ��ŵ�ͱ����ȱ�㡣�鲢�������Ǿ��ٶȸ����ˡ�



//�����������������ͬ���Ȱ����ݽ��зֿ飬������������ָ��p��q��������ָ�����next�����ƶ����ƶ��Ĺ����б���p֮ǰ��key��С��ѡ����key��p��q֮���key������ѡ����key����ô��q�ߵ�ĩβ��ʱ��������һ��֧���Ѱ�ҡ�
//ListNode* getPartion(ListNode *head) {
//	ListNode *p = head;
//	ListNode *q = head->next;
//	int valKey = head->val;
//	while (q != NULL) {
//		if (q->val<valKey)
//		{
//			p = p->next;
//			swap(p->val, q->val);
//		}
//		q = q->next;
//	}
//	swap(head->val, p->val);
//
//	return head;
//}

//�������������
//��Ϊ�����������ҵ�����ķָ��(����߶�����С���ұ߶�������ĵ�)��Ȼ���Էָ��Ϊ�����ڽ��зָ���������ÿ�
//1���Ȱ����ݽ��зֿ�
ListNode* getPartion(ListNode *PBegin, ListNode *PEnd) {
	ListNode *p = PBegin;
	ListNode *q = PBegin->next;
	int valKey = PBegin->val;
	while (q!=PEnd)
	{
		if (q->val<valKey)
		{
			p = p->next;
			swap(p->val, q->val);
		}
		q = q->next;
	}
	swap(PBegin->val, p->val);//�ѱ�־�㽻�����м䣬ʵ����߶��Ǳ���С�ģ��ұ߶��Ǳ�����ġ�

	return p;
}

//2�����еݹ���ʽ�Ķ�ÿһ�����ٽ��зֿ飬���õ���������С�
ListNode* Quicksort(ListNode *PBegin, ListNode *PEnd)
{
	if (PBegin!=PEnd)
	{
		ListNode *partion = getPartion(PBegin, PEnd);
		Quicksort(PBegin, partion);
		Quicksort(partion->next, PEnd);
		
	}
	return PBegin;
}

/****************************************************
ʱ�䣺2016��6��2��   20��03��30��
ע�ͣ�������Ĺ鲢����   Internet
***************************************************/
//1����ȡ��������е㣬ʵ�ֶԵ������Ȼ��֣����ں���ıȽϹ鲢��
ListNode* getMid(ListNode *head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *preEnd = NULL;
	while (fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		if (fast == NULL||fast->next == NULL)
		{
			preEnd = slow;
		}
		slow = slow->next;
	}
	preEnd->next = NULL;
	return slow;
}
//2��д����������ĺϲ��㷨
ListNode* mergeTwoList(ListNode *l1, ListNode *l2) {
	ListNode newHead(-1);
	ListNode *newPointer = &newHead;
	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			newPointer->next = l1;
			newPointer = newPointer->next;
			l1 = l1->next;
		}
		else
		{
			newPointer->next = l2;
			newPointer = newPointer->next;
			l2 = l2->next;
		}
	}
	while (l1)
	{
		newPointer->next = l1;
		newPointer = newPointer->next;
		l1 = l1->next;
	}
	while (l2)
	{
		newPointer->next = l2;
		newPointer = newPointer->next;
		l2 = l2->next;
	}
	return newHead.next;
}
//3�����еݹ�Ĺ鲢���򣬲��ϵĻ��ֵ�����Ȼ������һ���кϲ���
ListNode* mergeSort(ListNode *head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	ListNode *nextHead = getMid(head);
	ListNode *l1 = mergeSort(head);
	ListNode *l2 = mergeSort(nextHead);
	ListNode *res = mergeTwoList(l1, l2);
	return res;
}


ListNode* sortList(ListNode* head) {
	return mergeSort(head);
}
int main()
{
	ListNode head(-1);
	ListNode *p = &head;
	vector<int> vals = { 5,4,6,8,0,1,3,2,7 };
	fstream file;
	file.open("TestCode.txt");
	if (file)
	{
		string line;
		while (getline(file, line))
		{
			int num;
			istringstream in(line);
			while (in >> num)
			{
				vals.push_back(num);
			}
		}
		file.close();
		file.clear();
	}
	else
		cout << "���ļ�ʧ��" << endl;

	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}

	
	//auto res = sortList(head.next);
	//auto res = getPartion(head.next, NULL);
	//���ŵ�ʱ�临�ӶȲ�����Ҫ��
	long start, end;
	start = clock();
	auto res = Quicksort(head.next, NULL);
	end = clock();
	cout << "��������ʱ�䣺"<<(end - start)<< endl;
	cout << "������������";
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	
	//�鲢����
	long start2, end2;
	start2 = clock();
	auto resMergeSort = mergeSort(head.next);
	end2 = clock();
	cout << "�鲢����ʱ�䣺" << (end2 - start2) << endl;;
	cout << "�鲢��������";
	for (auto itr = resMergeSort; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

