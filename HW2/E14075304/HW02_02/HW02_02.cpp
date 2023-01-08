// HW02_02
// 許笙杰 E14075304 機械二乙

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text;		// 輸入的字串
	cout << "Enter a string: ";
	getline(cin, text);
	
	string word;		// 要搜尋的字串
	int count = 0;		// 字串出現的次數
	cout << "Search word: ";
	cin >> word;
	
	// 找出該字串的位置並顯示位置和次數
	cout << "The index of the string \"" << word << "\": ";
	for (size_t index = 0;
		(index = text.find(word, index)) != string::npos;
		index += word.length(), count++)
		cout << index << " ";

	cout << endl;
	cout << "\"" << word << "\" occurs " << count << (count == 1 ? " time" : " times");
	
	// 大小寫互換
	string replacement = word;		// 取代用的字串
	for (size_t index = 0; index < word.length(); index++)
	{
		if (isupper(word[index]))
			replacement[index] = tolower(word[index]);
		else if (islower(word[index]))
			replacement[index] = toupper(word[index]);
	}
	cout << endl;

	// 用大小寫互換過的字串取代原本的字串
	size_t start = text.find(word);		// 取代的起點
	while (start != string::npos) {
		text.replace(start, word.length(), replacement);
		start = text.find(word, start + replacement.length());
	}
	cout << text;
	return 0;
}

