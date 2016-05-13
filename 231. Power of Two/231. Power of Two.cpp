// 231. Power of Two.cpp : 定义控制台应用程序的入口点。
//
//Given an integer, write a function to determine if it is a power of two. 

#include "stdafx.h"
#include <iostream>
using namespace std;


bool isPowerOfTwo(int n) {
	int tempInt = log2(n);
	double tempDouble = log2(n);
	return tempDouble - tempInt == 0 ? 1 : 0;
}

bool isPowerOfTwo2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	else if (n % 2 == 0)
		return isPowerOfTwo2(n / 2);
	else
		return 0;
	

}
int main()
{
	bool res = isPowerOfTwo2(14);
	cout << res << endl;

	system("pause");
    return 0;
}

