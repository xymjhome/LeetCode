// 164. Maximum Gap.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given an unsorted array, find the maximum difference between the successive(���ڵ�) elements in its sorted form.
//
//Try to solve it in linear time / space.  ��ͼ�����������ʱ�� / �ռ䡣
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
//������ǰ�����������ô��Ҫ�ҳ�����Ԫ��֮�������ֵ��
//

#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;

//����
int getPartition(vector<int> &a, int low, int heigh) {
	int valKey = a[low];
	while (low<heigh)
	{
		while (low<heigh&&a[heigh]>=valKey)
		{
			heigh--;
		}
		a[low] = a[heigh];
		while (low<heigh&&a[low]<=valKey)
		{
			low++;
		}
		a[heigh] = a[low];
	}
	a[low] = valKey;
	return low;
}

void quickSort(vector<int> &a, int low, int heigh) {
	if (low<heigh)
	{
		int partition = getPartition(a, low, heigh);
		quickSort(a, low, partition - 1);
		quickSort(a, partition + 1, heigh);
	}
}
/****************************************************
ʱ�䣺2016��6��12��   11��05��53��
ע�ͣ�Internet  +  Myself
//����1��
//��ֱ�ӣ�����������ĿҪ�󣩵ķ�������������������Ԫ�ص�����ֵ��
��Ϊ�����ʱ�临�Ӷ���O(n * log(n))������ĿҪ���ʱ�临�Ӷ��ǣ�O(n)��
***************************************************/
int maximumGap(vector<int>& nums) {
	if (nums.size()<2)
	{
		return 0;
	}
	quickSort(nums, 0, nums.size() - 1);
	int maxNumGap = 0;
	for (int i=0;i<nums.size()-1;i++)
	{
		maxNumGap = maxNumGap > nums[i + 1] - nums[i] ? maxNumGap : nums[i + 1] - nums[i];
	}
	return maxNumGap;
}
//Internet + Myself
//����2��
//
//����Ͱ�����˼·��
/****************************************************
ʱ�䣺2016��6��12��   21��26��49��
ע�ͣ�Ͱ�����ԭ�����Ȼ�ȡ����������a���������λ����Ȼ�����λ��ѭ���ַ�ԭ�����Ԫ�ص�һ����ʱ�Ķ�ά����b��ȥ����ʱ��ά������10�У�����������������������ͬ�����ַ��Ĺ����Ǹ��ݸ�λ��ʮλ����λ�������Ĵ�С�����зַ����Ӹ�λ��ʼ�𽥵���λ��ÿ�ηַ���Ҫ���գ�����b��ÿ���м�¼��a����������д��a�У�ÿһλ�ıȽ϶�Ҫ���գ������Ƚ���a������������λʱ��a�����յ�b�е����м�Ϊ����õ����С�

  ��ԭ����ǣ�����ÿһλ�Ĵ�С�������򣨴Ӹ�λ�����λ����ÿλ�Ƚ�һ�ν��н����ͽ��л��գ���ô��λ�ͻᰴ�մ�С��������
     
***************************************************/
//��ȡnums����������Ԫ��λ��
int getMaxNumDigits(vector<int> &nums) {
	int maxValue = 0;
	int digits = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i]>maxValue)
		{
			maxValue = nums[i];
		}
	}
	while (maxValue)
	{
		digits++;
		maxValue /= 10;
	}
	return digits;
}
//��a��Ԫ�طַ�����ʱ��ά����b��,��ʱҪ���ݱȽϵ�λ�����зַ�������Ӧ����һ������λ����int����
void distributeElement(vector<int> &nums, vector<vector<int>> &b,int digits) {
	int divisor = 1;//���������ڿ��Ƶõ��Ƚ�λ
	for (int i = 1;i<digits;i++)
	{
		divisor *= 10;
	}
	for (int i =0;i<nums.size();i++)
	{
		int valueOfBit = (nums[i] / divisor) % 10;//�õ���λ��С��ȷ����λ����b�еڼ���
		int numOfRow = ++b[valueOfBit][0];//ȷ��nums[i]���ڵڼ���
		b[valueOfBit][numOfRow] = nums[i];//�ַ���b��
	}
}
//��b�е�Ԫ�ذ���˳���ƻ�a��, �˹��̳�Ϊ����, �û��պ���collectElments()ʵ��
void collectElments(vector<int> &nums, vector<vector<int>> &b) {
	int k = 0;
	for (int i = 0 ;i<b.size();i++)
	{
		for (int j = 1;j<=b[i][0];j++)
		{
			nums[k++] = b[i][j];
		}
	}
}
int maximumGap2(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return 0;
	}
	//1����ȡnums����������Ԫ��λ��,�������ƶ�ÿһλ�ıȽϣ�1λ��(num/1)%10; 2λ��(num/10)%10;3λ��(num/10*10)%10;4λ��(num/10*10*10)%10................��
	int digits = getMaxNumDigits(nums);
	//2����λ���е��÷ַ������ͻ��պ���
	for (int i = 1 ;i<=digits;i++)
	{
		//3�����ȴ�����ʱ�Ķ�ά����b�����ڴ洢�ַ���nums�����ݡ�����ÿһλ�ַ���ʼǰb��ÿ��Ԫ�ض�Ϊ0
		vector<int> tempB(nums.size(), 0);
		vector<vector<int>> b(10, tempB);
		//3.1�����зַ�
		distributeElement(nums, b, i);
		//3.2��ÿһλ�ַ�����л���
		collectElments(nums, b);
	}
	//4�������һλ������������ɣ�nums�о���������Ԫ������
	/*for (int i = 0;i<nums.size();i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;*/
	int maxNumGap = 0;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		maxNumGap = maxNumGap > nums[i + 1] - nums[i] ? maxNumGap : nums[i + 1] - nums[i];
	}
	return maxNumGap;
}
int main()
{
	vector<int>  num = { 3, 0, 6, 1, 5 };
	for (auto re : num)
	{
		cout << re << " ";
	}
	cout << endl;

	cout << maximumGap2(num) << endl;


	system("pause");
    return 0;
}

