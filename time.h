/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
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