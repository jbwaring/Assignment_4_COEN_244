/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include "./inPatient.h"
using namespace std;

inPatient::inPatient(string fname, string mname, string lname, int sin, int cond, int serv, Date &d1, Date &d2, double d_charge):Person(fname, lname, mname, sin){
			cond_no = cond;
			service = serv;
			adm_date = new Date(d1);
			dis_date = new Date(d2);
			int no_year = dis_date->get_year()-adm_date->get_year();
			int no_mo = dis_date->get_month()-adm_date->get_month();
			int no_d = dis_date->get_day()-adm_date->get_day();
			double charge = ((365*no_year)+(no_mo*31)+no_d)*d_charge;
			account = new Account(charge);
			
		}
inPatient::inPatient(inPatient* ptr):Person(ptr->fname, ptr->lname, ptr->mname, ptr->get_sint()){
			cond_no = ptr->cond_no;
			service = ptr->service;
			adm_date = new Date(ptr->adm_date);
			dis_date = new Date(ptr->dis_date);
			account = new Account(ptr->account->get_balance());

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

			ans.push_back(account->get_balance_str());
			        ans.back().insert(0, "Balance:                 ");
			ans.back().append(" CDN");
			ans.push_back(bed_serial);
			        ans.back().insert(0, "Bed Serial #:            ");
		
}
vector<string> inPatient::get_save(){
vector<string> ans;
			ans.push_back(fname);
			ans.push_back(mname);
			ans.push_back(lname);
			ans.push_back(to_string(get_sint())); 
			ans.push_back(hospital_services[service]);
			ans.push_back(to_string(cond_no));
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
				
			}
			
			ans.push_back(account->get_balance_str());
			ans.back().insert(0, "Balance:          ");
			ans.back().append(" CDN");
			ans.push_back(bed_serial);
			ans.back().insert(0, "Bed Serial #:          ");
			return ans;

}
double inPatient::compute_t_charge(double d_charge){
	int no_year = dis_date->get_year()-adm_date->get_year();
	int no_mo = dis_date->get_month()-adm_date->get_month();
	int no_d = dis_date->get_day()-adm_date->get_day();
	double ans = ((365*no_year)+(no_mo*31)+no_d)*d_charge;
	return ans;
}