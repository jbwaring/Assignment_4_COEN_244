#include <dialog.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./doctor.h"
#include "./inPatient.h"
#include "./outPatient.h"
#include "./hospital.h"
#include "./jb_base.h"

using namespace std;
int main_menu();
int main(){
Hospital H1;

int status;
    init_dialog(stdin, stdout); // INITIAL SPLASH-SCREEN
    status = dialog_yesno("Hospital Management System COEN 244","Do you wish to continue?", 0, 0);
    end_dialog();
  	system("clear");
if(status==1)
 	return 0;
//--------Create a Hospital--------//
Hospital H;
//--------Go to main menu--------//
main_menu();
	
return 0;

}

int main_menu(){
	init_dialog(stdin, stdout);
	// one contiguous block of 4 chars
    char c[6][20]={
        "option1",
        "description1",
        "option2",
        "description2",
        "option3",
        "description3"
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
	int ans = dialog_menu("Main Menu - Hospital Management System", "Select an option: (you can use the mouse!)", 100, 100, 50, 3, ptr);
	cout << endl << "answer: " << ans;
	end_dialog();
	
	return ans;
}