// 349. Intersection of Two Arrays.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given two arrays, write a function to compute their intersection��������.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
//
//Note :
//
//	Each element in the result must be unique.
//	The result can be in any order.
//����������Ľ�����Ԫ�ز����ظ���
#include "stdafx.h"
#include <vector>
#include <set>//set������Ԫ���ǲ��ظ���������
#include <iostream>
using namespace std;


/****************************************************
ʱ�䣺2016��6��7��   19��20��20��
ע�ͣ�Myself  
***************************************************/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() || nums2.empty()) {
		vector<int> nulls(0);
		return nulls;
	}
	vector<int> temp;
	set<int> temp1;
	set<int> temp2;
	set<int> temp3;
	temp1.insert(nums1.begin(), nums1.end());
	temp2.insert(nums2.begin(), nums2.end());
	//temp2.insert(nums2.begin(), nums2.end());
	//˫��forѭ�����Ч�ʺܵ�      ˫��forѭ�����Ч�ʺܵ�   You are here!  Your runtime beats 0.47% of cppsubmissions.
	/*for (auto itr = temp1.begin();itr!=temp1.end();itr++)
	{
		for (auto itr2 = temp2.begin(); itr2 != temp2.end(); itr2++)
		{
			if (*itr==*itr2)
			{
				temp.push_back(*itr);
			}
		}
	}*/
	
	//You are here!  Your runtime beats 12.60% of cppsubmissions.
	//����insrt�ķ���ֵ���Եõ�������set��map��Ԫ�ز����ظ��ģ������������������Ԫ��insert��ʱ������ж��������Ƿ���ڸ�ֵ��insert�᷵��һ��pair����ֵ����һ����Ҫ����Ԫ�ص�ֵ���ڶ�����һ��boolֵ�����boolֵΪ�棬��ԭ������û�д�ֵ����ӵ������У����Ϊ�٣���ԭ�������д�ֵ������ӡ�
	for (auto itr = temp2.begin();itr!=temp2.end();itr++)
	{
		auto res = temp1.insert(*itr);
		if (!res.second)
		{
			temp.push_back(*res.first);
		}
	}
	return temp;
} 
//Internet 
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//	set<int>s1, s2;
//	int n1 = nums1.size(), n2 = nums2.size();
//	for (int i = 0; i < n1; i++) s1.insert(nums1[i]);
//	for (int i = 0; i < n2; i++) s2.insert(nums2[i]);
//	vector<int>res;
//	set<int>::iterator it1 = s1.begin(), it2 = s2.begin();
//	while (it1 != s1.end() && it2 != s2.end())
//	{
//		if (*it1 == *it2)
//		{
//			res.push_back(*it1);
//			it1++;
//			it2++;
//		}
//		else if (*it1 < *it2) it1++;
//		else it2++;
//	}
//	return res;
//}
//Internet  +  Myself
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
	set<int>s1, s2;
	vector<int> res;
	s1.insert(nums1.begin(), nums1.end());
	s2.insert(nums2.begin(), nums2.end());
	auto itr1 = s1.begin();
	auto itr2 = s2.begin();
	while (itr1 != s1.end() && itr2 != s2.end()) {

		if (*itr1 == *itr2)
		{
			res.push_back(*itr1);
			itr1++;
			itr2++;

		}
			
		else if (*itr1 < *itr2)
			itr1++;
		else
			itr2++;
	}
	return res;
}

int main()
{
	vector<int>  num1 = { 4,7,9,7,6,7 };
	vector<int> num2 = { 5,0,0,6,1,6,2,2,4 };
	auto res = intersection(num1, num2);
	for (auto re : res)
	{
		cout << re << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

