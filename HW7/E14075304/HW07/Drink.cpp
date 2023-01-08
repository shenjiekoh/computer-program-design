// Drink.cpp
#include <iostream>
#include <string>
#include "Drink.h"

// 預設建構子定義，預設可樂去冰
Drink::Drink() : drink(1), no_ice(true) {}

// 兩參數建構子定義
Drink::Drink(int myDrink, bool myIce) : drink(myDrink), no_ice(myIce) {}

// 更換飲料函式定義
void Drink::change_drink(int myDrink)
{
	drink = myDrink;
}

// 變更冰塊函式定義
void Drink::change_ice(bool myIce)
{
	no_ice = myIce;
}