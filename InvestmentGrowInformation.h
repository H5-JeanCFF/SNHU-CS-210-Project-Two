#ifndef AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_
#define AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_
class InvestmentGrowInformation
{
private:
	// Variables
	double m_initialInvestmentAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	unsigned int m_numberOfYears;

public:
	// Get functions
	double getInitialInvestmentAmount() { return m_initialInvestmentAmount; }
	double getMonthlyDeposit() { return m_monthlyDeposit; }
	double getAnnualInterest() { return m_annualInterest; }
	unsigned int getNumberOfYears() { return m_numberOfYears; }

	// Constructor
	InvestmentGrowInformation();

	// Methods
	bool getUserValues();
	void showInputPrompts();
	bool showMenuSelection();
	void showBalanceAndInterestWithoutMonthlyDeposits();
	void showBalanceAndInterestWithMonthlyDeposits();
	void showMonthlyCompoundInterestTable();
};

#endif // AIRGEADBANKINGINVESTMENTAPP_INVESTMENTGROWINFORMATION_H_