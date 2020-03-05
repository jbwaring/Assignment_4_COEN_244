CPP = time.cpp date.cpp

all:main

main:
	g++ -o out_exe main.cpp $(CPP)
