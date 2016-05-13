// 343. Integer Break.cpp : 定义控制台应用程序的入口点。
//
//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: you may assume that n is not less than 2.
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//Myself
int integerBreak(int n) {
	if (n == 2 || n == 3)
	{
		return n - 1;
	}
	int m = n % 3;
	if (m == 0) {
		return pow(3, n / 3);
	}
	else if (m==1) {
		return pow(3, (n / 3-1))*(3+m);
	}
	else{
		return pow(3, (n / 3))*m;
	}
}

//Internet
int integerBreak2(int n) {
	if (n < 4) return n - 1;
	int res = 1;
	while (n > 2) {//看n包含多少个3,把他们相乘,直到n<=2
		res *= 3;
		n -= 3;
	}
	if (n == 0) return res;//n可以整除3，res就是各个3相乘
	if (n == 1) return (res / 3) * 4;//除3余1，把其中的一个3加1变为4再相乘
	if (n == 2) return res * 2;//除3余2,则可直接把2与res相乘
}
int main()
{
	int res = integerBreak(11);
	cout << res << endl;
	system("pause");
    return 0;
}

