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
ʱ�䣺2016��6��20��   9��29��38��
ע�ͣ�Myself   �Լ������󣬲��ǰ�������ÿһλ������������������֣����ǲ�����������������������е�����ʹ����ɵ��������
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
ʱ�䣺2016��6��20��   11��31��53��
ע�ͣ�Internet + Myself
�������£�
�ȿ���������
eg1. [0, 0, 0 , 0] ->  0
eg2. [1211, 12] -> 121211������121112��
���Կ��Կ������򣬶�����ĸ���(Ҳ���ǱȽϺ����ıȽ�ԭ��)������Щ����ֵ����Դ�С���������ǹ����µ����Ĵ�С�Ƚϡ�
���ԣ���Ȼ1211 > 12�� ����
"1211" + "12" = "121112",
��12�� + "1211" = "121211",
"121112" < "121211"
���Դӹ����µ����ĽǶ�����, "1211" < "12" ��


���������������򣬹������£�
���������Ǹ�������a, b
������ת�����ַ�����ʽ��Ȼ��������ӡ��ɵ����ֽ����
a��ǰ��b�ں󣬼�Ϊ��strAB
b��ǰ��a�ں󣬼�Ϊ��strBA
���strAB > strBA����ô����ʱa��b��ǰ�档

�����ľ���Ҫע��ȫ��0�������ǰ��0�����
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
	�����ľ���Ҫע��ȫ��0�������ǰ��0�����
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