#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef TIME_H
#define TIME_H 

class Time{
private:
	int* time;
public:

	Time();
	Time(int hour, int min, int sec);
	Time(const Time &t);
	static void get_time(const Time &t, unsigned int* ptr);
	static void print_time(unsigned int* time);
};


#endif