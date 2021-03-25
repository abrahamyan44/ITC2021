#include <string>
#include "nare_logger.h"

int main(){
	std::cout << "HEllo from main" << std::endl;
//    Level lvl_1 = 1;
	Level lvl_2 = INFO;
	std::string message1 = "Log message 1 ...";
//	std::string message2 = "Log message 2 ...";
//	Logger* my_log = Logger::GetLogger();
//	my_log->message(lvl_1,message1);
//	my_log->message(lvl_2,message2);
//	Logger::GetLogger()->error(message1);
	Logger::GetLogger()->message(lvl_2,"Info message 2");



};

