// Jean Carlos Farfan Fallu
// 02/23/2025

#include "InvestmentGrowInformation.h"
#include <iostream>
#include <iomanip>
#include <cmath> // for rounding, numeric_limits, and isinf
#include "UsersDatabase.h"

// Login and Create Account menu
bool InvestmentGrowInformation::userLoginMenu()
{
    int option;
    // Output
    std::cout << "+----------------------+" << std::endl;
    std::cout << "| Select Option        |" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << "| 1. Log In            |" << std::endl;
    std::cout << "| 2. Create user       |" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << " Option: ";
    std::cin >> option;

    try
    {
        // Start MySQL connection
        MYSQL *m_connection = connectSQL();

        switch (option)
        {
        case 1:

            // Run log in prompts and check if the values are correct.
            if (!loginUser(m_connection, m_username))
            {
                std::cerr << "Invalid username and password combination." << std::endl;
                return false;
            }
            break;

        case 2:;

            if (!createUser(m_connection))
            {
                std::cerr << "Invalid username and password combination." << std::endl;
                return false;
            }
            break;
        default:
            std::cout << "Try again." << std::endl;
            break;
        }
    }
    catch (const std::exception &e)
    {
        // Show exception errors
        std::cout << e.what() << std::endl;
        std::cout << "Database connection failed." << std::endl;
        return false;
    }

    return true;
}

// Pause program by pressing ENTER
void InvestmentGrowInformation::pauseProgram()
{

    // Pause program. Only works on Windows Operating Systems
    // system("pause");

    // Pause program (All Operating Systems).
    std::cout << "Press the key ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

// Validate results after math operations
void InvestmentGrowInformation::resultValidation(double result)
{
    // Detects infinity result.
    if (std::isinf(result))
    {
        throw std::overflow_error("Result is infinity.");
    }
    // Detects overflow in result.
    else if (result > std::numeric_limits<double>::max())
    {
        throw std::out_of_range("Result causes overflow.");
    }
    // Detects underflow in result.
    else if (result < std::numeric_limits<double>::lowest())
    {
        throw std::out_of_range("Result causes underflow.");
    }
}

// Get user input values (only numbers).
double InvestmentGrowInformation::getInput(double objectValue)
{
    double input;

    // If input is not a number.
    if (!(std::cin >> input))
    {
        throw std::invalid_argument("Value should be a number.");
    }
    // Detects infinity.
    else if (std::isinf(input))
    {
        throw std::out_of_range("Value is infinity.");
    }
    // Detect overflow in input.
    else if (input > std::numeric_limits<double>::max())
    {
        throw std::out_of_range("Value causes overflow.");
    }
    // Detect underflow in input.
    else if (input < std::numeric_limits<double>::lowest())
    {
        throw std::out_of_range("Value causes underflow.");
    }
    // If input is lower than the minimum accepted.
    else if (input < objectValue)
    {
        throw std::invalid_argument("Value cannot be lower than " + std::to_string(objectValue) + '.');
    }
    else
    {
        return input;
    }
}

// Round a value to two decimal places for accurate display in the terminal
void InvestmentGrowInformation::roundNumber(double &value)
{
    // Round the given value to 2 decimal places
    value = std::round(value * 100.0) / 100.0;
}

// Constructor: Initialize InvestmentGrowInformation object with default values.
InvestmentGrowInformation::InvestmentGrowInformation()
{
    // Default values
    m_initialInvestmentAmount = 0;
    m_monthlyDeposit = 0;
    m_annualInterest = 0;
    m_numberOfYears = 1;
    m_username = "";
}

// Print the input prompts.
void InvestmentGrowInformation::showInputPrompts()
{
    // Prompts
    std::cout << "**********************************" << std::endl;
    std::cout << "*********** Data Input ***********" << std::endl;
    std::cout << "Initial Investment Amount:" << std::endl;
    std::cout << "Monthly Deposit:" << std::endl;
    std::cout << "Annual Interest:" << std::endl;
    std::cout << "Number of years:" << std::endl;

    pauseProgram();

    std::cout << std::endl;
}

// Get user input for investment information and display tables.
bool InvestmentGrowInformation::getUserValues()
{
    try
    {
        // Prompts
        std::cout << "**********************************" << std::endl;
        std::cout << "*********** Data Input ***********" << std::endl;
        std::cout << "Initial Investment Amount: ";
        m_initialInvestmentAmount = getInput(0); // Input
        roundNumber(m_initialInvestmentAmount);
        std::cout << "Monthly Deposit: ";
        m_monthlyDeposit = getInput(0); // Input
        roundNumber(m_monthlyDeposit);
        std::cout << "Annual Interest: ";
        m_annualInterest = getInput(0); // Input
        roundNumber(m_annualInterest);
        std::cout << "Number of years: ";
        m_numberOfYears = getInput(1); // Input

        std::cout << std::endl;

        /*std::string query = "UPDATE users SET initial_investment_amount = " + std::to_string(m_initialInvestmentAmount) +
                            ", monthly_deposit = " + std::to_string(m_monthlyDeposit) + ", annual_interest = " + std::to_string(m_annualInterest) +
                            ", number_of_years = " + std::to_string(m_numberOfYears) + " WHERE username = '" + m_username + "';";
        std::cout << query << std::endl;

        // Executes query
        MYSQL_RES *result = execSQLQuery(m_connection, query);

        // Clean the memory for the next queries.
        mysql_free_result(result);*/

        // True = Continue with the menu.
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;

        // Clean invalid input.
        std::cin.clear();
        std::cin.ignore();

        // False = Repeat prompts.
        return false;
    }
}

bool InvestmentGrowInformation::showMenuSelection()
{
    // Variables
    int option;

    pauseProgram();

    // Output
    std::cout << "+--------------------------------------------+" << std::endl;
    std::cout << "| Select Option                              |" << std::endl;
    std::cout << "+--------------------------------------------+" << std::endl;
    std::cout << "| 1 - Change Investment Information          |" << std::endl;
    std::cout << "| 2 - Show Balance and Interest Tables       |" << std::endl;
    std::cout << "| 3 - Show Compound Interest Table in Months |" << std::endl;
    std::cout << "| 4 - Exit the program                       |" << std::endl;
    std::cout << "+--------------------------------------------+" << std::endl;
    std::cout << " Option: ";

    // Input
    std::cin >> option;

    switch (option)
    {

        // 1 - Change Investment Information
    case 1:
        getUserValues();
        break;

        // 2 - Show Balance and Interest Tables
    case 2:
        showBalanceAndInterestWithoutMonthlyDeposits();
        showBalanceAndInterestWithMonthlyDeposits();
        break;

        // 3 - Show Compound Interest Table in Months.
    case 3:
        showMonthlyCompoundInterestTable();
        break;

        // 4 - Exit the program
    case 4:
        return false; // Return false, and main() will finish the program.
        break;

        // < 1 and 4 >
    default:
        std::cout << "Incorrect option. Try again." << std::endl; // Error message
        break;
    }

    // Return true if the user's input is not 4 (exit option).
    return true;
}

// Display a table showing the year-end balance and year-end earned interest,
// excluding the effect of monthly deposits.
void InvestmentGrowInformation::showBalanceAndInterestWithoutMonthlyDeposits()
{
    // TODO: 999999999999999999 shows inf
    //  Variables
    double yearEndBalance = m_initialInvestmentAmount;
    double yearEndEarnedInterest;
    unsigned int currentYear;

    // Table
    std::cout << "+----------------------------------------------------------+" << std::endl;
    std::cout << "| Balance and Interest Without Additional Monthly Deposits |" << std::endl;
    std::cout << "+----------------------------------------------------------+" << std::endl;
    std::cout << "| " << std::setw(7) << "Year |" << std::setw(22) << "Year End Balance |"
              << std::setw(29) << "Year End Earned Interest |" << std::endl;
    std::cout << "+----------------------------------------------------------+" << std::endl;

    // Show rows
    for (currentYear = 1; currentYear <= m_numberOfYears; currentYear++)
    {
        try
        {
            // Calculate the year-end earned interest.
            yearEndEarnedInterest = yearEndBalance * (m_annualInterest / 100.0);
            resultValidation(yearEndEarnedInterest);
            roundNumber(yearEndEarnedInterest);

            // Calculate the year-end balance.
            yearEndBalance += yearEndBalance * (m_annualInterest / 100.0);
            resultValidation(yearEndEarnedInterest);
            roundNumber(yearEndBalance);

            // Show table row
            std::cout << "| " << std::setw(5) << currentYear << " |" << std::setw(20) << std::fixed << std::setprecision(2) << yearEndBalance << " |" << std::setw(27) << std::fixed
                      << std::setprecision(2) << yearEndEarnedInterest << " |" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << " Change investment information." << std::endl;
            // Stop printing.
            break;
        }
    }

    std::cout << "+----------------------------------------------------------+\n\n"
              << std::endl;
}

// Display a table showing the year-end balance and year-end earned interest,
// including the effect of monthly deposits.
void InvestmentGrowInformation::showBalanceAndInterestWithMonthlyDeposits()
{
    // Variables
    double yearEndBalance = m_initialInvestmentAmount;
    double yearEndEarnedInterest = 0;
    double yearEndEarnedWithoutInterest = m_initialInvestmentAmount;
    unsigned int currentYear;
    unsigned int monthCounter;

    // Table
    std::cout << "+----------------------------------------------------------+" << std::endl;
    std::cout << "|   Balance and Interest With Additional Monthly Deposits  |" << std::endl;
    std::cout << "+----------------------------------------------------------+" << std::endl;
    std::cout << "| " << std::setw(7) << "Year |" << std::setw(22) << "Year End Balance |"
              << std::setw(29) << "Year End Earned Interest |" << std::endl;
    std::cout << "+----------------------------------------------------------+" << std::endl;

    // Show rows
    for (currentYear = 1; currentYear <= m_numberOfYears; currentYear++)
    {
        try
        {
            // Calculate the year-end balance.
            for (monthCounter = 1; monthCounter <= 12; monthCounter++)
            {
                yearEndBalance += m_monthlyDeposit;
                yearEndBalance += yearEndBalance * ((m_annualInterest / 100.0) / 12.0);

                resultValidation(yearEndBalance);
            }

            // Calculate the year-end earned without interest before calculating the year-end earned interest.
            yearEndEarnedWithoutInterest += yearEndEarnedInterest + (m_monthlyDeposit * 12);
            resultValidation(yearEndEarnedWithoutInterest);

            // Calculate the year-end earned interest.
            yearEndEarnedInterest = yearEndBalance - yearEndEarnedWithoutInterest;

            resultValidation(yearEndEarnedInterest);

            // Show table row.
            std::cout << "| " << std::setw(5) << currentYear << " |" << std::setw(20) << std::fixed << std::setprecision(2) << yearEndBalance << " |" << std::setw(27) << std::fixed
                      << std::setprecision(2) << yearEndEarnedInterest << " |" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << " Change investment information." << std::endl;
            // Stop printing.
            break;
        }
    }

    std::cout << "+----------------------------------------------------------+\n\n"
              << std::endl;
}

void InvestmentGrowInformation::showMonthlyCompoundInterestTable()
{
    // Variables
    double openingAmount = m_initialInvestmentAmount;
    double depositAmount = m_monthlyDeposit;
    double total;
    double interest;
    double closingBalance;
    unsigned int month;

    // Output
    std::cout << "+---------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "| Month | Opening Amount | Deposit Amount |        $ Total |     $ Interest | Closing Balance |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------------------------+" << std::endl;

    // Print rows
    for (month = 1; month <= m_numberOfYears * 12; month++)
    {
        try
        {
            // $ Total
            total = openingAmount + depositAmount;
            resultValidation(total);

            // $ Interest
            interest = total * ((m_annualInterest / 100.0) / 12.0);
            resultValidation(interest);
            roundNumber(interest);

            // Closing Balance
            closingBalance = total + interest;
            resultValidation(closingBalance);

            // Show row
            std::cout << "| " << std::setw(5) << month << " |" << std::setw(15) << std::fixed << std::setprecision(2)
                      << openingAmount << " |" << std::setw(15) << std::fixed << depositAmount << " |" << std::setw(15) << total << " |" << std::setw(15) << interest << " |" << std::setw(16) << closingBalance << " |" << std::endl;

            // Change Opening Amount for the next month
            openingAmount = closingBalance;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << " Change investment information." << std::endl;
            // Stop printing.
            break;
        }
    }

    std::cout << "+---------------------------------------------------------------------------------------------+" << std::endl;
}