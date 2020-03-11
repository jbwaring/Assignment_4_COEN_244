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
double t_charge;
protected:
int service, cond_no;
public:

	inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d);
	inPatient(inPatient* ptr);
	void get_profile(vector<string> &ans);

// make destructor delete pointers of "private:" !!

};
#endif