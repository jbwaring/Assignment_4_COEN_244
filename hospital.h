#pragma once
#include "./doctor.h"
#include "./inPatient.h"
#include "./outPatient.h"
#include "./bed.h"

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Hospital
{
private:
vector<inPatient> in_pt;
vector<outPatient> out_pt;
vector<Bed> bed_ls;

public:

	Hospital();
	void add_inPT(inPatient* inptr);
	void add_outPT(outPatient* inptr);

};
#endif