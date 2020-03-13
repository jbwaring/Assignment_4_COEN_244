#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
	double balance;


public:

	Account();
	void pay_amount(double a);
	void get_balance(double &d);
	void add_charge(double d);



};

#endif 