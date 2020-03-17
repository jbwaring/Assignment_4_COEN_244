
#include "./account.h"


	Account::Account(){
		balance = 0;
	}
	Account::Account(double t){
		balance = t;
	}
	void Account::pay_amount(double a){
		balance = balance - a;
	}
	void Account::get_balance(double &d){
		d = balance;

	}
	void Account::add_charge(double d){
		balance = balance + d;
	}