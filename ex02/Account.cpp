/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malak <malak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:30:01 by malak             #+#    #+#             */
/*   Updated: 2025/11/01 23:00:31 by malak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{
    static int index = 0;
    _accountIndex = index++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    std::cout << "index:" << _accountIndex << ";ammount:" << _amount << ";created" << std::endl;
}
int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

Account::~Account( void )
{
   _displayTimestamp();
    std::cout <<  "index:" << _accountIndex << ";ammount:" << _amount << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    int p_amount(_amount);
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
   _displayTimestamp();
    std::cout <<  "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;
    if (withdrawal > _amount)
    {
       _displayTimestamp();
        std::cout <<  "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
   _displayTimestamp();
    std::cout <<  "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int     Account::checkAmount( void ) const
{
    return _amount;
}

void    Account::displayStatus( void ) const
{
   _displayTimestamp();
    std::cout <<  "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos( void )
{
   _displayTimestamp();
    std::cout <<  "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t time = std::time(NULL);
    std::tm*	tm = std::localtime(&time);
    std::cout << "["<<tm->tm_year + 1900
                << std::setw(2) << std::setfill('0') << tm->tm_mon + 1
                << std::setw(2) << std::setfill('0') << tm->tm_mday
                << "_"
                << std::setw(2) << std::setfill('0') << tm->tm_hour
                << std::setw(2) << std::setfill('0') << tm->tm_min
                << std::setw(2) << std::setfill('0') << tm->tm_sec << "] ";
     
}



