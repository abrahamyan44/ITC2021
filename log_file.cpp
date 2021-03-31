#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <chrono>

void WriteInFile(double interval)
{
    std::ofstream dataStorageFile;
    dataStorageFile.open("temp.txt");
    while(true) {
    	time_t currentTime = time(0);
    	char* currentDate = ctime(&currentTime);
    	dataStorageFile << "interval is " << interval << " Random number is :" << (float)(rand() % 1000) / float(10) << " The local date and time is: " << currentDate << std::endl;
    	usleep(a * 1000000);
    }
    dataStorageFile.close();
}

int main(int argc, char* argv[])
{
	srand(time(0));
    if(argc == 1) {
        std::cout << "Please write '--interval' then interval value " << std::endl;
        return 0;
    } else if(argc == 2) {
        std::cout << "You missed '--interval' or interval value" << std::endl;
    } else if(strcmp(argv[1], "--interval") && argc == 3) {
        std::cout << "first argument must be '--interval'" << std::endl;
    } else if(argc == 3) {
        write_in_file(atof(argv[2]));
    } else if(argc > 3) {
        std::cout << "too much arguments..." << std::endl;
    }    
}
