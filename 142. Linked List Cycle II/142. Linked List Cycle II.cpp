// 142. Linked List Cycle II.cpp : 定义控制台应用程序的入口点。
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
时间：2016年5月16日   22点07分45秒
注释：Myelf    自己写的方法是：如果单链表存在环，则利用快慢指针，当快指针等于慢指针时证明链表环存在，这个时候把链表从相遇点处切断，生成两个单链表，然后用两个count分别记录两个单链表到相遇点的距离，算出二者距离差，然后长的向后移动相对距离的长度，最后让两个链表一次向后走，当指针多只对象相同时即是环的起始点。-----------自己理解的方法没有总结规律，太笨拙！@！！！
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
	while (head!=NULL&&tempHead1!=NULL)//第一次提交控制条件head->next!=NULL&&tempHead1->next!=NULL错误，导致不能正确的返回环的起始点
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
时间：2016年5月16日   22点15分01秒
注释：Internet + Myself      理解网上的代码的思想，重写此题代码。
	  网上思想：对单恋表快慢指针相遇后，相遇点到环起始点，以及单链表头到环起始点的距离进行总结，可以得到如下结论——相遇点到环起始点的距离和链表头到环起始点的距离相同（不带链表头结点）；相遇点到环起始点的距离和链表头到环起始点的距离相差1（带链表头结点，因为ListNode head(-1);会增加1个距离）。
	  切记此结论是从相遇点起算起到环起始点的距离，以及快指针是慢指针的2倍移动速度。
	  切记要是想用相等距离，一定从带链表真实值的第一个节点作为头结点。



	  Example:
	  图中：        X     a      Y    b    Z
	                -------------|---------| 
                                 |         |
								 |---------| 
	                              c
	  X是链表的起点。   
	  Y是环的起点。
	  Z是fast和slow首次相遇的地方（二者同时从X出发，slow每次移动一步，fast每次移动两步）。
	  a, b, c分别表示XY（蓝色）, YZ（红色）, ZY（绿色）的长度。

	  当fast和slow在Z点首次相遇时：

	  fast移动的距离是：a + b + c + b
	  slow移动的距离是：a + b

	  因为fast的移动速度是slow的两倍，所以：

	  (a + b + c + d) == 2 * (a + b)

	  由此可以推出：

	  a == c

	  我们需要用上面的推论来寻找环的起点（Y）。

	  当fast和slow首次相遇时，我们就到了Z点。

	  由于a == c，也就是X到Y 与 Z到Y的距离相等。

	  因此，如果我们让指针p和q分别从X和Z出发，并且每次都移动一步，当它们相遇时，恰好就是环的起点Y。
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

