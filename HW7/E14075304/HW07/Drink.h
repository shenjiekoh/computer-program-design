// Drink.h
#pragma once
#ifndef DRINK_H
#define DRINK_H

// 飲料類別 Drink
class Drink
{
  public:
	// 建構子
	Drink();	// 預設建構子
	Drink(int myDrink, bool myIce);	// 兩參數建構子（引數為飲料和是否去冰）

	// 成員函式
	void change_drink(int myDrink);	// 更換飲料
	void change_ice(bool myIce);	// 變更冰塊

	// 朋友函式
	friend void show_drink(const Drink& myDrink);	// 顯示飲料內容

  private:
	int drink;		// 飲料選擇
	bool no_ice;	// 是否去冰
};
#endif