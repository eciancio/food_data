#include <string>
#include <mysql_connection.h>
#include <vector>
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
		void replace(std::string values);
		Table(std::string name, std::string db, int fields);
		std::vector<std::map<std::string, std::string> > select_row();
		std::vector<std::map<std::string, std::string> > selections(std::string query);
		std::string* get_feilds();
		void set_feilds(std::string *arr);
		std::vector<std::map<std::string, std::string> > select_row_where(std::string where);
};
#endif

