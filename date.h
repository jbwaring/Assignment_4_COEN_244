#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef DATE_H
#define DATE_H 

class Date{
private:
	int* date;
public:

	Date();
	Date(int hour, int min, int sec);
	Date(const Date &t);
	static void get_date(const Date &t, unsigned int* ptr);
	static void print_date(unsigned int* date);
};


#endif