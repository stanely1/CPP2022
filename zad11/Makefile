CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra
LFLAGS=-fsanitize=undefined
NAME=cezar
DEPS=files.hpp
OBJS=cezar.o files.o

$(NAME) : $(OBJS)
	g++ $(OBJS) -o $(NAME) $(LFLAGS)

%.o : %.cpp $(DEPS)
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm $(NAME) *.o test