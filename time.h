#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef TIME_H
#define TIME_H 
using namespace std;
class Time{
private:
	int time[];
public:

	Time();
	Time(int hour, int min, int sec);
	Time(const Time &t);
	vector<int> get_time();
	void print_time();
};


#endif