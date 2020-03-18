#include "./bed.h"



Bed::Bed(string ser, bool av){
	
serial = ser;
available = av;
	
}

Bed::Bed(Bed* b){

	serial = b->serial;
	available = b->available;
}

string Bed::get_serial(){

	return serial;
}

Bed::Bed(){
	available = true;
	serial = bed_serial_generator();
}