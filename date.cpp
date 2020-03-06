#include "./date.h"
using namespace std;
	Date::Date(){ //Default Date; January 24th 1984, presentation of the first Macintosh Computer.
		date[0]=1984;
		date[1]=1;
		date[2]=24;
	}
	Date::Date(int h, int m, int s){ //Explicit Constructor for Date, checking the format is correct.
		date[0]= h  ;
		date[1]= ( m >= 0 && m <  12) ? m : 0;  
		date[2]= ( s >= 0 && s < 31 ) ? s : 0;  
	}

	Date::Date(const Date &t){ // Copy constructor for the date class.
		date[0] = t.date[0];
		date[1] = t.date[1];
		date[2] = t.date[2];
	}
	vector<int> Date::get_date(){ // Returns a vector containing the date as int.
		vector<int> redate;
		redate.push_back(date[0]);
		redate.push_back(date[1]);
		redate.push_back(date[2]);
		return redate;
	}

	void Date::print_date(){		//Prints date with proper YYYY/MM/DD Formating including the added '0' if the month or day is less than 10.
		cout << endl << date[0]<< "/" ;
		if(date[1]<10){cout << 0 << date[1]<<"/";}else{cout << date[1]<<"/";}
		if(date[2]<10){cout << 0 << date[2];}else{cout << date[2];}
	}