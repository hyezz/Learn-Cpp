#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>	// exit()
#include <sstream>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs(filename);

		ifs.seekg(5);	//ifs.seekg(5, ios::beg) ���� ó�����κ��� 5byte �̵� �� �б�
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur);	// ���� �о���� ��ġ�������� 5byte �̵� �� �б�
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-5, ios::end);

		//ifs.seekg(0, ios::end);
		//cout << ifs.tellg() << endl;	// tellg() : ���� ��ġ

		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	// ���� �а� ����
	{
		//fstream iofs(filename, ios::in | ios::out);	// flag ���� ����
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read

		iofs.seekg(5);
		iofs.put('A');	// write
	}

	return 0;
}