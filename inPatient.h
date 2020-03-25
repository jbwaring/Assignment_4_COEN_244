/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#pragma once
#include <dialog.h>
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
//DESTRUCTOR:
	~inPatient(){/*
		delete adm_date;
		delete dis_date;
		delete bed;
		delete account;
		string recap = "Destructor Has Finished";
	init_dialog(stdin, stdout);
	dialog_msgbox("Patient REMOVE", &recap[0], 100, 100, 1);
	dialog_vars.input_result = NULL;
	end_dialog();*/
	}
	

};
#endif