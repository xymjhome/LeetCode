// 350. Intersection of Two Arrays II.cpp : 定义控制台应用程序的入口点。
//
//Given two arrays, write a function to compute their intersection.
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2, 2].
//Note :
//	Each element in the result should appear as many times as it shows in both arrays.
//	The result can be in any order.
//Follow up :
//What if the given array is already sorted ? How would you optimize your algorithm ?
//What if nums1's size is small compared to nums2's size ? Which algorithm is better ?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?

#include "stdafx.h"
#include <vector>
#include <set>//set集合中元素是不重复的且有序。
#include <algorithm>
#include <iostream>
using namespace std;


/****************************************************
时间：2016年6月8日   9点38分29秒
注释：Myself
***************************************************/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	auto itr1 = nums1.begin();
	auto itr2 = nums2.begin();
	vector<int> vals;
	while (itr1!=nums1.end()&&itr2!=nums2.end())
	{
		if (*itr1 == *itr2)
		{
			vals.push_back(*itr1);
			itr1++;
			itr2++;
		}
		else if (*itr1 < *itr2)
		{
			itr1++;
		}
		else
			itr2++;
	}
	return vals;
}
int main()
{
	vector<int>  num1 = { 4,7,9,7,6,7 };
	vector<int> num2 = { 5,0,0,6,1,6,2,2,4,7,7 };
	auto res = intersect(num1, num2);
	for (auto re : res)
	{
		cout << re << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

