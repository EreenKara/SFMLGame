#include "Yilan.hpp"
#include <iostream>

Yilan::Yilan(int yilanBoyut, int kareBoyut) {
	liste = new std::vector<sf::RectangleShape>();
	size = kareBoyut;
	boyut = yilanBoyut;
	konum.x = size * 5;
	konum.y = size * 3;
	this->yasiyormu = true;
	for (int i = 0; i < boyut; i++) {
		liste->push_back(sf::RectangleShape(sf::Vector2f(size, size)));
		liste->at(i).setPosition(konum.x - i*size, konum.y);
	}


}
sf::RectangleShape& Yilan::basKismi() {
	return liste->at(0);
}
std::vector<sf::RectangleShape>* Yilan::getYilanBogum() {
	return liste;
}


void Yilan::hareketEttir(Yon yon) {
	sf::Vector2f eskiPosition;
	eskiPosition = basKismi().getPosition();

	switch (yon)
	{
	case Yon::YUKARI:
		basKismi().setPosition(eskiPosition.x, eskiPosition.y - size);
		break;
	case Yon::ASAGÝ:
		basKismi().setPosition(eskiPosition.x, eskiPosition.y + size);
		break;
	case Yon::SAG:
		basKismi().setPosition(eskiPosition.x + size, eskiPosition.y);
		break;
	case Yon::SOL:
		basKismi().setPosition(eskiPosition.x - size, eskiPosition.y );
		break;
	}
	sf::Vector2f yeniPosition;
	for (int i = 1; i < liste->size(); i++)
	{

		yeniPosition = liste->at(i).getPosition();
		liste->at(i).setPosition(eskiPosition.x, eskiPosition.y);
		eskiPosition = yeniPosition;
	}
}


void Yilan::yemekYendi() {
	sf::RectangleShape kare(sf::Vector2f(size, size));
	sf::RectangleShape sonKare = liste->at(liste->size() - 1);
	kare.setPosition(sf::Vector2f(sonKare.getPosition().x, sonKare.getPosition().y));
	liste->push_back(kare);
}
void Yilan::setYasiyormu(bool yasiyormu) {
	this->yasiyormu = yasiyormu;
}
bool Yilan::isAlive() {
	return yasiyormu;
}