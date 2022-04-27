CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra -fsanitize=undefined

kolejka : main.cpp kolejka.cpp kolejka.hpp
	g++ $(CXXFLAGS) main.cpp kolejka.cpp -o kolejka

clean: 
	rm kolejka
