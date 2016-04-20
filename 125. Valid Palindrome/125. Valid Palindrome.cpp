// 125. Valid Palindrome.cpp : 定义控制台应用程序的入口点。
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty ? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.
//
//Subscribe to see which companies asked this question


#include "stdafx.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;


//注意自己写的方法中ispunct()函数
//功能：判断字符c是否为标点符号
//说明：当c为标点符号时，返回非零值，否则返回零。
//标点符号指那些既不是字母数字，也不是空格的可打印字符。
//相关函数：isalnum,isalpha,isdigit,isxdigit,iscntrl,isgraph,isprint,isspace

//myself
bool isPalindrome(string s) {
	string ss1;
	for (string::size_type i = 0; i != s.size(); i++)
	{
		if (!ispunct(s[i]))//如果c是标点符号ispunct(c)的返回值为1  
			if (!isspace(s[i]))
				ss1 += s[i];
	}
	//ss2.resize(ss1.size());
	transform(ss1.begin(), ss1.end(), ss1.begin(), [](char ch)->char {
		if (( ch > 'A'|| ch =='A')&&( ch < 'Z'|| ch == 'Z'))
			return ch + 32;
		else
			return ch;		
	});
	int starIndex = 0,endIndex=ss1.size()-1;
	while (starIndex != endIndex) {
		if (ss1[starIndex] == ss1[endIndex]) {
			starIndex++;
			endIndex--;
			if (starIndex >= endIndex)
				return true;
		}
		else {
			return false;
		}
	}

}
//网上代码自己理解编写,这样调用函数少，进行循环遍历的次数少，所以效率很高。。。。。。。。。。值得学习
bool isPalindrome2(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
	
		if (!isalnum(s[i]))
		{
			i++;
			continue;
		}
		if (!isalnum(s[j])) {
			j--;
			continue;
		}
		if (tolower(s[i]) != tolower(s[j]))
		{
			i++;
			j--;
			if (i > j)
				return true;
			
		}
		else {
			return false;
			
		}
		

	}
	return true;
}

int main()
{
	string ss = "A man, a plan, a canal : Panama ";
	string ss2 = "Zeus was deified saw Suez.";
	string ss3 = "race a car";
	string ss4 = "Alice Emma has long flowing red hair.";
	bool bo = isPalindrome(ss4);
	bool bo2 = isPalindrome2(ss4);
	cout <<bo<< endl;
	cout << bo2 << endl;


	system("pause");
    return 0;
}

