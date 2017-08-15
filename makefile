p_test-c:
	sudo g++ -Wall -I/usr/include/cppconn -o testapp test.cpp -L/usr/lib -lmysqlcppconn

p_test: test-c
	./testapp


test: 	
	 g++ -Wall -I/usr/include/cppconn food_sql.cpp food_sql_test.cpp -o food_sql_test -L/usr/lib -lmysqlcppconn
	 ./food_sql_test


