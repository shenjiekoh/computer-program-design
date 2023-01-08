// HW02_01
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	int num[5][5] = {};		// 存放數字的陣列
	srand(static_cast<unsigned int>(time(0)));

	// 產生15個數字的下三角矩陣
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			bool check;		//檢查數字是否重複，不重複為true，重複為false
			// 產生隨機數後進行檢查，若有重複則重新生成數字
			do
			{
				check = true;
				num[i][j] = rand() % 104 + 1;
				for (int m = 0; m <= i; m++)
				{
					for (int n = 0; (m == i ? n < j : n <= m); n++)
					{
						if (num[m][n] == num[i][j])
						{
							check = false;
							break;
						}
						else
							check = true;
					}
					if (check == false)
						break;
				}
			} while (check == false);
			cout << left << setw(4) << num[i][j];
		}
		cout << endl;
	}

	// 消除數字
	while (true)
	{
		int select[3] = {};		// 存放使用者輸入數字的陣列
		int count = 0;			// 數字個數
		bool valid;
		string input;		// 使用者輸入的字串
		string separators = " ,";		// 分隔符號（空白或逗號）
		do
		{
			// 使用者輸入
			cout << "Select 1~3 number(s) to eliminate: ";
			getline(cin, input);

			for (size_t index = input.find_first_not_of(separators); index < input.length(); index++)
			{
				if (isdigit(input[index]) || input[index] == ' ' || input[index] == ',')
					valid = true;
				else
				{
					valid = false;
					break;
				}
			}
		} while (!valid);
		

		size_t start = input.find_first_not_of(separators);		// 字串起點
		size_t end = 0;		// 字串終點

		// 找出字串內的數值並存在select陣列中
		while (start != string::npos)
		{
			end = input.find_first_of(separators, start + 1);
			if (end == string::npos)
				end = input.length();
			select[count++] = stoi((input.substr(start, end - start)));
			if (count >= 3)
				break;
			start = input.find_first_not_of(separators, end + 1);
		}

		// 選中的數字填上0
		for (int i = 0; i <= count; i++)
		{
			for (int m = 0; m < 5; m++)
			{
				for (int n = 0; n <= m; n++)
				{
					if (select[i] == num[m][n])
					{
						num[m][n] = 0;
						select[i] = 0;
						break;
					}
				}
				if (select[i] == 0)
					break;
			}
		}
		cout << endl;

		// 驗證陣列數字是否全部為0
		int sum = 0;		// 所有陣列數字之和
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				sum += num[i][j];
				cout << left << setw(4) << num[i][j];
			}
			cout << endl;
		}

		if (sum == 0)
			break;
	}
	cout << "Thank you for playing!" << endl;
	return 0;
}
