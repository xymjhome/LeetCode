// 57. Insert Interval.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//You may assume that the intervals were initially sorted according to their start times.��ʼ����ʼʱ���Ź���
//Example 1:
//Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//Example 2 :
//	Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//
//	This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].
#include "stdafx.h"

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


/**
* Definition for an interval.
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/****************************************************
ʱ�䣺2016��6��13��   18��46��29��
ע�ͣ�Myself  You are here!   Your runtime beats 17.04% of cppsubmissions.
***************************************************/
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	if (intervals.size()<1)
	{
		intervals.push_back(newInterval);
		return intervals;
	}
	intervals.push_back(newInterval);
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
	vector<Interval> result;
	Interval node = intervals[0];
	for (int i=1;i<intervals.size();i++)
	{
		Interval tempNode = intervals[i];
		if (node.end < tempNode.start)
		{
			result.push_back(node);
			node = tempNode;
			continue;
		}
		else
			node.end = max(node.end, tempNode.end);
	}
	result.push_back(node);
	return result;

}
//Internet
//������Ҫ���Ǹ���һ����ص��ҿ�ʼʱ������ļ���������в���һ���µļ����
//��Ȼ���������Խ���Merge Intervals����Ĵ��룬�Ƚ��µļ�����뵽�����У�Ȼ��ϲ����ɡ�ʱ�临�Ӷ���O(nlogn)��
//��ʵ�ϣ�Ҳ���Բ�����ֱ�Ӳ���ʱ�����������ʱ������λ�ÿ��Էֳ������֣�
//����λ�����
//����λ�ã����ص������ص���
//����λ���Ҳ�
//���������ֱַ���ֻ���ڲ���λ�ô�����ܴ��ڵ�������ɡ�
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(n)
//vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
//5     {
//	6         vector<Interval> vi;
//	7
//		8         int i = 0;
//	9         while (i < intervals.size() && intervals[i].end < newInterval.start)
//		10             vi.push_back(intervals[i++]);
//	11
//		12         vi.push_back(newInterval);
//	13         while (i < intervals.size() && vi[vi.size() - 1].end >= intervals[i].start)
//		14         {
//		15             vi[vi.size() - 1].start = min(intervals[i].start, vi[vi.size() - 1].start);
//		16             vi[vi.size() - 1].end = max(intervals[i].end, vi[vi.size() - 1].end);
//		17             ++i;
//		18         }
//	19
//		20          while (i < intervals.size())
//		21             vi.push_back(intervals[i++]);
//	22
//		23         return vi;
//	24     }

//Internet  +  Myself   You are here!  Your runtime beats 54.86% of cppsubmissions.
//�˷�Ч�ʸߣ���Ϊ�Լ��ķ���û�п��ǵ�û�в�������ǰ��������������ģ���������56��Merge intercals�ķ��������ʱ�临�Ӷȸߡ������䡣����
vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
	if (intervals.empty())
	{
		intervals.push_back(newInterval);
		return intervals;
	}
	vector<Interval> result;
	int i = 0;
	while (i < intervals.size()&&intervals[i].end<newInterval.start)
	{
		result.push_back(intervals[i]);
		i++;
	}
	result.push_back(newInterval);
	while (i<intervals.size()&&result[result.size()-1].end>=intervals[i].start)
	{
		result[result.size() - 1].start = min(result[result.size() - 1].start, intervals[i].start);
		result[result.size() - 1].end = max(result[result.size() - 1].end, intervals[i].end);
		i++;
	}
	while (i<intervals.size())
	{
		result.push_back(intervals[i]);
		i++;
	}
	return result;
}
int main()
{
	//[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]
	Interval a1(1, 2);
	Interval a2(3, 5);
	Interval a3(6, 7);
	Interval a4(8, 10);
	Interval a5(12, 16);
	vector<Interval> interval;
	interval.push_back(a1);
	interval.push_back(a2);
	interval.push_back(a3);
	interval.push_back(a4);
	interval.push_back(a5);

	//[4, 9]
	Interval   insertValue(4, 9);
	auto res = insert2(interval,insertValue);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[" << res[i].start << "," << res[i].end << "] ";
	}
	cout << endl;
	system("pause");
    return 0;
}

