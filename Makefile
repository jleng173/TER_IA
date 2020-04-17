
all: init.o switch_blend.o Carte.o PositionSouris.o
	g++ init.o switch_blend.o Carte.o PositionSouris.o main.cpp -lm -lGL -no-pie -lGLU -lglut -o test

init.o: init.cpp init.hpp
	g++ -c init.cpp -o init.o

Carte.o: Carte.cpp Carte.hpp
	g++ -c Carte.cpp -o Carte.o

PositionSouris.o: PositionSouris.cpp PositionSouris.hpp
	g++ -c PositionSouris.cpp -o PositionSouris.o

clean:
	rm -f *.o main
