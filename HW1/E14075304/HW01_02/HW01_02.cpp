// HW01_02
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// 設定1~100範圍內的隨機數作為電腦的第一次猜測
	srand((unsigned int)time(0));
	int lower_bound = 0;
	int upper_bound = 100;
	char reply;
	int guess = rand() % upper_bound + lower_bound +1;

	while (guess > lower_bound) // 如果猜測值不大於下限，退出猜測環節
	{
		// 開始進行猜測
		cout << "Is your number less than " << guess << "? (if my guess is equal to your number, press y)\n";
		cin >> reply;
		cout << endl;

		if (tolower(reply) == 'y') 
		{
			upper_bound = guess;	// 調整猜測區間上界
			if (upper_bound - lower_bound == 1)		// 猜測區間只剩兩個數字後，令猜測值等於下界
				guess = lower_bound;
			else
				guess -= (upper_bound - lower_bound) / 2;	// 取新區間中間值作為下一次猜測值
		}
		else if (tolower(reply) == 'n')
		{
			lower_bound = guess;	// 調整猜測區間上界
			guess += (upper_bound - lower_bound) / 2;		// G取新區間中間值作為下一次猜測值
		}
		// 若使用者不是回答y或n，重複詢問
	}

	// 顯示答案
	cout << "Your number is " << upper_bound << endl;
	return 0;
}