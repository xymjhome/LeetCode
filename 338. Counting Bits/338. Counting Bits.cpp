// 338. Counting Bits.cpp : 定义控制台应用程序的入口点。
//
//Given a non negative integer number num.For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example:
//For num = 5 you should return[0, 1, 1, 2, 1, 2].
//
//Follow up :
//
//It is very easy to come up with a solution with run time O(n*sizeof(integer)).But can you do it in linear time O(n) / possibly in a single pass ?
//Space complexity should be O(n).
//Can you do it like a boss ? Do it without using any builtin function like __builtin_popcount in c++ or in any other language
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> countBits(int num) {
	vector<int> vec;
	for (int i = 0; i <= num; i++) {
		int count = 0;
		int temp = i;
		while (temp) {
			int m = temp % 2;
			if (m) {
				count++;
			}
			temp = temp / 2;
		}
		vec.push_back(count);
	}
	return vec;
}

int main()
{
	vector<int> num;
	num = countBits(5);
	for (auto &r : num) {
		cout << r << ",";
	}
	cout << endl;
	system("pause");
    return 0;
}

