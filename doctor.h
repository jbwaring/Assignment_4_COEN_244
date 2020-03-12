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
protected:

public:

		Doctor(string fname, string mname, string lname, int sin, string l_no);
		void get_profile(vector<string> &ans);
		Doctor(Doctor* d);
		void get_license_no(string &s){
			s.clear();
			s = license_no;
				}
		void get_name(string &s){
			s = fname;
			s.append(" ");
			s.append(lname);
			cout << s;
		}
};

#endif