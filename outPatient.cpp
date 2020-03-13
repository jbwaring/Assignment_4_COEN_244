#include "./outPatient.h"


outPatient::outPatient(string fname, string mname, string lname, int sin, Date &apt, Doctor &prvd, double chrg):Person(fname, lname, mname, sin){
	
apt_date = new Date(apt);
prv_dr = new Doctor(prvd);
h_charge = chrg;

}

outPatient::outPatient(outPatient* pt):Person(pt->fname, pt->lname, pt->mname, pt->get_sint()){
	
apt_date = new Date(pt->apt_date);
prv_dr = new Doctor(pt->prv_dr);
h_charge = pt->h_charge;

}

void outPatient::get_profile(vector<string> &ans){
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
			// Date Insertion:
			/*if(apt_date->long_date==false){ //Date does not specify time of day
				ans.push_back(to_string(apt_date->date[0]));
				ans.back().append("/");
					if(apt_date->date[1]<10){
						ans.back().append("0").append(to_string(apt_date->date[1]));
					}else{
						ans.back().append(to_string(apt_date->date[1]));
					}
						ans.back().append("/");
							if(apt_date->date[2]<10){
								ans.back().append("0").append(to_string(apt_date->date[2]));
							}else{
								ans.back().append(to_string(apt_date->date[2]));
							}			
					ans.back().insert(0, "Admission Date:          ");
			}else{
				ans.push_back(to_string(apt_date->date[0]));
				ans.back().append("/");
					if(apt_date->date[1]<10){
						ans.back().append("0").append(to_string(apt_date->date[1]));
					}else{
						ans.back().append(to_string(apt_date->date[1]));
					}
						ans.back().append("/");
							if(apt_date->date[2]<10){
								ans.back().append("0").append(to_string(apt_date->date[2]));
							}else{
								ans.back().append(to_string(apt_date->date[2]));
							}			
					ans.back().insert(0, "Admission Date:          ");

					ans.push_back(to_string(apt_date->t->get_time(0)));
				ans.back().append(":");
					if(apt_date->t->get_time(1)<10){
						ans.back().append(":").append(to_string(apt_date->t->get_time(1)));
					}else{
						ans.back().append(to_string(apt_date->t->get_time(1)));
					}
						ans.back().append(":");
							if(apt_date->t->get_time(2)<10){
								ans.back().append("0").append(to_string(apt_date->t->get_time(2)));
							}else{
								ans.back().append(to_string(apt_date->t->get_time(2)));
							}			
					ans.back().insert(0, "Admission Time:          ");
			}*/
}
	vector<string> outPatient::get_save(){
		vector<string> ans;
			ans.push_back(fname);
			ans.push_back(mname);
			ans.push_back(lname);
			ans.push_back(to_string(get_sint()));
			ans.push_back(hospital_services[service]);
			return ans;
	}
