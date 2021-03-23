#include <iostream>
#include <cstring>
//#include <ctime>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <functional>

void timer_start(std::function<void(void)> func, int interval)
{
    std::thread([=]() {
        while (true)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

bool check_number(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) == false) {
        return false;
    }
        return true;
    }
}

void write_in_file(int a) 
{
    std::ofstream myfile;
    myfile.open("temp.txt");

    srand(time(0));
    time_t now = time(0);
               char* dt = ctime(&now);
               myfile << "Random number is :" << (float)(rand()%100)/float(10) << " The local date and time is: " << dt << std::endl;
//               usleep(atof(a)*1000000);
               myfile.close();
}

int main(int argc, char* argv[])
{
    if(argc == 1) {
        std::cout << "Please write '--interval' then interval value " << std::endl;
        return 0;
    } else if(argc == 2) {
        std::cout << "You missed '--interval' or interval value" << std::endl;
    } else if(strcmp(argv[1], "--interval") && argc == 3) {
        std::cout << "first argument must be '--interval'" << std::endl;
    } else if(argc == 3 && !check_number(argv[2])) {
        std::cout << "second argument must be number" << std::endl;
    } else if(argc > 3) {
        std::cout << "too much arguments..." << std::endl;
    } else {
       timer_start(write_in_file, argv[2]);
    }

}
