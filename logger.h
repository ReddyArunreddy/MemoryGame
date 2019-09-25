#ifndef __LOGGER_H__
#define __LOGGER_H__



#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
enum Log_Level{
	Trace,
	Debug,
	Info,
	Warn,
	Error,
	Fatal
};
struct logger_config
{
    std::string path;
};
class Logger{
	
public:
	virtual 
	std::ostream&
	cerr() = 0;
	
	virtual bool 
	open(logger_config) = 0;
	
	virtual void
	write_to_file(std::string Log) = 0;
};


#endif // end of __LOGGER_H__