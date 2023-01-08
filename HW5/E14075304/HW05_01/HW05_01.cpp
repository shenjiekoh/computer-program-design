// HW05_01
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// 樣版函式宣告
template <class T> double Mean(const T*, unsigned int);		// 平均數
template <class T> T Max(const T*, unsigned int);			// 最大值
template <class T> double Q1(const T*, unsigned int);		// 第一四分位數
template <class T> double SD(const T*, unsigned int);		// 標準差
template <class T> double In2SD(const T*, unsigned int);	// 資料在兩個標準差內的比例

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int min_size = 10;		// 陣列大小下界
	int max_size = 50;		// 陣列大小上界
	int min_element = -50;	// 元素下界
	int max_element = 50;	// 元素上界
	unsigned int arr_size = rand() % (max_size - min_size + 1) + min_size;		// 陣列大小

	// short型態陣列輸出
	short* arr_short = new short[arr_size];
	cout << "arr_short:\n";
	for (unsigned int i = 0; i < arr_size; i++)
	{
		arr_short[i] = rand() % (max_element - min_element + 1) + min_element;
		cout << setw(4) << arr_short[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl
		<< "Mean_short = " << Mean(arr_short, arr_size) << "\n"
		<< "Max_short = " << Max(arr_short, arr_size) << "\n"
		<< "Q1_short = " << Q1(arr_short, arr_size) << "\n"
		<< "SD_short = " << SD(arr_short, arr_size) << "\n"
		<< "In2SD_short = " << In2SD(arr_short, arr_size) << "%\n\n";

	// int型態陣列輸出
	int* arr_int = new int[arr_size];
	cout << "arr_int:\n";
	for (unsigned int i = 0; i < arr_size; i++)
	{
		arr_int[i] = rand() % (max_element - min_element + 1) + min_element;
		cout << setw(4) << arr_int[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl
		<< "Mean_int = " << Mean(arr_int, arr_size) << "\n"
		<< "Max_int = " << Max(arr_int, arr_size) << "\n"
		<< "Q1_int = " << Q1(arr_int, arr_size) << "\n"
		<< "SD_int = " << SD(arr_int, arr_size) << "\n"
		<< "In2SD_int = " << In2SD(arr_int, arr_size) << "%\n\n";

	// float型態陣列輸出
	float* arr_float = new float[arr_size];
	cout << "arr_float:\n";
	for (unsigned int i = 0; i < arr_size; i++)
	{
		arr_float[i] = rand() * (max_element - min_element) * 1.0 / RAND_MAX + min_element;
		cout << setw(10) << arr_float[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl
		<< "Mean_float = " << Mean(arr_float, arr_size) << "\n"
		<< "Max_float = " << Max(arr_float, arr_size) << "\n"
		<< "Q1_float = " << Q1(arr_float, arr_size) << "\n"
		<< "SD_float = " << SD(arr_float, arr_size) << "\n"
		<< "In2SD_float = " << In2SD(arr_float, arr_size) << "%\n\n";

	// double型態陣列輸出
	double* arr_double = new double[arr_size];
	cout << "arr_double:\n";
	for (unsigned int i = 0; i < arr_size; i++)
	{
		arr_double[i] = rand() * (max_element - min_element) * 1.0 / RAND_MAX + min_element;
		cout << setw(10) << arr_double[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl
		<< "Mean_double = " << Mean(arr_double, arr_size) << "\n"
		<< "Max_double = " << Max(arr_double, arr_size) << "\n"
		<< "Q1_double = " << Q1(arr_double, arr_size) << "\n"
		<< "SD_double = " << SD(arr_double, arr_size) << "\n"
		<< "In2SD_double = " << In2SD(arr_double, arr_size) << "%\n\n";

	delete[] arr_short;
	delete[] arr_int;
	delete[] arr_float;
	delete[] arr_double;
	return 0;
}

template <class T> double Mean(const T* arr, unsigned int num)
{
	double sum = 0;		// 元素總和
	for (int i = 0; i < num; i++)
		sum += arr[i];
	return sum / num;
}

template <class T> T Max(const T* arr, unsigned int num)
{
	T max = arr[0];		//目前最大值
	for (int i = 1; i < num; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template <class T> double Q1(const T* arr, unsigned int num)
{
	T* arr_copy = new T[num];	// 複製陣列
	for (unsigned int i = 0; i < num; i++)
		arr_copy[i] = arr[i];
	// 各元素從小到大排列
	for (int i = 0; i < num - 1; i++)
		for (int j = i + 1; j < num; j++)
			if (arr_copy[j] < arr_copy[i])
			{
				T temp = arr_copy[i];
				arr_copy[i] = arr_copy[j];
				arr_copy[j] = temp;
			}
	double index = num * 0.25;	// Q1位置
	double ans;					// Q1答案
	if (index == num / 4)
		ans = (arr_copy[num / 4 - 1] + arr_copy[num / 4]) / 2.0;
	else
		ans = arr_copy[num / 4];
	delete[] arr_copy;			// 刪除複製陣列
	return ans;
}

template <class T> double SD(const T* arr, unsigned int num)
{
	double mean = Mean(arr, num);	// 平均值
	double sum = 0;					// 總和
	for (int i = 0; i < num; i++)
		sum += pow(arr[i] - mean, 2);
	return sqrt(sum / num);
}

template <class T> double In2SD(const T* arr, unsigned int num)
{
	double sd = SD(arr, num);		// 標準差
	double mean = Mean(arr, num);	// 平均值
	int count = 0;					// 在兩個標準差範圍內元素個數
	for (int i = 0; i < num; i++)
		if (arr[i] >= mean - 2 * sd && arr[i] <= mean + 2 * sd)
			count++;
	return count * 100.0 / num;
}