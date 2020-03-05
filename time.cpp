#include "./time.h"
using namespace std;
	Time::Time(){
		time[0]=0;
		time[1]=0;
		time[2]=0;
	}
	Time::Time(int h, int m, int s){
		time[0]= ( h >= 0 && h < 24 ) ? h : 0;  
		time[1]= ( m >= 0 && m < 60 ) ? m : 0;  
		time[2]= ( s >= 0 && s < 60 ) ? s : 0;  
	}

	Time::Time(const Time &t){
		time = t.time;
	}
	void Time::get_time(const Time &t, unsigned int* ptr){
		ptr[0] = t.time[0];
		ptr[1] = t.time[1];
		ptr[2] = t.time[2];
	}

	void Time::print_time(unsigned int* time){

		cout << time[0]<< ":" << time[1]<< ":" << time[2];
	}