// HW09
// 許笙杰 E14075304 機械二乙

#include "MyVector.h"

int main()
{
	MyVector vec_A(1, 1, 1);	// 呼叫三個參數的建構子
	MyVector vec_B(vec_A);	// 呼叫拷貝建構子
	MyVector vec_C = vec_A;	// 呼叫拷貝建構子
	MyVector vec_D;	// 呼叫預設建構子
	MyVector vec_E(0, 4, 2);	// 呼叫三個參數的建構子
	MyVector vec_F;	// 呼叫預設建構子

	cout << "vec_A 為 " << vec_A << endl;	// 呼叫輸出導向運算子
	cout << "vec_C 為 " << vec_C << endl;	// 呼叫輸出導向運算子
	cout << "vec_C 與 vec_A 相加 ";
	vec_D = vec_C + vec_A;	// 先呼叫向量相加函式，該函式呼叫三個參數的建構子回傳結果，然後呼叫設定建構子，最後呼叫除構子
	cout << vec_D << endl;	// 呼叫輸出導向運算子
	cout << "vec_C 與 vec_A 相減 ";
	vec_B = vec_C - vec_A;	// 先呼叫向量相減函式，該函式呼叫三個參數的建構子回傳結果，然後呼叫設定建構子，最後呼叫除構子
	cout << vec_B << endl;	// 呼叫輸出導向運算子

	cout << endl;
	cout << "vec_C 為 " << vec_C << endl;	// 呼叫輸出導向運算子
	cout << "vec_E 為 " << vec_E << endl;	// 呼叫輸出導向運算子
	
	cin >> vec_F;	// 呼叫輸入導向運算子
	cout << "vec_F 為 " << vec_F << endl;	// 呼叫輸出導向運算子
	
	if (10 > vec_C)	// 先呼叫實數與向量長度比大小的函式，函式內部再呼叫計算長度函式
		cout << "vec_C 長度小於 10" << endl;
	else
		cout << "vec_C 長度大於 10" << endl;
	if (vec_C > vec_E)	// 先呼叫比較兩向量長度的函式，函式內部再呼叫兩次計算長度函式
		cout << "vec_C 長度較長" << endl;
	else
		cout << "vec_E 長度較長" << endl;
	if (vec_C > 5)	// 先呼叫向量長度與實數比大小的函式，函式內部再呼叫計算長度函式
		cout << "vec_C 長度大於 5" << endl;
	else
		cout << "vec_C 長度小於 5" << endl;
	
	cout << endl;
	cout << "vec_A 為 " << vec_A << endl;	// 呼叫輸出導向運算子
	cout << "vec_E 為 " << vec_E << endl;	// 呼叫輸出導向運算子
	
	cout << "vec_A 與 vec_E 內積 " << vec_A * vec_E << endl << endl;	// 呼叫向量內積函式
	cout << "5 * vec_A = " << (5 * vec_A) << endl;	// 先呼叫實數乘上向量函式，函式內部呼叫三個參數建構子回傳結果
													// 再呼叫輸出導向運算子，最後呼叫除構子
	cout << "vec_E / 2 + vec_A * 4 = " << (vec_E / 2 + vec_A * 4) << endl;	// 先呼叫向量乘上實數和向量除以實數的函式，兩函式共呼叫2次三參數建構子
																			// 再呼叫向量相加函式，此函式呼叫1次三參數建構子
																			// 然後呼叫輸出導向運算子，最後呼叫3次除構子
	
	cout << endl;
	cout << "向量 D (" << vec_D[0] << ", " << vec_D[1] << ", " << vec_D[2] << ")";	// 呼叫3次取分量運算子
	
	// 呼叫6次除構子
	return 0;
}