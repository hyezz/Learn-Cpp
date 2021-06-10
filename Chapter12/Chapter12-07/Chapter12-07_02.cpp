#include <iostream>
#include <string>

using namespace std;

// Interface class : ��� ��� �Լ��� ���� ���� �Լ�
class IErrorLog	// prefix : I
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!");
}

class ConsoleErrorLog : public IErrorLog
{
public:
	// �� �Լ��� �������� ������ �� Ŭ������ �ν��Ͻ��� ���� �� ����
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}