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
#include <cstdlib> 
#include <ctime>
using namespace sql;
using namespace std;

void pick_day();
string choose_random(vector<map<string,string> > meal);
vector<map<string,string> > read_in_meal(string meal);
int main(){
	pick_day();
}

vector<map<string,string> > read_in_meal(string meal){
	string name = "bank";
	string database = "prac_bank";

	Table *bank = new Table(name, database, 5);

	string arr[5] = {"id", "name","mean", "calories","preference"};
	bank->set_feilds(arr);

	vector<map<string,string> > results;
	results = bank->select_row_where(" mean=\""+ meal + "\" ");
	return results;
}

void pick_day(){
	srand(time(NULL));
	vector<map<string,string> > breakfast = read_in_meal("Breakfast");
	vector<map<string,string> > lunch = read_in_meal("Lunch");
	vector<map<string,string> > dinner = read_in_meal("Dinner");
	string first = choose_random(breakfast);
	string second = choose_random(lunch);
	string third = choose_random(dinner);
	cout<<first + " " + second + " " + third<<endl;
}

string choose_random(vector<map<string,string> > meal){
	int rands = (rand() % meal.size());
	return meal[rands]["name"];
}
