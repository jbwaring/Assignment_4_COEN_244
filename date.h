#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef DATE_H
#define DATE_H 
using namespace std;
class Date{
private:
	int date[];
public:

	Date();
	Date(int hour, int min, int sec);
	Date(const Date &t);
	vector<int> get_date();
	void print_date();
};


#endif