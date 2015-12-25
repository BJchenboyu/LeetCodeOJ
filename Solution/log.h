#pragma once
#include <string>
using namespace::std;
class log
{
public:
	log(void);
	~log(void);

	static void writeLog(string logMessage);
	static void writeLog(string logFilename,string logMessage);
};

