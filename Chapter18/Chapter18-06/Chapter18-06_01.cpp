#include <iostream>
#include <fstream>	// file stream
#include <string>
#include <cstdlib>	// exit()
#include <sstream>

using namespace std;

int main()
{
	// writing
	if (true)
	{
		// my_first_file.dat 파일이 없으면 새로 생성 
		//					 파일이 있으면 모드에 따라 다시 열거나, 싹 지우고 새로 생성
		ofstream ofs("my_first_file.dat");	// ios::app, ios::binary
		//ofstream ofs("my_first_file.dat", ios::app);	// append : 기존 파일에 추가해서 write
		//ofs.open("my_first_file.dat");

		if (!ofs)
		{
			cerr << "Couldn't open file " << endl;
			exit(1);
		}

		// 1) ASCII format 저장
		// output operator (<<) 사용하면 txt 모드로 파일 저장 (느림)
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		// 2) binary 저장
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));

		// 3) 출력할 문자열을 string 에 넣고 한번에 저장
		/*stringstream ss;
		ss << "Line 1" << endl;
		ss << "Line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));
		ofs.write(str.c_str(), str_length);*/

		//ofs.close();	// not necessary (소멸자가 자동으로 지워줌)
	}

	// reading
	if (true)
	{
		ifstream ifs("my_first_file.dat");
		//ifstream ifs("my_first_file_wrong.dat");

		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// 1) ASCII format read
		/*while (ifs)
		{
			string str;
			getline(ifs, str);

			cout << str << endl;
		}*/

		// 2) binary read (notepad에서 확인 불가)
		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (unsigned i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}

		// 3) string에 담아서 read
		/*unsigned str_len = 10;
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;*/
	}

	return 0;
}