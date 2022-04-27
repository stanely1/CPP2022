CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra -fsanitize=undefined

wielomian : main.cpp wielomian.cpp wielomian.hpp
	g++ $(CXXFLAGS) main.cpp wielomian.cpp -o wielomian

clean: 
	rm wielomian