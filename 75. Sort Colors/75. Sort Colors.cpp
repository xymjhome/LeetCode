// 75. Sort Colors.cpp : �������̨Ӧ�ó������ڵ㡣
//
//
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem. 
//����һ�������죬�ף����ҳ���Ϊn�����飬������Ԫ�ؽ��з���ʹͬ��ɫ��Ԫ�����ڣ������պ졢�ס�����˳���������
//���ǿ���ʹ������0��1��2�ֱ����죬�ף�����
#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;


/****************************************************
ʱ�䣺2016��6��8��   14��45��47��
ע�ͣ�Myself  ���û�������   You are here!   Your runtime beats 12.91% of cppsubmissions.
***************************************************/
void sortColors(vector<int>& nums) {
	int countRed=0, countWhilte=0, countBlue=0;
	for (int i=0;i<nums.size();i++)
	{
		if (nums[i] == 0)
		{
			countRed++;
		}
		else if (nums[i] == 1)
		{
			countWhilte++;
		}
		else
			countBlue++;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i >= 0 && i < countRed)
		{
			nums[i] = 0;

		}
		else if (i >= countRed&&i < countRed + countWhilte)
		{
			nums[i] = 1;
		}
		else
			nums[i] = 2;
	}
}
//���ÿ�������     You are here!    Your runtime beats 12.91% of cppsubmissions.
//1����ȡ�е�ֵ�����ֿ�
int getPartition(vector<int> &array, int low, int height) {
	int valKey = array[low];
	while (low<height)
	{
		//�����ȴ�height����ʼ�Ƚϣ���ΪvalKey��¼���ǵ�һ����λ��ֵ���Ÿ�λ�ȵ�λСʱ��ֱ�Ӹ��ǵ�λ��
		while (low<height&&array[height]>=valKey)
		{
			height--;
		}
		array[low] = array[height];//ֱ���Ǹ��ǣ����ǽ���
		while (low<height&&array[low]<=valKey)
		{
			low++;
		}
		//swap(array[low], array[height])//ֱ���Ǹ��ǣ����ǽ���;
		array[height] = array[low];
	}
	array[low] = valKey;
	return low;
}
void quickSort(vector<int> &array, int low, int height) {
	if (low<height)
	{
		int partition = getPartition(array, low, height);
		quickSort(array, low, partition-1);
		quickSort(array, partition + 1, height);
	}

}
void sortColors2(vector<int> &nums) {
	if (nums.empty())
	{
		return;
	}
	quickSort(nums, 0, nums.size() - 1);
}

//Internet(������) + Myself     You are here!  Your runtime beats 12.91% of cppsubmissions.
void sortColors3(vector<int> &nums) {
	if (nums.empty())
	{
		return;
	}
	int low = 0;
	int mid = 0;
	int heigh = nums.size() - 1;
	while (mid<=heigh)
	{
		switch (nums[mid])
		{
		case 0:
			swap(nums[low], nums[mid]);
			mid++;
			low++;
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(nums[mid], nums[heigh]);
			heigh--;
			break;
		default:
			break;
		}
	}
}

int main()
{
	vector<int>  num = { 0,1,2,0,0,0,2,2,1,1,2,2,0,0,1,1,1,2 };
	for (auto re : num)
	{
		cout << re << " ";
	}
	cout << endl;

	sortColors3(num);
	for (auto re : num)
	{
		cout << re << " ";
	}

	system("pause");
    return 0;
}

//Internet
//class Solution {
//public:
//	void swap(int* arr, int a, int b) {
//		int tmp = arr[a];
//		arr[a] = arr[b];
//		arr[b] = tmp;
//	}
//	void sortColors(int A[], int n) {
//		//0-----low------mid-------high-----end;  
//		int low = 0;
//		int mid = 0;
//		int high = n - 1;
//		while (mid <= high) {
//			switch (A[mid]) {
//			case 0:
//				swap(A, low, mid);
//				low++;
//				mid++;
//				break;
//			case 1:
//				mid++;
//				break;
//			case 2:
//				swap(A, mid, high);
//				high--;
//				break;
//			}
//		}
//	}
//};
//
//
//��չ����:
//
//���ȣ����������Ȼ��˼·��counting sort����Ҫ���α������顣��һ��ʹ��O(N)�ĸ��Ӷȣ�������м���0���м���1���м���2���ڶ��Σ����������ȥ��дԭ���飬���Ӷ�Ϊ2*O(N)��Ҳ����O(N)������ⷨ��˼·��1*O(N)�����Զ�����Ȼʱ�临�Ӷȵ�������ͬ�����ǳ�����ͬ����һ��ֻ����һ�ξ͵ó������ȷʵ���á�Ҳ���Կ���counting sort�ڲ�ͬԪ�رȽ��ٵ�ʱ��������Ż���
//
//��Σ�����Ŀ���Կ����ǿ�������ĺ�����չ����ȥ����ʹ��1��pivotal��һ������ֳ��������䣬����pivotal�ĺ�С�ڵ���pivotal�����䡣��������ʹ��2��pivotal������ֳ��������䡣����ʵ�ֲ��ֵ�trick�ǣ�����ʵ����Ҫ��������pivotal�������������������ʵ�֣����������˵�3��pitvotal(�����е�mid)���Ӷ������˵�4������������unsorted elements.���Ͻ�����ȥֱ��unsorted elements�������꣬��ʱҲ��������������������
//֮ǰ����CLRS�㷨����д��quick sort�Ĵ��롣���ڽ���������ɫ�����Ƶ�˼·����չһ�¿������������һ������������ȥ��֮ǰ���Ǹ������һ�¡����� :
//
//[cpp] view plain copy
//print ? ��CODE�ϲ鿴����Ƭ�������ҵĴ���Ƭ
//
//class Solution {
//public:
//	void quick_sort2(int* arr, int start, int end)
//	{
//		if (start >= end)
//			return;
//		int low = start;
//		int high = end;
//		int pivotal = arr[low];
//
//		while (low <= high) {
//			if (arr[low] <= pivotal) {
//				low++;
//			}
//			else {
//				swap(arr, low, high);
//				high--;
//			}
//		}
//		low--;
//		swap(arr, start, low);
//
//		quick_sort2(arr, start, low - 1);
//		quick_sort2(arr, low + 1, end);
//		return;
//	}
//
//	void quick_sort(int* arr, int length) {
//		if (length <= 1)
//			return;
//		int start = 0;
//		int end = length - 1;
//		quick_sort2(arr, start, end);
//	}
//};