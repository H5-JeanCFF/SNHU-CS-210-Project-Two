// Jean Carlos Farfan Fallu
// 10/01/2023

#include <iostream>
#include "InvestmentGrowInformation.h"


int main()
{
    // Object.
    InvestmentGrowInformation userInvestment;

    // Show prompts.
    userInvestment.showInputPrompts();

    // Call this function while the inputs are incorrect (false)
    while (!userInvestment.getUserValues()) {
        std::cout << "Try again." << std::endl;
    } 

    // Show Balance and Interest tables with and without monthly deposits.
    userInvestment.showBalanceAndInterestWithoutMonthlyDeposits();
    userInvestment.showBalanceAndInterestWithMonthlyDeposits();
    
    // Show user menu while this function returns true.
    while (userInvestment.showMenuSelection());
    
    return 0;
}
