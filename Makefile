run: main
	./main

compile: main.cpp run
	g++ main.cpp -o main
	run

