CXXFLAGS=-std=c++17 -O3 -Wshadow -Wall -Wextra
LFLAGS=-fsanitize=undefined
NAME=macierz
OBJS=main.o macierz.o wyjatki.o

$(NAME) : $(OBJS)
	g++ $(OBJS) -o $(NAME) $(LFLAGS)

%.o : %.c %.h
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm macierz *.o