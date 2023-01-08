// HW04_02
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void rescue(int*, const int, const int);

int main()
{
	int victim;		// 受困者人數
	int number;		// 報數時報到此數就可離開
	string input1;	// 輸入字串1
	string input2;	// 輸入字串2
	bool valid;		// 輸入是否合法?

	// 輸入受困者人數
	do
	{
		valid = true;
		cout << "How many victims do you have?" << endl;
		getline(cin, input1);
		for (size_t index = 0; input1[index] != '\0'; index++)
			if (!isdigit(input1[index]))
			{
				valid = false;
				break;
			}
	} while (!valid);
	victim = stoi(input1);

	// 輸入報數幸運數字
	do
	{
		valid = true;
		cout << "Which number can be rescued?" << endl;
		getline(cin, input2);
		for (size_t index = 0; input2[index] != '\0'; index++)
			if (!isdigit(input2[index]))
			{
				valid = false;
				break;
			}
	} while (!valid);
	number = stoi(input2);

	cout << endl;
	int* arr_victim = new int[victim];		// 受困者解救順序的動態陣列
	rescue(arr_victim, victim, number);
	delete[] arr_victim;		// 釋放動態空間
	return 0;
}

void rescue(int* arr, const int num_victim, const int rescue_num)
{
	// 陣列歸零
	for (int i = 0; i < num_victim; i++)
		arr[i] = 0;
	int n = -1;	// 受困者編號初始值
	for (int i = 1; i <= num_victim; i++)
	{
		int count = 0;	// 受困者報數
		// 記錄報到幸運數字的受困者編號
		while (count < rescue_num)
		{
			n = (n + 1) % num_victim;
			if (arr[n] == 0)	// 若第(n+1)個受困者還沒離開，繼續報數
				count++;
		}
		arr[n] = i;		// i為第(n+1)個受困者的離開順序
	}
	cout << "Rescue sequence:" << endl;
	for (int i = 0; i < num_victim; i++)
	{
		cout << setw(4) << arr[i] << (i != num_victim - 1 ? ", " : " ");
		if ((i + 1) % 20 == 0)
			cout << endl;
	}
}