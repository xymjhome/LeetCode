// 263. Ugly Number.cpp : 定义控制台应用程序的入口点。
//
//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note that 1 is typically treated as an ugly number.
//Write a program to check whether a given number is an ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//Note that 1 is typically treated as an ugly number.

//题目要求：编写程序判断一个给定的数字是否为“丑陋数” ugly number丑陋数是指只包含质因子2, 3, 5的正整数。 
//例如，6, 8是丑陋数而14不是，因为它包含额外的质因子7,注意，数字1也被视为丑陋数。  
//解题思路：根据丑陋数的定义，我们将给定数除以2、3、5，直到无法整除，也就是除以2、3、5的余数不再为0时停止。 
//这时如果得到1，说明是所有因子都是2或3或5，如果不是1，则不是丑陋数。
#include "stdafx.h"
#include <iostream>
using namespace std;


bool isUgly(int num) {
	if (num <= 0)//0也不是丑陋的数字
		return false;
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	if (num == 1)
		return true;
	else
		return false;
}

int main()
{
	bool res = isUgly(13);
	cout << res << endl;

	system("pause");
    return 0;
}

