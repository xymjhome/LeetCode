// 138. Copy List with Random Pointer.cpp : 定义控制台应用程序的入口点。
//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

//分析：
//我们知道如果是简单的copy List 的话，那么我们只需要从头到尾遍历下来，new出对应个数的Node，并把它们的连接关系设置好就可以了，但是这道题目中每个节点Node出现了Random属性，也就意味着可能当前结点Node所依赖的那个Random对应的结点还没有被创建出来。
//
//解题思路：
//为了解决“分析”里提到的问题，我们需要做如下三步处理！
//1. 在OldList中的每个结点后，插入一个CopyNode，这个结点的Random域和Next域与OldList中的被拷贝Node的Random域和Next一致，然后让被拷贝结点的Next域指向CopyNode结点，这样先创建出OldList中结点对应的CopyNode结点。
//2. 由于所有的CopyNode都已经创建出来了，我们就可以调整这些CopyNode真正的Random域的值了。

//3. 调整所有CopyNode的Next域的值，恢复OldList所有Node的Next的值到初始状态！-------此点特别注意，要恢复原链表！！！！！
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
时间：2016年5月30日   10点27分05秒
注释：Myself   虽然在AC上测试过了，效率不高，但是自己感觉是错的的，因为节点值得比较并不能代表地址，当单项链表中出现两个想的值得节点时会出错，不能指向真正的random节点。---------------------方法不好！！！效率低
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
		//	/*for (auto itr = newHead; itr != NULL; itr = itr->next)这中强制暴力复制的值比较方法不能正确的代表地址（当出现重复值时，地址不唯一）
		//	{
		//		if (oldItr->random->label==itr->label)
		//		{
		//			tempRandom = itr;
		//		}
		//	}
		//	newItr->random = tempRandom;*/
		//}
		//换位对地址索引的比较,每次都从旧的头开始寻找random不为空的值与其相等，所以时间复杂度高。------不用记忆理解学习
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

//Myself +  Online thinking  思路图见..NotePad/138. Copy List with Random Pointer_解法1    此方法虽然效率高，容易找到复制后random对应的节点，但是要想恢复以前的单链表的结果比较麻烦，需要用空间换时间，先存储起来原链表的结构，最后再进行恢复。---------------------方法不好！！！效率虽然高了，但是恢复原链表难。
//此题的另外一个难点就是要回复原来链表
//1、构建新链表的random指针：比如new1->random = new1->random->random->next, new2->random = NULL, new3 - random = NULL, new4->random = new4->random->random->next
//
//2、恢复原始链表：根据最开始保存的原始链表next指针映射关系恢复原始链表
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
	//设置new list的random指针
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
	//恢复old list的next指针
	for (int i = 1; i < nextPointer.size(); i++)
	{
		oldItr->next = nextPointer[i];
		oldItr = oldItr->next;
	}
	oldItr->next = NULL;
	return newHead;
}

//好好方法
//Myself +  Online thinking  思路图见..NotePad/138. Copy List with Random Pointer_解法2
//1、构建新节点random指针：new1->random = old1->random->next, new2 - random = NULL, new3 - random = NULL, new4->random = old4->random->next
//
//2、恢复原始链表以及构建新链表：例如old1->next = old1->next->next, new1->next = new1->next->next
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
	//1、构建新节点random指针：new1->random = old1->random->next, new2 - random = NULL, new3 - random = NULL, new4->random = old4->random->next
	RandomListNode *oldItr = head;
	while (oldItr)//此处的条件判断很重要，用旧的头依次向后移动并判断
	{
		if (oldItr->random)
		{
			oldItr->next->random = oldItr->random->next;
		}
		oldItr = oldItr->next->next;//只要oldItr不为空，oldItr->next就不会为空，因为可定后面有复制的元素
	}
	//2、恢复原始链表以及构建新链表：例如old1->next = old1->next->next, new1->next = new1->next->next
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

