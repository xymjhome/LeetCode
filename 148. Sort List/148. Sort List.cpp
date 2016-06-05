// 148. Sort List.cpp : 定义控制台应用程序的入口点。
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
时间：2016年6月2日   14点52分13秒
注释：Myself + Internet     快速排序时间复杂度过高，对于链表而言
***************************************************/
//表面上看，能够有O(n lgn)时间复杂度的算法为，快速排序，堆排序，归并排序，三者的空间复杂度分别为O(1), O(N), O(N)
//所以一开始，我想着用快速排序的方法来解决，但是发现代码很难写出来。于是网上看了一下提示，发现其实方法选错了。应该使用的方法是归并排序。
//
//通常而言，也就是针对数组而言，归并排序的空间复杂度为O(N), 你需要开出O(N)的额外空间来容纳数组，来表示归并后的顺序。但是，对于链表而言，你可以省下这部分空间的开销，你只需要改变节点的next指针的指向，就可以表示新的归并后的顺序了，所以空间复杂度陡然降到了O(1)。

//归纳一下，就是说，如果待排序的元素存储在数组中，那么快速排序相对归并排序就有两个原因更快。一是，可以很快地进行元素的读取(相对于链表，数组的元素是顺序摆放的，而链表的元素是随机摆放的)，数组的partion这步就比链表的partion这步快。二是，归并排序在merge阶段需要辅助数组，需要申请O(N)的空间，申请空间也是需要时间的。而快排不需要额外申请空间。如果待排序的元素存储在链表中，快排的优点就变成了缺点。归并排序于是就速度更优了。



//和数组快速排序中相同，先把数据进行分块，这里利用两个指针p和q，这两个指针均往next方向移动，移动的过程中保持p之前的key都小于选定的key，p和q之间的key都大于选定的key，那么当q走到末尾的时候便完成了一次支点的寻找。
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

//单链表快速排序：
//分为两步，首先找到链表的分割点(即左边都比他小，右边都比它大的点)，然后以分割点为左右在进行分割，即继续调用快
//1、先把数据进行分块
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
	swap(PBegin->val, p->val);//把标志点交换到中间，实现左边都是比他小的，右边都是比它大的。

	return p;
}

//2、进行递归形式的对每一个块再进行分块，最后得到有序的序列。
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
时间：2016年6月2日   20点03分30秒
注释：单链表的归并排序   Internet
***************************************************/
//1、获取单链表的中点，实现对单链表先划分，便于后面的比较归并。
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
//2、写两个单链表的合并算法
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
//3、进行递归的归并排序，不断的划分单链表，然后再逐一进行合并。
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
		cout << "打开文件失败" << endl;

	for (int i = 0; i < vals.size(); i++) {
		p->next = new ListNode(vals[i]);
		p = p->next;
	}

	
	//auto res = sortList(head.next);
	//auto res = getPartion(head.next, NULL);
	//快排的时间复杂度不满足要求
	long start, end;
	start = clock();
	auto res = Quicksort(head.next, NULL);
	end = clock();
	cout << "快速排序时间："<<(end - start)<< endl;
	cout << "快速排序结果：";
	for (auto itr = head.next; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	
	//归并排序
	long start2, end2;
	start2 = clock();
	auto resMergeSort = mergeSort(head.next);
	end2 = clock();
	cout << "归并排序时间：" << (end2 - start2) << endl;;
	cout << "归并排序结果：";
	for (auto itr = resMergeSort; itr != NULL; itr = itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

