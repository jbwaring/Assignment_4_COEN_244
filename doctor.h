#include "./person.h"
#include "./inPatient.h"
#include "./outPatient.h"
#include "./bed.h"
#ifndef DOCTOR_H
#define DOCTOR_H 
using namespace std;

class Doctor : public Person
{
private:
string license_no;
float h_pay;
Person* p_ptr;
string specty;
vector<inPatient> in_ls;
//vector<outPatient> out_l;
protected:

public:

		Doctor(string fname, string mname, string lname, int sin, string l_no);
		void get_profile(vector<string> &ans);
		Doctor(Doctor* d);

};

#endif