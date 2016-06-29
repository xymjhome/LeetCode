//179. Largest Number
//Total Accepted : 48022 Total Submissions : 245813 Difficulty : Medium
//Given a list of non negative integers, arrange them such that they form the largest number.
//For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
//Note : The result may be very large, so you need to return a string instead of an integer.
#include <iostream>

#include <algorithm>
#include <string>
#include <xstring>//
#include <set>
#include <vector>
using namespace std;


/****************************************************
时间：2016年6月20日   9点29分38秒
注释：Myself   自己理解错误，不是把整数的每一位都拆开排序输出最大的数字，而是不拆分整数，重新排列数组中的数，使其组成的数字最大。
***************************************************/
string largestNumber(vector<int>& nums) {
	multiset<int>  singleNum;
	for (int i = 0; i < nums.size(); i++)
	{
		int valNum = nums[i];
		if (valNum == 0)
			singleNum.insert(valNum);
		while (valNum) {
			int temp = valNum % 10;
			singleNum.insert(temp);
			valNum /= 10;
		}
	}
	string largeNum;
	for (auto itr = singleNum.rbegin(); itr != singleNum.rend(); itr++) {
		largeNum += to_string(*itr);
	}
	/*for (auto rr : singleNum)
	{
		largeNum += to_string(rr);
		cout << rr << " ";
	}
	cout << endl;*/
	cout << largeNum << endl;
	return largeNum;
}

/****************************************************
时间：2016年6月20日   11点31分53秒
注释：Internet + Myself
分析如下：
先看几个例子
eg1. [0, 0, 0 , 0] ->  0
eg2. [1211, 12] -> 121211而不是121112。
所以可以考虑排序，而排序的根据(也就是比较函数的比较原理)不是这些数的值的相对大小，而是它们构成新的数的大小比较。
所以，虽然1211 > 12， 但是
"1211" + "12" = "121112",
“12” + "1211" = "121211",
"121112" < "121211"
所以从构成新的数的角度来看, "1211" < "12" 。


对所有数进行排序，规则如下：
给定两个非负整数：a, b
将它们转换成字符串形式，然后进行连接。可得两种结果：
a在前，b在后，记为：strAB
b在前，a在后，记为：strBA
如果strAB > strBA，那么排序时a在b的前面。

其他的就是要注意全是0的情况和前导0的情况
***************************************************/
string largestNumber2(vector<int>& nums) {
	if (nums.empty())
	{
		return NULL;
	}
	sort(nums.begin(), nums.end(), [](int a, int b) {return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
	string res = "";
	for (auto rr : nums)
	{
		res += to_string(rr);
	}
   /* Input: [0, 0]
	Output : "00"
	Expected : "0"
	其他的就是要注意全是0的情况和前导0的情况
	*/
	//1
	/*if (res[0]=='0')
	{
		return "0";
	}
	else
		return res;*/
	//2
	auto pos = res.find_first_not_of('0');
	return pos == string::npos ? "0" : res;
	
}
int main() {
	vector<int>  nums = { 3, 30, 34, 5, 9 };
	string largeNum = largestNumber2(nums);
	cout << largeNum << endl;
	//bool bb = strcmp("1201", "1200");
	bool aa = "1200" < "1201";
	bool cc = false;
	cc = "121112" < "121211";
	//cout << aa << endl;
	system("pause");
	return 0;
}