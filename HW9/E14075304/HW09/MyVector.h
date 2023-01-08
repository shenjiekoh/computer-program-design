// MyVector.h
#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;
class MyVector
{
public:
	MyVector();	// 預設建構子
	MyVector(double x, double y, double z);	// 三個參數的建構子
	MyVector(const MyVector&);	// 拷貝建構子
	~MyVector();	// 除構子

	double length() const;	// 計算向量長度
	MyVector& operator=(const MyVector& vec);	// A.設定運算子
	MyVector operator+(const MyVector& vec) const;	// B.向量加法
	MyVector operator-(const MyVector& vec) const;	// C.向量減法
	double operator*(const MyVector& vec) const;	// D1.向量內積
	MyVector operator*(const double& value) const;	// D2.向量乘上實數
	friend MyVector operator*(const double& value, const MyVector& vec);	// D3.實數乘上向量
	const double& operator[](const int index) const;	// E.取分量值
	bool operator>(const MyVector& vec) const;	// F1.比較兩向量長度
	bool operator>(const double& value) const;	// F2.向量長度與實數比大小
	friend bool operator>(const double& value, const MyVector& vector);	// F3.實數與向量長度比大小
	MyVector operator/(const double& value) const;	// G.向量除以實數
	friend istream& operator>>(istream& is, MyVector& vector);	// H.輸入導向運算子
	friend ostream& operator<<(ostream& os, const MyVector& vector);	// I.輸出導向運算子

private:
	double* vector;	// 向量
};
#endif