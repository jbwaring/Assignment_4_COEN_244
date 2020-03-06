#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./person.h"
#ifndef DOCTOR_H
#define DOCTOR_H 
using namespace std;

class Doctor : public Person
{
private:
string license_no;
float h_pay;
Person* p_ptr;
protected:

public:

		Doctor(string fname, string mname, string lname, int sin, string l_no);
		void get_profile(vector<string> &ans);


};

#endif