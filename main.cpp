
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./time.h"
#include "./date.h"
using namespace std;

int main(){

Time t1(23,53,56);
Date d1;
d1.print_date();
vector<int> date_vec = d1.get_date();
cout << endl << date_vec[0] << date_vec[1] << date_vec[2];
return 0;
}