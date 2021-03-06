// 13. Roman to Integer.cpp : 定义控制台应用程序的入口点。

//基本字符：I、V、X、L、C、D、M相应的阿拉伯数字表示为：1、5、10、50、100、500、1000

//(1)相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
//(2)小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
//(3)小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ = 4；Ⅸ = 9；
//
//思路如下：
//从左边第一个数字开始，依次加，因为有（3）的情况的存在， 加过以后判断，要是存在（3）的情况，就减去前一个（i - 1）＊2，因为本来应该减去前面这个小的数， 但是上次一循环还加了一次，于是这次就减去2次

//右加左減：
//在较大的罗马数字的右边记上小的罗马数字，表示大数字加小数字。
//在较大的罗马数字的左边记上小的罗马数字，表示大数字减去小数字。
//左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
//但是，左减不能跨去一个位数。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。（等同于阿拉伯每位数字表示每位）
//左减数字必须为一位，比如8写成VIII，而非IIX。
//右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（見下方“数码限制”一項。）
//
//左减右加算法思想：
//
//不难发现，罗马数字是没有禁止，我建议大家可以先试着从I数到C，这样便对罗马数字有个了解，然后发现其为纯粹叠加而成的，所以用户输入一个数后，我们可以来遍历这个数，用sum来总计和，比较pre(s[i - 1]) 和 cur(s[i])，如果，cur 比 pre 小的话，直接相加，如果 cur 比 pre 大的话，则将总和sum减去pre这个地方数的两倍，同时加上 cur 就相当于后边的数比左边的数大，则用右边的数减左边的数。但因为之前已经加过一次了，所以减两次。



#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;


int romanToInt(string s) {
	//I、V、X、L、C、D、M相应的阿拉伯数字表示为：1、5、10、50、100、500、1000
	map<char, int>  m = { {'I',1},{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
	int n = s.size();
	int sum=0;
	for (int i = 0; i < n; i++)
		sum += m[s[i]];
	for (int i = 0; i < n - 1; i++) {
		if (m[s[i]] < m[s[i + 1]])
			sum -= m[s[i]]*2;
	}
	return sum;
}

//网上   从右往左加
int romanToInt2(string s)
{
	map<char, int>  m = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
	int res = 0;
	char max = 'I';
	for (int i = s.size() - 1; i >= 0; --i) {
		if (m[s[i]] >= m[max]) {
			max = s[i];
			res += m[s[i]];
		}
		else {
			res -= m[s[i]];
		}
	}
	return res;
}


int main()
{

	string s = "IIX";
	int value = romanToInt2(s);
	cout << value << endl;

	system("pause");
    return 0;
}

