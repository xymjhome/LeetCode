// 206. Reverse Linked List.cpp : 定义控制台应用程序的入口点。
//
//Reverse a singly linked list.(！！！！！！反向单向链表：把整个链表反转，即最后一个节点是头结点)
//
//click to show more hints.
//Hint:
//
//A linked list can be reversed either iteratively(迭代) or recursively(递归).Could you implement both ?
//递归：直接或者间接的调用自己的算法。   用函数自身给出定义的函数称为递归函数。
//迭代：迭代法也称辗转法，是一种不断用变量的旧值递推新值的过程,跟迭代法相对应的是直接法（或者称为一次解法），即一次性解决问题。迭代法又分为精确迭代和近似迭代。“二分法”和“牛顿迭代法”属于近似迭代法。
//      迭代算法是用计算机解决问题的一种基本方法。它利用计算机运算速度快、适合做重复性操作的特点，让计算机对一组指令（或一定步骤）进行重复执行，在每次执行这组指令（或这些步骤）时，都从变量的原值推出它的一个新值。
 
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


//myself 提交代码时错误：Run Code Status : Runtime Error   自己理解的把值反转  题目的意思是把整个链表反转加上头结点
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


//下面两个方法都是实现整个单链表的反转，最后一个元素变为头结点
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
作者：刘江涛
时间：2016年5月10日   15点53分41秒
注释：得到数组的长度
****************************************************************************************************************/
template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}
int main()
{
	//初始化一个链表
	ListNode head(-1);
	ListNode *p = &head;
	int val[] = { 1,2,3,4,5,6,7,8 };
	cout << getArrayLen(val) << endl;
	for (int i=0;i<getArrayLen(val);i++)
	{
		/*ListNode temp(val[i]);此想法错误的，因为你定义的变量并不会重新申请内存地址，所以可能地址相同，直接被覆盖了
		p->next = &temp;*/
		p->next = new ListNode(val[i]);//添加链表新节点的正确方法
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


