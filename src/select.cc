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
      sql = "SELECT * from COMPANY";

      /* Create a non-transactional object. */
      pqxx::nontransaction N(C);
      
      /* Execute SQL query */
      pqxx::result R( N.exec( sql ));
      
      /* List down all the records */
      for (auto c = R.begin(); c != R.end(); ++c) {
         std::cout << "ID = " << c[0].as<int>() << std::endl;
         std::cout << "Name = " << c[1].as<std::string>() << std::endl;
         std::cout << "Age = " << c[2].as<int>() << std::endl;
         std::cout << "Address = " << c[3].as<std::string>() << std::endl;
         std::cout << "Salary = " << c[4].as<float>() << std::endl;
      }
      std::cout << "Operation done successfully" << std::endl;
   } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}