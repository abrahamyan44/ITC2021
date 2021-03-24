#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <cstring>
using namespace std;

int main(int argc,char *argv[]){
	if(argc > 2 && !strcmp(argv[1],"--interval")){
		int count=0;
		if(!argv[2]) {
			std::cerr << "Please, enter the 'number'." << std::endl;
			return 0;
		}
		for(int i=0;i<strlen(argv[2]);++i) {
			if(argv[2][i]=='.') {
				count=0;
				i++;
				while(argv[2][i]!=0) {
					count++;
					i++;
				} 
			}
		}
		if(count==1) {
			srand(time(0));
			ofstream log_file;
			log_file.open("log_file.txt");
		for(int i=0; ;++i){
			time_t now = time(0);
			char*  dt=ctime(&now);
			int randomNumber = rand()%9;
			log_file<<"Tempreture is :"<<randomNumber<<" "<<"Data and time is : "<<dt<<endl;
			usleep(atof(argv[2])*1000000);
		}
		log_file.close();
		}
		else {
			std::cerr << "Please, enter 1 digit after '.'." << std::endl;
		}
	}
	else {
		if(argv[2]) {
			std::cerr << "Please, keep the form: ./exe --interval 'number'." << std::endl;
		}
		else {
			std::cerr << "Please, enter the --interval for executing the code." << std::endl;
		}
	}
	return 0;
}
