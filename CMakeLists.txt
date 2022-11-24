include(FetchContent)

cmake_minimum_required(VERSION 3.16)
project(postgresql-samples)

find_package(PostgreSQL REQUIRED)

FetchContent_Declare(
  libpqxx
  GIT_REPOSITORY https://github.com/jtv/libpqxx.git
  GIT_TAG a6b1d60e74c1427c8ac2324b85cd4a0dc2068332
)
set(PQXX_LIBRARIES pqxx_static)

FetchContent_MakeAvailable(libpqxx)

add_executable(connecting src/connecting.cc)
add_executable(creating-table src/creating-table.cc)
add_executable(insert src/insert.cc)
add_executable(select src/select.cc)
add_executable(update src/update.cc)
add_executable(delete src/delete.cc)

target_link_libraries(connecting PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)

target_link_libraries(creating-table PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)

target_link_libraries(insert PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)

target_link_libraries(select PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)

target_link_libraries(update PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)

target_link_libraries(delete PRIVATE ${PQXX_LIBRARIES} PostgreSQL::PostgreSQL)