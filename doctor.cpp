#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./doctor.h"
using namespace std;

		Doctor::Doctor(string fname, string mname, string lname, int sin, string l_no):Person(fname, lname, mname, sin){
			license_no = l_no;
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
			ans.back().insert(0, "Medical License Number:  ").append("\n");
		}

		Doctor::Doctor(Doctor* d):Person(d->fname, d->lname, d->mname, d->get_sint()){
				license_no = d->license_no;
			h_pay = d->h_pay;

		}