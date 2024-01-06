#include <SFML/Graphics.hpp>
#include <vector>
#include "Yon.cpp"



class Yilan
{
private:
	int size;
	int boyut;
	std::vector<sf::RectangleShape>* liste;
	sf::Vector2f konum; // Bas kýsmýnýn knoumu zaten önemli olan
public:

	Yilan(int yilanBoyut,int kareBoyut) {
		liste = new std::vector<sf::RectangleShape>();
		size = kareBoyut;
		boyut = yilanBoyut;
		konum.x = size * 5;
		konum.y = size * 3;
		for (int i = 0; i < boyut; i++) {
			liste->push_back(sf::RectangleShape(sf::Vector2f(size, size)));
			liste->at(i).setPosition(konum.x-i, konum.y);
		}
		

	}
	sf::RectangleShape basKismi() {
		return liste->at(0);
	}
	std::vector<sf::RectangleShape>* getYilanBogum() {
		return liste;
	}


	void hareketEttir(Yon yon) {
		sf::Vector2f eskiPosition;
		eskiPosition = basKismi().getPosition();
		switch (yon)
		{
		case Yon::YUKARI:
			basKismi().setPosition(eskiPosition.x, eskiPosition.y + size);
			break;
		case Yon::ASAGÝ:
			basKismi().setPosition(eskiPosition.x, eskiPosition.y - size);
			break;
		case Yon::SAG:
			basKismi().setPosition(eskiPosition.x+size, eskiPosition.y);
			break;
		case Yon::SOL:
			basKismi().setPosition(eskiPosition.x- size, eskiPosition.y * size);
			break;
		}
		sf::Vector2f yeniPosition;

		for (int i =1;i<liste->size();i++)
		{
			yeniPosition= liste->at(i).getPosition();
			liste->at(i).setPosition(eskiPosition.x,eskiPosition.y);
			eskiPosition = yeniPosition;
		}
	}


	void yemekYendi() {
		sf::RectangleShape kare(sf::Vector2f(size, size));
		sf::RectangleShape sonKare = liste->at(liste->size() - 1);
		kare.setPosition(sf::Vector2f(sonKare.getPosition().x,sonKare.getPosition().y));
		liste->push_back(kare);
	}
	bool isAlive() {
		return true;
	}

};