#include <iostream>
#include <pqxx/pqxx> 


int main(int argc, char* argv[]) {
   char * sql;
   
   try {
      pqxx::connection C("dbname = testdb user = postgres password = 123 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         std::cout << "Opened database successfully: " << C.dbname() << std::endl;
      } else {
         std::cout << "Can't open database" << std::endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

      /* Create a transactional object. */
      pqxx::work W(C);
      
      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      std::cout << "Table created successfully" << std::endl;
   } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}