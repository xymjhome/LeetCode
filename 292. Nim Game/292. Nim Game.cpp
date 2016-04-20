// 292. Nim Game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
bool canWinNim(int n) {
	if (n % 4 == 0)
		return false;
	return true;
}

int main()
{
	while(true){
		int n;
		cin >> n;
		if (canWinNim(n))
		{
			cout << "此堆石头数目" << n << "必赢" << endl;
		}
		else {
			cout << "此堆石头数目" << n << "必输" << endl;
		}
	
	}
	
	system("pause");
    return 0;
}

