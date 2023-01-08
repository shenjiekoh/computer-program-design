// HW06_02
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//自訂資料型態 MyMatrix，其成員包含指向二維動態陣列的指標、矩陣的行與列之值三個成員
struct MyMatrix
{
	double** Data;
	unsigned int rows;
	unsigned int columns;
};

//自訂資料型態 MyValue，其成員包含欲紀錄之數值、記錄其所在矩陣之位置(地址)的指標、其在矩陣內之位置(下標)
struct MyValue
{
	double Data;
	MyMatrix* matrix;
	unsigned int rows;
	unsigned int columns;
};

//Function prototypes
inline int Random(const int, const int);	//2
void Create(MyMatrix&);	//1-1
void Create(MyMatrix&, const int, const int);	//1-2
void Create_elements(MyMatrix&);	//3
MyMatrix Convolution(const MyMatrix&, const MyMatrix&); //4
void Print_Matrix(const MyMatrix&); //5
MyValue Maximum(MyMatrix&); //6
void Print_Max(const MyValue&);	//7
void Release(MyMatrix&);	//8

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//索伯運算子宣告
	double mask_Sx[3][3] = { {1,0,-1}, {2,0,-2}, {1,0,-1} };
	double mask_Sy[3][3] = { {1,2,1}, {0,0,0}, {-1,-2,-1} };

	MyMatrix A;	//影像矩陣A
	Create(A);
	Create_elements(A);
	cout << "Matrix A" << endl;
	Print_Matrix(A);
	Print_Max(Maximum(A));

	MyMatrix Sx, Sy;	//索伯運算子Sx和Sy
	Create(Sx, 3, 3);
	Create(Sy, 3, 3);
	//把double型態矩陣轉為MyMatrix型態矩陣
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			Sx.Data[i][j] = mask_Sx[i][j];
			Sy.Data[i][j] = mask_Sy[i][j];
		}

	MyMatrix Gx = Convolution(A, Sx);	//矩陣Gx=A*Sx
	cout << "Convolution with Sobel operator Sx (Matrix Gx)" << endl;
	Print_Matrix(Gx);
	Print_Max(Maximum(Gx));

	MyMatrix Gy = Convolution(A, Sy);	//矩陣Gy=A*Sy
	cout << "Convolution with Sobel operator Sy (Matrix Gy)" << endl;
	Print_Matrix(Gy);
	Print_Max(Maximum(Gy));

	MyMatrix G;	//索伯檢測結果矩陣G
	Create(G, A.rows, A.columns);
	cout << "Sobel edge detection result (Matrix G)" << endl;
	for (int i = 0; i < A.rows; i++)
		for (int j = 0; j < A.columns; j++)
			G.Data[i][j] = sqrt(pow(Gx.Data[i][j], 2) + pow(Gy.Data[i][j], 2));
	Print_Matrix(G);
	Print_Max(Maximum(G));

	//釋放動態記憶空間
	Release(A);
	Release(Sx);
	Release(Sy);
	Release(Gx);
	Release(Gy);
	Release(G);
	return 0;
}

//2. 亂數產生矩陣(MyMatrix)行列值的函式，引數輸入亂數之下界與上界，回傳隨機值
inline int Random(const int lower, const int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

//1-1. 建立 MyMatrix 成員的函式(單引數且無回傳值)，在函數內呼叫 “亂數產生函式” 產生行列值，並建立二維動態陣列
void Create(MyMatrix& matrix)
{
	matrix.rows = Random(4, 10);
	matrix.columns = Random(4, 10);
	matrix.Data = new double*[matrix.rows];
	for (int i = 0; i < matrix.rows; i++)
		matrix.Data[i] = new double[matrix.columns];
}

//1-2. 建立 MyMatrix 成員的函式(三引數且無回傳值)，直接由主程式給予行列大小，在函數內建立二維動態陣列
void Create(MyMatrix& matrix, const int rows, const int columns)
{
	matrix.rows = rows;
	matrix.columns = columns;
	matrix.Data = new double*[rows];
	for (int i = 0; i < rows; i++)
		matrix.Data[i] = new double[columns];
}

//3. 隨機建立矩陣(MyMatrix)元素值的函式，此函數限制為單引數且無回傳值，在函數內給予二維陣列中各個元素數值
void Create_elements(MyMatrix& matrix)
{
	const int min_element = 0;
	const int max_element = 255;
	for (int i = 0; i < matrix.rows; i++)
		for (int j = 0; j < matrix.columns; j++)
			matrix.Data[i][j] = rand() % (max_element - min_element + 1) + min_element;
}

//4. 矩陣(MyMatrix)與索伯運算子進行卷積的函式，此函數至多只能有三個引數，不限制回傳值形式，亦可不回傳
MyMatrix Convolution(const MyMatrix& matrix, const MyMatrix& mask)
{
	MyMatrix ans;
	Create(ans, matrix.rows, matrix.columns);
	for (int i = 0; i < matrix.rows; i++)
		for (int j = 0; j < matrix.columns; j++)
		{
			ans.Data[i][j] = 0;
			for (int x = 0; x < mask.rows; x++)
				for (int y = 0; y < mask.columns; y++)
					if (!(i + x - 1 < 0 || i + x - 1 >= matrix.rows || j + y - 1 < 0 || j + y - 1 >= matrix.columns))
						ans.Data[i][j] += matrix.Data[i + x - 1][j + y - 1] * mask.Data[mask.rows - x - 1][mask.columns - y - 1];
		}
	return ans;
}

//5. 列印出陣列元素的函數，此函數限制為單引數且無回傳值，引數傳入 MyMatrix，於函式中列印出 MyMatrix 的元素值
void Print_Matrix(const MyMatrix& matrix)
{
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.columns; j++)
			cout << setw(10) << matrix.Data[i][j];
		cout << endl;
	}
}

//6. 求矩陣最大元素及其下標的函數，若有多筆數據為最大值只須回傳一筆，結果以 MyValue進行封裝並 return by value 回傳 MyValue。
MyValue Maximum(MyMatrix& matrix)
{
	MyValue max;
	max.Data = matrix.Data[0][0];
	max.matrix = &matrix;
	for (int i = 0; i < matrix.rows; i++)
		for (int j = 0; j < matrix.columns; j++)
			if (matrix.Data[i][j] >= max.Data)
			{
				max.Data = matrix.Data[i][j];
				max.rows = i + 1;
				max.columns = j + 1;
			}
	return max;
}

//7. 列印 MyValue 之函式，應輸出元素數值、其下標及其所在之矩陣(MyMatrix)之地址
void Print_Max(const MyValue& max)
{
	cout << "Max element: " << max.Data << endl
		<< "Position (row,column): (" << max.rows << "," << max.columns << ")" << endl
		<< "Address of matrix: " << max.matrix << endl << endl;
}

//8. 歸還 MyMatirx 使用空間，此函數限制為單引數且無回傳值
void Release(MyMatrix& matrix)
{
	for (int i = 0; i < matrix.rows; i++)
		delete[] matrix.Data[i];
	delete[] matrix.Data;
}