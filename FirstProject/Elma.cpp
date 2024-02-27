#include "Elma.hpp"

Elma::Elma(int boyut, Renk* renk) {
	this->boyut = boyut;
	this->renk = renk;
	this->daire = new sf::CircleShape(boyut);
	sf::Color color(renk->red, renk->green, renk->blue);
	this->daire->setFillColor(color);
	
}
sf::CircleShape* Elma::getElma() {
	return daire;
}
void Elma::konumDegistir(sf::Vector2f konum) {
	this->daire->setPosition(konum);
}
Elma::~Elma() {
	delete daire;

}

