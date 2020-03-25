/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include <fstream>
#include <iterator>
#include "./hospital.h"
class IODaemon
{	
	friend class Hospital;

public:
	string filename;
	IODaemon(string f);
	void save(Hospital &H1);
	void load(Hospital &H1, string filename);
	/*void save_doc_io(){
	std::ofstream output_file("./data/doc_data.txt");

	for(size_t i = 0; i<H1.doc_pt.size(); i++){
	vector<string> buff;
	buff.append(H1.doc_pt[i].fname);
	buff.append(H1.doc_pt[i].mname);
	buff.append(H1.doc_pt[i].lname);
	buff.append(H1.doc_pt[i].get_sin());
	buff.append(H1.doc_pt[i].get_license_no());
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(buff.begin(), buff.end(), output_iterator);
    }
}*/



};

