#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Renk.hpp"

class Elma {
private:
	Renk* renk;
	int boyut;
	sf::CircleShape* daire;
public:
	Elma(int boyut, Renk* renk);
	sf::CircleShape* getElma();
	void konumDegistir(sf::Vector2f konum);
	~Elma();



};