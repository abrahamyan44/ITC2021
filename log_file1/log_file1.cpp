#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;


void  data_print (int interval)
{
	int count  = 0;
	int number = random();

	while(true) 
	{
		this_thread::sleep_for(chrono::seconds(interval));
		auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

		cout << count << "\t" <<   number <<"\t" << ctime(&timenow) << endl;
		count = count + interval;
	}
}



int main() 
{
		int repeat;
		cout << "Enter the repeat interval" << endl;  
		cin >> repeat;
	    data_print (repeat);

}
