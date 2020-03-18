#pragma once
#include "./person.h"
#include "./date.h"
#include "./bed.h"
#include "./account.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#ifndef INPATIENT_H
#define INPATIENT_H 

using namespace std;

class inPatient : public Person
{
private:
Date* adm_date;
Date* dis_date;
Bed* bed;
string bed_serial;
protected:
int service, cond_no;
public:
	Account* account;
	inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d1, Date &d2, double d_charge);
	inPatient(inPatient* ptr);
	void get_profile(vector<string> &ans);
	vector<string> get_save();
	double compute_t_charge(double d_charge);
	void set_bed_serial(string serial){
		bed_serial = serial;
	}
// make destructor delete pointers of "private:" !!

};
#endif