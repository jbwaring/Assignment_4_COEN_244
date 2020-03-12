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
	int ans;
	init_dialog(stdin, stdout);
	// one contiguous block of 4 chars
    char c[2][8]={
        "option1",
        "option2"
      };

    // use a smart pointer
    std::unique_ptr<char*[]> param(new char*[2]);
    param[0] = &c[0][0];
    param[1] = &c[1][0];
	ans = dialog_menu("Main Menu - Hospital Management System", "Select an option:", 100, 100, 50, 2, param.get());
	end_dialog();
	return ans;
}