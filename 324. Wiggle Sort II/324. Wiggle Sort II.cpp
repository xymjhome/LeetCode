// 324. Wiggle Sort II.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//	Example:
//(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is[1, 4, 1, 5, 1, 6].
//(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is[2, 3, 1, 3, 1, 2].
//
//Note :
//	You may assume all input has valid answer.
//
//	Follow Up :
//Can you do it in O(n) time and / or in - place with O(1) extra space ?
//https://10.108.227.243/svn/AirDefenseWithUI/87
//simulation@BUPT#15
#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


/****************************************************
ʱ�䣺2016��6��13��   19��53��11��
ע�ͣ�Myself  ˼·�д��󣡣�����������������������
//Can you do it in O(n) time and / or in - place with O(1) extra space ?����������������

Internet   
�����O(1)ʱ�临�ӶȺͿռ临�Ӷȵ����Ž���ʱû��������ô��취���������Ϊ�ȸ��Ƶ�ǰ���飬�����Ƶ���������Ȼ������λ��Ϊ�罫�����Ϊ�����֣�small part��large part����������ԭʼ���鼴�ɣ���������ԭ���ǿ��Ա�����ֵ��ͬ�����鰤��һ���Է�����Ŀ����

��������Ҳ��ע����뽵���棬������Ȼ�п��ܰ���һ�𡣱���[4, 5, 5, 6]��һ�����������������Ȼ��4��5��5��6��������Ϊ5��6��4��5
public void wiggleSort(int[] nums) {
    int[] temp = Arrays.copyOfRange(nums, 0, nums.length);
	Arrays.sort(temp);
	int large = temp.length / 2 + (temp.length % 2 == 0 ? -1 : 0);
	int small = temp.length - 1;
	for (int i = 0, j = 1; i < temp.length; i+=2, j+=2) {
	if(j < temp.length) nums[j] = temp[small--];
	nums[i] = temp[large--];
}
}

Small half:  M . S . S . S      Small half:  M . S . S . S .
Large half:  . L . L . M .      Large half:  . L . L . L . M
--------------------------      --------------------------
Together:    M L S L S M S      Together:    M L S L S L S M
***************************************************/
void wiggleSort(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	sort(nums.begin(), nums.end());
	vector<int> result;
	int mid = nums.size() / 2 + (nums.size() % 2 == 0 ? -1 : 0);
	int hight = nums.size()-1;
	for (int i =mid;i>=0;i--)
	{
		result.push_back(nums[i]);
		if (hight > mid)
		{
			result.push_back(nums[hight--]);
		}
	}
	while (hight >mid)
	{
		result.push_back(nums[mid++]);
	}
	for (int i = 0;i<result.size();i++)
	{
		nums[i] = result[i];
	}
}

/****************************************************
ʱ�䣺2016��6��16��   17��30��39��
ע�ͣ��ⷨII O(n)ʱ�临�Ӷ�+O(1)�ռ临�ӶȽⷨ��

	1. ʹ��O(n)ʱ�临�Ӷȵ�quickSelect�㷨����δ�����������nums��ѡ����λ��mid
    2. ���սⷨI��˼·����nums������±�xͨ������idx()��[0, 1, 2, ... , n - 1, n] ӳ�䵽 [1, 3, 5, ... , 0, 2, 4, ...]���õ�  ���±�ix
    3. ����λ��midΪ�磬������mid��Ԫ��������ix�Ľ�С���֣�����С��mid��Ԫ��������ix�Ľϴ󲿷֡�
***************************************************/
//�Լ�д�ҵ�n���Ԫ�أ���quickSelect�����ƿ�������
//1���ҳ���Ŧ��λ�ã�������
int getPartition(vector<int> &a, int low, int height) {
	int valKey = a[low];
	while (low<height)
	{
		while (low < height&&a[height] >= valKey) height--;
		a[low] = a[height];
		while (low < height&&a[low] <= valKey) low++;
		a[height] = a[low];
	}
	a[low] = valKey;
	return low;
}
//2�����ٲ���ָ����Сλ�ã������������һ��������
bool quickSelect(vector<int> &a, int low, int height, int k) {
	if (k-1<low||k-1>height)
	{
		return false;
	}
	//����������ֵ�ָ���ҿ��ſ�ʼ����Ŧ�����Ч��
	int mid = (low + height) / 2;
	if (a[low] > a[mid])
	{
		swap(a[low], a[mid]);
	}
	if (a[mid]>a[height])
	{
		swap(a[mid], a[height]);
	}
	if (a[low]>a[height])
	{
		swap(a[low], a[height]);
	}
	//�������м�ֵ��ʹ��Ŧpivot,��������������λ
	swap(a[low], a[mid]);
	int partition = getPartition(a, low, height);
	if (partition==k-1)
	{
		return true;
	}
	else if (partition > k - 1)
	{
		return quickSelect(a, low, partition - 1, k);
	}
	else
	{
		return quickSelect(a, partition + 1, height, k);
	}
}
//˼·�����ҵ���λ����Ȼ��������ҽ�����λ���������������λ���ϣ��������󽫱���λ��С��������ż��λ���ϣ�
//
//����(1 + 2 * pos) % (len | 1)����һ����Ƽ��������ӳ�䣬������ʹ��С��һ�����ӳ�䵽1, 3, 5������λ�ã�Ҳ����low��ӳ�䵽������λ�ã�������һ�������ӳ�䵽�Ӹߵ��͵�ż��λ�ã�Ҳ����high������ӳ�䵽��(n | 1)������ż��λ�ã������ͻ���С����λ����ֵ���ȴ�������ţ���������λ����ֵ���ȴ������ҷţ�ʣ�µĵ�����λ������ֵ�����ڴ�����λ����С����λ����ֵ�м䣮
void wiggleSort2(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	//���Ȼ�ȡ��ֵ����ʱ��ֵ��ߵĶ�����ֵС���ұߵĶ�����ֵ��
	int minIndex = nums.size() / 2;
	quickSelect(nums, 0, nums.size() - 1, minIndex);
	for (auto rr : nums)
	{
		cout << rr << ",";
	}
	cout << endl;
	//Internet      ����ͨ��ӳ�佻����û����⣬���һ����
	//�������ͨ��ӳ���ƶ�����ȥ��ֵֻ�����⣬ȡ��ֵ��һ��������
	int len = nums.size(), low = 0, high = len - 1, mid = nums[minIndex -1], i = 0;
	auto index = [=](int pos) { return (1 + pos * 2) % (len | 1); };//lambda  ��ʽ����[=],[&]��&���߱��������ò������õķ�ʽ��=���ʾ����ֵ����ķ�ʽ��
	while (i <= high)
	{
		if (nums[index(i)] > mid) 
		{
			swap(nums[index(i++)], nums[index(low++)]);
		}
		else if (nums[index(i)] < mid)
		{
			swap(nums[index(i)], nums[index(high--)]);
		}
		else i++;
	}



}

/****************************************************
ʱ�䣺2016��6��17��   10��29��07��
ע�ͣ�Internet  +  Myself   ����c++��STL���е�nth_element���������n���Ԫ��

td::nth_element
default (1)
template <class RandomAccessIterator>
void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
RandomAccessIterator last);

custom (2)
template <class RandomAccessIterator, class Compare>
void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
RandomAccessIterator last, Compare comp);


// nth_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector
bool myfunction (int i,int j) { return (i<j); }
int main () {
std::vector<int> myvector;
// set some values:
for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
std::random_shuffle (myvector.begin(), myvector.end());
// using default comparison (operator <):
std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end());
// using function as comp
std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);
// print out content:
std::cout << "myvector contains:";
for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';

return 0;
}
***************************************************/
// nth_element example
/*#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector
bool myfunction(int i, int j) { return (i < j); }
int main() {
	std::vector<int> myvector;
	// set some values:
	for (int i = 1; i < 10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
	std::random_shuffle(myvector.begin(), myvector.end());
	// using default comparison (operator <):
	std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end());
	// using function as comp
	std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end(), myfunction);
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}*/
void wiggleSort3(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	auto beginIterator = nums.begin();
	int midIndex = nums.size() / 2;
	nth_element(nums.begin(), nums.begin() + midIndex, nums.end());
	int mid = *(nums.begin() + midIndex);
	int len = nums.size(), low = 0, high = len - 1, i = 0;
	auto index = [=](int pos) { return (1 + pos * 2) % (len | 1); };
	while (i <= high)
	{
		if (nums[index(i)] > mid) swap(nums[index(i++)], nums[index(low++)]);
		else if (nums[index(i)] < mid) swap(nums[index(i)], nums[index(high--)]);
		else i++;
	}
}
int main()
{
	//nums = [1, 5, 1, 1, 6, 4]
	vector<int> test = { 1,2,3,4,5 };
	cout << *(test.begin()) << endl;
	cout<< *(test.begin()+3) << endl;
	vector<int> nums = { 3,3,3,2,2,2,3,2,1,1,2,1,2,3,3,3,1,2 };
	//sort(nums.begin(), nums.end());
	//cout << "nums.size()/2-1 ==" << nums.size() / 2 - 1 <<"           "<<nums[nums.size()/2-1]<< endl;
	for (auto rr : nums)
	{
		cout << rr << ",";
	}
	cout << endl;

	wiggleSort2(nums);

	for (auto rr : nums)
	{
		cout << rr << ",";
	}
	cout << endl;

	system("pause");
    return 0;

}

