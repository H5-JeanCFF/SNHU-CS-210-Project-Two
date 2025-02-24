// Jean Carlos Farfan Fallu
// 02/23/2025

#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include <iostream>
#include <tuple>
#include <iomanip>
#include <termios.h>
#include <unistd.h>

// Code reference: https://terminalroot.com/how-to-hide-input-via-cli-with-cpp/
std::string getHiddenPassword() {
    std::string password;
    char ch;
    struct termios oldt, newt;

    // Disable echoing
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::cout << "Enter Password: ";
    std::cin >> password;

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << std::endl;

    return password;
}

// SQL Connection structure
struct SQLConnection
{
    std::string server;
    std::string user;
    std::string password;
    std::string databaseName;

    SQLConnection(std::string server, std::string user, std::string password, std::string databaseName)
    {
        this->server = server;
        this->user = user;
        this->password = password;
        this->databaseName = databaseName;
    }
};

// Function that establishes a connection to the SQL database.
MYSQL *connectSQL()
{
    MYSQL *connection = mysql_init(NULL);

    struct SQLConnection SQLdata("localhost", "AirgeadAdmin", "s3cr3tp4ssw0rd", "airgead_db");

    if (!mysql_real_connect(connection, SQLdata.server.c_str(),
                            SQLdata.user.c_str(), SQLdata.password.c_str(),
                            SQLdata.databaseName.c_str(), 0, NULL, 0))
    {
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        return nullptr;
    }

    return connection;
}

// Executes a SQL query and retrieves the result.
MYSQL_RES *execSQLQuery(MYSQL *connection, std::string query)
{
    if (mysql_query(connection, query.c_str()))
    {
        std::cout << "MySQL Query Error: " << mysql_error(connection) << std::endl;
        throw std::runtime_error("Unable to run query.");
        return nullptr;
    }

    return mysql_store_result(connection); // Store the full result set
}

// Prints database users (FOR TESTS)
void printUsers(MYSQL *connection)
{
    std::string query = "SELECT * FROM users;";
    MYSQL_RES *result = execSQLQuery(connection, query);

    if (!result)
    {
        return;
    }

    mysql_free_result(result); // Free result before continuing
}

// Authenticates a user using username and password.
bool loginUser(MYSQL *connection, std::string &m_username)
{
    printUsers(connection);

    // Prompts
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    password = getHiddenPassword();

    std::string query = "SELECT id FROM users WHERE username = '" + username + "' AND password = '" + password + "';";

    try
    {
        // Executes query
        MYSQL_RES *result = execSQLQuery(connection, query);

        // True if there is a register with the same username and password.
        bool success = (mysql_num_rows(result) > 0);
        
        // Clean the memory for the next queries.
        mysql_free_result(result);

        m_username = username;

        return success;
    }
    catch (const std::exception &e)
    {
        // Catch exceptions related to executing a query.
        std::cerr << e.what() << std::endl;
        return false;
    }
}

// Authenticates a user using username and password.
bool createUser(MYSQL *connection)
{
    printUsers(connection);

    // Prompts
    std::string firstName, lastName, email, username, password;
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;
    std::cout << "e-mail: ";
    std::cin >> email;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::string query = "INSERT INTO users (first_name, last_name, email, password, username) VALUES ('" +
    firstName +"', '" + lastName + "', '" + email + "', '" + password + "', '" + username + "');";

    try
    {
        // Executes query
        MYSQL_RES *result = execSQLQuery(connection, query);

        // Clean the memory for the next queries.
        mysql_free_result(result);

        return true;
    }
    catch (const std::exception &e)
    {
        // Catch exceptions related to executing a query.
        std::cerr << e.what() << std::endl;
        return false;
    }
}
