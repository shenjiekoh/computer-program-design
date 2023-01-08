#include <iostream>
#include "Combo.h"

using std::cout;
using std::cin;
using std::endl;

bool upgradeFries = false;	// 升級大薯（預設不加大）
bool upgradeSalad = false;	// 升級大份沙拉（預設不加大）
int McTyphoon = 1;	// 冰颱風口味（預設巧克力味）
int chicken = 1;	// 炸雞口味（預設原味）
int Combo::custom_Count = 0;	// 顧客數量初始為0

// 預設建構子定義（大當克+經典配餐+可樂去冰）
Combo::Combo() : main(1), side('A'), drink(1, true)
{
	++custom_Count;
}

// 三參數建構子定義（主餐、配餐、飲料，飲料預設去冰）
Combo::Combo(int myMain, char mySide, int myDrink)
{
	change_main(myMain);
	change_side(mySide);
	drink.change_drink(myDrink);
	++custom_Count;
}

// 四參數建構子定義（主餐、配餐、飲料、是否去冰）
Combo::Combo(int myMain, char mySide, int myDrink, bool myIce)
{
	change_main(myMain);
	change_side(mySide);
	drink.change_drink(myDrink);
	drink.change_ice(myIce);
	++custom_Count;
}

// 更換主餐函式
void Combo::change_main(int myMain)
{
	main = myMain;
}

// 更換配餐函式
void Combo::change_side(char mySide)
{
	side = toupper(mySide);
	char reply;	// 使用者回覆
	int select;	// 選擇的口味
	switch (side)
	{
	case 'A':	// 經典配餐
		cout << "Upgrade to large fries? (+5NTD) (y/n): ";
		// 若輸入錯誤，程式中斷
		if (!(cin >> reply) || (tolower(reply) != 'y' && tolower(reply) != 'n'))
		{
			cout << "Wrong input!" << endl << "System aborted";
			exit(1);
		}
		else
			if (tolower(reply) == 'y')
				upgradeFries = true;
		break;

	case 'B':	// 清爽配餐
		cout << "Upgrade to large salad? (+10NTD) (y/n): ";
		if (!(cin >> reply) || (tolower(reply) != 'y' && tolower(reply) != 'n'))
		{
			cout << "Wrong input!" << endl << "System aborted";
			exit(1);
		}
		else
			if (tolower(reply) == 'y')
				upgradeSalad = true;
		break;

	case 'C':	// 酷炫配餐
		cout << "Select flavor:" << endl
			<< "1. Chocolate" << endl
			<< "2. Berries" << endl
			<< "3. Coffee" << endl;
		if (!(cin >> select) || select < 0 || select > 3)
		{
			cout << "Wrong input!" << endl << "System aborted";
			exit(1);
		}
		else
		{
			if (select == 2)
				McTyphoon = 2;
			else if (select == 3)
				McTyphoon = 3;
		}
		break;

	case 'D':	// 勁脆配餐
		cout << "Select taste:" << endl
			<< "1. Original" << endl
			<< "2. Spicy" << endl;
		if (!(cin >> select) || (select != 1 && select != 2))
		{
			cout << "Wrong input!" << endl << "System aborted";
			exit(1);
		}
		else
		{
			if (select == 2)
				chicken = 2;
		}
		break;

	case 'E':	// 豪麥配餐
		break;

	default:	// 輸入其他東西則程式中斷
		cout << "Wrong input!" << endl << "System aborted";
		exit(1);
	}
}

// 變更飲料資訊函式
void Combo::change_drink_info(int myDrink, bool myIce)
{
	drink.change_drink(myDrink);
	drink.change_ice(myIce);
}

// 計算價格函式
Cash Combo::TotalPrice()
{
	int main_price[] = { 72,62,99,82,44,60,100,72,110,90,52,44,69,109,109,109,119 };	// 各主餐單價
	int side_price[] = { 55,55,65,68,79 };	// 配餐價格
	int total = main_price[main - 1] + side_price[side - 65] + (upgradeFries ? 5 : 0) + (upgradeSalad ? 10 : 0);
	cout << "Total: " << total << "NTD" << endl;
	Cash price(total);	// 建構套餐價格為Cash物件
	return price;
}

// 獲取目前顧客數的函式
int Combo::GetCustomCount() const
{
	return custom_Count;
}