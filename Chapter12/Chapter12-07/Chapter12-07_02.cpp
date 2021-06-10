#include <iostream>
#include <string>

using namespace std;

// Interface class : 모든 멤버 함수가 순수 가상 함수
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
	// 이 함수를 구현하지 않으면 이 클래스의 인스턴스를 만들 수 없다
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