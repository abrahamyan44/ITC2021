#include <iostream>
#include <ctime>
#include <unistd.h>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {   
	if(argc == 1) {
	   cout << "Please write --interval and input interval value " << endl;
	   return 0;
   } else if (argc == 2) {
	   cout << "you missed '--interval' or value of interval" << endl;
   }

   else if(!strcmp(argv[1], "--interval")) {
       int count = 0;
       for(int i = 0; i < strlen(argv[2]); ++i) {
           if(argv[2][i] == '.') {
              count = 0;
              ++i;
              while(argv[2][i]! = 0) {
                  count++;
                  ++i;
              }
              break;
           }
       }
       if(count == 1) {
           ofstream myfile;
           myfile.open ("temp.txt");
           for(int i = 0; i < 10; ++i){
               srand(time(0));
               time_t now = time(0);
               char* dt = ctime(&now);
               myfile << "Random number is :" << (float)(rand()%100) / float(10) << " " << "The local date and time is: " << dt << endl;
               usleep(atof(argv[2])*1000000);
			   myfile.close();
          }
       }
	 }
  }

