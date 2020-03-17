#pragma once
#include "./person.h"
#include "./date.h"
#include "./bed.h"
#ifndef INPATIENT_H
#define INPATIENT_H 

using namespace std;

class inPatient : public Person
{
private:
Date* adm_date;
Date* dis_date;
Bed* bed;

double t_balance;
protected:
int service, cond_no;
public:

	inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d1, Date &d2, double d_charge);
	inPatient(inPatient* ptr);
	void get_profile(vector<string> &ans);
	vector<string> get_save();
	double compute_t_charge(double d_charge);
	void pay_amount(double a);
	void add_charge(double d);
	void get_balance(double &d);
	double get_balance(){
		return t_balance;
	}
// make destructor delete pointers of "private:" !!

};
#endif