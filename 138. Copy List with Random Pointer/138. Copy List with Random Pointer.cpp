// 138. Copy List with Random Pointer.cpp : �������̨Ӧ�ó������ڵ㡣
//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

//������
//����֪������Ǽ򵥵�copy List �Ļ�����ô����ֻ��Ҫ��ͷ��β����������new����Ӧ������Node���������ǵ����ӹ�ϵ���úþͿ����ˣ����������Ŀ��ÿ���ڵ�Node������Random���ԣ�Ҳ����ζ�ſ��ܵ�ǰ���Node���������Ǹ�Random��Ӧ�Ľ�㻹û�б�����������
//
//����˼·��
//Ϊ�˽�������������ᵽ�����⣬������Ҫ��������������
//1. ��OldList�е�ÿ�����󣬲���һ��CopyNode���������Random���Next����OldList�еı�����Node��Random���Nextһ�£�Ȼ���ñ���������Next��ָ��CopyNode��㣬�����ȴ�����OldList�н���Ӧ��CopyNode��㡣
//2. �������е�CopyNode���Ѿ����������ˣ����ǾͿ��Ե�����ЩCopyNode������Random���ֵ�ˡ�

//3. ��������CopyNode��Next���ֵ���ָ�OldList����Node��Next��ֵ����ʼ״̬��-------�˵��ر�ע�⣬Ҫ�ָ�ԭ������������
#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;


struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};

/****************************************************
ʱ�䣺2016��5��30��   10��27��05��
ע�ͣ�Myself   ��Ȼ��AC�ϲ��Թ��ˣ�Ч�ʲ��ߣ������Լ��о��Ǵ�ĵģ���Ϊ�ڵ�ֵ�ñȽϲ����ܴ����ַ�������������г����������ֵ�ýڵ�ʱ���������ָ��������random�ڵ㡣---------------------�������ã�����Ч�ʵ�
***************************************************/
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head==NULL)
	{
		return NULL;
	}
	RandomListNode *p = head;
	RandomListNode *newHead = new RandomListNode(head->label);
	RandomListNode *q=newHead;
	while (p&&p->next)
	{
		p = p->next;
		q->next = new RandomListNode(p->label);
		q = q->next;
	}
	RandomListNode *oldItr = head;
	RandomListNode *newItr = newHead;
	while (oldItr)
	{
		RandomListNode *newRandomIndex = newHead;
		RandomListNode *oldRandomIndex = head;
		//RandomListNode *tempRandom = NULL;
		if (oldItr->random==NULL)
		{
			newItr->random = NULL;
		}
		//if (oldItr->random != NULL)
		//{
		//	/*for (auto itr = newHead; itr != NULL; itr = itr->next)����ǿ�Ʊ������Ƶ�ֵ�ȽϷ���������ȷ�Ĵ����ַ���������ظ�ֵʱ����ַ��Ψһ��
		//	{
		//		if (oldItr->random->label==itr->label)
		//		{
		//			tempRandom = itr;
		//		}
		//	}
		//	newItr->random = tempRandom;*/
		//}
		//��λ�Ե�ַ�����ıȽ�,ÿ�ζ��Ӿɵ�ͷ��ʼѰ��random��Ϊ�յ�ֵ������ȣ�����ʱ�临�Ӷȸߡ�------���ü������ѧϰ
		else {
			while (oldItr->random!= oldRandomIndex)
			{
				oldRandomIndex = oldRandomIndex->next;
				newRandomIndex = newRandomIndex->next;
			}
			newItr->random = newRandomIndex;
		}
		oldItr = oldItr->next;
		newItr = newItr->next;
	}
	return newHead;
}

//Myself +  Online thinking  ˼·ͼ��..NotePad/138. Copy List with Random Pointer_�ⷨ1    �˷�����ȻЧ�ʸߣ������ҵ����ƺ�random��Ӧ�Ľڵ㣬����Ҫ��ָ���ǰ�ĵ�����Ľ���Ƚ��鷳����Ҫ�ÿռ任ʱ�䣬�ȴ洢����ԭ����Ľṹ������ٽ��лָ���---------------------�������ã�����Ч����Ȼ���ˣ����ǻָ�ԭ�����ѡ�
//���������һ���ѵ����Ҫ�ظ�ԭ������
//1�������������randomָ�룺����new1->random = new1->random->random->next, new2->random = NULL, new3 - random = NULL, new4->random = new4->random->random->next
//
//2���ָ�ԭʼ���������ʼ�����ԭʼ����nextָ��ӳ���ϵ�ָ�ԭʼ����
RandomListNode *copyRandomList2(RandomListNode *head) {
	if (head == NULL)
	{
		return NULL;
	}
	vector<RandomListNode*> nextPointer;
	RandomListNode *temp = head;
	while (temp)
	{
		nextPointer.push_back(temp);
		temp = temp->next;
	}
	RandomListNode *p = head;
	RandomListNode *newHead = new RandomListNode(head->label);
	RandomListNode *q = newHead;
	while (p&&p->next)
	{
		q->random = p;
		RandomListNode *pNext = p->next;
	    p->next = q;
		q->next = new RandomListNode(pNext->label);
		q = q->next;
		p = pNext;
	}
	q->random = p;
	p->next = q;

	
	RandomListNode *newItr = newHead;
	//����new list��randomָ��
	while (newItr)
	{
		if (newItr->random->random==NULL)
		{
			newItr->random = NULL;
		}
		else
		{
			newItr->random = newItr->random->random->next;
		}
		newItr = newItr->next;
	}
	RandomListNode *oldItr = head;
	//�ָ�old list��nextָ��
	for (int i = 1; i < nextPointer.size(); i++)
	{
		oldItr->next = nextPointer[i];
		oldItr = oldItr->next;
	}
	oldItr->next = NULL;
	return newHead;
}

//�ú÷���
//Myself +  Online thinking  ˼·ͼ��..NotePad/138. Copy List with Random Pointer_�ⷨ2
//1�������½ڵ�randomָ�룺new1->random = old1->random->next, new2 - random = NULL, new3 - random = NULL, new4->random = old4->random->next
//
//2���ָ�ԭʼ�����Լ���������������old1->next = old1->next->next, new1->next = new1->next->next
RandomListNode *copyRandomList3(RandomListNode *head) {
	if (head == NULL)
	{
		return NULL;
	}
	RandomListNode *p = head;
	while (p)
	{
		RandomListNode *pNext = p->next;
		RandomListNode *q = new RandomListNode(p->label);
		p->next = q;
		q->next = pNext;
		p = pNext;
	}
	//1�������½ڵ�randomָ�룺new1->random = old1->random->next, new2 - random = NULL, new3 - random = NULL, new4->random = old4->random->next
	RandomListNode *oldItr = head;
	while (oldItr)//�˴��������жϺ���Ҫ���þɵ�ͷ��������ƶ����ж�
	{
		if (oldItr->random)
		{
			oldItr->next->random = oldItr->random->next;
		}
		oldItr = oldItr->next->next;//ֻҪoldItr��Ϊ�գ�oldItr->next�Ͳ���Ϊ�գ���Ϊ�ɶ������и��Ƶ�Ԫ��
	}
	//2���ָ�ԭʼ�����Լ���������������old1->next = old1->next->next, new1->next = new1->next->next
	RandomListNode *newHead = head->next;
	RandomListNode *new2 = head->next;
	RandomListNode *old2 = head;
	while (new2->next!=NULL)
	{
		old2->next = old2->next->next;
		old2 = old2->next;
		new2->next = new2->next->next;
		new2 = new2->next;
	}
	old2->next = NULL;
	new2->next = NULL;
	return newHead;
}
int main()
{
	RandomListNode head(-1);
	RandomListNode *p = &head;
	vector<int> vals = { 1,2,3,4,5,6,6,7 };
	for (int i = 0; i < vals.size(); i++) {
		p->next = new RandomListNode(vals[i]);
		p = p->next;
	}
	RandomListNode *tempPointer = &head;
	RandomListNode *one=NULL, *three=NULL, *six=NULL;
	for (int i = 0;i<7;i++)
	{
		tempPointer = tempPointer->next;
		if (i==0)
		{
			one = tempPointer;
		}
		else if (i==2)
		{
			three = tempPointer;
		}
		else if (i==5)
		{
			six = tempPointer;
		}
	}
	one->random = three;
	three->random = six;
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr << " ";
		if (itr->random!=NULL)
		{
			cout << "random:" << itr->random << " ";
		}
	}
	cout << endl;

	auto res = copyRandomList3(head.next);
	for (auto itr = res; itr != NULL; itr = itr->next)
	{
		cout << itr << " ";
		if (itr->random != NULL)
		{
			cout << "random:" << itr->random << " ";
		}
	}

	system("pause");
    return 0;
}

