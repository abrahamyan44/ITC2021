#include "gcd.hpp"

void diff()
{
	ifstream file1;
	ifstream file2;
	ofstream result;
	string line1;
	string line2;
	int cnt1 = 0;
	int cnt2 = 0;

	file1.open("files/output.txt", ios::in);
	file2.open("files/goutput.txt", ios::in);
	result.open("files/result.txt", ios::out);
	if( file1.fail() )
   	{
		cout << "Something wrong. Can't open output.txt.";
	}

	if( file2.fail() ) 
	{
		cout << "Something wrong. Can't open goutput.txt.";
	}

	if( result.fail() )
   	{
		cout << "Something wrong. Can't open result.txt.";
	}

	result << "gcd result \t" << "ggcd result" << endl;

	while( !file2.eof() ) 
	{
	
		getline(file1, line1);
		getline(file2, line2);
		if(line1 == line2) 
		{
		result<< line1 << "\t \t \t" <<line2 <<"\t \t ok" << endl;
		cnt1++;
		} else
	   	{
		result << line1 << "\t"<< line2 <<"\t failed" << endl;
		cnt2++;
		}
	}
	result << "match: " << cnt1 << ";   failed:  " << cnt2 << endl;
	cout << "All tests are done. You can see the results in \"files \\result.txt\". " << endl;
 	file1.close();
	file2.close();
	result.close();
}





/*void file_reader (ifstream file, string "file_path")
{
	file.open("file_path", ios::in);

	if( file.fail() ) {
		cout << "Something wrong. Can't open output.txt.";
	}
}

void diff() 
{
	ofstream result;
	string line1;
	string line2;
	int cnt1 = 0;
	int cnt2 = 0;

	file_reader( file1, "files/output.txt");
	file_reader( file2, "files/goutput.txt");

	result.open("filies/result.txt", ios::out);

	if( result.fail() ) {
		cout << "Something wrong. Can't open result.txt.";
	}

	result << "gcd result \t" << "ggcd result" << endl;

	while( !file2.eof() ) {
	
		getline(file1, line1);
		getline(file2, line2);
		if(line1 == line2) {
		result<< line1 << "\t \t \t" <<line2 <<"\t \t ok" << endl;
		cnt1++;
		} else {
		result << line1 << "\t"<< line2 <<"\t failed" << endl;
		cnt2++;
		}
	}
	result << "match: " << cnt1 << ";   failed:  " << cnt2 << endl;
	cout << "All tests are done. You can see the results in \"result.txt\". " << endl;
 	file1.close();
	file2.close();
	result.close();
}
*/
