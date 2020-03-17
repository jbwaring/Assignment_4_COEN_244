#pragma once

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


};

#endif 