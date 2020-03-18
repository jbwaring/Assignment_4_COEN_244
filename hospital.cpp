#include "./hospital.h"

Hospital::Hospital(){
	
	for(size_t i=0; i<500; i++){
		Bed* ptr;
		ptr = new Bed(Bed::bed_serial_generator(), true);
		bed_ls.push_back(new Bed(ptr));
		delete ptr;
	}

}

void Hospital::add_doc(Doctor* inptr){
	doc_pt.push_back(new Doctor(inptr));
	return;

}
void Hospital::add_inPT(inPatient* inptr){
	string bed_serial;
	for(size_t i=0; i<bed_ls.size(); i++){
		if(bed_ls[i].is_available() == true){
			bed_serial = bed_ls[i].get_serial();
		}
	}
	in_pt.push_back( new inPatient(inptr));
	in_pt.back().set_bed_serial(bed_serial);
	return;

}

void Hospital::add_outPT(outPatient* inptr){


	out_pt.push_back( new outPatient(inptr));

	return;

}

void Hospital::get_bed_serials(vector<string> &s){
	s.clear();
	for(size_t i=0; i<bed_ls.size(); i++)
		s.push_back(bed_ls[i].get_serial());
}
