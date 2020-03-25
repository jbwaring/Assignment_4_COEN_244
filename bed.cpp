/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
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
	serial = BED_SER[counter];
	counter ++;
}


