// 313. Super Ugly Number.cpp : 定义控制台应用程序的入口点。
//
//Write a program to find the nth super ugly number.
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
//Note:
//(1) 1 is a super ugly number for any given primes.
//(2) The given numbers in primes are in ascending order.
//(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

#include "stdafx.h"
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;



/****************************************************************************************************************
作者：刘江涛
时间：2016年5月6日   22点26分31秒
注释：myself   但是Time Limit Exceeded 
****************************************************************************************************************/
int nthSuperUglyNumber(int n, vector<int>& primes) {
	int count = 0;
	int m = primes.size();
	for (int i=1;;i++)
	{
		int prime = i;
		for (int j=0;j<m;j++)
		{
			while (prime%primes[j] == 0)
				prime /= primes[j];
		}
		if (prime==1)
		{
			count++;
			cout << i << " ";
		}
		if (count == n)
			return i;
	}
}


//Internet
//public int nthSuperUglyNumber(int n, int[] primes) {
//	int len = primes.length;
//	int[] res = new int[n];
//	int[] index = new int[len];
//	res[0] = 1;
//	if (n <= 1) return res[0];
//	for (int i = 1; i < n; i++) {
//		int num = Integer.MAX_VALUE;
//		for (int j = 0; j < len; j++) {
//			num = Math.min(num, primes[j] * res[index[j]]);
//		}
//		res[i] = num;
//		for (int j = 0; j < len; j++) {
//			if (res[i] % primes[j] == 0) index[j]++;
//		}
//	}
//	return res[n - 1];
//}


//Internet
//public int nthSuperUglyNumber(int n, int[] primes) {
//	int[] pointer = new int[primes.length];
//	Arrays.fill(pointer, 0);
//	int ugly[] = new int[n];
//	ugly[0] = 1;
//	for (int i = 1; i < n; i++) {
//		int min = Integer.MAX_VALUE;
//		int minIndex = 0;
//		for (int j = 0; j < primes.length; j++) {
//			if (ugly[pointer[j]] * primes[j] < min) {
//				min = ugly[pointer[j]] * primes[j];
//				minIndex = j;
//			}
//			else if (ugly[pointer[j]] * primes[j] == min) {
//				pointer[j]++;
//			}
//		}
//		ugly[i] = min;
//		pointer[minIndex]++;
//	}
//	return ugly[n - 1];
//}



/****************************************************************************************************************
作者：刘江涛
时间：2016年5月10日   10点05分31秒
注释：Through the Internet to organize their own
****************************************************************************************************************/
int nthSuperUglyNumber2(int n, vector<int>& primes) {
	int len = primes.size();
	vector<int> pointer(len, 0);
	vector<int> ugly;
	ugly.resize(n);
	ugly[0] = 1;
	for (int i =1;i<n;i++)
	{
		int num = INT_MAX;
		for (int j = 0;j<len;j++)
		{
			if (ugly[pointer[j]]*primes[j]<num)
			{
				num =  min(num,ugly[pointer[j]] * primes[j]);
			}
		}
		ugly[i] = num;
		for (int j = 0;j<len;j++)
		{
			if (ugly[i] % primes[j]==0)
			{
				pointer[j]++;
			}
		}
		
	}
	for ( auto res : ugly)
	{
		cout << res << " ";
	}
	return ugly[n - 1];
}

//Try to write with  pointer  by self
int nthSuperUglyNumber3(int n, vector<int>& primes) {
}


int main()
{
	vector<int> primes = { 2, 7, 13, 19 };
	int n = nthSuperUglyNumber2(12, primes);
	cout << endl;
	cout << n << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << 7 % 7 << endl;

	system("pause");
    return 0;
}

