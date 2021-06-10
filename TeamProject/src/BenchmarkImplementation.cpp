#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <sqlite3.h>
#include "../include/BenchmarkTable.hpp"
#include "../include/Timer.hpp"
#include "../include/ExternFunctions.hpp"

typedef long long ll;

using namespace std;

void RunAllArtaxiadAlgorithms(int* array, int size, const int& test_count, sqlite3*& db) {
    BenchmarkTable table(test_count);
	cout << endl;
	cout << "Artaxiad team algorithms: ";
	try {
		table.Run(BubbleSortByArtaxiad, size, array, "Bubble");
		table.WriteInTables("Artaxiad");
		table.Run(QuickSortByArtaxiad, size, array, "Quick");
		table.WriteInTables("Artaxiad");
		table.Run(MergeSortByArtaxiad, size, array, "Merge");
		table.WriteInTables("Artaxiad");
		table.Run(HeapSortByArtaxiad, size, array, "Heap");
		table.WriteInTables("Artaxiad");
		table.Run(InsertionSortByArtaxiad, size, array, "Insertion");
		table.WriteInTables("Artaxiad");
		table.Run(SelectionSortByArtaxiad, size, array, "Selection");
		table.WriteInTables("Artaxiad");
		table.Run(ShellSortByArtaxiad, size, array, "Shell");
		table.WriteInTables("Artaxiad");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable(db, "Artaxiad");
}

void RunAllArshakidAlgorithms(int* array, int size, const int& test_count, sqlite3*& db) {
    BenchmarkTable table(test_count);
	cout << endl;
	cout << "Arshakid team algorithms: ";
	try {
		table.Run(BubbleSortByArshakid, size, array, "Bubble");
		table.WriteInTables("Arshakid");
		table.Run(QuickSortByArshakid, size, array, "Quick");
		table.WriteInTables("Arshakid");
		table.Run(MergeSortByArshakid, size, array, "Merge");
		table.WriteInTables("Arshakid");
		table.Run(HeapSortByArshakid, size, array, "Heap");
		table.WriteInTables("Arshakid");
		table.Run(InsertionSortByArshakid, size, array, "Insertion");
		table.WriteInTables("Arshakid");
		table.Run(SelectionSortByArshakid, size, array, "Selection");
		table.WriteInTables("Arshakid");
		table.Run(ShellSortByArshakid, size, array, "Shell");
		table.WriteInTables("Arshakid");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable(db, "Arshakid");
}

void RunAllBagratidAlgorithms(int* array, int size, const int& test_count, sqlite3*& db) {
    BenchmarkTable table(test_count);
	cout << endl;
	cout << "Bagratid team algorithms: ";
	try {
		table.Run(BubbleSortByBagratid, size, array, "Bubble");
		table.WriteInTables("Bagratid");
		table.Run(QuickSortByBagratid, size, array, "Quick");
		table.WriteInTables("Bagratid");
		table.Run(MergeSortByBagratid, size, array, "Merge");
		table.WriteInTables("Bagratid");
		table.Run(HeapSortByBagratid, size, array, "Heap");
		table.WriteInTables("Bagratid");
		table.Run(InsertionSortByBagratid, size, array, "Insertion");
		table.WriteInTables("Bagratid");
		table.Run(SelectionSortByBagratid, size, array, "Selection");
		table.WriteInTables("Bagratid");
		table.Run(ShellSortByBagratid, size, array, "Shell");
		table.WriteInTables("Bagratid");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable(db, "Bagratid");
}

void RunAllRubenidAlgorithms(int* array, int size, const int& test_count, sqlite3*& db) {
    BenchmarkTable table(test_count);
	cout << endl;
	cout << "Rubenid team algorithms: ";
	try {
		table.Run(BubbleSortByRubenid, size, array, "Bubble");
		table.WriteInTables("Rubenid");
		table.Run(QuickSortByRubenid, size, array, "Quick");
		table.WriteInTables("Rubenid");
		table.Run(MergeSortByRubenid, size, array, "Merge");
		table.WriteInTables("Rubenid");
		table.Run(HeapSortByRubenid, size, array, "Heap");
		table.WriteInTables("Rubenid");
		table.Run(InsertionSortByRubenid, size, array, "Insertion");
		table.WriteInTables("Rubenid");
		table.Run(SelectionSortByRubenid, size, array, "Selection");
		table.WriteInTables("Rubenid");
		table.Run(ShellSortByRubenid, size, array, "Shell");
		table.WriteInTables("Rubenid");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable(db, "Rubenid");
}

int*  GenerateRandomArray(int size) {
    int* array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand();
	}
    return array;
}

void CreateTeamTable (std::string team_name) {
	sqlite3* DataBase;
	char* ErrorMessage = 0;
	std::string sql;
	bool not_open;

	not_open = sqlite3_open("DataBase.db", &DataBase);
	if (not_open) {
		std::cout << "Can't open Dabase" << std::endl;
		sqlite3_close(DataBase);
	}

	sql =   " Drop table if exists " +  team_name + " ;" 
	       	" Create table if not exists " + team_name + 
	      	" ( Algorithm_Selector  INTEGER     PRIMARY KEY   AUTOINCREMENT,"
		    " min_result          float       NOT NULL," 
			" max_result          float       NOT NULL," 
			" average_result      float       NOT NULL,"
			" Foreign key (Algorithm_Selector)  references Algorithms(Algorithm_Selector) );"; 
	
	not_open = sqlite3_exec(DataBase, sql.c_str(), 0, 0, &ErrorMessage);
	if(not_open) {
		fprintf(stderr,"Error: %s\n", ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
} 

void CreateTable() {
	sqlite3* DataBase;
	bool not_open;
	const char* sql;
	char* ErrorMessage = 0;

	sqlite3_open("DataBase.db", &DataBase);
	sql =   " Create Table if not exists Algorithms ( "
			"Algorithm_Selector    INTEGER    PRIMARY KEY  AUTOINCREMENT,"
			"Algorithm             TEXT       NOT NULL ); ";

	not_open = sqlite3_exec(DataBase, sql, 0, 0, &ErrorMessage);
	if (not_open) {
		fprintf(stderr," Error_alg: %s\n",ErrorMessage);
		sqlite3_free(ErrorMessage);
	}

	sql = " Insert into Algorithms  (Algorithm)  values ('BubbleSort');"
          " Insert into Algorithms  (Algorithm)  values ('QuickSort');"
	      " Insert into Algorithms  (Algorithm)  values ('MergeSort');"
	      " Insert into Algorithms  (Algorithm)  values ('HeapSort');"
	      " Insert into Algorithms  (Algorithm)  values ('InsertionSort');"
	      " Insert into Algorithms  (Algorithm)  values ('SelectionSort');"
          " Insert into Algorithms  (Algorithm)  values ('ShellSort');";
	sqlite3_exec(DataBase, sql, 0, 0, &ErrorMessage);
	if (not_open) {
		fprintf(stderr," Error: %s\n",ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
}

void BenchmarkTable::WriteInTables(std::string team_name) {
	sqlite3* DataBase;
	bool not_open;
	std::string sql;
	char* ErrorMessage = 0;

	sqlite3_open("DataBase.db", &DataBase);
	
	sql = "Insert into " + team_name + " ( min_result, max_result, average_result ) values ( " + to_string( m_timer[m_timer.size() - 1][0] ) + " , " + to_string( m_timer[m_timer.size() - 1][2] ) + " , " +  to_string( GetAverageTime( m_timer[m_timer.size() - 1] )) + " );"; 
		
	not_open = sqlite3_exec(DataBase, sql.c_str(), 0, 0, &ErrorMessage);
	if(not_open) {
		fprintf(stderr, "Error_write : %s\n", ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
}

void CreateDataBase() {
	sqlite3* DataBase;
	const char* sql;
	char* ErrorMessage = 0;
	bool not_open;
	
	sqlite3_open("DataBase.db", &DataBase);
	sql = "PRAGMA foreign_keys = ON;";
	not_open = sqlite3_exec(DataBase, sql, 0, 0, &ErrorMessage);

	if(not_open) {
		fprintf(stderr, "Error_keys: %s\n", ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
	
	CreateTeamTable("Rubenid ");
	CreateTeamTable("Bagratid ");
	CreateTeamTable("Artaxiad ");
	CreateTeamTable("Arshakid ");
	CreateTable();
	sqlite3_close(DataBase);
}



int main(int argc, char** argv) {
	srand(time(0));
	int size = atoi(argv[1]);
	int test_count = argc < 3 || atoi(argv[2]) <= 0 ? 3 : min(3, atoi(argv[2]));
    int* array = GenerateRandomArray(size);
	sqlite3* db;
	CreateDataBase();
	const char* table;
	sqlite3_open("database/results.db", &db);
	table = "CREATE TABLE RESULTS("  \
        "TEAM        TEXT      NOT NULL," \
        "ALGORITHM          TEXT     NOT NULL," \
        "MINIMUM           FLOAT     NOT NULL," \
        "AVERAGE            FLOAT     NOT NULL," \
        "MAXIMUM            FLOAT      NOT NULL);";
	sqlite3_exec(db, table, 0, 0, 0);
	RunAllArtaxiadAlgorithms(array, size, test_count, db);
	RunAllArshakidAlgorithms(array, size, test_count, db);
    RunAllBagratidAlgorithms(array, size, test_count, db);
	RunAllRubenidAlgorithms(array, size, test_count, db);
	sqlite3_close(db);
	return 0;
}
