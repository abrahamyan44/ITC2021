#include <chrono> 
#include <ctime> 
#include <string>
#include <iostream> 
#include <fstream>

#ifndef NARE_LOGGER_H
#define NARE_LOGGER_H

enum Level
{
	ERROR,
	WARNING,
	INFO,
	MESSAGE

};

class Logger
{

public:

	static Logger* GetLogger();
	
	void message(Level lvl, const std::string& message);
        void error(const std::string& message);
	void warning(const std::string& message);
	void info(const std::string& message);

private:
	Logger();

	const std::string m_sfileName;
	std::fstream m_logfile;
	int m_verbosity;

	static Logger* m_pThis;
	std::string levels[4] = {"ERROR", "WARNING", "INFO", "MESSAGE"};		

};


#endif
