// Combo.h
#pragma once
#ifndef COMBO_H
#define COMBO_H
#include "Drink.h"
#include "Cash.h"

// 套餐類別 Combo
class Combo
{
  public:
	// 建構子
	Combo();	// 預設建構子
	Combo(int myMain, char mySide, int myDrink);	// 三參數建構子
	Combo(int myMain, char mySide, int myDrink, bool myIce);	// 四參數建構子

	// 成員函式
	void change_main(int myMain);	// 更換主餐
	void change_side(char mySide);	// 更換配餐
	void change_drink_info(int myDrink, bool myIce);	// 變更飲料資訊（包含更換飲料、是否去冰）
	Cash TotalPrice();	// 計算價格的函式
	int GetCustomCount() const;	// 獲取目前顧客數的函式

	// 朋友函式
	friend void show_combo(const Combo& myCombo);	// 顯示套餐內容的朋友函式

  private:
	int main;	// 主餐
	char side;	// 配餐
	static int custom_Count;	// 顧客數
	Drink drink;	// 飲料物件
};
#endif