#include "nare_logger.h"
#include <cassert>
#include <iostream>
using namespace std;


namespace Util
{
        const char* CurrentDateTime(){

                time_t now = time(0);
                char* dt = ctime(&now);
                return dt;
        }
}


Logger* Logger::m_pThis = NULL;

Logger::Logger()
	: m_sfileName("log.txt")
	, m_verbosity(3)
{
	m_logfile.open(m_sfileName.c_str(), ios::out | ios::app);
	assert(m_logfile.is_open());
}

Logger* Logger::GetLogger() {

    if (m_pThis == NULL){
        m_pThis = new Logger();
    }
    return m_pThis;
}


void Logger::message(Level lvl, const std::string& message)
{
	if (m_verbosity & static_cast<int>(lvl)) {
		assert(m_logfile.is_open());
		m_logfile << Util::CurrentDateTime() << " : " << 
			levels[static_cast<int>(lvl)] << " : " << message <<
			std::endl;

	}
}

void Logger::error(const std::string& message)
{

	assert(m_logfile.is_open());
	m_logfile << Util::CurrentDateTime() << " : " <<  "ERROR : " << message << std::endl;


}

void Logger::warning(const std::string& message)
{

        assert(m_logfile.is_open());
        m_logfile << Util::CurrentDateTime() << " : " <<  "WARNING : " << message << std::endl;


}

void Logger::info(const std::string& message)
{

        assert(m_logfile.is_open());
        m_logfile << Util::CurrentDateTime() << " : " <<  "INFO : " << message << std::endl;


}

