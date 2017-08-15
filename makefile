p_test-c:
	sudo g++ -Wall -I/usr/include/cppconn -o testapp test.cpp -L/usr/lib -lmysqlcppconn

p_test: test-c
	./testapp


base_test: 	
	 g++ -Wall -I/usr/include/cppconn food_sql.cpp food_sql_test.cpp -o food_sql_test -L/usr/lib -lmysqlcppconn
	 ./food_sql_test

pantry_test:
	 g++ -Wall -I/usr/include/cppconn food_sql.cpp Update_Bank.cpp -o up_bank -L/usr/lib -lmysqlcppconn
	 ./up_bank

test:
	 g++ -Wall -I/usr/include/cppconn food_sql.cpp  make_meals.cpp -o make_meal -L/usr/lib -lmysqlcppconn
	 ./make_meal


