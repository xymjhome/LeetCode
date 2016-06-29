// 164. Maximum Gap.cpp : 定义控制台应用程序的入口点。
//
//Given an unsorted array, find the maximum difference between the successive(相邻的) elements in its sorted form.
//
//Try to solve it in linear time / space.  试图解决它在线性时间 / 空间。
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
//如果我们把数组排序，那么需要找出相邻元素之间的最大差值。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;

//快排
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
时间：2016年6月12日   11点05分53秒
注释：Internet  +  Myself
//方法1：
//最直接（但不符合题目要求）的方法是先排序再找相邻元素的最大差值。
因为排序的时间复杂度是O(n * log(n))，而题目要求的时间复杂度是：O(n)。
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
//方法2：
//
//基于桶排序的思路。
/****************************************************
时间：2016年6月12日   21点26分49秒
注释：桶排序的原理：首先获取所排序数组a中最大数的位数，然后根据位数循环分发原数组的元素到一个临时的二维数组b中去（临时二维数组有10行，列数和排序数组中列数相同），分发的规则是根据个位、十位、百位、、、的大小来进行分发，从个位开始逐渐到高位，每次分发后都要回收（即把b中每行中记录的a的数据重新写到a中，每一位的比较都要回收），当比较完a中最大数的最高位时，a所回收的b中的序列即为排序好的序列。

  简单原理就是：根据每一位的大小进行排序（从个位到最高位），每位比较一次进行结束就进行回收，那么此位就会按照大小进行排序。
     
***************************************************/
//获取nums数组中最大的元素位数
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
//把a中元素分发到临时二维数组b中,此时要根据比较的位数进行分发，所以应该有一个控制位数的int参数
void distributeElement(vector<int> &nums, vector<vector<int>> &b,int digits) {
	int divisor = 1;//除数，用于控制得到比较位
	for (int i = 1;i<digits;i++)
	{
		divisor *= 10;
	}
	for (int i =0;i<nums.size();i++)
	{
		int valueOfBit = (nums[i] / divisor) % 10;//得到此位大小，确定此位所在b中第几行
		int numOfRow = ++b[valueOfBit][0];//确定nums[i]放在第几列
		b[valueOfBit][numOfRow] = nums[i];//分发到b中
	}
}
//将b中的元素按照顺序复制回a中, 此过程称为回收, 用回收函数collectElments()实现
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
	//1、获取nums数组中最大的元素位数,用来控制对每一位的比较（1位：(num/1)%10; 2位：(num/10)%10;3位：(num/10*10)%10;4位：(num/10*10*10)%10................）
	int digits = getMaxNumDigits(nums);
	//2、按位进行调用分发函数和回收函数
	for (int i = 1 ;i<=digits;i++)
	{
		//3、首先创建临时的二维数组b，用于存储分发的nums的数据。并且每一位分发开始前b的每个元素都为0
		vector<int> tempB(nums.size(), 0);
		vector<vector<int>> b(10, tempB);
		//3.1、进行分发
		distributeElement(nums, b, i);
		//3.2、每一位分发后进行回收
		collectElments(nums, b);
	}
	//4、到最后一位结束堆排序完成，nums中就是排序后的元素序列
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

