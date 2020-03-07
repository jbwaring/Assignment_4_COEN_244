#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef TIME_H
#define TIME_H 
using namespace std;
class Time{
private:
	int time_array[];
public:

	Time();
	Time(int hour, int min, int sec);
	Time(const Time &t);
	int get_time(int i);
};


#endif