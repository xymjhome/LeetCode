// 292. Nim Game.cpp : �������̨Ӧ�ó������ڵ㡣
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
			cout << "�˶�ʯͷ��Ŀ" << n << "��Ӯ" << endl;
		}
		else {
			cout << "�˶�ʯͷ��Ŀ" << n << "����" << endl;
		}
	
	}
	
	system("pause");
    return 0;
}

