CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra
LFLAGS=-fsanitize=undefined
NAME=bst
DEPS=bst.hpp bst.tpp
OBJS=main.o

$(NAME) : $(OBJS)
	g++ $(OBJS) -o $(NAME) $(LFLAGS)

%.o : %.cpp $(DEPS)
	g++ $(CXXFLAGS) -c -o $@ $<

test: spec_test.cpp $(DEPS)
	g++ $(CXXFLAGS) -o test spec_test.cpp $(LFLAGS)

clean:
	rm $(NAME) *.o test