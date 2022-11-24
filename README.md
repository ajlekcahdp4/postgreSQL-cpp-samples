# postgreSQL C++ API tutorial
All the samples were taken from [here](https://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm)
## Interface APIs
| APIs | Description |
| :---- | ------------ |
| pqxx::connection | This is a typedef which will be used to connect to the database. Here, dbstring provides required parameters to connect to the datbase, for example dbname = testdb user = postgres password=pass123 hostaddr=127.0.0.1 port=5432. If connection is setup successfully then it creates C with connection object which provides various useful function public function. |
| C.is_open() | The method is_open() is a public method of connection object and returns boolean value. If connection is active, then this method returns true otherwise it returns false. |
| pqxx::work W(C) | This is a typedef which will be used to create a transactional object using connection C, which ultimately will be used to execute SQL statements in transactional mode. If transaction object gets created successfully, then it is assigned to variable W which will be used to access public methods related to transactional object. |
| W.exec(const std::string &sql) | This public method from transactional object will be used to execute SQL statement. |
| W.commit() | This public method from transactional object will be used to commit the transaction. |
| W.abort() | This public method from transactional object will be used to rollback the transaction. |
| pqxx::nontransaction N(C) | This is a typedef which will be used to create a non-transactional object using connection C, which ultimately will be used to execute SQL statements in non-transactional mode. If transaction object gets created successfully, then it is assigned to variable N which will be used to access public methods related to non-transactional object. |
| N.exec(const std::string & sql) | This public method from non-transactional object will be used to execute SQL statement and returns a result object which is actually an interator holding all the returned records. |