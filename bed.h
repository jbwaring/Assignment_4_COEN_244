#include "./person.h"
#include "./date.h"
#ifndef BED_H
#define BED_H 
using namespace std;

class Bed
{

private:
string serial;
bool available;
public:
	Bed();
	Bed(string ser, bool av);
	Bed(Bed* b);
	bool is_available(){
		return available;
	}
	static string bed_serial_generator(){

	string ans;

	int v1 = rand() % 25 + 65; 
	char a = v1;
	ans.push_back(a);
	v1 = rand() % 25 + 65; 
	a = v1;
	ans.push_back(a);
	v1 = rand() % 9 + 0; 
	ans.append(to_string(v1));
	v1 = rand() % 9 + 0; 
	ans.append(to_string(v1));
	v1 = rand() % 9 + 0; 
	ans.append(to_string(v1));
	v1 = rand() % 25 + 65; 
	a = v1;
	ans.push_back(a);
	v1 = rand() % 25 + 65; 
	a = v1;
	ans.push_back(a);
	v1 = rand() % 25 + 65; 
	a = v1;
	ans.push_back(a);
	v1 = rand() % 9 + 0; 
	ans.append(to_string(v1));
	v1 = rand() % 9 + 0; 
	ans.append(to_string(v1));
	return ans;
}

string get_serial();



};

#endif