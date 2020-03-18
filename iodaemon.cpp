#include "./IODaemon.h"
using namespace std;

IODaemon::IODaemon(string f){

	ofstream file;
  	file.open (f);
  	file.close();
  	filename = f;
  	file.close();

}

void IODaemon::save(Hospital &H1){ //CAUTION THIS CLEARS THE FILE BEFORE WRITING!!!
	ofstream file;
	file.open(filename, ofstream::out | ofstream::trunc); // opens and clears content.
	
	file << "##INPLS##";
	for(size_t i =0; i<H1.in_pt.size();i++){
		file << "\n";
		file << "##" << i << "##";
		vector<string> buff = H1.in_pt[i].get_save();
		for(size_t j = 0; j<buff.size(); j++ ){
			file << buff[j];
			file << "#";
		}
	}
	file << "\n##OUTPLS##";

	for(size_t i =0; i<H1.out_pt.size();i++){
		file << "\n";
		file << "##" << i << "##";
		vector<string> buff = H1.out_pt[i].get_save();
		for(size_t j = 0; j<buff.size(); j++ ){
			file << buff[j];
			file << "#";
		}
	}

	file << "\n##DOCS##";

	for(size_t i =0; i<H1.doc_pt.size();i++){
		file << "\n";
		file << "##" << i << "##";
		vector<string> buff = H1.doc_pt[i].get_save();
		for(size_t j = 0; j<buff.size(); j++ ){
			file << buff[j];
			file << "#";
		}
	}


}


void IODaemon::load(Hospital &H1, string filename){
	//shall be able to load data from file to hospital object.
}


