#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	// c-style string example
	{
		char* strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		cout << strHello << endl;
	}

	// basic_string<>, string, wstring
	{
		// basic_string 템플릿으로 만들어진 클래스의 인스턴스
		// string: <type: char>, wstring: <type: wchar_t>
		string string;
		wstring wstring;

		wchar_t wc;	// wide-character/unicode
	}

	// wstring example
	{
		// Stackoverflow.com
		// C++ Code to cout international characters using Visual Studio 2015 [closed]
		// https://stackoverflow.com/questions/33404685/c-code-to-cout-international-characters-using-visual-studio-2015
		const wstring texts[] =
		{
			L"안녕하세요?", // Korean
			L"Ñá", //Spanish
			L"forêt intérêt", //French
			L"Gesäß", //German
			L"取消波蘇日奇諾", //Chinese
			L"日本人のビット", //Japanese
			L"немного русский", //Russian
			L"ένα κομμάτι της ελληνικής", // Greek
			L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
			L"کمی از ایران ", // Persian (I know it, from 300 movie)
			L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
			L"Но какво, по дяволите, е това?" //Bulgarian
		};

		locale::global(locale(""));
		wcout.imbue(locale());

		for (size_t i = 0; i < 11; ++i)
			wcout << texts[i] << endl;
	}

	return 0;
}