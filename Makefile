CPP = time.cpp date.cpp person.cpp doctor.cpp inPatient.cpp bed.cpp outPatient.cpp

all:main

main:
	g++ -v  -o out_exe main.cpp $(CPP)
