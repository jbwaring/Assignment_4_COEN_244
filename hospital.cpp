#include "./hospital.h"

Hospital::Hospital(){
	
	/*for(size_t i=0; i<500; i++){
		Bed* ptr;
		string serial;
		ptr = new Bed(Bed::bed_serial_generator(), true);
		bed_ls.push_back(new Bed(ptr));
		delete ptr;
	}*/

}

void Hospital::add_doc(Doctor* inptr){
	doc_pt.push_back(new Doctor(inptr));
	return;

}
void Hospital::add_inPT(inPatient* inptr){
	string bed_serial;
	int bed_rank = 0;
	while(bed_ls[bed_rank].is_available() == false)
		bed_rank++;

			bed_serial = bed_ls[bed_rank].get_serial();
			bed_ls[bed_rank].use();
		
	
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
	for(size_t i=0; i<500; i++)
		s.push_back(bed_ls[i].get_serial());
}
