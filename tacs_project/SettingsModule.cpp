#include <ios>
#include <string>
#include <iostream>
#include "sqlite3.h"
 
using namespace std;
 
void write_to_db()
{
   int rc;
   char *error;
   const char *sqlInsert = "INSERT INTO SleepManager VALUES(20, 20);";
   const char *sqlSelect = "SELECT * FROM SleepManager;";
 
   // Open Database
   sqlite3 *db;
   rc = sqlite3_open("../sql/TACS.db", &db);
   if (rc)
   {
      cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(db) << endl << endl;
      sqlite3_close(db);
      return;
   }
   else
   {
      cout << "Opened" << endl << endl;
   }
 
   // Execute SQL
   rc = sqlite3_exec(db, sqlInsert, NULL, NULL, &error);
   if (rc)
   {
      cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(db) << endl << endl;
      sqlite3_free(error);
   }
   else
   {
      cout << "Inserted a value into MyTable." << endl << endl;
   }
 
   // Display MyTable
   char **results = NULL;
   int rows, columns;
   sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);
   if (rc)
   {
      cerr << "Error executing SQLite3 query: " << sqlite3_errmsg(db) << endl << endl;
      sqlite3_free(error);
   }
   else
   {
	sqlite3_free_table(results);
   }
   // Close Database
   sqlite3_close(db);
}