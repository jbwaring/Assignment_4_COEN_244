/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include "./outPatient.h"


outPatient::outPatient(string fname, string mname, string lname, int sin, Date &d, Doctor &prvd, double chrg):Person(fname, lname, mname, sin){
	
apt_date = new Date(d);;
prv_dr = new Doctor(prvd);
account = new Account(chrg);

}

outPatient::outPatient(outPatient* pt):Person(pt->fname, pt->lname, pt->mname, pt->get_sint()){
	
apt_date = new Date(pt->apt_date);
prv_dr = new Doctor(pt->prv_dr);
account = new Account(pt->account->get_balance());

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
			//APT DATE:
			ans.push_back(to_string(apt_date->get_year()));
				ans.back().append("/");
					if(apt_date->get_month()<10){
						ans.back().append("0").append(to_string(apt_date->get_month()));
					}else{
						ans.back().append(to_string(apt_date->get_month()));
					}
						ans.back().append("/");
							if(apt_date->get_day()<10){
								ans.back().append("0").append(to_string(apt_date->get_day()));
							}else{
								ans.back().append(to_string(apt_date->get_day()));
							}			
					ans.back().insert(0, "Apointment Date:          ");


			ans.push_back("Doctor:");
			ans.push_back(prv_dr->get_fname());
			ans.back().append(" ");
			ans.back().append(prv_dr->get_lname());
			ans.push_back("License No: ");
			ans.back().append(prv_dr->get_license_no());

			
				
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
