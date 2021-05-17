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
		table.Run(QuickSortByArtaxiad, size, array, "Quick");
		table.Run(MergeSortByArtaxiad, size, array, "Merge");
		table.Run(HeapSortByArtaxiad, size, array, "Heap");
		table.Run(InsertionSortByArtaxiad, size, array, "Insertion");
		table.Run(SelectionSortByArtaxiad, size, array, "Selection");
		table.Run(ShellSortByArtaxiad, size, array, "Shell");
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
		table.Run(QuickSortByArshakid, size, array, "Quick");
		table.Run(MergeSortByArshakid, size, array, "Merge");
		table.Run(HeapSortByArshakid, size, array, "Heap");
		table.Run(InsertionSortByArshakid, size, array, "Insertion");
		table.Run(SelectionSortByArshakid, size, array, "Selection");
		table.Run(ShellSortByArshakid, size, array, "Shell");
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
		table.Run(QuickSortByBagratid, size, array, "Quick");
		table.Run(MergeSortByBagratid, size, array, "Merge");
		table.Run(HeapSortByBagratid, size, array, "Heap");
		table.Run(InsertionSortByBagratid, size, array, "Insertion");
		table.Run(SelectionSortByBagratid, size, array, "Selection");
		table.Run(ShellSortByBagratid, size, array, "Shell");
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
		table.Run(QuickSortByRubenid, size, array, "Quick");
		table.Run(MergeSortByRubenid, size, array, "Merge");
		table.Run(HeapSortByRubenid, size, array, "Heap");
		table.Run(InsertionSortByRubenid, size, array, "Insertion");
		table.Run(SelectionSortByRubenid, size, array, "Selection");
		table.Run(ShellSortByRubenid, size, array, "Shell");
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

void CreateTeamTable (std::string table_name) {
	sqlite3* DataBase;
	char* ErrorMessage = 0;
	std::string sql;
	bool not_open;

	not_open = sqlite3_open("DataBase.db", &DataBase);
	if (not_open) {
		std::cout << "Can't open Dabase" << std::endl;
		sqlite3_close(DataBase);
	}

	sql =   "algorithm_selector          int     NOT NULL," 
			"min_result          float   NOT NULL," 
			"max_result          float   NOT NULL," 
			"average_result      float   NOT NULL);";

	std::string result = table_name + sql;
	
	not_open = sqlite3_exec(DataBase, result.c_str(), 0, 0, &ErrorMessage);
	if(not_open) {
		fprintf(stderr,"Error %s\n", ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
} 

void CreateTable() {
	sqlite3* DataBase;
	bool not_open;
	const char* sql;
	char* ErrorMessage = 0;

	sqlite3_open("DataBase.db", &DataBase);
	sql = " Create Table Algorithms ( "
			"ID           INT PRIMERY KEY  NOT NULL,"
			"Algorithm    TEXT             NOT NULL ); ";

	not_open = sqlite3_exec(DataBase, sql, 0, 0, &ErrorMessage);
	if (not_open) {
		fprintf(stderr," Error: %s\n",ErrorMessage);
		sqlite3_free(ErrorMessage);
	}

	sql = " Insert into Algorithms values (1, 'ShellSort');"
              " Insert into Algorithms values (2, 'QuickSort');"
	      " Insert into Algorithms values (3, 'HeapSort');"
	      " Insert into Algorithms values (4, 'MergeSort');"
	      " Insert into Algorithms values (5, 'SelectionSort');"
	      " Insert into Algorithms values (6, 'InsertionSort');"
              " Insert into Algorithms values (7, 'BubbleSort');";
	sqlite3_exec(DataBase, sql, 0, 0, &ErrorMessage);
	if (not_open) {
		fprintf(stderr," Error: %s\n",ErrorMessage);
		sqlite3_free(ErrorMessage);
	}
}

void CreateDataBase() {
	sqlite3* DataBase;

	CreateTeamTable(" CREATE TABLE Rubenid (");
	CreateTeamTable(" CREATE TABLE Bagratid (");
	CreateTeamTable(" CREATE TABLE Artaxiad (");
	CreateTeamTable(" CREATE TABLE Arshakid (");
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
