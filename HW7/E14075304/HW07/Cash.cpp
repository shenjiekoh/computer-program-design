// Cash.cpp
#include <iostream>
#include "Cash.h"

using std::cout;
using std::endl;

// 一參數建構子定義
Cash::Cash(int cash)
{
	total = cash;
}

// 轉換零錢函數定義
void Cash::convert(int cash)
{
	one_thousand = cash / 1000;
	five_hundred = (cash % 1000) / 500;
	one_hundred = (cash % 500) / 100;
	fifty = (cash % 100) / 50;
	ten = (cash % 50) / 10;
	five = (cash % 10) / 5;
	one = cash % 5;
}

// 找零函數定義，輸入消費者付費金額，函數內換算應找零金額
void Cash::change(int payment)
{
	if (payment < total)	// 若付費金額不足支付餐點價格，系統中斷退出
	{
		cout << "Your payment is not enough..." << endl << "System aborted";
		exit(1);
	}
	total = payment - total;
}

// 列印函數定義，輸出找零金額
void Cash::print()
{
	convert(total);
	cout << "CHANGE: " << total << "NTD" << endl
		<< one_thousand << " x 1000NTD" << endl
		<< five_hundred << " x 500NTD" << endl
		<< one_hundred << " x 100NTD" << endl
		<< fifty << " x 50NTD" << endl
		<< ten << " x 10NTD" << endl
		<< five << " x 5NTD" << endl
		<< one << " x 1NTD" << endl;
	cout << endl;
}