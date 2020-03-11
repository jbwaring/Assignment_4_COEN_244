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
vector<inPatient> in_pt;
vector<outPatient> out_pt;
vector<Bed> bed_ls;

public:

	Hospital();
	void add_inPT(inPatient* inptr);
	void add_outPT(outPatient* inptr);
	void get_bed_serials(vector<string> &s);
};
#endif