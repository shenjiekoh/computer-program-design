// HW01_01
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// 設定100元張數
	srand((unsigned int)time(0));	
	int num = rand() % 17 + 4;
	int reply;
	int amount;
	
	// 選擇提款金額
	cout << "Select amount:" << endl
		<< "1. $10000" << endl
		<< "2. $5000" << endl
		<< "3. $2000" << endl
		<< "4. $1000" << endl
		<< "5. Custom" << endl
		<< "Press any key to cancel..." << endl;
	cin >> reply;

	// 記錄提款金額
	switch (reply)
	{
	case 1:
		amount = 10000;
		break;
	case 2:
		amount = 5000;
		break;
	case 3:
		amount = 2000;
		break;
	case 4:
		amount = 1000;
		break;
	case 5:
		do
		{
			cout << endl << "Enter amount: $";
			cin >> amount;
			if (amount % 100 != 0)		// 款項不能用100元提出
				cout << "Invalid enter. Try again.";
			else if (amount % 1000 / 100 > num)		// 100元不足
				cout << "$100 is not enough. Try again.";
			else
				break;
		} while (true);
		break;
	default:
		exit(1);	// 取消
	}
	cout << endl;

	// 計算所需100元和1000元的張數
	int num_1000 = amount / 1000;
	int num_100 = amount % 1000 / 100;

	// 向使用者提問是否要把1000元換成100元
	cout << "Exchange $1000 for $100?" << endl
		<< "1. Yes" << endl
		<< "2. No" << endl;
	cin >> reply;


	if (reply == 1)
	{
		// 使用者輸入1000元張數
		int change;
		cout << endl;
		cout << "How many $1000 do you want to exchange for $100?" << endl;
		cin >> change;

		// 判斷換鈔數量
		if (change * 10 + num_100 > num)
		{
			num_100 += (num - num_100) / 10 * 10;
			num_1000 -= num_100 / 10;
		}
		if (num_100 < 10)
			cout << "Not enough $100 notes for exchanging!" << endl;
	}
	cout << endl;

	// 顯示結果
	cout << "$1000 : " << num_1000 << endl
		<< "$100 : " << num_100 << endl
		<< "Total : $" << amount << endl;

	return 0;
}
