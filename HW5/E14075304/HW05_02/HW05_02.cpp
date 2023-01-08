// HW05_02
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// 函式宣告
float Mean(const float*, unsigned int); 	// 平均值
float Max(const float*, unsigned int);		// 最大值
float Q1(const float*, unsigned int);		// 第一四分位數
float SD(const float*, unsigned int);		// 標準差
float In2SD(const float*, unsigned int);	// 資料在兩個標準差內的比例
int random(int, int);			// int亂數
float random(float, float);		// float亂數

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int min_size = 3;		// 陣列大小下界
	int max_size = 17;		// 陣列大小上界
	float min_element = -5.08;		// 元素下界
	float max_element = 15.97;		// 元素上界
	unsigned int arr_size = random(min_size, max_size);		// 陣列大小
	float* arr = new float[arr_size];		// float陣列

	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = random(min_element, max_element);
		cout << setw(8) << arr[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
	float(*pfun[5])(const float*, unsigned int) = { Mean,Max,Q1,SD,In2SD };		// 函數指標陣列
	cout << "Mean = " << pfun[0](arr, arr_size) << "\n"
		<< "Max = " << pfun[1](arr, arr_size) << "\n"
		<< "Q1 = " << pfun[2](arr, arr_size) << "\n"
		<< "SD = " << pfun[3](arr, arr_size) << "\n"
		<< "In2SD = " << pfun[4](arr, arr_size) << "%\n";
	return 0;
}

float Mean(const float* arr, unsigned int num)
{
	float sum = 0;		// 總和
	for (int i = 0; i < num; i++)
		sum += arr[i];
	return sum / num;
}

float Max(const float* arr, unsigned int num)
{
	float max = arr[0];	// 目前最大值
	for (int i = 1; i < num; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

float Q1(const float* arr, unsigned int num)
{
	float* arr_copy = new float[num];		// 複製陣列
	for (unsigned int i = 0; i < num; i++)
		arr_copy[i] = arr[i];
	// 各元素從小到大排列
	for (int i = 0; i < num - 1; i++)
		for (int j = i + 1; j < num; j++)
			if (arr_copy[j] < arr_copy[i])
			{
				float temp = arr_copy[i];
				arr_copy[i] = arr_copy[j];
				arr_copy[j] = temp;
			}
	float index = num * 0.25;	// Q1位置
	float ans;					// Q1答案
	if (index == num / 4)
		ans = (arr_copy[num / 4 - 1] + arr_copy[num / 4]) / 2.0;
	else
		ans = arr_copy[num / 4];
	delete[] arr_copy;		// 刪除複製陣列
	return ans;
}

float SD(const float* arr, unsigned int num)
{
	float mean = Mean(arr, num);	// 平均值
	float sum = 0;					// 總和
	for (int i = 0; i < num; i++)
		sum += pow(arr[i] - mean, 2);
	return sqrt(sum / num);
}

float In2SD(const float* arr, unsigned int num)
{
	float sd = SD(arr, num);		// 標準差
	float mean = Mean(arr, num);	// 平均值
	int count = 0;					// 在兩個標準差範圍內元素個數
	for (int i = 0; i < num; i++)
		if (arr[i] >= mean - 2 * sd && arr[i] <= mean + 2 * sd)
			count++;
	return count * 100.0f / num;
}

int random(int lower, int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

float random(float lower, float upper)
{
	return rand()*(upper - lower) / RAND_MAX + lower;
}