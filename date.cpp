#include "./date.h"
using namespace std;
	Date::Date(){
		date[0]=0;
		date[1]=0;
		date[2]=0;
	}
	Date::Date(int h, int m, int s){
		date[0]= h  ;
		date[1]= ( m >= 0 && m <  12) ? m : 0;  
		date[2]= ( s >= 0 && s < 31 ) ? s : 0;  
	}

	Date::Date(const Date &t){
		date = t.date;
	}
	void Date::get_date(const Date &t, unsigned int* ptr){
		ptr[0] = t.date[0];
		ptr[1] = t.date[1];
		ptr[2] = t.date[2];
	}

	void Date::print_date(unsigned int* date){

		cout << date[0]<< "/" << date[1]<< "/" << date[2];
	}