
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./time.h"
#include "./date.h"
#include "./person.h"
#include "./doctor.h"
#include "./jb_base.h"
using namespace std;

int main(){
Doctor* d1;

d1 = new Doctor("John", "M.", "Lasseter", 645792152, "MD76458EDJCJML01");
vector<string> d1_profile;
d1->get_profile(d1_profile);
for(size_t i=0; i<d1_profile.size(); i++)
	cout << endl << d1_profile[i];



return 0;

}