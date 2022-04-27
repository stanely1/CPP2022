CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra

wyrazenie: main.o wyrazenie.o
	g++ main.o wyrazenie.o -o wyrazenie -fsanitize=undefined
main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp
wyrazenie.o: wyrazenie.cpp wyrazenie.hpp
	g++ $(CXXFLAGS) -c wyrazenie.cpp

clean:
	rm wyrazenie *.o