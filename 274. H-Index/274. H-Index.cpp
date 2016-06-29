// 274. H-Index.cpp : 定义控制台应用程序的入口点。
//
//274. H - Index
//Given an array of citations(each citation is a non - negative integer) of a researcher, write a function to compute the researcher's h-index.
//According to the definition of h - index on Wikipedia : "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h - index is 3.
//
//Note : If there are several possible values for h, the maximum one is taken as the h - index.
//
//	Hint :
//
//	An easy approach is to sort the array first.
//	What are the possible values of h - index ?
//	A faster approach is to use extra space.

#include "stdafx.h"

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

//快速排序
int getPartition(vector<int> &a, int low, int heigh) {
	int valKey = a[low];
	while (low<heigh)
	{
		while (low<heigh&&a[heigh]<=valKey)
		{
			heigh--;
		}
		a[low] = a[heigh];
		while (low<heigh&&a[low]>=valKey)
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
时间：2016年6月8日   19点24分06秒
注释:Myself  + Internet
求出文章索引的H-index值。对于h-index，意思是某个学者有n篇文章，找出最大的h，使得该作者有h篇文章，并且这h篇文章的引用次数大于等于h。
思路：
对于给定的而一个数组，可以先进行排序。逐渐找出引用最多的文章加入到集合中，每次加入一个元素集合就增大一个，也就是h增加一。当加入一个新的元素是，这个元素的引用次数小于h+1时就返回此时的h，否则，将h加1。
以上。
***************************************************/
//You are here!  Your runtime beats 21.47% of cppsubmissions.
int hIndex(vector<int>& citations) {
	if (citations.empty())
	{
		return 0;
	}
	vector<int> countPapers;
	int indexH=0;
	//sort(citations.begin(), citations.end(), [](int a, int b) {return a > b; });
	//利用快速排序进行排序，不利于c++内部排序算法函数。
	quickSort(citations, 0, citations.size() - 1);
	for (auto ss: citations)
	{
		cout << ss << "__";
	}
	cout << endl;
	//方法一
	/*for (int rr : citations)
	{
		cout << rr << " ";
		if (indexH>=rr)
		{
			break;
		}
		countPapers.push_back(rr);
		indexH++;
		
	}
	cout << endl;*/
	//方法二
	for (int rr : citations)
	{
		countPapers.push_back(rr);
	}
	for (int i = 0;i<countPapers.size();i++)
	{
		if (i+1<=countPapers[i])
		{
			indexH = i + 1;
		}
		else
		{
			break;
		}
	}
	return indexH;
}
int main()
{
	vector<int>  num = { 3, 0, 6, 1, 5 };
	for (auto re : num)
	{
		cout << re << " ";
	}
	cout << endl;

	cout<<hIndex(num)<<endl;


	system("pause");
    return 0;
}

