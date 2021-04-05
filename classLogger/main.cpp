#include <iostream>

#include "Logger.hpp"

int main(int argc, char* argv[])
{
	/*testing*/

	Logger& log = Logger::Get();
	log.Error("error_msg");

	log.Warning("error_msg");
	log.Info("error_msg");

	log.Message(MSGS::verbosity::ERROR,"error_msg");

	//std::cout << "Current Verbosity is:" << log.GetVerbosity();
	//int level = std::stoi(argv[2]);

	return 0;
}
