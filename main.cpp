
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "./time.h"
#include "./date.h"
using namespace std;

int main(){

Time t1(23,53,56);

unsigned int* time;
time = (unsigned int *)malloc(sizeof(unsigned int) * 3);
Time::get_time(t1, time);

Time::print_time(time);
cout << endl;


return 0;
}