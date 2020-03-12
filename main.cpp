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
string select_doctor();
Hospital H1;
int main(){
	Doctor* d1;
	Doctor* d2;
	Doctor* d3;
	Doctor* d4;
	d1 = new Doctor("Jean-Pierre", "M", "Waring", 123456789, "A54CTE890");
	d2 = new Doctor("Pierre", "M", "Magnat", 987654321, "B34CTE890");
	d3 = new Doctor("Amir", "N", "Peter", 768546243, "C54ILT564");
	d4 = new Doctor("Lawrence", "N", "Johnston", 849019586, "H67LKT086");
	H1.add_doc(d1);
	H1.add_doc(d2);
	H1.add_doc(d3);

string testere = select_doctor();
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
string select_doctor(){

if(H1.doc_pt.empty()==true){
	string recap = "Program will crash... \nCreate a Doctor before attempting to assign one to a patient.";
	init_dialog(stdin, stdout);
	dialog_msgbox("ERROR: No Doctors on file!", &recap[0], 100, 100, 1);
	end_dialog();
	return "NONE";
}
int docno = H1.doc_pt.size();
char c[2*docno][128];
for(int i = 0; i<2*docno; i++){
	for(int j = 0; j<128; j++)
		c[i][j] = '\0';
}
	string s;
	// DOCTOR NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	H1.doc_pt[k].get_name(s);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // DOCTOR LICENSE NO // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
	j++;
	H1.doc_pt[k].get_license_no(s);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    init_dialog(stdin, stdout);
	dialog_menu("Doctor List Menu", "Select your Patient's Doctor:", 100, 100, 50, docno, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();

return "OK";
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

	dialog_inputbox("New outPatient", "Enter First Name:", 0, 0,NULL , 0);
string fname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New outPatient", "Enter Last Name:", 0, 0,NULL , 0);
string lname = dialog_vars.input_result;
 	end_dialog();
 	dialog_inputbox("New outPatient", "Enter Middle Name:", 0, 0,NULL , 0);
string mname = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New outPatient", "Enter SIN:", 0, 0,NULL , 0);
string sin = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New outPatient", "Enter Condition Number (Between 1 and 10):", 0, 0,NULL , 0);
string cond = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New outPatient", "Select Provider", 0, 0,NULL , 0);
string serv = dialog_vars.input_result;
 	end_dialog();
/*
 	
 	dialog_inputbox("New outPatient", "Enter Appointment Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();

 	Date* apt;
 	apt = new Date(2020,3,2);
 	outPatient* P1;
 	P1 = new outPatient(fname, mname, lname, stoi(sin), apt, Doctor &prvd, double chrg);
 	H1.add_inPT(P1);
 	string recap;
 	vector<string> test;
 	 H1.in_pt[0].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New outPatient Successfully Added!", &recap[0], 100, 100, 1);*/
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

 	dialog_inputbox("New Doctor", "Enter License Number:", 0, 0,NULL , 0);
string l_no = dialog_vars.input_result;
 	end_dialog();
 	Doctor* D1;
 	D1 = new Doctor(fname, mname, lname, stoi(sin), l_no);
 	H1.add_doc(D1);
 	string recap;
 	vector<string> test;
 	 H1.doc_pt.back().get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New Doctor Successfully Added!", &recap[0], 100, 100, 1);
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