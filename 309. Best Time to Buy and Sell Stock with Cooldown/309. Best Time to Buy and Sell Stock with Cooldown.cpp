// 309. Best Time to Buy and Sell Stock with Cooldown.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//Example :
//
//	prices = [1, 2, 3, 0, 2]
//	maxProfit = 3
//	transactions = [buy, sell, cooldown, buy, sell]

#include "stdafx.h"
#include "math.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//internet ��Ҫ�Ժ�ϰ��̬�滮��Dynamic Programming��������ϸ�������ڲ�����
//�ⷨI��
//
//���븨������sells��buys
//
//sells[i]��ʾ�ڵ�i��������Ʊ���ܻ�õ�����ۻ�����
//buys[i]��ʾ�ڵ�i�������Ʊ���ܻ�õ�����ۻ�����
//
//��ʼ����sells[0] = 0��buys[0] = -prices[0]
//
//��i�콻��ʱ��õ��ۼ�����ֻ���i - 1�����i - 2���й�
//
//�ǵ�i�����i - 1��ļ۸�delta = price[i] - price[i - 1]
//
//״̬ת�Ʒ���Ϊ��
//
//sells[i] = max(buys[i - 1] + prices[i], sells[i - 1] + delta)
//buys[i] = max(sells[i - 2] - prices[i], buys[i - 1] - delta)
//
//�������̵ĺ���Ϊ��
//
//��i������������ۻ����� = max(��i - 1������~��i������������ۻ�����, ��i - 1�������󷴻�~��Ϊ��i������������ۻ�����)
//��i�����������ۻ����� = max(��i - 2������~��i�����������ۻ�����, ��i - 1������󷴻�~��Ϊ��i�����������ۻ�����)
//
//��ʵ���ϣ�
//
//��i - 1�������󷴻ڣ���Ϊ��i������ �ȼ��� ��i - 1����й�Ʊ����i��������
//��i - 1������󷴻ڣ���Ϊ��i������ �ȼ��� ��i - 1��û�й�Ʊ����i��������
//
//������������Ϊmax(sells)����Ȼ��������Ʊʱ�ſ��ܻ�����档
//Python���룺
//
//class Solution(object) :
//	def maxProfit(self, prices) :
//	"""
//	: type prices : List[int]
//	: rtype : int
//	"""
//	size = len(prices)
//	if not size :
//		return 0
//		buys = [None] * size
//		sells = [None] * size
//		sells[0], buys[0] = 0, -prices[0]
//		for x in range(1, size) :
//			delta = prices[x] - prices[x - 1]
//			sells[x] = max(buys[x - 1] + prices[x], sells[x - 1] + delta)
//			buys[x] = max(buys[x - 1] - delta, sells[x - 2] - prices[x] if x > 1 else None)
//			return max(sells)



//Internet  C++����
int maxProfit2(vector<int>& prices) {
	if (prices.size() < 2) return 0;
	//δ���й�Ʊ
	vector<int> sell(prices.size(), 0);
	//���й�Ʊ
	vector<int> buy(prices.size(), 0);
	sell[0] = 0;
	buy[0] = -prices[0];
	for (int i = 1; i < prices.size(); ++i) {
		sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		if (i > 1)
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
		else
			buy[i] = max(buy[i - 1], -prices[i]);
	}
	return sell[prices.size() - 1];
}

//��д���벻��ȷ����ȫ��������Ľ���˼·�����Ը�дҲ���ԣ���Ҫ���궯̬�滮���¿�
int maxProfit(vector<int>& prices) {
	 int n = prices.size();
	 vector<int> sells(n, 0);
	 vector<int> buys(n, 0);
	 buys[0] = -prices[0];
	 if (n == 0)
		return 0;
	 for (int j = 1; j < n; j++) {
	   int	delta = prices[j] - prices[j - 1];
	   sells[j] = max(buys[j - 1] + prices[j], sells[j - 1] + delta);
	   if (j > 1)
			buys[j] = max(buys[j - 1]-delta, sells[j - 2] - prices[j]);
	 }
	 sort(sells.begin(), sells.end(), [](int a, int b) {return a > b; });
	 return sells[0];
	
}

int main()
{
	vector<int> prices = { 1, 2, 3, 0, 2 };
	int res = maxProfit2(prices);
	cout << res << endl;


	system("pause");
    return 0;
}

