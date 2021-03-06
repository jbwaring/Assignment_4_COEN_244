/* ASSIGNMENT 4 - COEN 244
Jean-Baptiste WARING 40054925 
FAROUQ HAMEDALLAH	 40087448
HOSPITAL MANAGEMENT SYSTEM
*/
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
#include "./account.h"
#include "./jb_base.h"
#include "./IODaemon.h"
using namespace std;
int main_menu();
string select_doctor();
void patient_profile(bool ext, string name );
void patient_account(bool ext, string name);
void outP_ls(bool getprofile);
void account_menu(bool ext, int rank);
void del_inPT();
void del_outPT();
void delete_menu();
Hospital H1;
IODaemon io_daemon("data.txt");
int Bed::counter=0;
int main(){
	

	Doctor* d1;
	Doctor* d2;
	Doctor* d3;
	Doctor* d4;
	d1 = new Doctor("Jean-Pierre", "M", "Waring", 123456789, "A54CTE890", "Pediatrician");
	d2 = new Doctor("Pierre", "M", "Magnat", 987654321, "B34CTE890", "Surgeon");
	d3 = new Doctor("Amir", "N", "Peter", 768546243, "C54ILT564", "Ophtalmologist");
	d4 = new Doctor("Lawrence", "N", "Johnston", 849019586, "H67LKT086", "Dentist");
	H1.add_doc(d1);
	H1.add_doc(d2);
	H1.add_doc(d3);
	io_daemon.save(H1);
	int status;
    init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    status = dialog_yesno("Hospital Management System COEN 244","Do you wish to continue?", 0, 0);
    end_dialog();
  	system("clear");
if(status==1)
 	return 0;
while(main_menu()==0){
	dialog_vars.input_result = NULL;
if(main_menu()==1){
	system("clear");
	cout << "quiting..."<< endl;
	return 0;
}}

return 0;

}

string select_doctor(){
	dialog_vars.input_result = NULL;
if(H1.doc_pt.empty()==true){
	string recap = "Program will crash... \nCreate a Doctor before attempting to assign one to a patient.";
	init_dialog(stdin, stdout);
	dialog_msgbox("ERROR: No Doctors on file!", &recap[0], 100, 100, 1);
	dialog_vars.input_result = NULL;
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
	string sp;
	// DOCTOR NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	s.clear();
	H1.doc_pt[k].get_license_no(s);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // DOCTOR LICENSE NO // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
		s.clear();
	j++;
	H1.doc_pt[k].get_name(s);
	H1.doc_pt[k].get_spec(sp);
	s.append(" - ");
	s.append(sp);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    
   }
    


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("Doctor List Menu", "Select your Patient's Doctor:", 100, 100, 50, docno, ptr);
	end_dialog();
	return dialog_vars.input_result;
}

void inP_ls(bool getprofile){
	int docno = H1.in_pt.size();
char c[2*docno][128];
for(int i = 0; i<2*docno; i++){
	for(int j = 0; j<128; j++)
		c[i][j] = '\0';
}
	string s;
	// PATIENTS NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	s.clear();
	s = H1.in_pt[k].get_fname();
	s.append(" ");
	s.append(H1.in_pt[k].get_lname());
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // Get SIN No. // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
		s.clear();
	j++;
	s = H1.in_pt[k].get_sin();
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    if(getprofile ==true){
    init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("inPatient List Menu", "Select an entry to see full profile.", 100, 100, 50, docno, ptr);
	end_dialog();
	patient_profile(false, dialog_vars.input_result);
	}else if(getprofile==false){
		init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("inPatient List Menu", "Select an entry to see Account.", 100, 100, 50, docno, ptr);
	end_dialog();
	patient_account(false, dialog_vars.input_result);
	}

}

void outP_ls(bool getprofile){
	int docno = H1.out_pt.size();
char c[2*docno][128];
for(int i = 0; i<2*docno; i++){
	for(int j = 0; j<128; j++)
		c[i][j] = '\0';
}
	string s;
	// PATIENTS NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	s.clear();
	s = H1.out_pt[k].get_fname();
	s.append(" ");
	s.append(H1.out_pt[k].get_lname());
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // Get SIN No. // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
		s.clear();
	j++;
	s = H1.out_pt[k].get_sin();
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    if(getprofile==true){
    init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("outPatient List Menu", "Select an entry to see full profile.", 100, 100, 50, docno, ptr);
	end_dialog();
	patient_profile(true, dialog_vars.input_result);
	}else if(getprofile==false){
		init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("outPatient List Menu", "Select an entry to see Account.", 100, 100, 50, docno, ptr);
	end_dialog();
	patient_account(true, dialog_vars.input_result);
	}

}
void doctor_list(){

	string doc_license_no = select_doctor();
 	int i = 0;
 	while(doc_license_no.compare(H1.doc_pt[i].get_license_no())!=0){
 		i++;
 	}

 	string recap;
 	vector<string> test;
 	 H1.doc_pt[i].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("DOCTOR FILE", &recap[0], 100, 100, 1);
	dialog_vars.input_result = NULL;
	end_dialog();


}
void patient_profile(bool ext, string name ){

if(ext == false){ //inPatient Profile Printing
	int i = 0;
	string s;
	while(i<H1.in_pt.size()){
		s.clear();
		s = H1.in_pt[i].get_fname();
		s.append(" ");
		s.append(H1.in_pt[i].get_lname());
		if(s==name)
			break;

		i++;
	}

string recap;
 	vector<string> test;
 	 H1.in_pt[i].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);
 	}
 	recap.append(to_string(i));
	init_dialog(stdin, stdout);
	dialog_msgbox("Patient File:", &recap[0], 100, 100, 1);
	end_dialog();

	dialog_vars.input_result = NULL;
	main_menu();


}
if(ext == true){ //outPatient Profile Printing
	int i = 0;
	string s;
	while(i<H1.out_pt.size()){
		s.clear();
		s = H1.out_pt[i].get_fname();
		s.append(" ");
		s.append(H1.out_pt[i].get_lname());
		if(s==name)
			break;

		i++;
	}

string recap;
 	vector<string> test;
 	 H1.out_pt[i].get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);
 	}
 	recap.append(to_string(i));
	init_dialog(stdin, stdout);
	dialog_msgbox("Patient File:", &recap[0], 100, 100, 1);
	end_dialog();

	dialog_vars.input_result = NULL;
	main_menu();


}

}

void patient_account(bool ext, string name){

if(ext == false){ //inPatient Profile Printing
	int i = 0;
	string s;
	while(i<H1.in_pt.size()){
		s.clear();
		s = H1.in_pt[i].get_fname();
		s.append(" ");
		s.append(H1.in_pt[i].get_lname());
		if(s==name)
			break;

		i++;
	}
	account_menu(false, i);
}
if(ext == true){ //outPatient Profile Printing
	int i = 0;
	string s;
	while(i<H1.out_pt.size()){
		s.clear();
		s = H1.out_pt[i].get_fname();
		s.append(" ");
		s.append(H1.out_pt[i].get_lname());
		if(s==name)
			break;

		i++;
	}

	account_menu(true, i);
	}
}

void account_menu(bool ext, int rank){
if(ext==false){ // IN-PATIENT ACCOUNT MENU

	char c[4][40]={
        "1",
        "Make Payment",
        "2",
        "Add Charge",
      };
 	string title = "Patient Account: ";
 	title.append(H1.in_pt[rank].get_sin());
    string current_charge = "Current Balance: ";
    current_charge.append(H1.in_pt[rank].account->get_balance_str());
    current_charge.append(" CDN.");
    char* param[4];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu(&title[0], &current_charge[0], 100, 100, 50, 2, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
		case 1: {// Make a payment
		dialog_vars.input_result = NULL;
		dialog_inputbox("Make A Payment", "Enter Sum: (CDN)", 0, 0,NULL , 0);
		string sum = dialog_vars.input_result;
 		end_dialog();
 		double sum_paid = stod(sum);
 		H1.in_pt[rank].account->pay_amount(sum_paid);
 		string n_bal = "New Balance: ";
 		n_bal.append(H1.in_pt[rank].account->get_balance_str());
 		n_bal.append(" CDN.\nReturning to Main Menu.");
		dialog_msgbox("Payment Accepted", &n_bal[0], 100, 100, 1);
		end_dialog();
		main_menu();
		break;}
		case 2: {// Add Charge --> note that a negative charge is a payment and a negative payment is a charge but I am implementing to show menus etc although same level of functionnality can be achieved using only one function.
		string sum;
		string n_bal;
		dialog_vars.input_result = NULL;
		dialog_inputbox("Add a Charge", "Enter Sum: (CDN)", 0, 0,NULL , 0);
		sum = dialog_vars.input_result;
 		end_dialog();
 		double sum_paid = stod(sum);
 		H1.in_pt[rank].account->add_charge(sum_paid);
 		n_bal = "New Balance: ";
 		n_bal.append(H1.in_pt[rank].account->get_balance_str());
 		n_bal.append(" CDN.\nReturning to Main Menu.");
		dialog_msgbox("Charge Added Successfully.", &n_bal[0], 100, 100, 1);
		end_dialog();
		main_menu();
		break;}
		default:
			break;
	}



}
if(ext==true){ // OUT-PATIENT ACCOUNT MENU

	char c[4][40]={
        "1",
        "Make Payment",
        "2",
        "Add Charge",
      };
 	string title = "Patient Account: ";
 	title.append(H1.out_pt[rank].get_sin());
    string current_charge = "Current Balance: ";
    current_charge.append(H1.out_pt[rank].account->get_balance_str());
    current_charge.append(" CDN.");
    char* param[4];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu(&title[0], &current_charge[0], 100, 100, 50, 2, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
		case 1: {// Make a payment
		dialog_vars.input_result = NULL;
		dialog_inputbox("Make A Payment", "Enter Sum: (CDN)", 0, 0,NULL , 0);
		string sum = dialog_vars.input_result;
 		end_dialog();
 		double sum_paid = stod(sum);
 		H1.out_pt[rank].account->pay_amount(sum_paid);
 		string n_bal = "New Balance: ";
 		n_bal.append(H1.out_pt[rank].account->get_balance_str());
 		n_bal.append(" CDN.\nReturning to Main Menu.");
		dialog_msgbox("Payment Accepted", &n_bal[0], 100, 100, 1);
		end_dialog();
		main_menu();
		break;}
		case 2: {// Add Charge --> note that a negative charge is a payment and a negative payment is a charge but I am implementing to show menus etc although same level of functionnality can be achieved using only one function.
		string sum;
		string n_bal;
		dialog_vars.input_result = NULL;
		dialog_inputbox("Add a Charge", "Enter Sum: (CDN)", 0, 0,NULL , 0);
		sum = dialog_vars.input_result;
 		end_dialog();
 		double sum_paid = stod(sum);
 		H1.out_pt[rank].account->add_charge(sum_paid);
 		n_bal = "New Balance: ";
 		n_bal.append(H1.out_pt[rank].account->get_balance_str());
 		n_bal.append(" CDN.\nReturning to Main Menu.");
		dialog_msgbox("Charge Added Successfully.", &n_bal[0], 100, 100, 1);
		end_dialog();
		main_menu();
		break;}
		default:
			break;
	}



}

}

void patient_list_menu(bool get_profile){
if(get_profile==true){
	char c[4][40]={
        "1",
        "List inPatients",
        "2",
        "List outPatients",
      };
 	
    // use a smart pointer
    char* param[4];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu("Patient Listing Menu", "Select an option:", 100, 100, 50, 2, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
	case 1:
		if(H1.in_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No inPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
		inP_ls(true);
		break;
	case 2:
	if(H1.out_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No outPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
		outP_ls(true);
		break;
	default:
		break;
	}
}else if(get_profile == false){

char c[4][40]={
        "1",
        "inPatients Accounts",
        "2",
        "outPatients Accounts",
      };
 	
    char* param[4];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu("Patient Accounts Listing Menu", "Select an option:", 100, 100, 50, 2, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
	case 1:
		if(H1.in_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No inPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
		inP_ls(false);
		break;
	case 2:
	if(H1.out_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No outPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
		outP_ls(false);
		break;
	default:
		break;
	}




}

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

 	dialog_inputbox("New inPatient", "Enter Service\n 0-ER\n 1-Surgery\n 2-Short-Term \n 3-Radiology \n 4-Lab\n 5-Blood", 0, 0,NULL , 0);
string serv = dialog_vars.input_result;
 	end_dialog();

 	
 	dialog_inputbox("New inPatient", "Enter Admission Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Release Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string r_date = dialog_vars.input_result;
 	end_dialog();

 	dialog_inputbox("New inPatient", "Enter Daily Charge (CDN)", 0, 0,NULL , 0);
string d_charge = dialog_vars.input_result;
 	end_dialog();

 	Date* d1;
 	Date* d2;
 	d1 = new Date(date);
 	d2 = new Date(r_date);
 	inPatient* P1;
 	P1=new inPatient(fname, mname, lname, stoi(sin), stoi(cond), stoi(serv), *d1, *d2, stod(d_charge));
 	H1.add_inPT(P1);
 	string recap;
 	vector<string> test;
 	 H1.in_pt.back().get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New inPatient Successfully Added!", &recap[0], 100, 100, 1);
	end_dialog();
	dialog_vars.input_result = NULL;
	main_menu();
}
void add_outPatient(){
	init_dialog(stdin, stdout);
	dialog_vars.nocancel = 1;

	string doc_license_no = select_doctor();
 	int i = 0;
 	while(doc_license_no.compare(H1.doc_pt[i].get_license_no())!=0){
 		i++;
 	}

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

 	
 	
 	dialog_inputbox("New outPatient", "Enter Appointment Date (DD/MM/YYYY):", 0, 0,NULL , 0);
string date = dialog_vars.input_result;
 	end_dialog();	
 	dialog_inputbox("New outPatient", "Set Appointment Fees:", 0, 0,NULL , 0);
string apt_fees = dialog_vars.input_result;
 	end_dialog();	
 	outPatient* INP1;
 	Date* d1;
 	d1 = new Date(date);
 	INP1 = new outPatient(fname, mname, lname, stoi(sin), *d1, H1.doc_pt[i], stod(apt_fees));
 	H1.add_outPT(INP1);
 	
 	string rec;
 	vector<string> _vec;
 	 H1.out_pt.back().get_profile(_vec);
 for(size_t i =0;i<_vec.size(); i++){
 	rec.append("\n");
 	rec.append(_vec[i]);
 }
	init_dialog(stdin, stdout);
	dialog_msgbox("New outPatient Successfully Added!", &rec[0], 100, 100, 1);
	dialog_vars.input_result = NULL;
	end_dialog();
	main_menu();
}
void add_Doctor(){
	init_dialog(stdin, stdout);
	dialog_vars.nocancel = 1;
dialog_vars.input_result = NULL;
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
 	dialog_inputbox("New Doctor", "Enter Specialty:", 0, 0,NULL , 0);
string specty = dialog_vars.input_result;
 	end_dialog();

 	Doctor* D1;
 	D1 = new Doctor(fname, mname, lname, stoi(sin), l_no, specty);
 	H1.add_doc(D1);
 	string recap;
 	vector<string> test;
 	 H1.doc_pt.back().get_profile(test);
 for(size_t i =0;i<test.size(); i++){
 	recap.append("\n");
 	recap.append(test[i]);}
	init_dialog(stdin, stdout);
	dialog_msgbox("New Doctor Successfully Added!", &recap[0], 100, 100, 1);
	dialog_vars.input_result = NULL;
	end_dialog();
	main_menu();
}
int main_menu(){
	INIT:init_dialog(stdin, stdout);
	dialog_vars.input_result = NULL;
	// one contiguous block of 4 chars
    char c[16][40]={
        "1",
        "Add a new inPatient",
        "2",
        "Add a new outPatient",
        "3",
        "Add a Doctor",
        "4",
        "Patient Listings",
        "5",
        "Doctor List",
        "6",
        "Accounts",
        "7",
        "Delete a File",
        "8",
        "Save Current State"
      };
 	
    // use a smart pointer
    char* param[16];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    param[4] = &c[4][0];
    param[5] = &c[5][0];
    param[6] = &c[6][0];
    param[7] = &c[7][0];
    param[8] = &c[8][0];
    param[9] = &c[9][0];
    param[10] = &c[10][0];
    param[11] = &c[11][0];
    param[12] = &c[12][0];
    param[13] = &c[13][0]; 
    param[14] = &c[14][0];
    param[15] = &c[15][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu("Main Menu - Hospital Management System", "Select an option: (you can use the mouse!)", 100, 100, 50, 8, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
		case 1:
		add_inPatient();
		break;
		case 2:
		add_outPatient();
		break;
		case 3:
		add_Doctor();
		break;
		case 4:
		patient_list_menu(true);
		break;
		case 5:
		doctor_list();
		break;
		case 6:
		patient_list_menu(false);
		break;
		case 7:
		delete_menu();
		break;
		case 8:
		io_daemon.save(H1);
		break;
		default:
		break;

	}
	
	return 0;
}

void delete_menu(){

char c[4][40]={
        "1",
        "Remove an inPatient",
        "2",
        "Remove an outPatient",
      };
 	
    char* param[4];
    param[0] = &c[0][0];
    param[1] = &c[1][0];
    param[2] = &c[2][0];
    param[3] = &c[3][0];
    char** ptr = &param[0];
    dialog_vars.input_result = NULL;
	dialog_menu("Patient Removal Menu", "Select an option:", 100, 100, 50, 2, ptr);
	string ans = dialog_vars.input_result;
	int ans_case = stoi(ans);
	end_dialog();
	switch(ans_case){
		case 1:
		del_inPT();
		break;
		case 2:
		del_outPT();
		break;
		default:
		break;
	}

}

void del_inPT(){
	if(H1.in_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No inPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
	int docno = H1.in_pt.size();
char c[2*docno][128];
for(int i = 0; i<2*docno; i++){
	for(int j = 0; j<128; j++)
		c[i][j] = '\0';
}
	string s;
	// PATIENTS NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	s = to_string(k);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // Get SIN No. // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
		s.clear();
	j++;
	
	s.clear();
	s = H1.in_pt[k].get_fname();
	s.append(" ");
	s.append(H1.in_pt[k].get_lname());
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("inPatient List Menu", "Select an entry to delete.", 100, 100, 50, docno, ptr);
	end_dialog();
	int del_rank = stoi(dialog_vars.input_result);
	H1.in_pt.erase(H1.in_pt.begin()+del_rank);
	main_menu();
}

void del_outPT(){
	if(H1.out_pt.size()==0){
			init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    dialog_msgbox("No outPatients found!", "Returning to Main Menu.", 100, 100, 1);
			  dialog_vars.input_result = NULL;
    end_dialog();
			main_menu();
		}
	int docno = H1.out_pt.size();
char c[2*docno][128];
for(int i = 0; i<2*docno; i++){
	for(int j = 0; j<128; j++)
		c[i][j] = '\0';
}
	string s;
	// PATIENTS NAMES //
	int k = 0;
	for(size_t j=0; j<2*docno; j++){
	j++;
	s = to_string(k);
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }
    // Get SIN No. // 
    k = 0;
	for(size_t j=1; j<2*docno; j++){
		s.clear();
	j++;
	
	s.clear();
	s = H1.out_pt[k].get_fname();
	s.append(" ");
	s.append(H1.out_pt[k].get_lname());
	k++;
    for(size_t i = 0; i<s.length(); i++)
    	c[j-1][i] = s[i];
    }


    char* param[2*docno];
    for(size_t i = 0; i<2*docno; i++)
    	param[i] = &c[i][0];

    char** ptr = &param[0];
    init_dialog(stdin, stdout);
    dialog_vars.input_result = NULL;
	dialog_menu("outPatient List Menu", "Select an entry to delete.", 100, 100, 50, docno, ptr);
	end_dialog();
	int del_rank = stoi(dialog_vars.input_result);
	H1.out_pt.erase(H1.out_pt.begin()+del_rank);
	main_menu();
}