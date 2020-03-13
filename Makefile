CPP = time.cpp date.cpp person.cpp doctor.cpp inPatient.cpp bed.cpp outPatient.cpp hospital.cpp IODaemon.cpp account.cpp

all:main

main:
	g++ -std=c++17 -ldialog -lncurses -o out_exe main.cpp $(CPP)
