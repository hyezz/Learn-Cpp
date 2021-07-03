#include <iostream>
#include <regex>	// C++ 11 ���� ��� ����

using namespace std;

int main()
{
	//regex re("\\d");	// \d : digit
	//regex re("\\d+");	// + : 1�� �̻�, * : ��� ��
	//regex re("[ab]");	// a or b
	//regex re("[[:digit:]]{3}");	// [:digit:] = \d, {3} : 3�� �Է� ����
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}");	// {1,5} : 1�� �̻� 5�� ����
	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	// ? : �־, ��� ����

	string str;

	while (true)
	{
		getline(cin, str);

		// �Է¹��� str �� re ���ǿ� �´��� Ȯ��
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