// Jean Carlos Farfan Fallu
// 02/23/2025

#ifndef AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_
#define AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_

#include <string>
#include <mysql/mysql.h>
class InvestmentGrowInformation
{
private:
	// Variables
	double m_initialInvestmentAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	unsigned int m_numberOfYears;
	std::string m_username;
	MYSQL *m_connection;

public:
	// Get functions
	double getInitialInvestmentAmount() { return m_initialInvestmentAmount; }
	double getMonthlyDeposit() { return m_monthlyDeposit; }
	double getAnnualInterest() { return m_annualInterest; }
	unsigned int getNumberOfYears() { return m_numberOfYears; }

	// Constructor
	InvestmentGrowInformation();

	// Methods
	double getInput(double objectValue);
	bool getUserValues();
	bool showMenuSelection();
	bool userLoginMenu();
	void resultValidation(double result);
	void showInputPrompts();
	void showBalanceAndInterestWithoutMonthlyDeposits();
	void showBalanceAndInterestWithMonthlyDeposits();
	void showMonthlyCompoundInterestTable();
	void pauseProgram();
	void roundNumber(double &value);
};

#endif // AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_