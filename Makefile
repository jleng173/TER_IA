
all: init.o switch_blend.o Carte.o PositionSouris.o ppm.o Batiment.o Forme.o 
	g++ init.o switch_blend.o Carte.o PositionSouris.o Batiment.o Forme.o ppm.o main.cpp -lm -lGL -no-pie -lGLU -lglut -o test

init.o: init.cpp init.hpp
	g++ -c init.cpp -o init.o

Carte.o: Carte.cpp Carte.hpp
	g++ -c Carte.cpp -o Carte.o

PositionSouris.o: PositionSouris.cpp PositionSouris.hpp
	g++ -c PositionSouris.cpp -o PositionSouris.o

Batiment.o: Batiment.cpp Batiment.hpp
	g++ -c Batiment.cpp -o Batiment.o

Forme.o: Forme.cpp Forme.hpp
	g++ -c Forme.cpp -o Forme.o

ppm.o: ppm.cpp ppm.hpp
	g++ -c ppm.cpp -o ppm.o


clean:
	rm -f *.o main
