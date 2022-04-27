CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra

tabbit: main.o tabbit.o
	g++ main.o tabbit.o -o tabbit -fsanitize=undefined
main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp
tabbit.o: tabbit.cpp tabbit.hpp
	g++ $(CXXFLAGS) -c tabbit.cpp

clean:
	rm tabbit *.o