#include <iostream>
#include <pqxx/pqxx> 


int main(int argc, char* argv[]) {
   char * sql;
   
   try {
      pqxx::connection C("dbname = testdb user = postgres password = cohondob \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         std::cout << "Opened database successfully: " << C.dbname() << std::endl;
      } else {
         std::cout << "Can't open database" << std::endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

      /* Create a transactional object. */
      pqxx::work W(C);
      
      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      std::cout << "Records created successfully" << std::endl;
   } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}