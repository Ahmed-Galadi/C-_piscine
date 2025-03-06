
#include "Account.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <ctime>

// static vars
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static privat function 
void	Account::_displayTimestamp( void ) {
	
}

// constructor
Account::Account(int initialDeposit) {
	
	std::stringstream indexStream;
	std::stringstream depoStream;
	
	indexStream << _nbAccounts;
	depoStream << initialDeposit;
	
	std::cout << "index:" << indexStream.str() << ';';
	_accountIndex = _nbAccounts;
	std::cout << "amount:" << depoStream.str() << ';' << "created" << std::endl;
	_amount = initialDeposit;
	_nbAccounts++;
}

// destructor
Account::~Account(void) {

	std::stringstream indexStream;
	std::stringstream amountStream;
	
	indexStream << _accountIndex;
	amountStream << _amount;
	
	std::cout << "index:" << indexStream.str() << ';';
	std::cout << "amount:" << amountStream.str() << ';' << "closed" << std::endl;
}

// static getters
int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbDeposits);
}

void Account::displayAccountsInfos(void) {
	
	std::stringstream accounts;
	std::stringstream total;
	std::stringstream deposits;
	std::stringstream withdrawals;

	accounts << Account::getNbAccounts();
	total << Account::getTotalAmount();
	deposits << Account::getNbDeposits();
	withdrawals << Account::getNbWithdrawals();
	
	std::cout << "accounts:" << accounts.str() << ';'
		<< "total:" << total.str() << ';'
		<< "deposits:" << deposits.str() << ';'
		<< "withdrawal:" << withdrawals.str() << ';'
		<< std::endl;
}

// setters / getters
void Account::makeDeposit(int deposit) {
	
	std::stringstream acc_index;
	std::stringstream prev_amount;
	std::stringstream new_deposit;

	acc_index << _accountIndex;
	prev_amount << _amount;
	new_deposit << deposit;
	std::cout << "index:" << acc_index.str() << ';'
		<< "p_amount:" << prev_amount.str() << ';'
		<< "deposit:" << new_deposit.str() << ';';
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	prev_amount.str("");
	prev_amount.clear();
	prev_amount << _amount;
	new_deposit.str("");
	new_deposit.clear();
	new_deposit << _nbDeposits;
	std::cout << "amount:" << prev_amount.str() << ';'
		<< "nb_deposits:" << new_deposit.str() << ';'
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

	std::stringstream acc_index;
	std::stringstream prev_amount;
	std::stringstream prev_deposits;
	std::stringstream acc_withdrawal;

	acc_index << _accountIndex;
	prev_amount << _amount;
	prev_deposits << _nbDeposits;
	std::cout << "index:" << acc_index.str() << ';'
		<< "p_amount:" << prev_amount.str() << ';'
		<< "deposits:" <<  prev_deposits.str() << ';'
		<< "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	acc_withdrawal << withdrawal;
	prev_amount.str("");
	prev_amount.clear();
	prev_amount << _amount;
	std::cout << acc_withdrawal.str() << ';'
		<< "amount:" << prev_amount.str() << ';'
		<< "nb_withdrawals:" << acc_withdrawal.str() << std::endl;
	return (true);
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus( void ) const {
	
	std::stringstream acc_index;
	std::stringstream acc_amount;
	std::stringstream acc_deposits;
	std::stringstream acc_withdrawl;

	acc_index << _accountIndex;
	acc_amount << _amount;
	acc_deposits << _nbDeposits;
	acc_withdrawl << _nbWithdrawals;
	
	std::cout << "index:" << acc_index.str() << ';'
		<< "amount:" << acc_amount.str() << ';'
		<< "deposits:" << acc_deposits.str() << ';'
		<< "withdrawals:" << acc_withdrawl.str() << ';'
		<< std::endl;
} 
