/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#ifndef PERSON_H
#define PERSON_H 
using namespace std;
const string hospital_services[6] = {"ER", "Surgery", "Short-Term", "Radiology", "Lab", "Blood"};
 class Person{
private:
int sin;
protected:
	string fname, lname, mname;
	int service;

public:
	Person(string f, string l, string m, int sin);
	virtual void get_profile(){};
	string get_sin();
	int get_sint();
	string get_fname(){
		return fname;
	}
	string get_lname(){
		return lname;
	}
 };

#endif