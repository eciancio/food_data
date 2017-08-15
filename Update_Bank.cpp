// Will update the Bank of all foods using csv.. food_bank.csv
// Categories are Name, Meal, Calories, Preference.
#include "food_sql.h"
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace sql;
using namespace std;

string add_parenthesis(string word);
void read_in_csv();
int main(){
	read_in_csv();
}

void read_in_csv(){
 // will read in food data from csv and push to db
 string name = "bank";
 string database = "prac_bank";

 Table *bank = new Table(name, database, 5);

 ifstream file;
 file.open ( "bank.csv");
 string value;
 int id = 0;
 string names;
 string meal;
 string calories;
 string preference;
 while (file.good()){
	 getline(file, names, ',');
	 getline(file, meal, ',');
	 getline(file, calories, ',');
	 getline(file, preference, '\n');
	 ostringstream convert;
	 convert << id;
	 string insert = "";
	 insert += convert.str() + ", ";
	 insert += add_parenthesis(names) + ", ";
	 insert+= add_parenthesis(meal) + ",";
	 insert += calories + ",";
	 insert += preference;
	 id++;
	 bank->replace(insert);
 }
}

string add_parenthesis(string word){
	word = "\"" + word + "\"";
	return word;
}
