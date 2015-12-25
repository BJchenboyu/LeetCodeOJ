#include "log.h"
#include <fstream>
#include <iostream>
#include <atltime.h>
log::log(void)
{
}


log::~log(void)
{
}

void log::writeLog(string logMessage)
{
	writeLog("./log.txt",logMessage);
}

void log::writeLog(string logFilename,string logMessage)
{
	fstream fs;
	fs.open(logFilename.c_str(),fstream::out|ofstream::app);
	if (!fs.bad())
	{
		CTime time=CTime::GetCurrentTime();
		fs<<endl;
		fs<<time.GetYear()<<"-"<<time.GetMonth()<<"-"<<time.GetDay()<<" "<<time.GetHour()<<":"<<time.GetMinute()<<":"<<time.GetSecond()<<endl;
		fs<<logMessage<<endl;
		fs.close();
	}
}


