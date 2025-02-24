// Jean Carlos Farfan Fallu
// 02/23/2025

#ifndef USERS_DATABASE_H
#define USERS_DATABASE_H

#include <mysql/mysql.h>
#include <string>

MYSQL* connectSQL();
bool loginUser(MYSQL *connection, std::string &m_username);
bool createUser(MYSQL *connection);
MYSQL_RES *execSQLQuery(MYSQL *connection, std::string query);

#endif // USERS_DATABASE_H
