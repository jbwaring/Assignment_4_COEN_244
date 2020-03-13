
#include "./account.h"


	Account::Account(){
		balance = 0;
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