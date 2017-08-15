#include <string>
#include <mysql_connection.h>
#ifndef _main_h
#define _main_h
using namespace sql::mysql;

void create_table(sql::Connection *con, std::string name, std::string db, std::string vars);

class Table{
	private:
		std::string name;
		std::string database;
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		int fields;
		std::string *labels=NULL;
	public:
		std::string get_database();
		void insert(std::string values);
		Table(std::string name, std::string db, int fields);
		std::map<std::string, std::string> select_row(std::string query);
		std::string* get_feilds();
		void set_feilds(std::string *arr);
};
#endif

