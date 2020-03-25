/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./doctor.h"
using namespace std;

		Doctor::Doctor(string fname, string mname, string lname, int sin, string l_no, string spec):Person(fname, lname, mname, sin){
			license_no = l_no;
			specty = spec;
			h_pay = 12.5; //FUCK YOU DOCTORS YOU GET PAID JUST LIKE EVERYONE ELSE!
		}
		void Doctor::get_profile(vector<string> &ans){
			ans.clear();
			ans.push_back(fname);
			ans.back().insert(0, "First Name:              ");
			ans.push_back(mname);
			ans.back().insert(0, "Middle Name:             ");
			ans.push_back(lname);
			ans.back().insert(0, "Last Name:               ");
			ans.push_back(get_sin());
			ans.back().insert(0, "Social Insurance Number: ");
			ans.push_back(license_no);
			ans.back().insert(0, "Medical License Number:  ");
			ans.push_back(specty);
			ans.back().insert(0, "Specialty:               ");

		}

		Doctor::Doctor(Doctor* d):Person(d->fname, d->lname, d->mname, d->get_sint()){
				license_no = d->license_no;
			h_pay = d->h_pay;
			specty = d->specty;

		}

		vector<string> Doctor::get_save(){
			vector<string> ans;

			ans.push_back(fname);
			ans.push_back(mname);
			ans.push_back(lname);
			ans.push_back(to_string(get_sint()));
			ans.push_back(license_no);
			return ans;

		}