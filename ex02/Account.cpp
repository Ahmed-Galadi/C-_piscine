
#include "Account.hpp"
#include <iostream>
#include <ostream>
#include <ctime>

// static vars
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static privat function 
void	Account::_displayTimestamp( void ) {

	std::time_t now = std::time(NULL);
	std::tm *local_time = std::localtime(&now);

	int year = local_time->tm_year + 1900;
	int month = local_time->tm_mon + 1;
	int day = local_time->tm_mday;
	int hours = local_time->tm_hour;
	int minutes = local_time->tm_min;
	int seconds = local_time->tm_sec;

	std::cout << '[' << year << month << day
		<< '_' << hours << minutes << seconds << "] ";
}

// constructor
Account::Account(int initialDeposit) {
	
	Account::_displayTimestamp();	
	std::cout << "index:" << _nbAccounts << ';';
	_accountIndex = _nbAccounts;
	std::cout << "amount:" << initialDeposit << ';' << "created" << std::endl;
	_amount = initialDeposit;
	Account::_totalAmount += _amount;
	_nbAccounts++;
}

// destructor
Account::~Account(void) {

	Account::_displayTimestamp();	
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';' << "closed" << std::endl;
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
	
	Account::_displayTimestamp();	
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
		<< "total:" <<  Account::getTotalAmount() << ';'
		<< "deposits:" << Account::getNbDeposits() << ';'
		<< "withdrawal:" << Account::getNbWithdrawals() << ';'
		<< std::endl;
}

// setters / getters
void Account::makeDeposit(int deposit) {
	
	Account::_displayTimestamp();	
	std::cout << "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "deposit:" << deposit << ';';
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << _amount << ';'
		<< "nb_deposits:" << _nbDeposits << ';'
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();	
	std::cout << "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ';'
		<< "amount:" << _amount << ';'
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus( void ) const {
	
	Account::_displayTimestamp();	
	std::cout << "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "deposits:" << _nbDeposits << ';'
		<< "withdrawals:" << _nbWithdrawals << ';'
		<< std::endl;
} 
