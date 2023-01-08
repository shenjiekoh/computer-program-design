// HW04_01
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function prototypes
inline int Random(const int, const int);
double** Create(const int, const int);
void Create_elements(double**&, const int, const int);
void Convolution(double**, const double*const*const, const int, const int, const double*const*const);
double** Sobel_edge_detection(const double*const*const, const double*const*const, const int, const int);
void Print_matrix(const double*const*const, const int, const int);
double** Maximum(const double*const*const, const int, const int, int&);
void Release(double**&, const int);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	const int lower = 4;	// 亂數下界
	const int upper = 10;	// 亂數上界
	int m = Random(lower, upper);	// rows
	int n = Random(lower, upper);	// columns
	double** result;	// 承接結果用的指標
	int count;			// 最大值的個數

	double** A = Create(m, n);	// 原矩陣A				
	Create_elements(A, m, n);
	cout << "Original matrix A" << endl;
	Print_matrix(A, m, n);
	result = Maximum(A, m, n, count);
	cout << "Max element: " << result[0][0] << endl;
	cout << "Position (row,column): ";
	for (int i = 0; i < count; i++)
		cout << "(" << result[i][1] << "," << result[i][2] << ") ";
	cout << endl << endl;

	double** Sx = Create(3, 3);		// 橫向運算子Sx
	// Sx定義
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Sx[i][j] = 0;
			if (j % 2 == 0)
				Sx[i][j] = 1;
			if (j == 2)
				Sx[i][j] *= -1;
			if (i == 1)
				Sx[i][j] *= 2;
		}
	}
	double** Gx = Create(m, n);		// 矩陣Gx=A*Sx
	Convolution(Gx, A, m, n, Sx);
	cout << "Convolution result with Sx operator" << endl << "Matrix Gx" << endl;
	Print_matrix(Gx, m, n);
	result = Maximum(Gx, m, n, count);
	cout << "Max element: " << result[0][0] << endl;
	cout << "Position (row,column): ";
	for (int i = 0; i < count; i++)
		cout << "(" << result[i][1] << "," << result[i][2] << ") ";
	cout << endl << endl;

	double** Sy = Create(3, 3);		// 縱向運算子Sy
	// Sy定義
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Sy[i][j] = 0;
			if (i % 2 == 0)
				Sy[i][j] = 1;
			if (i == 2)
				Sy[i][j] *= -1;
			if (j == 1)
				Sy[i][j] *= 2;
		}
	}
	double** Gy = Create(m, n);		// 矩陣Gy=A*Sy
	Convolution(Gy, A, m, n, Sy);
	cout << "Convolution result with Sy operator" << endl << "Matrix Gy" << endl;
	Print_matrix(Gy, m, n);
	result = Maximum(Gy, m, n, count);
	cout << "Max element: " << result[0][0] << endl;
	cout << "Position (row,column): ";
	for (int i = 0; i < count; i++)
		cout << "(" << result[i][1] << "," << result[i][2] << ") ";
	cout << endl << endl;

	double** G = Sobel_edge_detection(Gx, Gy, m, n);	//索伯檢測結果矩陣G
	cout << "Sobel edge detection result of matrix A" << endl << "Matrix G" << endl;
	Print_matrix(G, m, n);
	result = Maximum(G, m, n, count);
	cout << "Max element: " << result[0][0] << endl;
	cout << "Position (row,column): ";
	for (int i = 0; i < count; i++)
		cout << "(" << result[i][1] << "," << result[i][2] << ") ";
	cout << endl;

	// 釋放動態空間
	Release(A, m);
	Release(Sx, 3);
	Release(Sy, 3);
	Release(Gx, m);
	Release(Gy, m);
	Release(G, m);
	Release(result, count);
	return 0;
}

inline int Random(const int lower, const int upper)
{
	return ((lower < upper) ? rand() % (upper - lower + 1) + lower : rand() % (lower - upper + 1) + upper);
}

double** Create(const int rows, const int columns)
{
	// 創造動態空間
	double** matrix = new(double*[rows]);
	for (int i = 0; i < rows; i++)
		matrix[i] = new double[columns];
	return matrix;
}

void Create_elements(double**& matrix, const int rows, const int columns)
{
	const int lower = 0;		// 矩陣元素下界
	const int upper = 255;		// 矩陣元素上界
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rand() % (upper - lower + 1);
}

void Convolution(double** result, const double*const*const matrix, const int rows, const int columns, const double*const*const mask)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			double convolution = 0;		// 卷積值
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					if (!(i + x - 1 < 0 || i + x - 1 >= rows || j + y - 1 < 0 || j + y - 1 >= columns))
						convolution += matrix[i + x - 1][j + y - 1] * mask[2 - x][2 - y];
			result[i][j] = convolution;
		}
}

double** Sobel_edge_detection(const double*const*const matrix1, const double*const*const matrix2, const int rows, const int columns)
{
	double** result = Create(rows, columns);	// 為回傳的指標創造動態空間
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			result[i][j] = sqrt(pow(matrix1[i][j], 2) + pow(matrix2[i][j], 2));
	return result;
}

void Print_matrix(const double*const*const matrix, const int rows, const int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(10) << matrix[i][j];
		cout << endl;
	}
}

double** Maximum(const double*const*const matrix, const int rows, const int columns, int& count)
{
	double max = matrix[0][0];		// 矩陣最大元素
	count = 0;		//最大元素個數
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] > max)
				max = matrix[i][j];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] == max)
				count++;
	double** result = Create(count, 3);
	count = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] == max)
			{
				result[count][0] = max;
				result[count][1] = i + 1;
				result[count][2] = j + 1;
				count++;
			}
	return result;
}

void Release(double**& matrix, const int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}