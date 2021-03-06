/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
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

		Doctor(string fname, string mname, string lname, int sin, string l_no, string spec);
		void get_profile(vector<string> &ans);
		Doctor(Doctor* d);
		void get_license_no(string &s){
			s.clear();
			s = license_no;
				}
		string get_license_no(){
			return license_no;
		}
		void get_name(string &s){
			s = fname;
			s.append(" ");
			s.append(lname);
			
		}
		void get_spec(string &s){
			s = specty;
		}
		vector<string> get_save();
};

#endif