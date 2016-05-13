// 343. Integer Break.cpp : �������̨Ӧ�ó������ڵ㡣
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
	while (n > 2) {//��n�������ٸ�3,���������,ֱ��n<=2
		res *= 3;
		n -= 3;
	}
	if (n == 0) return res;//n��������3��res���Ǹ���3���
	if (n == 1) return (res / 3) * 4;//��3��1�������е�һ��3��1��Ϊ4�����
	if (n == 2) return res * 2;//��3��2,���ֱ�Ӱ�2��res���
}
int main()
{
	int res = integerBreak(11);
	cout << res << endl;
	system("pause");
    return 0;
}

