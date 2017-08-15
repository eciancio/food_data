#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <stdlib.h>
#include <iostream>
#include "food_sql.h"
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <string>
#include <map>

using std::string;
using namespace sql;


void create_table(sql::Connection *con, std::string name, std::string db, std::string vars){
	sql::Statement *stmt; 
	stmt = con->createStatement();
	string create_table = "CREATE TABLE " + name + vars + ";";
	string use_db = "USE " + db;

	stmt->execute(use_db);
	stmt->execute(create_table);
	delete stmt;
}


string Table::get_database(){
	return this->database;
}

Table::Table(string name, string db, int fields){
		this->name = name;
		this->database = db;
		this->driver = get_driver_instance();
		this->con = driver->connect("tcp://127.0.0.1:3306", "root", "Panthers16");
		this->fields = fields;
		this->stmt = con->createStatement();
}


void Table::insert(string values){
	string insert = "Insert INTO " + database + "." + name + "\n";
	string vals = "VALUES (" + values + ");";

	stmt->execute(insert + vals);
}
  
std::map<string, string> Table::select_row(string query){

	string squery = "Select "+ query + " FROM " + database + "." + name + ";";
	
	sql::ResultSet  *res;
	res = stmt->executeQuery(squery);
	res->next();
	std::map<string,string> results;
	for(int i = 0; i < this->fields; i++){
	
		results[this->labels[i]] = res->getString(this->labels[i]);
	}	
	return results;
}

void Table::set_feilds(string *arr){
	this->labels = new string[this->fields];
	for(int i = 0; i< this->fields; i++){
		labels[i] = arr[i];
	}
}

string* Table::get_feilds(){
	string *dog = new string[this->fields];
	for(int i = 0; i< this->fields; i++){
		dog[i] = this->labels[i];
	}
	return dog;
}
		
