// 324. Wiggle Sort II.cpp : 定义控制台应用程序的入口点。
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
时间：2016年6月13日   19点53分11秒
注释：Myself  思路有错误！！！！！！！！！！！！！
//Can you do it in O(n) time and / or in - place with O(1) extra space ?不满足条件！！！

Internet   
这道题O(1)时间复杂度和空间复杂度的最优解暂时没想出来，用蠢办法解决。方案为先复制当前数组，将复制的数组排序，然后以中位数为界将数组分为两部分，small part和large part。交替填入原始数组即可，这样做的原因是可以避免有值相同的数组挨在一起，以符合题目规则。

交替填入也得注意必须降序交替，否则任然有可能挨在一起。比如[4, 5, 5, 6]这一组如果升序交替填入任然是4、5、5、6，降序则为5、6、4、5
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
时间：2016年6月16日   17点30分39秒
注释：解法II O(n)时间复杂度+O(1)空间复杂度解法：

	1. 使用O(n)时间复杂度的quickSelect算法，从未经排序的数组nums中选出中位数mid
    2. 参照解法I的思路，将nums数组的下标x通过函数idx()从[0, 1, 2, ... , n - 1, n] 映射到 [1, 3, 5, ... , 0, 2, 4, ...]，得到  新下标ix
    3. 以中位数mid为界，将大于mid的元素排列在ix的较小部分，而将小于mid的元素排列在ix的较大部分。
***************************************************/
//自己写找第n大的元素，即quickSelect，类似快速排序
//1、找出枢纽的位置，即划分
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
//2、快速查找指定大小位置，即快速排序的一个子问题
bool quickSelect(vector<int> &a, int low, int height, int k) {
	if (k-1<low||k-1>height)
	{
		return false;
	}
	//利用三数中值分割法来找快排开始的枢纽，提高效率
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
	//三数的中间值即使枢纽pivot,让其放在数组的首位
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
//思路：先找到中位数，然后从左往右将比中位数大的数放在奇数位置上，从右往左将比中位数小的数放在偶数位置上．
//
//其中(1 + 2 * pos) % (len | 1)这是一个设计极其巧妙的映射，这样会使得小于一半的数映射到1, 3, 5等奇数位置，也就是low会映射到的奇数位置，而大于一半的数会映射到从高到低的偶数位置，也就是high会依次映射到从(n | 1)到０的偶数位置．这样就会让小于中位数的值优先从右往左放，而大于中位数的值优先从左往右放，剩下的等于中位数数的值会留在大于中位数和小于中位数的值中间．
void wiggleSort2(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	//首先获取中值，此时中值左边的都比中值小，右边的都比中值大
	int minIndex = nums.size() / 2;
	quickSelect(nums, 0, nums.size() - 1, minIndex);
	for (auto rr : nums)
	{
		cout << rr << ",";
	}
	cout << endl;
	//Internet      这种通过映射交换的没有理解，需进一步看
	//下面这个通过映射移动对于去中值只有问题，取中值下一个最大可以
	int len = nums.size(), low = 0, high = len - 1, mid = nums[minIndex -1], i = 0;
	auto index = [=](int pos) { return (1 + pos * 2) % (len | 1); };//lambda  隐式捕获[=],[&]，&告诉编译器采用捕获引用的方式，=则表示采用值捕获的方式。
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
时间：2016年6月17日   10点29分07秒
注释：Internet  +  Myself   利用c++的STL库中的nth_element函数来求第n大的元素

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

