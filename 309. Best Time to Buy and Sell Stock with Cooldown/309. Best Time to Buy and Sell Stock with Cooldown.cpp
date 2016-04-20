// 309. Best Time to Buy and Sell Stock with Cooldown.cpp : 定义控制台应用程序的入口点。
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

//internet 需要以后复习动态规划（Dynamic Programming）后在仔细看，现在不明白
//解法I：
//
//引入辅助数组sells和buys
//
//sells[i]表示在第i天卖出股票所能获得的最大累积收益
//buys[i]表示在第i天买入股票所能获得的最大累积收益
//
//初始化令sells[0] = 0，buys[0] = -prices[0]
//
//第i天交易时获得的累计收益只与第i - 1天与第i - 2天有关
//
//记第i天与第i - 1天的价格差：delta = price[i] - price[i - 1]
//
//状态转移方程为：
//
//sells[i] = max(buys[i - 1] + prices[i], sells[i - 1] + delta)
//buys[i] = max(sells[i - 2] - prices[i], buys[i - 1] - delta)
//
//上述方程的含义为：
//
//第i天卖出的最大累积收益 = max(第i - 1天买入~第i天卖出的最大累积收益, 第i - 1天卖出后反悔~改为第i天卖出的最大累积收益)
//第i天买入的最大累积收益 = max(第i - 2天卖出~第i天买入的最大累积收益, 第i - 1天买入后反悔~改为第i天买入的最大累积收益)
//
//而实际上：
//
//第i - 1天卖出后反悔，改为第i天卖出 等价于 第i - 1天持有股票，第i天再卖出
//第i - 1天买入后反悔，改为第i天买入 等价于 第i - 1天没有股票，第i天再买入
//
//所求的最大收益为max(sells)。显然，卖出股票时才可能获得收益。
//Python代码：
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



//Internet  C++代码
int maxProfit2(vector<int>& prices) {
	if (prices.size() < 2) return 0;
	//未持有股票
	vector<int> sell(prices.size(), 0);
	//持有股票
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

//改写代码不正确，完全不理解此题的解题思路，所以改写也不对，需要看完动态规划重新看
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

