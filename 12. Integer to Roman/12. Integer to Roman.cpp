// 12. Integer to Roman.cpp : 定义控制台应用程序的入口点。
//
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
//Subscribe to see which companies asked this question

//计数规则：
//
//1.若干相同数字连写表示的数是这些罗马数字的和，如III = 3；
//
//2.小数字在大数字前面表示的数是用大数字减去小数字，如IV＝4；
//
//3.小数字在大数字后面表示的数是用大数字加上小数字，如VI = 6;
//
//组合规则：
//
//(1)基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
//
//(2)不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
//(3)V 和 X 左边的小数字只能用Ⅰ。
//(4)L 和 C 左边的小数字只能用×。
//(5)D 和 M 左 边的小数字只能用 C 。

//map<char, int>  m = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };

//int val[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//string r[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

#include "stdafx.h"
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;


//myself  map按键值顺序排列，所以取值的时候要利用逆序迭代器   
string intToRoman(int num) {
	map<int, string> mp = { { 1000,"M" },{ 900,"CM" },{ 500,"D" },{ 400,"CD" },{ 100,"C" },{ 90,"XC" },{ 50,"L" },{ 40,"XL" },{ 10,"X" },{ 9,"IX" },{ 5,"V" },{ 4,"IV" },{ 1,"I" } };
	map<int, string>::reverse_iterator iter = mp.rbegin();
	string roman;
	while (num > 0&& iter!=mp.rend()) {

		while (num >= iter->first) {
			roman += iter->second;
			num -= iter->first;
		}
		++iter;
	}

	return roman;
}


//自己的想法错误，因为unordered_map虽然是无顺序的，但是不一定按照初始化时你初始的顺序，而是随机的排列
//string intToRoman2(int num) {
//	unordered_map<int, string> mp = { { 1000,"M" },{ 900,"CM" },{ 500,"D" },{ 400,"CD" },{ 100,"C" },{ 90,"XC" },{ 50,"L" },{ 40,"XL" },{ 10,"X" },{ 9,"IX" },{ 5,"V" },{ 4,"IV" },{ 1,"I" } };
//	unordered_map<int, string>::iterator iter = mp.begin();
//	string roman;
//	while (num > 0 && iter != mp.end()) {
//
//		while (num >= iter->first) {
//			roman += iter->second;
//			num -= iter->first;
//		}
//		++iter;
//	}
//
//	return roman;
//}



//internet    
string intToRoman3(int num) {
	int n[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string r[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string s = "";
	for (int i = 0; num > 0; num %= n[i], ++i)
	{
		for (int j = 0, k = num / n[i]; j < k; ++j) {
			s += r[i];
		}
	}
	return s;
}


//myself + internet
string intToRoman4(int num) {
	int n[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string r[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string roman;
	int i = 0;
	while (num > 0) {
		while (num >= n[i]) {
			roman += r[i];
			num -= n[i];
		}
		++i;
	}

	return roman;
}




int main()
{

	map<char, int>  m = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
	map<char, int>::iterator it = m.begin();
	cout << it->first << " " << it->second << endl;

	string res = intToRoman3(10);
	cout << res << endl;

	system("pause");
    return 0;
}

