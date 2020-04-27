
all: clean init.o ppm.o Carte.o Decor.o PositionSouris.o Batiment.o Chateau.o Caserne.o Tour.o Ferme.o Forme.o Ressource.o Personnage.o Guerrier.o Paysan.o Arbaletrier.o
	g++ -std=c++14 init.o ppm.o Carte.o Decor.o PositionSouris.o Batiment.o Chateau.o Caserne.o Tour.o Ferme.o Forme.o Ressource.o Personnage.o Guerrier.o Paysan.o Arbaletrier.o main.cpp -lm -lGL -no-pie -lGLU -lglut -o test && ./test

init.o: init.cpp init.hpp
	g++ -c init.cpp -o init.o

Carte.o: Carte.cpp Carte.hpp
	g++ -std=c++14 -c Carte.cpp -o Carte.o

Decor.o: Decor.cpp Decor.hpp
	g++ -std=c++14 -c Decor.cpp -o Decor.o

PositionSouris.o: PositionSouris.cpp PositionSouris.hpp
	g++ -c PositionSouris.cpp -o PositionSouris.o

Forme.o: Forme.cpp Forme.hpp
	g++ -c Forme.cpp -o Forme.o

ppm.o: ppm.cpp ppm.hpp
	g++ -c ppm.cpp -o ppm.o

Ressource.o: Ressource.cpp Ressource.hpp
	g++ -c Ressource.cpp -o Ressource.o

#Batiment
Batiment.o: Batiment.cpp Batiment.hpp
	g++ -std=c++14 -c Batiment.cpp -o Batiment.o

Chateau.o: Chateau.cpp Chateau.hpp
	g++ -std=c++14 -c Chateau.cpp -o Chateau.o

Caserne.o: Caserne.cpp Caserne.hpp
	g++ -std=c++14 -c Caserne.cpp -o Caserne.o

Tour.o: Tour.cpp Tour.hpp
	g++ -std=c++14 -c Tour.cpp -o Tour.o

Ferme.o: Ferme.cpp Ferme.hpp
	g++ -std=c++14 -c Ferme.cpp -o Ferme.o

#Personnage
Personnage.o: Personnage.cpp Personnage.hpp
	g++ -std=c++14 -c Personnage.cpp -o Personnage.o

Guerrier.o: Guerrier.cpp Guerrier.hpp
	g++ -std=c++14 -c Guerrier.cpp -o Guerrier.o

Paysan.o: Paysan.cpp Paysan.hpp
	g++ -std=c++14 -c Paysan.cpp -o Paysan.o

Arbaletrier.o: Arbaletrier.cpp Arbaletrier.hpp
	g++ -std=c++14 -c Arbaletrier.cpp -o Arbaletrier.o

clean:
	rm -f *.o

