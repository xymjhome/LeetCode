// 23. Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。
//
//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
#include "stdafx.h"

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
时间：2016年6月4日   13点53分36秒
注释：Myself      运行时间过高，此法不好You are here!   Your runtime beats 3.58% of cppsubmissions.
***************************************************/
ListNode* mergeList(ListNode *l1, ListNode *l2) {
	ListNode newHead(-1);
	ListNode *p = &newHead;
	while (l1!=NULL&&l2!=NULL)
	{
		if (l1->val<l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	while (l1)
	{
		p->next = l1;
		l1 = l1->next;
		p = p->next;
	}
	while (l2)
	{
		p->next = l2;
		l2 = l2->next;
		p = p->next;
	}
	return newHead.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n==0)
	{
		return NULL;
	}
	ListNode *newHead = NULL;
	for (int i = 0; i < n; i++)
	{
		 newHead = mergeList(lists[i],newHead); 
	}
	return newHead;
}


/****************************************************
时间：2016年6月6日   18点48分38秒
注释：Internet  +   Myself     
    将每个链表的表头元素取出来，建立一个小顶堆，因为k个链表中都排好序了，因此每次取堆顶的元素就是k个链表中的最小值，可以将其合并到合并链表中，再将这个元素的指针指向的下一个元素也加入到堆中，再调整堆，取出堆顶，合并链表。。。。以此类推，直到堆为空时，链表合并完毕。
	因为想练习建堆的过程，所以我没有用STL里的make_heap等方法，而是自己写的建堆函数。若想看用STL的建堆方法的，可以参考网上答案。
    建堆的时间复杂度是k/2logk, 每次取出堆顶再加入元素的复杂度是logk,假设每条链表平均有n个元素，则一共有nk-k次。因此总的时间复杂度为O(nklogk)。
***************************************************/
//Internet               You are here!  Your runtime beats 67.68% of cppsubmissions.
// 调整小顶堆,以第i个元素为根建立小顶堆
//位置从1开始，取元素时记得-1
// 自顶向下
void minHeap(vector<ListNode*> &heap, int i) {
	int l = i * 2;
	int r = l + 1;
	int least(i);
	// 算出最小元素的位置
	if ((l < heap.size() + 1) && heap[l - 1]->val < heap[i - 1]->val) {
		// 如果没有超过边界并且左孩子比父亲小，则换
		least = l;
	}
	if (r < heap.size() + 1 && heap[r - 1]->val < heap[least - 1]->val) {
		// 如果没有超过边界并且右孩子最小，则换
		least = r;
	}
	if (least != i) {
		swap(heap[i - 1], heap[least - 1]);
		minHeap(heap, least);
	}
}
// 建立小顶堆
// 自低向上
void makeHeap(vector<ListNode*> &heap) {
	// 从最后一个元素的父节点开始建立小顶堆
	for (int i = heap.size() / 2; i > 0; i--) {
		minHeap(heap, i);
	}
}

// 在小顶堆中插入一个元素
// 自低向上
void pushHeap(vector<ListNode*> &heap, ListNode* p) {
	heap.push_back(p);
	int child = heap.size();
	int parent = child / 2;
	for (int child = heap.size(), parent = child / 2; parent; child--, parent = child / 2) {
		if (heap[child - 1]->val < heap[parent - 1]->val) {
			swap(heap[child - 1], heap[parent - 1]);
		}
	}
}
// 弹出堆顶
ListNode* popHeap(vector<ListNode*> &heap) {
	swap(heap[0], heap[heap.size() - 1]);
	auto p = heap.back();
	heap.pop_back();
	minHeap(heap, 1);
	return p;
}

ListNode *mergeKLists3(vector<ListNode *> &lists) {
		// 使用堆排序, 
		// 1. 选出每个链表的头来插入小顶堆中，
		// 2. 再把堆顶接入合并链表中，
		// 3. 被选出的指针后移再加入小顶堆中,回到2
		// 4. 最后所有链表都为空时，返回合并链表的头指针
		if (lists.empty()) return nullptr;
		vector<ListNode* > heap;
		// 1. 选出每个链表的头来插入小顶堆中，
		for (int i = 0; i != lists.size(); i++) {
			if (lists[i]) heap.push_back(lists[i]);
		}
		makeHeap(heap);
		// 2. 再把堆顶接入合并链表中，
		ListNode head(-1); // 合并链表的表头
		ListNode* p = &head;
		while (!heap.empty()) {
			auto minNode = popHeap(heap);
			p->next = minNode; // 接入链表
			p = p->next;
			// 3. 被选出的指针后移再加入小顶堆中,回到2
			auto next = minNode->next;
			if (next) pushHeap(heap, next);
		}
		// 4. 最后所有链表都为空时，返回合并链表的头指针
		return head.next;
}



//Internet + Myself  
// 使用堆排序, 
	// 1. 选出每个链表的头来插入小顶堆中，
	// 2. 再把堆顶接入合并链表中，
	// 3. 被选出的指针后移再加入小顶堆中,回到2
	// 4. 最后所有链表都为空时，返回合并链表的头指针


void downElement(vector<ListNode*> &heap, int elementIndex);
//1、建立堆
void creatHeap(vector<ListNode*> &heap) {
	for (int i = heap.size()/2-1;i>=0;i--)
	{
		downElement(heap, i);
	}
}
//2、下沉元素：（1）当传递的是最后一个非叶子节点的索引时（从最后一个非叶子节点开始，将每个父节点都调整为最小堆），是建立最小堆。
//             （2）当传递的是堆的第一个元素时（即完全二叉树的根节点向下沉，是进行堆排序输出最小节点后，继续生成最小堆），堆排序过程中生成最小堆。
void downElement(vector<ListNode*> &heap,int elementIndex) {
	int min = 0;
	int index = elementIndex;
	while (2*index+1<heap.size())//存在左孩子节点
	{
		min = 2 * index + 1;
		if (2*index+2<heap.size())//存在右孩子节点
		{
			if (heap[2 * index + 2]->val<heap[min]->val)
			{
				min = 2 * index + 2;
			}	
		}
		if (heap[index]->val<heap[min]->val)
		{
			break;
		}
		else
		{
			swap(heap[index], heap[min]);
			index = min;
		}
	}
}

//把堆的首元素弹出
ListNode* popHeap2(vector<ListNode*> &heap) {
	auto temp = heap[0];
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downElement(heap, 0);
	return temp;
}
void pushHeap2(vector<ListNode*> &heap,ListNode *p) {
		heap.push_back(p);
		//1、主要这个地方重新建堆造成runtime低
	    // creatHeap(heap);
	    //2、效率也不是很高
		/*int child = heap.size();
		int parent = child / 2;
		while (parent)
		{
			if (heap[child-1]->val<heap[parent-1]->val)
			{
				swap(heap[child-1], heap[parent-1]);
			}
			child = parent;
			parent = child / 2;
		}*/
		//3、效率相对高
		int child = heap.size();
		int parent = child / 2;
		for (int child = heap.size(), parent = child / 2; parent; child--, parent = child / 2) {
			if (heap[child - 1]->val < heap[parent - 1]->val) {
				swap(heap[child - 1], heap[parent - 1]);
			}
		}
}
//You are here!  Your runtime beats 40.40% of cppsubmissions.
ListNode* mergeKLists2(vector<ListNode*>& lists) {
	vector<ListNode*> heap;
	for (int i = 0; i != lists.size(); i++) {
		if (lists[i]) heap.push_back(lists[i]);
	}
	if (heap.empty())
	{
		return NULL;
	}
	ListNode newHead(-1);
	ListNode *p = &newHead;
	creatHeap(heap);
	while (!heap.empty())
	{

		ListNode *minHeap = popHeap2(heap);
		p->next = minHeap;
		p = p->next;
		auto next = minHeap->next;
		if (next)
			pushHeap2(heap,next);
		//creatHeap(heap);//这种重新再次构建最小堆会超时

	}
	for (int i = 0; i < lists.size(); i++) {
		cout << lists[i]->val << " ";
	}
	cout << endl;
	for (auto res = newHead.next;res!=NULL;res = res->next)
	{
		cout << res->val << " ";
	}
	cout << endl;
	return newHead.next;
}
int main()
{

	ListNode head1(-1);
	ListNode *p = &head1;
	vector<int> vals1 = { 0,1,2,3,4,5 };
	for (int i = 0; i < vals1.size(); i++) {
		p->next = new ListNode(vals1[i]);
		p = p->next;
	}
	ListNode head2(-1);
	ListNode *p2 = &head2;
	vector<int> vals2 = { 5,6,7,8,9,10 };
	for (int i = 0; i < vals2.size(); i++) {
		p2->next = new ListNode(vals2[i]);
		p2 = p2->next;
	}
	ListNode head3(-1);
	ListNode *p3 = &head3;
	vector<int> vals3 = { -1, 1 };
	for (int i = 0; i < vals3.size(); i++) {
		p3->next = new ListNode(vals3[i]);
		p3= p3->next;
	}
	ListNode head4(-1);
	ListNode *p4 = &head4;
	vector<int> vals4 = { -3, 1, 4 };
	for (int i = 0; i < vals4.size(); i++) {
		p4->next = new ListNode(vals4[i]);
		p4 = p4->next;
	}
	ListNode head5(-1);
	ListNode *p5 = &head5;
	vector<int> vals5 = { -2, -1, 0, 2 };
	for (int i = 0; i < vals5.size(); i++) {
		p5->next = new ListNode(vals5[i]);
		p5 = p5->next;
	}
	vector<ListNode*> sortList;
	//sortList.push_back(head1.next);
	//sortList.push_back(head2.next);
	sortList.push_back(head3.next);
	sortList.push_back(head4.next);
	sortList.push_back(head5.next);
	
	auto res1 = mergeKLists2(sortList);
	for (auto itr = res1;itr!=NULL;itr= itr->next)
	{
		cout << itr->val << " ";
	}
	cout << endl;

	//ListNode head6(-1);
	//ListNode *p6 = &head6;
	//vector<int> vals6 = { 1 };
	//for (int i = 0; i < vals6.size(); i++) {
	//	p6->next = new ListNode(vals6[i]);
	//	p6 = p6->next;
	//}
	//vector<ListNode*> sortList2;
	//sortList2.push_back(head6.next);
	//auto res = mergeKLists3(sortList);
	//for (auto itr = res;itr!=NULL;itr= itr->next)
	//{
	//	cout << itr->val << " ";
	//}
	//cout << endl;
	system("pause");
	return 0;
}

