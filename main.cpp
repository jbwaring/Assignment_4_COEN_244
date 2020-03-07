
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./time.h"
#include "./date.h"
#include "./person.h"
#include "./doctor.h"
#include "./inPatient.h"
#include "./jb_base.h"
using namespace std;
int main(){
Time t(12,23,45);
Date d1(2020,12,4,23,56,7);
Date d2(2345,3,30);
Date d(d2);
vector<string> personProfile;
inPatient* hello;
hello = new inPatient("test", "test", "test", 123456789, 1, 1, d1);
hello->get_profile(personProfile);

for(size_t i = 0; i < personProfile.size(); i ++)
	cout << endl << personProfile[i];
return 0;

}