// 326. Power of Three.cpp : 定义控制台应用程序的入口点。
//
//Given an integer, write a function to determine if it is a power of three.（power 表示幂值）
//
//Follow up :
//Could you do it without using any loop（循环） / recursion(递归) ?
//
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

//Myself  利用递归判断一个数是否是三的幂（递归的运行时间少）
bool isPowerOfThree(int n) {
	if (n == 1) return true;
	else if (n == 0) return false;
	else if (n % 3 == 0)
	{
		return isPowerOfThree(n / 3);
	}
	else
		return false;
}


//Myself  bu利用递归判断一个数是否是三的幂,利用log函数
bool isPowerOfThree2(int n) {
	/*double log(double); 以e为底的对数
	double log10(double); c++中自然对数函数：log(N)   以10为底：log10(N)但没有以2为底的函数但是可以用换底公式解决：log2(N) = log10(N) / log10(2)*/

	//double log3(N) = log10(N) / log10(3);用换底公式求出以3为底N对数
	double counts = log10(n) / log10(3);
	int    tempCounts = log10(n) / log10(3);
	return (counts - tempCounts) == 0 ? 1 : 0;
}



int main()
{
	bool res = isPowerOfThree2(28);
	double ss = log10(3);
	cout << ss << endl;
	cout << "测试结果"<<res << endl;

	system("pause");
    return 0;
}

