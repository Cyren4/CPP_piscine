#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <locale>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << " index:" << Account::_nbAccounts;
    std::cout << ";amount:" << this->_amount << ";created" << std::endl;
    Account::_nbAccounts++;
}

Account::Account(int initial_deposit){
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << " index:" << Account::_nbAccounts;
    std::cout << ";amount:" << initial_deposit << ";created" << std::endl;
    Account::_totalAmount += initial_deposit; 
    Account::_nbAccounts++;
}

Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount << ";close" << std::endl;
}

void	Account::displayAccountsInfos(void){
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    if (this->_amount <= withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        std::cout << ";withdrawal:" << withdrawal;
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        std::cout << ";amount:" << this->_amount;
        std::cout << ";nb_withdrawal:" << this->_nbWithdrawals << std::endl;
    }
    return true;
}

int		Account::checkAmount(void) const{
    return this->_amount;
}

void	Account::displayStatus(void) const{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void){
    time_t now = time(0);
    tm *ltm = localtime(&now);
	std::cout << "[" <<std::setfill('0') << std::setw(4);
    std::cout << 1900 + ltm->tm_year;
	std::cout << std::setfill('0') << std::setw(2);
    std::cout << 1 + ltm->tm_mon;
	std::cout << std::setfill('0') << std::setw(3);
    std::cout << ltm->tm_mday << '_';
	std::cout << std::setfill('0') << std::setw(2);
    std::cout << 5 + ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2);
    std::cout << 30 + ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(3);
    std::cout << ltm->tm_sec << "]";
}

int	Account::getNbAccounts(){
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(){
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(){
    return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals(){
    return (Account::_totalNbWithdrawals);
}