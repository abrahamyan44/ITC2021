#include "Logger.hpp"

Logger::Logger(const std::string& path = "log_file.txt") noexcept
	:m_logfile{}
	,m_verbosity(3)
{
	m_logfile.open(path.c_str());		

	assert(m_logfile);
	assert(m_logfile.is_open());
}

Logger::~Logger() noexcept
{
	m_logfile.close();
}

void Logger::Error(const std::string& m, ...) noexcept
{
	time_t now = time(0); 	// current date/time based on current system
	char* dt = ctime(&now); // convert now to string form
	
	assert(m_logfile.is_open());

	m_logfile << "[ ERROR ]   " << m << "   " << dt << std::endl;
}

void Logger::Warning(const std::string& m, ...) noexcept
{
	time_t now = time(0);   //current date/time based on current system
	char* dt = ctime(&now); //convert now to string form
			
	m_logfile << "[ WARNING ]   " << m << "   " << dt << std::endl;
}

void Logger::Info(const std::string& m, ...) noexcept
{
	time_t now = time(0);   //current date/time based on current system
	char* dt = ctime(&now); //convert now to string form

	m_logfile << "[ INFO ]   " << m << "   " << dt << std::endl;
}

void Logger::Message(MSGS::verbosity level, const std::string& m, ...) noexcept
{
	time_t now = time(0);
	char* dt = ctime(&now);

	switch(level) {
		case 1:
			Error(m);
			break;
		case 2:
			Warning(m);
			break;
		case 3:
			Info(m);
			break;
		case 4:
			Error(m);
			Warning(m);
			Info(m);			
			break;
		default:
			m_logfile << "[ ERROR ]   " << m <<
			   	"   " << dt << std::endl;
			break;
	}
}

Logger& Logger::Get() noexcept
{
	static Logger log; // Instantited on first use	
	return log;	
}

unsigned int Logger::GetVerbosity() const noexcept
{
	return m_verbosity;
}

void Logger::SetVerbosity(unsigned int level) noexcept
{
	m_verbosity = level ;
}

