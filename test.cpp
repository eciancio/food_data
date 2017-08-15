#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/statement.h>

using namespace sql;

int main(void){
sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;


driver = get_driver_instance();
con = driver->connect("tcp://127.0.0.1:3306", "root", "Panthers16");


stmt = con->createStatement();
stmt->execute("USE testdb");
stmt->execute("INSERT INTO Ye(id, NAME) VALUES (2, 'Grape')");

delete stmt;
delete con;
}
