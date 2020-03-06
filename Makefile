CPP = time.cpp date.cpp person.cpp doctor.cpp

all:main

main:
	g++ -o out_exe main.cpp $(CPP)
