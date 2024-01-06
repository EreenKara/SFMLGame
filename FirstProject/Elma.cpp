#include <string>
#include <SFML/Graphics.hpp>
#include "Renk.cpp"

class Elma {
private:
	Renk* renk;
	int boyut;
	sf::CircleShape* daire;
public:
	Elma(int boyut,Renk* renk) {
		this->boyut = boyut;
		this->renk = renk;
		this->daire = new sf::CircleShape(4);
		sf::Color color(renk->red, renk->green, renk->blue);
		this->daire->setFillColor(color);
	}
	sf::CircleShape* getElma() {
		return daire;
	}
	void konumDegistir(sf::Vector2f konum) {
		this->daire->setPosition(konum);
	}
	~Elma() {
		delete daire;
		
	}



};