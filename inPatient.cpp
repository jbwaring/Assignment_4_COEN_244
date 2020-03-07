#include "./inPatient.h"
using namespace std;

inPatient::inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d):Person(fname, lname, mname, sin){
			cond_no = cond;
			int service = serv;
			adm_date = new Date(d);
		}

void inPatient::get_profile(vector<string> &ans){
			ans.clear();
			ans.push_back(fname);
			ans.back().insert(0, "First Name:              ");
			ans.push_back(mname);
			ans.back().insert(0, "Middle Name:             ");
			ans.push_back(lname);
			ans.back().insert(0, "Last Name:               ");
			ans.push_back(get_sin());
			ans.back().insert(0, "Social Insurance Number: ");
			ans.push_back(hospital_services[service]);
			ans.back().insert(0, "Hospital Service:        ");
			ans.push_back(to_string(cond_no));
			ans.back().insert(0, "Severity Number:         ").append("/10 \n");
			// Date Insertion:
			if(adm_date->long_date==false){ //Date does not specify time of day
				ans.push_back(to_string(adm_date->date[0]));
				ans.back().append("/");
					if(adm_date->date[1]<10){
						ans.back().append("0").append(to_string(adm_date->date[1]));
					}else{
						ans.back().append(to_string(adm_date->date[1]));
					}
						ans.back().append("/");
							if(adm_date->date[2]<10){
								ans.back().append("0").append(to_string(adm_date->date[2]));
							}else{
								ans.back().append(to_string(adm_date->date[2]));
							}			
					ans.back().insert(0, "Admission Date:          ");
			}else{
				ans.push_back(to_string(adm_date->date[0]));
				ans.back().append("/");
					if(adm_date->date[1]<10){
						ans.back().append("0").append(to_string(adm_date->date[1]));
					}else{
						ans.back().append(to_string(adm_date->date[1]));
					}
						ans.back().append("/");
							if(adm_date->date[2]<10){
								ans.back().append("0").append(to_string(adm_date->date[2]));
							}else{
								ans.back().append(to_string(adm_date->date[2]));
							}			
					ans.back().insert(0, "Admission Date:          ");

					ans.push_back(to_string(adm_date->t->get_time(0)));
				ans.back().append(":");
					if(adm_date->t->get_time(1)<10){
						ans.back().append(":").append(to_string(adm_date->t->get_time(1)));
					}else{
						ans.back().append(to_string(adm_date->t->get_time(1)));
					}
						ans.back().append(":");
							if(adm_date->t->get_time(2)<10){
								ans.back().append("0").append(to_string(adm_date->t->get_time(2)));
							}else{
								ans.back().append(to_string(adm_date->t->get_time(2)));
							}			
					ans.back().insert(0, "Admission Time:          ");
			}
}