
all: init.o switch_blend.o
	g++ init.o switch_blend.o main.cpp -lm -lGL -no-pie -lGLU -lglut -o test

init.o: init.cpp init.hpp
	g++ -c init.cpp -o init.o


clean:
	rm -f *.o main
