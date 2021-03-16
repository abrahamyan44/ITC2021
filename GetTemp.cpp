#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <iomanip>


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

int main(int argc, char* argv[])
{
    std::ofstream MyFile("temp.txt");
    if(!MyFile)
    {
        std::cout << "Error in creating file.";
            return 0;
    }
    float interval = strtof(argv[2], NULL);
    
    if(strcmp(argv[1],"--interval") == 0 && interval != 0)
    {
        srand(time(0));
        int Temp;
        float count = interval;
        while(true)
        {
            Temp = rand()%100;
            MyFile << count << "\t" << Temp << "\t" << currentDateTime() << std::endl;
            count += interval;
            usleep(interval*1000000);
        }
    }
    
    MyFile.close();
}
