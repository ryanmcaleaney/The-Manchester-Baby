all:

	g++ -c baby.cpp
	g++ -c babycode.cpp
	g++ baby.o babycode.o

clean: