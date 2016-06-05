// 234. Palindrome Linked List.cpp : 定义控制台应用程序的入口点。
//
//Given a singly linked list, determine if it is a palindrome(回文).
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
时间：2016年5月23日   11点04分06秒
注释：Internet
	  解法一： 一次遍历，装入vector，然后再一次遍历判断回文。时间复杂度O(n)，空间复杂度O(n)
	  解法二：找到链表中点，拆分后，逆转后半个链表，然后两个链表同时顺序遍历一次。若链表长度为奇数，最末尾的元素可以忽略。时间复杂度O(n)，空间复杂度O(1)
	  解法三：递归算法。【（1）比较朴素的算法。由于给定的数据结构是单链表，要访问链表的尾部元素，必须从头开始遍历。为了方便判断，我们可以申请一个辅助栈结构来存储链表的内容，第一次遍历将链表节点值依次入栈，第二次遍历比较判断是否为回文。
	  （2). 时间O(n)和空间O(1)解法。既然用到了栈，可以想到递归的过程本身就是出入栈的过程，我们可以先递归访问单链表，然后做比较。这样就省去了辅助空间，从而将空间复杂度降为O(1)】
	  Myself
		将回文联表构成一个环。
***************************************************/


/****************************************************************************************************************
时间：2016年5月23日   20点36分29秒
注释：自己想法，但是Time Limit Exceeded  估计中间的循环次数过多
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

//解法一： 一次遍历，装入vector，然后再一次遍历判断回文。时间复杂度O(n)，空间复杂度O(n)
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


//解法二：找到链表中点，拆分后，逆转后半个链表，然后两个链表同时顺序遍历一次。若链表长度为奇数，最末尾的元素可以忽略。时间复杂度O(n)，空间复杂度O(1)
ListNode *getMidLisNode(ListNode *head) {
	/*一次遍历, 查找不定长链表中点:
		1. 使用两个指针进行遍历, 快指针每次步进2, 慢指针每次步进1.
		2. 当快指针到达链表尾部的时候, 慢指针指向的就是链表的中点*/
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
	//利用递归实现链表的反转
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
	//获取单链表的中点
	ListNode *midLisNode = getMidLisNode(head);

	ListNode *secondHead = midLisNode->next;
	midLisNode->next = NULL;

	//反转第二个链表
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

//解法三：递归算法。【（1）比较朴素的算法。由于给定的数据结构是单链表，要访问链表的尾部元素，必须从头开始遍历。为了方便判断，我们可以申请一个辅助栈结构来存储链表的内容，第一次遍历将链表节点值依次入栈，第二次遍历比较判断是否为回文。
//（2).时间O(n)和空间O(1)解法。既然用到了栈，可以想到递归的过程本身就是出入栈的过程，我们可以先递归访问单链表，然后做比较。这样就省去了辅助空间，从而将空间复杂度降为O(1)】

ListNode* listHead = NULL;
bool flag = true;
//Myself   每次都返回头结点，这种和直接返回程序结果还是有差距，应该向Internet上一样，直接根据根据递归从后往前比较链表元素是否相等的真假值来控制递归函数的递归。   但是这种方法减少了一半链表的比较操作。
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


////解法三：递归算法。Internet  +  Myself
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
	//return true;//不加此句话表示每次递归时如果比较元素相等则没有返回值，函数没有返回值是错误的。Run Code Status: Compile Error（编译错误） : control reaches end of non-void function [-Werror=return-type]
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

