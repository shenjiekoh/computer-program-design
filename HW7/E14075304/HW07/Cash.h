// Cash.h
#pragma once
#ifndef CASH_H
#define CASH_H

// 錢組合類別 Cash
class Cash
{
  public:
	// 建構子
	Cash(int cash);	// 一參數建構子（引數為輸入金額）

	// 成員函式
	void convert(int cash);	// 將總金額轉換為各項零錢或鈔票數目的函數
	void change(int payment);	// 計算找零金額的函數
	void print();	// 列印函數

  private:
	int one_thousand;	// 1000元數量
	int five_hundred;	// 500元數量
	int one_hundred;	// 100元數量
	int fifty;	// 50元數量
	int ten;	// 10元數量
	int five;	// 5元數量
	int one;	// 1元數量
	int total;	// 總共金額
};
#endif