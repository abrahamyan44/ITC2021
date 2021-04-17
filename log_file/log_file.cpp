#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <chrono>

void write_in_file(double a)
{
    std::ofstream myfile;
    myfile.open("temp.txt");
    while(true) {
    	time_t now = time(0);
    	char* dt = ctime(&now);
    	myfile << "interval is " << a << " Random number is :" << (float)(rand()%1000)/float(10) << " The local date and time is: " << dt << std::endl;
    	usleep(a * 1000000);
    }
    myfile.close();
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
