/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
#include "./time.h"
	Time::Time(){
		time_array[0]=0;
		time_array[1]=0;
		time_array[2]=0;
	}
	Time::Time(int h, int m, int s){
		time_array[0]= ( h >= 0 && h < 24 ) ? h : 0;  
		time_array[1]= ( m >= 0 && m < 60 ) ? m : 0;  
		time_array[2]= ( s >= 0 && s < 60 ) ? s : 0;  
	}

	Time::Time(const Time &t){
		time_array[0] = t.time_array[0];
		time_array[1] = t.time_array[1];
		time_array[2] = t.time_array[2];
	}
	int Time::get_time(int i){
		return time_array[i];
	}