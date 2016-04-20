// 318. Maximum Product of Word Lengths.cpp : �������̨Ӧ�ó������ڵ㡣
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


//�Լ�д������find_first_of���������ַ����к�����ͬ���ַ�����������ʹʱ�临�Ӷȷǳ��ߣ�����������Ŀ��Ҫ��
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
			auto  iter = words[i].find_first_of(words[j]);//s.find(args)����s��args��һ�γ��ֵ�λ�ã��Ҳ�������npos
														  //s.find_first_of(args)��s�в���args����һ�ַ���һ�γ��ֵ�λ�ã��Ҳ�������npos
			if (iter==string::npos) {
				count.push_back(words[i].size()*words[j].size());
			}
		}
	}
	//int m = max(c)
	auto max = max_element(count.begin(), count.end(), [](int s1, int s2) {return s2 > s1; });
	return *max;
}



//����
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

//���� ���Ǻܺ�
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


//�루&������|�������^��  ����������������������λִ����Ӧ�Ĳ���������λ�룬��λ�򣬰�λ���
//"abcw", "baz"  �˷�������������ַ�������ת�����Լ�Ѱ����ͬ�ַ�����ʱ�临�Ӷ�
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





//ͨ�����ϵ�����Լ���д
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

