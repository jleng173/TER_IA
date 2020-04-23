
all: init.o switch_blend.o ppm.o Carte.o Decor.o PositionSouris.o Batiment.o Forme.o Ressource.o Personnage.o
	g++ -std=c++14 init.o switch_blend.o ppm.o Carte.o Decor.o PositionSouris.o Batiment.o Forme.o Ressource.o Personnage.o main.cpp -lm -lGL -no-pie -lGLU -lglut -o test && ./test

init.o: init.cpp init.hpp
	g++ -c init.cpp -o init.o

Carte.o: Carte.cpp Carte.hpp
	g++ -std=c++14 -c Carte.cpp -o Carte.o

Decor.o: Decor.cpp Decor.hpp
	g++ -c Decor.cpp -o Decor.o

PositionSouris.o: PositionSouris.cpp PositionSouris.hpp
	g++ -c PositionSouris.cpp -o PositionSouris.o

Batiment.o: Batiment.cpp Batiment.hpp
	g++ -c Batiment.cpp -o Batiment.o

Forme.o: Forme.cpp Forme.hpp
	g++ -c Forme.cpp -o Forme.o

ppm.o: ppm.cpp ppm.hpp
	g++ -c ppm.cpp -o ppm.o

Ressource.o: Ressource.cpp Ressource.hpp
	g++ -c Ressource.cpp -o Ressource.o

Personnage.o: Personnage.cpp Personnage.hpp
	g++ -c Personnage.cpp -o Personnage.o

clean:
	rm -f *.o main

