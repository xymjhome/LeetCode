// 23. Merge k Sorted Lists.cpp : �������̨Ӧ�ó������ڵ㡣
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
ʱ�䣺2016��6��4��   13��53��36��
ע�ͣ�Myself      ����ʱ����ߣ��˷�����You are here!   Your runtime beats 3.58% of cppsubmissions.
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
ʱ�䣺2016��6��6��   18��48��38��
ע�ͣ�Internet  +   Myself     
    ��ÿ������ı�ͷԪ��ȡ����������һ��С���ѣ���Ϊk�������ж��ź����ˣ����ÿ��ȡ�Ѷ���Ԫ�ؾ���k�������е���Сֵ�����Խ���ϲ����ϲ������У��ٽ����Ԫ�ص�ָ��ָ�����һ��Ԫ��Ҳ���뵽���У��ٵ����ѣ�ȡ���Ѷ����ϲ������������Դ����ƣ�ֱ����Ϊ��ʱ������ϲ���ϡ�
	��Ϊ����ϰ���ѵĹ��̣�������û����STL���make_heap�ȷ����������Լ�д�Ľ��Ѻ��������뿴��STL�Ľ��ѷ����ģ����Բο����ϴ𰸡�
    ���ѵ�ʱ�临�Ӷ���k/2logk, ÿ��ȡ���Ѷ��ټ���Ԫ�صĸ��Ӷ���logk,����ÿ������ƽ����n��Ԫ�أ���һ����nk-k�Ρ�����ܵ�ʱ�临�Ӷ�ΪO(nklogk)��
***************************************************/
//Internet               You are here!  Your runtime beats 67.68% of cppsubmissions.
// ����С����,�Ե�i��Ԫ��Ϊ������С����
//λ�ô�1��ʼ��ȡԪ��ʱ�ǵ�-1
// �Զ�����
void minHeap(vector<ListNode*> &heap, int i) {
	int l = i * 2;
	int r = l + 1;
	int least(i);
	// �����СԪ�ص�λ��
	if ((l < heap.size() + 1) && heap[l - 1]->val < heap[i - 1]->val) {
		// ���û�г����߽粢�����ӱȸ���С����
		least = l;
	}
	if (r < heap.size() + 1 && heap[r - 1]->val < heap[least - 1]->val) {
		// ���û�г����߽粢���Һ�����С����
		least = r;
	}
	if (least != i) {
		swap(heap[i - 1], heap[least - 1]);
		minHeap(heap, least);
	}
}
// ����С����
// �Ե�����
void makeHeap(vector<ListNode*> &heap) {
	// �����һ��Ԫ�صĸ��ڵ㿪ʼ����С����
	for (int i = heap.size() / 2; i > 0; i--) {
		minHeap(heap, i);
	}
}

// ��С�����в���һ��Ԫ��
// �Ե�����
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
// �����Ѷ�
ListNode* popHeap(vector<ListNode*> &heap) {
	swap(heap[0], heap[heap.size() - 1]);
	auto p = heap.back();
	heap.pop_back();
	minHeap(heap, 1);
	return p;
}

ListNode *mergeKLists3(vector<ListNode *> &lists) {
		// ʹ�ö�����, 
		// 1. ѡ��ÿ�������ͷ������С�����У�
		// 2. �ٰѶѶ�����ϲ������У�
		// 3. ��ѡ����ָ������ټ���С������,�ص�2
		// 4. �����������Ϊ��ʱ�����غϲ������ͷָ��
		if (lists.empty()) return nullptr;
		vector<ListNode* > heap;
		// 1. ѡ��ÿ�������ͷ������С�����У�
		for (int i = 0; i != lists.size(); i++) {
			if (lists[i]) heap.push_back(lists[i]);
		}
		makeHeap(heap);
		// 2. �ٰѶѶ�����ϲ������У�
		ListNode head(-1); // �ϲ�����ı�ͷ
		ListNode* p = &head;
		while (!heap.empty()) {
			auto minNode = popHeap(heap);
			p->next = minNode; // ��������
			p = p->next;
			// 3. ��ѡ����ָ������ټ���С������,�ص�2
			auto next = minNode->next;
			if (next) pushHeap(heap, next);
		}
		// 4. �����������Ϊ��ʱ�����غϲ������ͷָ��
		return head.next;
}



//Internet + Myself  
// ʹ�ö�����, 
	// 1. ѡ��ÿ�������ͷ������С�����У�
	// 2. �ٰѶѶ�����ϲ������У�
	// 3. ��ѡ����ָ������ټ���С������,�ص�2
	// 4. �����������Ϊ��ʱ�����غϲ������ͷָ��


void downElement(vector<ListNode*> &heap, int elementIndex);
//1��������
void creatHeap(vector<ListNode*> &heap) {
	for (int i = heap.size()/2-1;i>=0;i--)
	{
		downElement(heap, i);
	}
}
//2���³�Ԫ�أ���1�������ݵ������һ����Ҷ�ӽڵ������ʱ�������һ����Ҷ�ӽڵ㿪ʼ����ÿ�����ڵ㶼����Ϊ��С�ѣ����ǽ�����С�ѡ�
//             ��2�������ݵ��Ƕѵĵ�һ��Ԫ��ʱ������ȫ�������ĸ��ڵ����³����ǽ��ж����������С�ڵ�󣬼���������С�ѣ��������������������С�ѡ�
void downElement(vector<ListNode*> &heap,int elementIndex) {
	int min = 0;
	int index = elementIndex;
	while (2*index+1<heap.size())//�������ӽڵ�
	{
		min = 2 * index + 1;
		if (2*index+2<heap.size())//�����Һ��ӽڵ�
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

//�Ѷѵ���Ԫ�ص���
ListNode* popHeap2(vector<ListNode*> &heap) {
	auto temp = heap[0];
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downElement(heap, 0);
	return temp;
}
void pushHeap2(vector<ListNode*> &heap,ListNode *p) {
		heap.push_back(p);
		//1����Ҫ����ط����½������runtime��
	    // creatHeap(heap);
	    //2��Ч��Ҳ���Ǻܸ�
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
		//3��Ч����Ը�
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
		//creatHeap(heap);//���������ٴι�����С�ѻᳬʱ

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

