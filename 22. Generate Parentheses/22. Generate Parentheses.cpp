// 22. Generate Parentheses.cpp : 定义控制台应用程序的入口点。
//
//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//"((()))", "(()())", "(())()", "()(())", "()()()"
//
//Subscribe to see which companies asked this question

#include "stdafx.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;



//利用递归进行求解，要以后用树的思想求解
vector<string> generateParenthesis(int n) {
	vector<string> res;
	if (n == 0)
		res.push_back("");
	if (n == 1) {
		res.push_back("()");
	}
	else {
		vector<string> pre_vec = generateParenthesis(n - 1);
		set<string> filter_set;
		int sizes = pre_vec.size();
		for (int i = 0; i < sizes; ++i) {
			string temp_str = pre_vec[i];
			for (int j = 0; j < temp_str.size(); j++) {
				string now_str = temp_str.substr(0, j) + "()" + temp_str.substr(j, temp_str.size());
				filter_set.insert(now_str);
			}
		}

		for (auto &r : filter_set) {
			res.push_back(r);
		}
	}

	return res;
}
int main()
{
	vector<string> res;
	res = generateParenthesis(3);
	for (auto &s : res) {
		cout << s<<",";
	}
	cout << endl;


	system("pause");
    return 0;

}

