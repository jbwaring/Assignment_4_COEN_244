#pragma once
#include "./person.h"
#include "./date.h"
#include "./doctor.h"
#include "./bed.h"
#ifndef OUTPATIENT_H
#define OUTPATIENT_H 
using namespace std;


class outPatient : public Person
{

private:
Date* apt_date;
Doctor* prv_dr;
double h_charge;

public:

	outPatient(string fname, string mname, string lname, int sin, Date &apt, Doctor &prvd, double chrg);
	outPatient(outPatient* pt);
	void get_profile(vector<string> &ans);
	vector<string> get_save();

};


#endif