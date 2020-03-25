/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include "./account.h"
using namespace std;

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
	double Account::get_balance(){
		return balance;
	}
	string Account::get_balance_str(){
		ostringstream tempFloatingPrecision;
		tempFloatingPrecision << fixed;
		tempFloatingPrecision << setprecision(2);
		tempFloatingPrecision << balance;
		return tempFloatingPrecision.str();
	}
	void Account::add_charge(double d){
		balance = balance + d;
	}