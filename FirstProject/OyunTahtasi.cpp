#include "OyunTahtasi.hpp"

OyunTahtasi::OyunTahtasi(int kareBoyut, sf::Vector2u ekranSize) {
	this->tahtaListesti = new  std::vector<sf::RectangleShape>();
	this->kareBoyut = kareBoyut;
	this->ekranSize = ekranSize;
}


std::vector<sf::RectangleShape>* OyunTahtasi::oyunTahtasiOlustur() {
	sf::RectangleShape kare(sf::Vector2f(20, 20));
	int kareSayisiX = ekranSize.x / kareBoyut;
	int kareSayisiY = ekranSize.y / kareBoyut;
	for (size_t i = 0; i < kareSayisiX; i++)
	{
		for (size_t j = 0; j < kareSayisiY; j++)
		{
			kare.setPosition(sf::Vector2f(kareSayisiX * 20, kareSayisiY * 20));
			tahtaListesti->push_back(kare);
		}
	}
	return tahtaListesti;
}

bool OyunTahtasi::oyunTahtasiSinirlarindaMi() {


	return false;
}

OyunTahtasi::~OyunTahtasi() {

	delete tahtaListesti;
}
