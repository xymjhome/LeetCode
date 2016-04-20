// 12. Integer to Roman.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
//Subscribe to see which companies asked this question

//��������
//
//1.������ͬ������д��ʾ��������Щ�������ֵĺͣ���III = 3��
//
//2.С�����ڴ�����ǰ���ʾ�������ô����ּ�ȥС���֣���IV��4��
//
//3.С�����ڴ����ֺ����ʾ�������ô����ּ���С���֣���VI = 6;
//
//��Ϲ���
//
//(1)�������֢�X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
//
//(2)���ܰѻ������� V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
//(3)V �� X ��ߵ�С����ֻ���â�
//(4)L �� C ��ߵ�С����ֻ���á���
//(5)D �� M �� �ߵ�С����ֻ���� C ��

//map<char, int>  m = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };

//int val[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//string r[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

#include "stdafx.h"
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;


//myself  map����ֵ˳�����У�����ȡֵ��ʱ��Ҫ�������������   
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


//�Լ����뷨������Ϊunordered_map��Ȼ����˳��ģ����ǲ�һ�����ճ�ʼ��ʱ���ʼ��˳�򣬶������������
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

