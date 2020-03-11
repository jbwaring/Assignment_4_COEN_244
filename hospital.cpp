#include "./hospital.h"

Hospital::Hospital(){
	

}


void Hospital::add_inPT(inPatient* inptr){


	in_pt.push_back( new inPatient(inptr));

	return;

}

void Hospital::add_outPT(outPatient* inptr){


	out_pt.push_back( new outPatient(inptr));

	return;

}
