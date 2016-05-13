// 326. Power of Three.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given an integer, write a function to determine if it is a power of three.��power ��ʾ��ֵ��
//
//Follow up :
//Could you do it without using any loop��ѭ���� / recursion(�ݹ�) ?
//
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

//Myself  ���õݹ��ж�һ�����Ƿ��������ݣ��ݹ������ʱ���٣�
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


//Myself  bu���õݹ��ж�һ�����Ƿ���������,����log����
bool isPowerOfThree2(int n) {
	/*double log(double); ��eΪ�׵Ķ���
	double log10(double); c++����Ȼ����������log(N)   ��10Ϊ�ף�log10(N)��û����2Ϊ�׵ĺ������ǿ����û��׹�ʽ�����log2(N) = log10(N) / log10(2)*/

	//double log3(N) = log10(N) / log10(3);�û��׹�ʽ�����3Ϊ��N����
	double counts = log10(n) / log10(3);
	int    tempCounts = log10(n) / log10(3);
	return (counts - tempCounts) == 0 ? 1 : 0;
}



int main()
{
	bool res = isPowerOfThree2(28);
	double ss = log10(3);
	cout << ss << endl;
	cout << "���Խ��"<<res << endl;

	system("pause");
    return 0;
}

