/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#pragma once
#include "./doctor.h"
#include "./inPatient.h"
#include "./outPatient.h"
#include "./bed.h"

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Hospital
{
	friend class Bed; //(to get serial # generator.)
private:


public:
vector<inPatient> in_pt;
vector<outPatient> out_pt;
vector<Doctor> doc_pt;
Bed bed_ls[500];
	Hospital();
	void add_doc(Doctor* inptr);
	void add_inPT(inPatient* inptr);
	void add_outPT(outPatient* inptr);
	void get_bed_serials(vector<string> &s);
};
#endif