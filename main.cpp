#include <dialog.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./doctor.h"
#include "./inPatient.h"
#include "./outPatient.h"
#include "./hospital.h"
#include "./date.h"
#include "./jb_base.h"

using namespace std;
int main_menu();

Hospital H1;
int main(){


int status;

    init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    status = dialog_yesno("Hospital Management System COEN 244","Do you wish to continue?", 0, 0);
    end_dialog();
  	system("clear");
if(status==1)
 	return 0;
 vector<string> test;
if(main_menu()==1){
	system("clear");
	cout << "quiting..."<< endl;
	return 0;
}
 H1.in_pt[0].get_profile(test);
 for(size_t i =0;i<test.size(); i++)
 	cout << endl << test[i];
//--------Go to main menu--------//

return 0;

}

void add_inPatient(){
	init_dialog(stdin, stdout);
	dialog_vars.nocancel = 1;

	dialog_inputbox("New inPatient", "Enter First Name:", 0, 0,NULL , 0);
string fname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Last Name:", 0, 0,NULL , 0);
string lname = dialog_vars.input_result;
 	end_dialog();
 	dialog_inputbox("New inPatient", "Enter Middle Name:", 0, 0,NULL , 0);
string mname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter SIN:", 0, 0,NULL , 0);
string sin = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Condition Number (Between 1 and 10):", 0, 0,NULL , 0);
string cond = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Service\0 1-ER\0 2-Pediatry", 0, 0,NULL , 0);
string serv = dialog_vars.input_result;
 	end_dialog();

 	
 	dialog_inputbox("New inPatient", "Enter Admission Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();

 	Date* d1;
 	d1 = new Date(2020,3,2);
 	inPatient* P1;
 	P1=new inPatient(fname, mname, lname, stoi(sin), stoi(cond), stoi(serv), *d1);
 	H1.add_inPT(P1);
 	string recap;
 	vector<string> test;
 	 H1.in_pt[0].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New inPatient Successfully Added!", &recap[0], 100, 100, 1);
	end_dialog();
	main_menu();
}
void add_outPatient(){
	init_dialog(stdin, stdout);
	dialog_vars.nocancel = 1;

	dialog_inputbox("New inPatient", "Enter First Name:", 0, 0,NULL , 0);
string fname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Last Name:", 0, 0,NULL , 0);
string lname = dialog_vars.input_result;
 	end_dialog();
 	dialog_inputbox("New inPatient", "Enter Middle Name:", 0, 0,NULL , 0);
string mname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter SIN:", 0, 0,NULL , 0);
string sin = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Condition Number (Between 1 and 10):", 0, 0,NULL , 0);
string cond = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Service\0 1-ER\0 2-Pediatry", 0, 0,NULL , 0);
string serv = dialog_vars.input_result;
 	end_dialog();

 	
 	dialog_inputbox("New inPatient", "Enter Admission Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();

 	Date* d1;
 	d1 = new Date(2020,3,2);
 	inPatient* P1;
 	P1=new inPatient(fname, mname, lname, stoi(sin), stoi(cond), stoi(serv), *d1);
 	H1.add_inPT(P1);
 	string recap;
 	vector<string> test;
 	 H1.in_pt[0].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New inPatient Successfully Added!", &recap[0], 100, 100, 1);
	end_dialog();
	main_menu();
}
void add_Doctor(){
	init_dialog(stdin, stdout);
	dialog_vars.nocancel = 1;

	dialog_inputbox("New Doctor", "Enter First Name:", 0, 0,NULL , 0);
string fname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New Doctor", "Enter Last Name:", 0, 0,NULL , 0);
string lname = dialog_vars.input_result;
 	end_dialog();
 	dialog_inputbox("New Doctor", "Enter Middle Name:", 0, 0,NULL , 0);
string mname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New Doctor", "Enter SIN:", 0, 0,NULL , 0);
string sin = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New Doctor", "Enter Condition Number (Between 1 and 10):", 0, 0,NULL , 0);
string cond = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New Doctor", "Enter Service\0 1-ER\0 2-Pediatry", 0, 0,NULL , 0);
string serv = dialog_vars.input_result;
 	end_dialog();

 	
 	dialog_inputbox("New Doctor", "Enter Admission Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();

 	Date* d1;
 	d1 = new Date(2020,3,2);
 	inPatient* P1;
 	P1=new inPatient(fname, mname, lname, stoi(sin), stoi(cond), stoi(serv), *d1);
 	H1.add_inPT(P1);
 	string recap;
 	vector<string> test;
 	 H1.in_pt[0].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New inPatient Successfully Added!", &recap[0], 100, 100, 1);
	end_dialog();
	main_menu();
}
int main_menu(){
	init_dialog(stdin, stdout);
	// one contiguous block of 4 chars
    char c[6][40]={
        "1",
        "Add a new inPatient",
        "2",
        "Add a new outPatient",
        "3",
        "Add a Doctor"
      };
 	
    // use a smart pointer
    char* param[6];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    param[4] = &c[4][0];
    param[5] = &c[5][0];
    char** ptr = &param[0];
	dialog_menu("Main Menu - Hospital Management System", "Select an option: (you can use the mouse!)", 100, 100, 50, 3, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
		case 1:
		add_inPatient();
		case 2:
		add_outPatient();
		case 3:
		add_Doctor();
		default:
		break;

	}
	
	return 0;
}