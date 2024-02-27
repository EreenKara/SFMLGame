#pragma once
#include <SFML/Graphics.hpp>

class OyunTahtasi {
private:
	std::vector<sf::RectangleShape>* tahtaListesti;
	sf::Vector2u ekranSize;
	int kareBoyut;
public:

	OyunTahtasi(int kareBoyut, sf::Vector2u ekranSize);


	std::vector<sf::RectangleShape>* oyunTahtasiOlustur();

	bool oyunTahtasiSinirlarindaMi();

	~OyunTahtasi();



};