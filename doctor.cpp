#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./doctor.h"
using namespace std;

		Doctor::Doctor(string fname, string mname, string lname, int sin, string l_no):Person(fname, lname, mname, sin){
			license_no = l_no;
			h_pay = 12.5;
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