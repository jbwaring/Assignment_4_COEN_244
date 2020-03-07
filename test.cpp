
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
int main(){

int* ptr;
ptr = new int[3];
ptr[0] = 1;
ptr[1] = 2;
ptr[2] = 3;
cout << ptr[0] <<ptr[1]<<ptr[2];
return 0;

}