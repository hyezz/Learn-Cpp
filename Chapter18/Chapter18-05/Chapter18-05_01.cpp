#include <iostream>
#include <regex>	// C++ 11 부터 사용 가능

using namespace std;

int main()
{
	//regex re("\\d");	// \d : digit
	//regex re("\\d+");	// + : 1개 이상, * : 없어도 됨
	//regex re("[ab]");	// a or b
	//regex re("[[:digit:]]{3}");	// [:digit:] = \d, {3} : 3개 입력 가능
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}");	// {1,5} : 1개 이상 5개 이하
	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	// ? : 있어도, 없어도 가능

	string str;

	while (true)
	{
		getline(cin, str);

		// 입력받은 str 이 re 조건에 맞는지 확인
		if (regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		// print matches
		{
			auto begin = sregex_iterator(str.begin(), str.end(), re);
			auto end = sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}