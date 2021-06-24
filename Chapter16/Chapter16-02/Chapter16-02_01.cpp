#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	// vector
	{
		vector<int> container;
		for (int i = 0; i < 10; ++i)
			container.push_back(i);

		vector<int>::const_iterator itr;
		itr = container.begin();

		// while문 iterator
		while (itr != container.end())
		{
			cout << *itr << " ";

			++itr;
		}
		cout << endl;

		// for문 iterator
		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;

		// for문 (현대적 사용)
		for (auto& e : container)
			cout << e << " ";
		cout << endl;
	}

	// list
	{
		list<int> container;
		for (int i = 0; i < 10; ++i)
			container.push_back(i);

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}
	
	// set
	{
		set<int> container;
		for (int i = 0; i < 10; ++i)
			container.insert(i);

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}

	// map
	{
		map<int, char> container;
		for (int i = 0; i < 10; ++i)
			container.insert(make_pair(i, char(i + 65)));

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << itr->first << " " << itr->second << endl;
		cout << endl;
	}

	return 0;
}