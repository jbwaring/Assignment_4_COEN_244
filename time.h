#ifndef TIME_H
#define TIME_H 
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