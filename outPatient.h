#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./person.h"
#include "./date.h"
#include "./time.h"
#include "./doctor.h"
#include "./bed.h"
#ifndef OUTPATIENT_H
#define OUTPATIENT_H 
using namespace std;


class outPatient
{

private:
Date* apt_date;
Doctor* prv_dr;
double h_charge;

public:

	outPatient();



};


#endif