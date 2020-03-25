/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#pragma once
#include "./time.h"
#include <vector>
#ifndef DATE_H
#define DATE_H 
using namespace std;
class Date {
	friend class inPatient;
private:
	int* date;
	Time* t;
	bool long_date;
public:

	Date();
	Date(int y, int mo, int d);
	Date(int y, int mo, int d, int h, int mm, int s);
	Date(const Date &d);
	Date(const Date* d);
	Date(string dt);
	vector<int> get_date();
	void print_date();
	int get_day();
	int get_month();
	int get_year();
	~Date();
};


#endif