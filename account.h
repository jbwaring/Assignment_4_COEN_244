/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
	double balance;


public:

	Account();
	Account(double t);
	void pay_amount(double a);
	void add_charge(double d);
	void get_balance(double &d);
	double get_balance();
	std::string get_balance_str();

};

#endif 