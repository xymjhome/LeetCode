// 35. Search Insert Position.cpp : 定义控制台应用程序的入口点。
//
//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1, 3, 5, 6], 5 → 2
//[1, 3, 5, 6], 2 → 1
//[1, 3, 5, 6], 7 → 4
//[1, 3, 5, 6], 0 → 0
//
//Subscribe to see which companies asked this question


#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;


int searchInsert(vector<int>& nums, int target) {

	vector<int> ::iterator it = nums.begin();
	int count = 0;
	while (*it <= target) {
		if (*it == target) {
			return count;
		}
		++it;
		++count; 
		if (it == nums.end()) {
			nums.insert(it, target);
			return count;
		}
	}
	nums.insert(it, target);
	return count;
}


//折半查找算法
//bin_search(int A[], int n, int key) {
//	int low, high, mid;
//	low = 0;
//	high = n - 1;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (A[mid] == key)return mid;
//		if (A[mid] < key) {
//			low = mid + 1;
//		}
//		if (A[mid] > key) {
//			high = mid - 1;
//		}
//	}
//	return -1;
//}


int searchInsert2(vector<int>& nums, int target) {
	int n = nums.size();
	if (target > nums[n - 1]) {
		nums.push_back(target);
		return n;
	}
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low<=high){
		mid = (low + high) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		if (nums[mid] > target)
			high = mid - 1;
		if (nums[mid] < target)
			low = mid + 1;
	}
	nums.insert(nums.begin() + low, target);
	return low;
}



int main()
{
	vector<int> vec = { 1, 3, 5, 8 };
	/*vector<int> ::iterator it = vec.begin();
	vec.insert(it, 10);*/
	for (auto &r : vec) {
		cout << r << " ";
	}
	cout <<"****************************"<< endl;
	int res = searchInsert2(vec,7);
	cout <<"index in "<<res <<endl;
	for (auto &r : vec) {
		cout << r << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

