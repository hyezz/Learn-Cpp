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

		ifs.seekg(5);	//ifs.seekg(5, ios::beg) 파일 처음으로부터 5byte 이동 후 읽기
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur);	// 현재 읽어들인 위치에서부터 5byte 이동 후 읽기
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-5, ios::end);

		//ifs.seekg(0, ios::end);
		//cout << ifs.tellg() << endl;	// tellg() : 현재 위치

		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	// 파일 읽고 쓰기
	{
		//fstream iofs(filename, ios::in | ios::out);	// flag 설정 가능
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read

		iofs.seekg(5);
		iofs.put('A');	// write
	}

	return 0;
}