CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra -fsanitize=undefined

main: main.cpp kolory.cpp kolory.hpp punkty.cpp punkty.hpp
	g++ $(CXXFLAGS) -o main main.cpp kolory.cpp punkty.cpp

clean:
	rm main