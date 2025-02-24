// Jean Carlos Farfan Fallu
// 02/23/2025

#include <iostream>
#include "InvestmentGrowInformation.h"

int main()
{

    // Object
    InvestmentGrowInformation userInvestment;

    // Show prompts.
    userInvestment.userLoginMenu();

    // Show Balance and Interest tables with and without monthly deposits.
    userInvestment.showBalanceAndInterestWithoutMonthlyDeposits();
    userInvestment.showBalanceAndInterestWithMonthlyDeposits();

    // Show user menu while this function returns true.
    while (userInvestment.showMenuSelection());

    return 0;
}
