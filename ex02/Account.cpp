
#include "Account.hpp"
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;

Account::Account(int initialDeposit) {
	
	std::stringstream indexStream;
	std::stringstream depoStream;
	
	indexStream << _nbAccounts;
	depoStream << initialDeposit;
	
	std::cout << "index:" << indexStream.str() << ';';
	_accountIndex = _nbAccounts;
	std::cout << "amount:" << depoStream.str() << "created" << std::endl;
	_amount = initialDeposit;
	_nbAccounts++;
}

void Account::displayAccountsInfos(void) {
	
}


