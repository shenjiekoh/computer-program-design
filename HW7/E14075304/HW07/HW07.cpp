// HW07
// 許笙杰 E14075304 機械二乙
#include <iostream>
#include <iomanip>
#include <string>
#include "Combo.h"

using namespace std;

void show_menu();	// 顯示菜單
void error();	// 顯示錯誤訊息

// 外部變數
extern bool upgradeFries;	// 升級大薯
extern bool upgradeSalad;	// 升級大沙拉
extern int McTyphoon;	// 冰颱風口味
extern int chicken;		// 炸雞口味

int main()
{
	int main;	// 主餐
	char side;	// 配餐
	int drink;	// 飲料
	int ice;	// 冰塊
	int payment;	// 付費金額
	
	show_menu();	// 顯示菜單

	// 第一位顧客
	cout << "Select main course (1~17): ";
	if (!(cin >> main) || main < 1 || main > 17)	// 輸入錯誤，程式中斷顯示錯誤訊息
		error();
	cout << "Select side dish (A/B/C/D/E): ";
	if (!(cin >> side) || toupper(side) < 'A' || toupper(side) > 'E')
		error();
	cout << "Choose drink (1~5): ";
	if (!(cin >> drink) || drink < 1 || drink > 5)
		error();
	cout << "Do you want to remove ice cube from your drink? (Yes:1 No:0)" << endl;
	if (!(cin >> ice) || (ice != 0 && ice != 1))
		error();
	Combo customer1(main, side, drink, ice);	// 建立第一位顧客的套餐物件
	show_combo(customer1);	// 顯示套餐內容
	Cash total1 = customer1.TotalPrice();	// 計算並顯示第一位顧客套餐價格
	cout << "Pay please (Insert number): ";	// 輸入付費金額
	if (!(cin >> payment))
		error();
	total1.change(payment);
	total1.print();	// 輸出找零結果
	
	// 第二位顧客
	cout << "Select main course (1~17): ";
	if (!(cin >> main) || main < 1 || main > 17)
		error();
	cout << "Select side dish (A/B/C/D/E): ";
	if (!(cin >> side) || toupper(side) < 'A' || toupper(side) > 'E')
		error();
	cout << "Choose drink (1~5): ";
	if (!(cin >> drink) || drink < 1 || drink > 5)
		error();
	Combo customer2(main, side, drink);	// 建立第二位顧客的套餐物件
	cout << "Do you want to remove ice cube from your drink? (Yes:1 No:0)" << endl;	// 詢問是否去冰
	if (!(cin >> ice) || (ice != 0 && ice != 1))
		error();
	customer2.change_drink_info(drink, ice);
	show_combo(customer2);
	Cash total2 = customer2.TotalPrice();	// 計算並顯示第二位顧客套餐價格
	cout << "Pay please (Insert number): ";
	if (!(cin >> payment))
		error();
	total2.change(payment);
	total2.print();

	// 第三位顧客
	Combo customer3;	// 預設套餐
	cout << "Select main course (1~17): ";
	if (!(cin >> main) || main < 1 || main > 17)
		error();
	customer3.change_main(main);
	cout << "Select side dish (A/B/C/D/E): ";
	if (!(cin >> side) || toupper(side) < 'A' || toupper(side) > 'E')
		error();
	customer3.change_side(side);
	cout << "Choose drink (1~5): ";
	if (!(cin >> drink) || drink < 1 || drink > 5)
		error();
	cout << "Do you want to remove ice cube from your drink? (Yes:1 No:0)" << endl;
	if (!(cin >> ice) || (ice != 0 && ice != 1))
		error();
	customer3.change_drink_info(drink, ice);
	show_combo(customer3);
	Cash total3 = customer3.TotalPrice();	// 計算並顯示第三位顧客套餐價格
	cout << "Pay please (Insert number): ";
	if (!(cin >> payment))
		error();
	total3.change(payment);
	total3.print();
	cout << "Customer Count: " << customer3.GetCustomCount() << endl;	// 輸出目前顧客數量
	return 0;
}

// 顯示菜單函式定義
void show_menu()
{
	cout << setw(50) << "MENU" << endl;
	for (int i = 1; i <= 100; i++)
		cout << "=";
	cout << endl;
	cout << setw(40) << "Main course" << endl;
	cout << "(1) BigDonald\t\t\t\t\t\t\t72"<< endl
		<< "(2) Single Beef Burger\t\t\t\t\t\t62" << endl
		<< "(3) Florence Beef Burger\t\t\t\t\t99" << endl
		<< "(4) Roasted Chicken Burger\t\t\t\t\t82" << endl
		<< "(5) DonaldChicken\t\t\t\t\t\t44" << endl
		<< "(6) Chicken DonaldNuggets (6pcs)\t\t\t\t60" << endl
		<< "(7) Chicken DonaldNuggets (10pcs)\t\t\t\t100" << endl
		<< "(8) Spicy Chicken Fillet Burger\t\t\t\t\t72" << endl
		<< "(9) Chicken DonaldCrispy (2pcs)\t\t\t\t\t110" << endl
		<< "(10) Chicken DonaldCrispy Wings(2pcs)\t\t\t\t90" << endl
		<< "(11) Shrimp Burger with Cheese Sauce\t\t\t\t52" << endl
		<< "(12) Fillet-O-Fish\t\t\t\t\t\t44" << endl
		<< "(13) Fish Burger with Thousand Island Sauce\t\t\t69" << endl
		<< "(14) ABC Florence Beef Burger\t\t\t\t\t109" << endl
		<< "(15) ABC Spicy Chicken Fillet Burger\t\t\t\t109" << endl
		<< "(16) ABC Roasted Chicken Burger\t\t\t\t\t109" << endl
		<< "(17) Florence Beef Burger with King Oyster Mushroom\t\t119" << endl;
	for (int i = 1; i <= 100; i++)
		cout << "-";
	cout << endl;
	cout << setw(55) << "Side dish\t\t\t    |  Drink" << endl;
	cout << "(A) Classic Set - French Fries + Drink(M)\t\t\t55  |  (1) Coke" << endl
		<< "(B) Light Set - Summer Salad + Drink(M)\t\t\t\t55  |  (2) Diet Coke" << endl
		<< "(C) Cool Set - McTyphoon + Drink(M)\t\t\t\t65  |  (3) Black Tea" << endl
		<< "(D) Crispy Set - Chicken DonaldCrispy + Drink(M)\t\t68  |  (4) Green Tea" << endl
		<< "(E) HeroMc Set - Chicken Chop + French Fries(S) + Drink(M)\t79  |  (5) Orange Juice" << endl;
	for (int i = 1; i <= 100; i++)
		cout << "=";
	cout << endl << endl;
}

// 顯示錯誤訊息函式定義
void error()
{
	cout << "Wrong input!" << endl << "System aborted";
	exit(1);
}

// 顯示飲料內容朋友函式定義
void show_drink(const Drink& myDrink)
{
	string drink_menu[5] = { "(1) Coke","(2) Diet Coke","(3) Black Tea","(4) Green Tea","(5) Orange Juice" };
	cout << "Drink: " << drink_menu[myDrink.drink - 1] << "(M)" << (myDrink.no_ice == true ? " (No ice)" : "");
}

// 顯示套餐內容朋友函式定義
void show_combo(const Combo& myCombo)
{
	string main_menu[] = { "(1) BigDonald",
						   "(2) Single Beef Burger",
						   "(3) Florence Beef Burger",
						   "(4) Roasted Chicken Burger",
						   "(5) DonaldChicken",
						   "(6) Chicken DonaldNuggets (6pcs)",
						   "(7) Chicken DonaldNuggets (10pcs)",
						   "(8) Spicy Chicken Fillet Burger",
						   "(9) Chicken DonaldCrispy (2pcs)",
						   "(10) Chicken DonaldCrispy Wings(2pcs)",
						   "(11) Shrimp Burger with Cheese Sauce",
						   "(12) Fillet-O-Fish",
						   "(13) Fish Burger with Thousand Island Sauce",
						   "(14) ABC Florence Beef Burger",
						   "(15) ABC Spicy Chicken Fillet Burger",
						   "(16) ABC Roasted Chicken Burger",
						   "(17) Florence Beef Burger with King Oyster Mushroom" };
	string side_menu[] = { "(A) Classic Set - French Fries",
						   "(B) Light Set - Summer Salad",
						   "(C) Cool Set - McTyphoon",
						   "(D) Crispy Set - Chicken DonaldCrispy",
						   "(E) HeroMc Set - Chicken Chop + French Fries(S)" };
	string size[2] = { "(M)","(L)" };
	string flavor[3] = { "(Chocolate)","(Berries)","(Coffee)" };
	string taste[2] = { "(Original)","(Spicy)" };
	cout << "Your order:" << endl;
	cout << main_menu[myCombo.main - 1] << endl;
	cout << side_menu[myCombo.side - 65];
	switch (myCombo.side)
	{
	case 'A':
		cout << size[upgradeFries];
		break;
	case 'B':
		cout << size[upgradeSalad];
		break;
	case 'C':
		cout << flavor[McTyphoon - 1];
		break;
	case 'D':
		cout << taste[chicken - 1];
		break;
	}
	cout << " + Drink(M)" << endl;
	show_drink(myCombo.drink);
	cout << endl;
}