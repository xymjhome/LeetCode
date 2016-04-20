// 268. Missing Number.cpp : 定义控制台应用程序的入口点。
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?

#include "stdafx.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int missingNumber(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	for (auto &r : nums) {
		cout << r << " ";
	}
	cout << endl;
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
	if (nums[0] != 0) {
		return 0;
	}
	int res;
	for (int i = 1; i < n; ++i) {

		if (nums[i] - nums[i - 1] == 1)
		{ 
			if (i == (n - 1)) {
				return nums[i] + 1;	
			}
			continue;
		}
			
		else
		{
			return  nums[i] - 1;
		}

	}


}

//想法错误：关联容器不支持顺序容器的位置相关的操作。
//int missingNumber2(vector<int>& nums) {
//
//	set<int> num(nums.begin(), nums.end());
//	for (auto &r : num) {
//		cout << r << " ";
//	}
//	cout << endl;
//	int n = num.size();
//	for (int i = 0; i < n; ++i) {
//		cout << num[i] << " ";
//	}
//	cout << endl;
//
//
//	if (num[0] != 0) {
//		return 0;
//	}
//	for (int i = 1; i < n; ++i) {
//		if (num[i] - num[i - 1] == 1)
//			continue;
//		else
//		{
//			return num[i] - 1;
//		}
//	}
//
//}

//xu jin yi bu li jie
//网上：根据异或的特性，对于一个数，异或自己是0，异或0是自己，所以我们把0-n都异或一遍，再对着给定数组异或一遍，结果就是缺失的数。
//^=d的优先级低于==
int missingNumber3(vector<int>& nums) {

	int res = 0;
	for (int i = 0; i <= nums.size(); i++) 
	{
		//res ^= i == nums.length ? i : i ^ nums[i];
		res = res^ (i == nums.size() ? i : i ^ nums[i]);
	}
	return res;

}
//w s 利用等差数列的和求解
int missingNumber4(vector<int>& nums) {
	int n = (1 + nums.size())*nums.size() / 2;
	for (int i = 0; i < nums.size(); i++) {
		n -= nums[i];
	}
	return n;
}

int main()
{
	vector<int>  vec = {1,3,2};
	int res = missingNumber4(vec);
	cout << res << endl;

	system("pause");
    return 0;
}

