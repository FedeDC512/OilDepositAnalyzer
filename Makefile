warn=-Wall -Wextra -g3

compile:
	cd src && g++ $(warn) -o main main.cpp ./**/*.cpp ./**/*.h 

run: compile	
	cd src && ./main

start:
	cd src && ./main