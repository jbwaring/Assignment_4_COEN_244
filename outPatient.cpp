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