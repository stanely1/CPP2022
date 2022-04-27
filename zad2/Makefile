CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra -fsanitize=undefined

zmienne : main.cpp zmienne.cpp zmienne.hpp
	g++ $(CXXFLAGS) main.cpp zmienne.cpp -o zmienne

clean: 
	rm zmienne