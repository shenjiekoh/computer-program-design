// HW03
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));	// 隨機亂數種子
	// 隨機矩陣A的維度大小
	int m = rand() % (10 - 4 + 1) + 4;
	int n = rand() % (10 - 4 + 1) + 4;
	double **A = new(double *[m]);	// 原始矩陣A動態空間
	for (int i = 0; i < m; i++)
		A[i] = new double[n];

	// 輸出原始矩陣A
	cout << "Original matrix A" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 256;
			cout << setw(10) << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	double Sx[3][3] = { {1,0,-1}, {2,0,-2}, {1,0,-1} };	// 橫向運算子Sx
	double **Gx = new(double *[m]);	// 矩陣Gx動態空間
	for (int i = 0; i < m; i++)
		Gx[i] = new double[n];

	// 計算各元素卷積值並輸出矩陣Gx
	cout << "Convolution result with Sx operator" << endl << "Matrix Gx" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double convolution = 0;	// 卷積值
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					if (!(i + x - 1 < 0 || i + x - 1 >= m || j + y - 1 < 0 || j + y - 1 >= n))
						convolution += A[i + x - 1][j + y - 1] * Sx[2 - x][2 - y];
			Gx[i][j] = convolution;
			cout << setw(10) << Gx[i][j];
		}
		cout << endl;
	}
	cout << endl;

	double Sy[3][3] = { {1,2,1}, {0,0,0}, {-1,-2,-1} };	// 縱向運算子Sy
	double **Gy = new(double *[m]);	// 矩陣Gy動態空間
	for (int i = 0; i < m; i++)
		Gy[i] = new double[n];

	// 計算各元素卷積值並輸出矩陣Gy
	cout << "Convolution result with Sy operator" << endl << "Matrix Gy" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double convolution = 0;
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					if (!(i + x - 1 < 0 || i + x - 1 >= m || j + y - 1 < 0 || j + y - 1 >= n))
						convolution += A[i + x - 1][j + y - 1] * Sy[2 - x][2 - y];
			Gy[i][j] = convolution;
			cout << setw(10) << Gy[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	double **G = new(double *[m]);	// 矩陣G動態空間
	for (int i = 0; i < m; i++)
		G[i] = new double[n];

	// 橫縱向值結合並輸出矩陣G
	cout << "Sobel edge detection result of matrix A" << endl << "Matrix G" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G[i][j] = sqrt(pow(Gx[i][j], 2) + pow(Gy[i][j], 2));
			cout << setw(10) << G[i][j];
		}
		cout << endl;
	}
	cout << endl;

	double max_A = A[0][0];	// 矩陣A最大元素
	int row_max_A;	// 最大元素所在row
	int column_max_A;	//最大元素所在column

	// 尋找最大值及其所在位置
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] > max_A)
				max_A = A[i][j];

	cout << "Max element of A: " << max_A << endl;
	cout << "Position (row,column): ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == max_A)
			{
				row_max_A = i + 1;
				column_max_A = j + 1;
				cout << "(" << row_max_A << "," << column_max_A << ") ";
			}
		}
	}
	cout << endl << endl;

	double max_Gx = Gx[0][0];	// 矩陣Gx最大元素
	int row_max_Gx;
	int column_max_Gx;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (Gx[i][j] > max_Gx)
				max_Gx = Gx[i][j];

	cout << "Max element of Gx: " << max_Gx << endl;
	cout << "Position (row,column): ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Gx[i][j] == max_Gx)
			{
				row_max_Gx = i + 1;
				column_max_Gx = j + 1;
				cout << "(" << row_max_Gx << "," << column_max_Gx << ") ";
			}
		}
	}
	cout << endl << endl;

	double max_Gy = Gy[0][0];	// 矩陣Gy最大元素
	int row_max_Gy;
	int column_max_Gy;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (Gy[i][j] > max_Gy)
				max_Gy = Gy[i][j];

	cout << "Max element of Gy: " << max_Gy << endl;
	cout << "Position (row,column): ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Gy[i][j] == max_Gy)
			{
				row_max_Gy = i + 1;
				column_max_Gy = j + 1;
				cout << "(" << row_max_Gy << "," << column_max_Gy << ") ";
			}
		}
	}
	cout << endl << endl;

	double max_G = G[0][0];		// 矩陣G最大元素
	int row_max_G;
	int column_max_G;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (G[i][j] > max_G)
				max_G = G[i][j];

	cout << "Max element of G: " << max_G << endl;
	cout << "Position (row,column): ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (G[i][j] == max_G)
			{
				row_max_G = i + 1;
				column_max_G = j + 1;
				cout << "(" << row_max_G << "," << column_max_G << ") ";
			}
		}
	}
	cout << endl;

	// 釋放所有動態記憶體空間
	for (int i = 0; i < m; i++)
	{
		delete[] A[i];
		delete[] Gx[i];
		delete[] Gy[i];
		delete[] G[i];
	}
	delete[] A;
	delete[] Gx;
	delete[] Gy;
	delete[] G;
	return 0;
}