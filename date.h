#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./time.h"
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
	Date(const Date &t);
	vector<int> get_date();
	void print_date();
	~Date();
};


#endif