// 75. Sort Colors.cpp : 定义控制台应用程序的入口点。
//
//
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem. 
//给定一个包含红，白，蓝且长度为n的数组，将数组元素进行分类使同颜色的元素相邻，并按照红、白、蓝的顺序进行排序。
//我们可以使用整数0，1和2分别代表红，白，蓝。
#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;


/****************************************************
时间：2016年6月8日   14点45分47秒
注释：Myself  利用基数排序   You are here!   Your runtime beats 12.91% of cppsubmissions.
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
//利用快速排序     You are here!    Your runtime beats 12.91% of cppsubmissions.
//1、获取中点值，划分块
int getPartition(vector<int> &array, int low, int height) {
	int valKey = array[low];
	while (low<height)
	{
		//必须先从height处开始比较，因为valKey记录的是第一个低位的值，放高位比低位小时，直接覆盖低位。
		while (low<height&&array[height]>=valKey)
		{
			height--;
		}
		array[low] = array[height];//直接是覆盖，不是交换
		while (low<height&&array[low]<=valKey)
		{
			low++;
		}
		//swap(array[low], array[height])//直接是覆盖，不是交换;
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

//Internet(见下面) + Myself     You are here!  Your runtime beats 12.91% of cppsubmissions.
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
//扩展分析:
//
//首先，这道题最天然的思路是counting sort。需要两次遍历数组。第一次使用O(N)的复杂度，输出来有几个0，有几个1，有几个2。第二次，用这个计数去改写原数组，复杂度为2*O(N)，也就是O(N)。上面解法的思路是1*O(N)，所以二者虽然时间复杂度的量级相同，但是乘数不同。第一种只遍历一次就得出结果，确实更好。也可以看做counting sort在不同元素比较少的时候的特殊优化。
//
//其次，本题目可以看做是快速排序的横向扩展。快去排序使用1个pivotal把一个数组分成两个区间，大于pivotal的和小于等于pivotal的区间。而本题是使用2个pivotal把数组分成三个区间。代码实现部分的trick是，本来实际需要的是两个pivotal，但是这样不方便代码实现，于是增加了第3个pitvotal(代码中的mid)，从而增加了第4个区间来代表unsorted elements.不断进行下去直到unsorted elements被消耗完，此时也就完成了三个区间的排序。
//之前按照CLRS算法导论写过quick sort的代码。现在借助和蓝三色旗类似的思路，扩展一下快速排序的另外一种做法，看上去比之前的那个好理解一下。如下 :
//
//[cpp] view plain copy
//print ? 在CODE上查看代码片派生到我的代码片
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