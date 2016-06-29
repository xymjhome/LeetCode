// 56. Merge Intervals.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].

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
ʱ�䣺2016��6��13��   11��41��54��
ע�ͣ�Myself   �о��Լ��ķ�����Ȼ�ܳ��𰸣����Ƿ����ܷ�������������Ч�ʵ�    You are here!  Your runtime beats 15.21% of cppsubmissions.
	���������Ϸ���������������Լ������Ĳ��������
***************************************************/
vector<Interval> merge(vector<Interval>& intervals) {
	Interval temp(0, 0);
	vector<Interval> tempVec;
	if (intervals.size()==0)
	{
		return tempVec;
	}
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
	for (int i = 0;i<intervals.size();i++)
	{
		cout << "[" << intervals[i].start << "," << intervals[i].end << "] ";
	}
	cout << endl;
	if (intervals.size() == 1)
	{
		tempVec.push_back(intervals[0]);
	}
	for (int i = 0; i < intervals.size()-1; i++)
	{
		if (intervals[i].end<intervals[i+1].start)
		{
			temp.start = intervals[i].start;
			temp.end = intervals[i].end;
			tempVec.push_back(temp);
			if (i+1== intervals.size() - 1)
			{
				tempVec.push_back(intervals[i + 1]);
			}
		}
		else
		{
			if (intervals[i].end>intervals[i + 1].end)
			{
				temp.start = intervals[i].start;
				temp.end = intervals[i].end;
				intervals[i + 1] = temp;
				if (i + 1 == intervals.size() - 1)
				{
					tempVec.push_back(intervals[i + 1]);
				}
			}
			else
			{
				temp.start = intervals[i].start;
				temp.end = intervals[i+1].end;
				intervals[i + 1] = temp;
				if (i + 1 == intervals.size() - 1)
				{
					tempVec.push_back(intervals[i + 1]);
				}
			}
		}
	}
	for (int i = 0; i < tempVec.size(); i++)
	{
		cout << "[" << tempVec[i].start << "," << tempVec[i].end << "] ";
	}
	cout << endl;
	return tempVec;
}
//Internet_1
//��1���Ƚ�Ŀ���������鰴X���С�����������磺[2, 3][1, 2][3, 9] ->[1, 2][2, 3][3, 9]
//��2��ɨ��������Ŀ���������飬����Щ����ϲ������ɸ������ཻ�����䡣����[2, 3][1, 2][4, 9] ->[1, 3][4, 9]
//��������������
//a : [1, 3] [2, 6] ->[1, 6] ��һ�������end���ڵ��ڵڶ��������start, ͬʱ�ڶ��������end���ڵ�һ�������end
//	b : [1, 7] [2, 4] ->[1, 7] ��һ�������end���ڵ��ڵڶ��������start, ͬʱ�ڶ��������endС�ڵ�һ�������end
//	c : [1, 2] [3, 4] ->[1, 2][3, 4] ��һ�������endС�ڵڶ��������start

// �ȽϺ���   You are here!  Your runtime beats 28.19% of cppsubmissions.
//static bool cmp(const Interval& ina, const Interval& inb) {
//	return ina.start < inb.start;
//}
//vector merge(vector &intervals) {
//	vector result;
//	int count = intervals.size();
//	if (count <= 1) {
//		return intervals;
//	}//if
//	 // x������
//	sort(intervals.begin(), intervals.end(), cmp);
//	// �ϲ�
//	result.push_back(intervals[0]);
//	// ����3�����
//	for (int i = 1; i < count; i++) {
//		Interval preIn = result.back();
//		Interval curIn = intervals[i];
//		// [1,3] [2,6]
//		if (curIn.start <= preIn.end && curIn.end > preIn.end) {
//			preIn.end = curIn.end;
//			result.pop_back();
//			result.push_back(preIn);
//		}//if
//		 // [1,2] [3,4]
//		else if (curIn.start > preIn.end) {
//			result.push_back(curIn);
//		}
//		// [1,7] [2,3] �������κ���
//	}//for
//	return result;
//}



//Internet_2
//static int compare_Interval(Interval val1, Interval val2) {
//
//	return val1.start < val2.start;
//}
//vector<Interval> merge(vector<Interval>& intervals) {
//	vector<Interval> result;
//
//	if (intervals.size() <= 1) {
//		return  intervals;
//	}
//	sort(intervals.begin(), intervals.end(), compare_Interval);
//	Interval node = intervals[0];
//	for (int index = 1; index < intervals.size(); index++) {
//		Interval tmp = intervals[index];
//		if (tmp.start > node.end) {
//			result.push_back(node);
//			node = tmp;
//			continue;
//		}
//		else {
//			node.end = max(tmp.end, node.end);
//		}
//	}
//	result.push_back(node);
//	return result;
//}

//Internet +  Myself  You are here!   Your runtime beats 28.19% of cppsubmissions.
vector<Interval> merge2(vector<Interval>& intervals) {
	vector<Interval> result;
	if (intervals.size() <= 1)
	{
		return intervals;
	}
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
	Interval node = intervals[0];
	for (int i=1;i<intervals.size();i++)
	{
		Interval tempNode = intervals[i];
		if (node.end<tempNode.start)
		{
			result.push_back(node);
			node = tempNode;
			continue;
		}
		else
		{
			node.end = max(node.end, tempNode.end);
		}
	}
	result.push_back(node);//���ڿ������һ���ڵ�����
	return result;
}


int main()
{
	//Given[1, 3], [2, 6], [8, 10], [15, 18]
	Interval a1(1, 3);
	Interval a2(2, 6);
	Interval a3(8, 10);
	Interval a4(15, 18);
	vector<Interval> interval;
	interval.push_back(a1);
	interval.push_back(a2);
	interval.push_back(a3);
	interval.push_back(a4);

	auto res = merge2(interval);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[" << res[i].start << "," << res[i].end << "] ";
	}
	cout << endl;
	system("pause");
    return 0;
}

