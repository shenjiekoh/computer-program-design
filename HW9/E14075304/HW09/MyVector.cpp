// MyVector.cpp
#include "MyVector.h"
#include <cmath>
using namespace std;

// 預設建構子
MyVector::MyVector()
{
	vector = new double[3];
	vector[0] = 0;
	vector[1] = 0;
	vector[2] = 0;
}

// 三個參數的建構子
MyVector::MyVector(double x, double y, double z)
{
	vector = new double[3];
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

// 拷貝建構子
MyVector::MyVector(const MyVector& vec)
{
	vector = new double[3];
	vector[0] = vec[0];
	vector[1] = vec[1];
	vector[2] = vec[2];
}

// 除構子
MyVector::~MyVector()
{
	delete[] vector;
	vector = 0;
}

// 計算向量長度
double MyVector::length() const
{
	return sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
}

// A.設定運算子
MyVector& MyVector::operator=(const MyVector& vec)
{
	if (this == &vec)
		return *this;
	vector = new double[3];
	vector[0] = vec.vector[0];
	vector[1] = vec.vector[1];
	vector[2] = vec.vector[2];
	return *this;
}

// B.向量加法
MyVector MyVector::operator+(const MyVector& vec) const
{
	return MyVector(vector[0] + vec.vector[0], vector[1] + vec.vector[1], vector[2] + vec.vector[2]);
}

// C.向量減法
MyVector MyVector::operator-(const MyVector& vec) const
{
	return MyVector(vector[0] - vec.vector[0], vector[1] - vec.vector[1], vector[2] - vec.vector[2]);
}

// D1.向量內積
double MyVector::operator*(const MyVector& vec) const
{
	return vector[0] * vec.vector[0] + vector[1] * vec.vector[1] + vector[2] * vec.vector[2];
}

// D2.向量乘上實數
MyVector MyVector::operator*(const double& value) const
{
	return MyVector(vector[0] * value, vector[1] * value, vector[2] * value);
}

// D3.實數乘上向量
MyVector operator*(const double& value, const MyVector& vec)
{
	return MyVector(value * vec.vector[0], value * vec.vector[1], value * vec.vector[2]);
}

// E.取分量值
const double& MyVector::operator[](const int index) const
{
	if (index < 0)
	{
		cout << endl << "Negative index";
		exit(1);
	}
	else if (index > 2)
	{
		cout << endl << "Out of range index";
		exit(1);
	}
	else
		return vector[index];
}

// F1.比較兩向量長度
bool MyVector::operator>(const MyVector& vector) const
{
	return this->length() > vector.length();
}

// F2.向量長度與實數比大小
bool MyVector::operator>(const double& value) const
{
	return this->length() > value;
}

// F3.實數與向量長度比大小
bool operator>(const double& value, const MyVector& vector)
{
	return value > vector.length();
}

// G.向量除以實數
MyVector MyVector::operator/(const double& value) const
{
	if (value == 0)
	{
		cout << endl << "Denominator cannot be 0";
		exit(1);
	}
	return MyVector(vector[0] / value, vector[1] / value, vector[2] / value);
}

// H.輸入導向運算子
istream& operator>>(istream& is, MyVector& vec)
{
	cout << "Enter x,y,z : ";
	is >> vec.vector[0] >> vec.vector[1] >> vec.vector[2];
	return is;
}

// I.輸出導向運算子
ostream& operator<<(ostream& os, const MyVector& vec)
{
	os << "(" << vec.vector[0] << ", " << vec.vector[1] << ", " << vec.vector[2] << ")";
	return os;
}