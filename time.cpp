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
		time[0] = t.time[0];
		time[1] = t.time[1];
		time[2] = t.time[2];
	}
	
	vector<int> Time::get_time(){
		vector<int> retime;
		retime.push_back(time[0]);
		retime.push_back(time[1]);
		retime.push_back(time[2]);
		return retime;
	}

	void Time::print_time(){
		cout << endl;
		if(time[0]<10){cout << 0 << time[0]<<":";}else{cout << time[0]<<":";}
		if(time[1]<10){cout << 0 << time[1]<<":";}else{cout << time[1]<<":";}
		if(time[2]<10){cout << 0 << time[2];}else{cout << time[2];}
	}