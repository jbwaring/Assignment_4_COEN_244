#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./person.h"
#include "./date.h"
#include "./time.h"
#ifndef INPATIENT_H
#define INPATIENT_H 
using namespace std;

class inPatient : public Person 
{
private:
Date* adm_date;
protected:
int service, cond_no;
public:

	inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d);
	void get_profile(vector<string> &ans);

// make destructor delete pointers of "private:" !!

};
#endif