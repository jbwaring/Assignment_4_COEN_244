/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include "./person.h"
using namespace std;

	Person::Person(string f, string l, string m, int s){
		fname = f;
		lname = l;
		mname = m; 
		sin = s;
	}
	int Person::get_sint(){
		return sin;
	}

	/*int Person::get_sin(){
		return sin;
	}*/
	string Person::get_sin(){
		if(sin>999999999 || sin<100000000){
			return "SIN FORMAT INVALID!";
		}
		string out = to_string(sin);
		out.insert(3, "-");
		out.insert(7, "-");
		return out;

	}
