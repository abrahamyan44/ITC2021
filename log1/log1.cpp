#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <iomanip>

int main(int argc, char* argv[])
{
  //Data..
    time_t time_start = time(0);
    char* data = ctime(&time_start);
    int temperature;
    float interval = strtof(argv[2], NULL);
    
  //Creating file..
    std::ofstream my_log("log.txt");    
    if(!my_log)
	{
	    std::cout << "Error in creating file.";
		return 0;
	}     
  //File <-- info & cout <-- info..
    if(strcmp(argv[1],"--interval") == 0 && interval != 0)
    {
      //Title.. 
	my_log << "INTVL" << "\t" << "TEMP" << "\t" << "DATA" 
		<< "\t   " << "TIME" << "\t    " << "YEAR" << std::endl;
	
	std::cout << "INTVL" << "\t" << "TEMP" << "\t" << "DATA" 
		<< "\t   " << "TIME" << "\t    " << "YEAR" << std::endl;
      
      //Implement..
	float count = interval;
        while(true)
        {
	    temperature = rand() % 100;
            my_log << count << "\t" << temperature << "\t" << data  << std::endl;
            std::cout << count << "\t" << temperature << "\t" << data  << std::endl;
	    count += interval;
            usleep(interval*1000000);
        }
    }
    
    my_log.close();
    return 0;
}
