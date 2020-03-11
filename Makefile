CPP = time.cpp date.cpp person.cpp doctor.cpp inPatient.cpp bed.cpp outPatient.cpp hospital.cpp

all:main

main:
	g++ -o out_exe main.cpp $(CPP)
