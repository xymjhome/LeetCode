// 318. Maximum Product of Word Lengths.cpp : 定义控制台应用程序的入口点。
//
//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//
//Example 1:
//
//	Given["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//		Return 16
//		The two words can be "abcw", "xtfn".
//
//		Example 2:
//
//	Given["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//		Return 4
//		The two words can be "ab", "cd".
//
//		Example 3:
//
//	Given["a", "aa", "aaa", "aaaa"]
//		Return 0
//		No such pair of words.
#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


//自己写的利用find_first_of查找两个字符串中含有相同的字符，但是这样使时间复杂度非常高，不能满足题目的要求
int maxProduct(vector<string>& words) {
	//vector<int> ivec1(10, 42);
	vector<int> count(1,0);
	/*stable_sort(words.begin(), words.end(), [](const string  s1,const string s2) {
		return s1.size() > s2.size();
	});
	for (auto &r : words) {
		cout << r << ",";
	}*/
	//cout << endl;
	int n = words.size();
	/*vector<int> mask(n);
	for (int i = 0; i < n; i++) {
		for (char c : words[i])
			mask[i] |= 1 << (c - 'a');
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto  iter = words[i].find_first_of(words[j]);//s.find(args)查找s中args第一次出现的位置，找不到返回npos
														  //s.find_first_of(args)在s中查找args中任一字符第一次出现的位置，找不到返回npos
			if (iter==string::npos) {
				count.push_back(words[i].size()*words[j].size());
			}
		}
	}
	//int m = max(c)
	auto max = max_element(count.begin(), count.end(), [](int s1, int s2) {return s2 > s1; });
	return *max;
}



//网上
int maxProduct2(vector<string>& words) {
	int len = 0;
	vector<int> mask(words.size());
	for (int i = 0; i < words.size(); i++) {
		for (char c : words[i])
			mask[i] |= 1 << (c - 'a');
		for (int j = 0; j < i; j++) {
			int wlen = words[i].length() * words[j].length();
			if (wlen > len && !(mask[i] & mask[j])) {
				len = wlen;
			}
		}
	}
	return len;
}

//网上 不是很好
//int maxProduct3(vector<string>& words) {
//
//		int  wSize = words.size(), res = 0, i, j;
//		if (wSize <= 1) return res;
//		unsigned int bitMask[wSize] = { 0 };
//		sort(words.begin(), words.end(), [](string &left, string &right) {return left.size()>right.size(); });
//		for (i = 0; i<wSize; ++i)
//			for (j = 0; j<words[i].size(); ++j) bitMask[i] |= 1 << (words[i][j] - 'a');
//		for (i = 0; i<wSize - 1 && res < int(words[i].size())*int(words[i + 1].size()); ++i)
//			for (j = i + 1; j<wSize; ++j)
//				if (!(bitMask[i] & bitMask[j]))
//				{
//					res = max(res, int(words[i].size()) * int(words[j].size()));
//					break;
//				}
//		return res;
//}


//与（&），或（|），异或（^）  运算符在两个运算对象上逐位执行相应的操作，即按位与，按位或，按位异或
//"abcw", "baz"  此方法很巧妙，利用字符到数的转化可以简化寻找相同字符串的时间复杂度
void strToBits(vector<int>& bits, vector<string>& words) {
	for (int i = 0; i<words.size(); ++i) {
		int tmp = 0;
		for (int j = 0; j<words[i].size(); ++j) {
			int offset = words[i][j] - 'a';
			cout << offset << endl;
			tmp = (tmp | (1 << offset));
		}
		bits[i] = tmp;
	}
}





//通过网上的理解自己编写
int maxProduct4(vector<string>& words) {
	int len = 0;
	int n = words.size();
	vector<int> mark(n, 0);
	for (int i = 0; i < n; i++) {
		for (auto &c : words[i]) {
			int offset = c - 'a';
			mark[i] = mark[i] | (1 << offset);
		}
		for (int j = 0; j < i; j++) {
			int wlen = words[i].size()*words[j].size();
			if (wlen > len&&!(mark[i] & mark[j]))
				len = wlen;
		}
	
	}
	return len;


}
int main()
{
	vector<string> ss = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	vector<string> ss2 = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
	vector<string> ss3 = { "a", "aa", "aaa", "aaaa"};
	vector<string> ss4 = { "abcw", "baz" };
	vector<int> bit(ss4.size(),0);
	//strToBits(bit,ss4);
	int m = maxProduct(ss);
	cout << m << endl;
	//vector<int> mmmm= { 1,21,2 };
	//auto max = max_element(mmmm.begin(), mmmm.end(), [](int s1, int s2) {return s2 > s1; });
	//cout << *max << endl;


	system("pause");
    return 0;
}

