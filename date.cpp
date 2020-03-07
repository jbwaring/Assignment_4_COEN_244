#include "./date.h"
using namespace std;
	Date::Date(){ //Default Date; January 24th 1984, presentation of the first Macintosh Computer.
		date = new int[3];
		date[0]=1984;
		date[1]=1;
		date[2]=24;
		long_date = false;
	}
	Date::Date(int y, int mo, int d, int h, int mm, int s){ //Explicit Constructor for Date, checking the format is correct.
		date = new int[3];
		date[0]= y  ;
		date[1]= ( mo >= 0 && mo<  13) ? mo : 0;  
		date[2]= ( d >= 0 && d < 32 ) ? d : 0;  
		t = new Time(h,mm,s);
		long_date = true;
	}
	Date::Date(int y, int mo, int d){
		date = new int[3];
		date[0]= y  ;
		date[1]= ( mo >= 0 && mo<  13) ? mo : 0;  
		date[2]= ( d >= 0 && d < 32 ) ? d : 0;  
		long_date = false;

	}

	Date::Date(const Date &d){ 
	date = new int[3];			// Copy constructor for the date class.
		if(d.long_date==true){
		date[0] = d.date[0];
		date[1] = d.date[1];
		date[2] = d.date[2];
		t = new Time(d.t->get_time(0),d.t->get_time(1),d.t->get_time(2));
		long_date=true;} 
		else{
		date[0] = d.date[0];
		date[1] = d.date[1];
		date[2] = d.date[2];
		long_date=false;
		}
	}

	Date::~Date(){
		delete date;
		delete t;
	}

	vector<int> Date::get_date(){ // Returns a vector containing the date as int.
		vector<int> redate;
		if(long_date==false){
		redate.push_back(date[0]);
		redate.push_back(date[1]);
		redate.push_back(date[2]);
		return redate;
		}else{
			redate.push_back(date[0]);
			redate.push_back(date[1]);
			redate.push_back(date[2]);
			redate.push_back(t->get_time(0));
			redate.push_back(t->get_time(1));
			redate.push_back(t->get_time(2));

		}
		return redate;
	}

	void Date::print_date(){		//Prints date with proper YYYY/MM/DD Formating including the added '0' if the month or day is less than 10.
		cout << endl << date[0]<< "/" ;
		if(date[1]<10){cout << 0 << date[1]<<"/";}else{cout << date[1]<<"/";}
		if(date[2]<10){cout << 0 << date[2];}else{cout << date[2];}
	}

