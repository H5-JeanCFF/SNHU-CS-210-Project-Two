#include "InvestmentGrowInformation.h"
#include <iostream>
#include <iomanip>

// Constructor: Initialize InvestmentGrowInformation object with default values.
InvestmentGrowInformation::InvestmentGrowInformation()
{
    // Default values
    m_initialInvestmentAmount = 0;
    m_monthlyDeposit = 0;
    m_annualInterest = 0;
    m_numberOfYears = 1;
}

// Print the input prompts.
void InvestmentGrowInformation::showInputPrompts() {
    // Prompts
    std::cout << "**********************************" << std::endl;
    std::cout << "*********** Data Input ***********" << std::endl;
    std::cout << "Initial Investment Amount:" << std::endl;
    std::cout << "Monthly Deposit:" << std::endl;
    std::cout << "Annual Interest:" << std::endl;
    std::cout << "Number of years:" << std::endl;

    system("pause"); // Pause program
    std::cout << std::endl;
}

// Get user input for investment information and display tables.
bool InvestmentGrowInformation::getUserValues()
{
    // Prompts
    std::cout << "**********************************" << std::endl;
    std::cout << "*********** Data Input ***********" << std::endl;
    std::cout << "Initial Investment Amount: ";
    std::cin >> m_initialInvestmentAmount; // Input
    std::cout << "Monthly Deposit: ";
    std::cin >> m_monthlyDeposit; // Input
    std::cout << "Annual Interest: ";
    std::cin >> m_annualInterest; // Input
    std::cout << "Number of years: ";
    std::cin >> m_numberOfYears; // Input

    system("pause"); // Pause program
    std::cout << std::endl;

    // If something is wrong, return false and main() call again this function
    if ((m_initialInvestmentAmount < 0) || (m_monthlyDeposit < 0) || (m_annualInterest < 0) || (m_numberOfYears <= 0)) {
        return false;
    }

    // The values are correct
    return true;
}

bool InvestmentGrowInformation::showMenuSelection()
{
    // Variables
    int option;

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

    switch (option) {

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
    // Variables
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
    for (currentYear = 1; currentYear <= m_numberOfYears; currentYear++) {

        // Calculate the year-end earned interest.
        yearEndEarnedInterest = yearEndBalance * (m_annualInterest / 100.0);

        // Calculate the year-end balance.
        yearEndBalance += yearEndBalance * (m_annualInterest / 100.0);

        // Show table row
        std::cout << "| " << std::setw(5) << currentYear << " |" << std::setw(20) << std::fixed <<
            std::setprecision(2) << yearEndBalance << " |" << std::setw(27) << std::fixed
            << std::setprecision(2) << yearEndEarnedInterest << " |" << std::endl;
    }

    std::cout << "+----------------------------------------------------------+\n\n" << std::endl;
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
    for (currentYear = 1; currentYear <= m_numberOfYears; currentYear++) {

        // Calculate the year-end balance.
        for (monthCounter = 1; monthCounter <= 12; monthCounter++) {
            yearEndBalance += m_monthlyDeposit;
            yearEndBalance += yearEndBalance * ((m_annualInterest / 100.0) / 12.0);
        }

        // Calculate the year-end earned without interest before calculating the year-end earned interest.
        yearEndEarnedWithoutInterest += yearEndEarnedInterest + (m_monthlyDeposit * 12);

        // Calculate the year-end earned interest.
        yearEndEarnedInterest = yearEndBalance - yearEndEarnedWithoutInterest;

        // Show table row.
        std::cout << "| " << std::setw(5) << currentYear << " |" << std::setw(20) << std::fixed <<
            std::setprecision(2) << yearEndBalance << " |" << std::setw(27) << std::fixed
            << std::setprecision(2) << yearEndEarnedInterest << " |" << std::endl;
    }

    std::cout << "+----------------------------------------------------------+\n\n" << std::endl;
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
    for (month = 1; month <= m_numberOfYears * 12; month++) {

        // $ Total
        total = openingAmount + depositAmount;

        // $ Interest
        interest = total * ((m_annualInterest / 100.0) / 12.0);

        // Closing Balance
        closingBalance = total + interest;

        // Show row
        std::cout << "| " << std::setw(5) << month << " |" << std::setw(15) << std::fixed << std::setprecision(2)
            << openingAmount << " |" << std::setw(15) << std::fixed << depositAmount << " |" << std::setw(15) <<
            total << " |" << std::setw(15) << interest << " |" << std::setw(16) << closingBalance << " |" << std::endl;

        // Change Opening Amount for the next month
        openingAmount = closingBalance;
    }


    std::cout << "+---------------------------------------------------------------------------------------------+" << std::endl;
}