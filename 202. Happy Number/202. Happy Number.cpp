// 202. Happy Number.cpp : 定义控制台应用程序的入口点。
//
//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example : 19 is a happy number
//
//	1^2 + 9^2 = 82
//	8^2 + 2^2 = 68
//	6^2 + 8^2 = 100
//	1^2 + 0^2 + 0^2 = 1

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;


//myself
bool isHappy(int n) {
	vector<int> digital;
	set<int> placeDig;
	int count = 0;
	while (1) {
		cout <<"循环第"<< ++count << "次"<<endl;
		while (n) {
			int dig = n % 10;
			n /= 10;
			digital.push_back(dig);
		}
		int sum = 0;
		for (auto &num : digital) {
			sum += pow(num, 2);
		}
		cout << "sum:::" << sum << endl;
		digital.clear();
		if (sum == 1)
			return true;
		auto res = placeDig.insert(sum);
		if (res.second == false) {
			return false;
		}
		else
			n = sum;
	}
}




int main()
{
	bool res = isHappy(19);
	cout << res << endl;

	system("pause");
    return 0;
}

