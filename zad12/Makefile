CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra
LFLAGS=-fsanitize=undefined
NAME=svg
DEPS=ios_manipulators.hpp xml.hpp svg.hpp
OBJS=main.o ios_manipulators.o xml.o svg.o

$(NAME) : $(OBJS)
	g++ $(OBJS) -o $(NAME) $(LFLAGS)

%.o : %.cpp $(DEPS)
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm $(NAME) *.o
