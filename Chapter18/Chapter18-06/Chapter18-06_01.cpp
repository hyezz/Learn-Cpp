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
		// my_first_file.dat ������ ������ ���� ���� 
		//					 ������ ������ ��忡 ���� �ٽ� ���ų�, �� ����� ���� ����
		ofstream ofs("my_first_file.dat");	// ios::app, ios::binary
		//ofstream ofs("my_first_file.dat", ios::app);	// append : ���� ���Ͽ� �߰��ؼ� write
		//ofs.open("my_first_file.dat");

		if (!ofs)
		{
			cerr << "Couldn't open file " << endl;
			exit(1);
		}

		// 1) ASCII format ����
		// output operator (<<) ����ϸ� txt ���� ���� ���� (����)
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		// 2) binary ����
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));

		// 3) ����� ���ڿ��� string �� �ְ� �ѹ��� ����
		/*stringstream ss;
		ss << "Line 1" << endl;
		ss << "Line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));
		ofs.write(str.c_str(), str_length);*/

		//ofs.close();	// not necessary (�Ҹ��ڰ� �ڵ����� ������)
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

		// 2) binary read (notepad���� Ȯ�� �Ұ�)
		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (unsigned i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}

		// 3) string�� ��Ƽ� read
		/*unsigned str_len = 10;
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;*/
	}

	return 0;
}