#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef PERSON_H
#define PERSON_H 
using namespace std;

 class Person{
private:
int sin;
protected:
	string fname, lname, mname;
	
public:
	Person(string f, string l, string m, int sin);
	virtual void get_profile(){};
	string get_sin();

 };

#endif