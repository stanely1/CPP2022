CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra
LFLAGS=-fsanitize=undefined
NAME=rational
OBJS=main.o rational.o rational_exception.o

$(NAME) : $(OBJS)
	g++ $(OBJS) -o $(NAME) $(LFLAGS)

%.o : %.cpp %.h
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm $(NAME) *.o