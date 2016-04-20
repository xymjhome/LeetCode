// 125. Valid Palindrome.cpp : �������̨Ӧ�ó������ڵ㡣
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


//ע���Լ�д�ķ�����ispunct()����
//���ܣ��ж��ַ�c�Ƿ�Ϊ������
//˵������cΪ������ʱ�����ط���ֵ�����򷵻��㡣
//������ָ��Щ�Ȳ�����ĸ���֣�Ҳ���ǿո�Ŀɴ�ӡ�ַ���
//��غ�����isalnum,isalpha,isdigit,isxdigit,iscntrl,isgraph,isprint,isspace

//myself
bool isPalindrome(string s) {
	string ss1;
	for (string::size_type i = 0; i != s.size(); i++)
	{
		if (!ispunct(s[i]))//���c�Ǳ�����ispunct(c)�ķ���ֵΪ1  
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
//���ϴ����Լ�����д,�������ú����٣�����ѭ�������Ĵ����٣�����Ч�ʺܸߡ�������������������ֵ��ѧϰ
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

