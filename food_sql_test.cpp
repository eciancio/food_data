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
#include <assert.h>   

using namespace sql;
void test_create_table();

void test_select_row_where();
void test_set_feilds();
void test_insert_and_select_two_columns();
void test_insert_and_select();
void test_create_table_object();	
int main(){
	test_create_table();
	test_set_feilds();
        test_insert_and_select();
	test_select_row_where();
	test_insert_and_select_two_columns();
 	test_create_table_object();	
}

void test_create_table(){
	sql::Driver *driver;
	sql::Connection *con;
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "Panthers16");

	sql::Statement *stmt;
	stmt = con->createStatement();

	stmt->execute("DROP TABLE IF EXISTS testdb.create_test;");	
	std::string name = "create_test";
	std::string vars = "(id int, name TEXT)";
	create_table(con, name, "testdb", vars);
	stmt->execute("SELECT * FROM create_test")==0;
	
	std::cout<< "test_create_table PASSED"<<std::endl;	

	delete stmt;
	delete con;
}

void test_create_table_object(){	
	Table *prac= new Table("I","DB",2);
	assert(prac->get_database() == "DB");
	std::cout<< "test_create_tale_object PASSED"<<std::endl;
}

void test_insert_and_select(){

	std::string name = "Prac_Table";
	std::string database = "testdb";

	Table *prac = new Table(name, database,1);
	std::string arr[1] = {"id"};
	prac->set_feilds(arr);
	prac->insert("\"words\"");
	prac->select_row();
	std::cout<< "test_insert_and_select PASSED"<<std::endl;
}

void test_insert_and_select_two_columns(){

	std::string name = "Prac_two";
	std::string database = "testdb";

	Table *prac = new Table(name, database,2);
	std::string arr[2] = {"id","Name"};
	prac->set_feilds(arr);

	prac->insert("\"dogs\", 2");
	std::vector<std::map<std::string,std::string> > results;
	results = prac->select_row();
	for( int i = 0; i < int(results.size()); i++){
		assert(results[i]["id"]=="dogs");
		assert(results[i]["Name"]=="2");
	}
	std::cout<<"test_insert_and_select_two_columns PASSED"<<std::endl;
}

void test_set_feilds(){
	std::string name = "Prac_two";
	std::string database = "testdb";

	Table *prac = new Table(name, database, 2);

	std::string arr[2] = {"id", "Name"}; 
	prac->set_feilds(arr);

	std::string *result = prac->get_feilds();
	assert(result[0] == "id");
	assert(result[1] == "Name");

	std::cout<<"test_set_fields PASSED"<<std::endl;

}
void test_select_row_where(){
	std::string name = "select_where";
	std::string database = "testdb";

	Table *prac = new Table(name, database, 2);

	std::string arr[2] = {"id", "food"};
	prac->set_feilds(arr);

	std::vector<std::map<std::string,std::string> > results;
	results = prac->select_row_where(" id=2 ");

	assert(results[0]["id"] == "2" );
	assert(results[0]["food"] == "Bread" );
	std::cout<<"test_select_row_where PASSED"<<std::endl;
}



