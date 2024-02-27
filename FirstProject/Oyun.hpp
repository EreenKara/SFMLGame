#pragma once
#include <SFML/Graphics.hpp>
#include "OyunTahtasi.hpp"
#include "Yilan.hpp"
#include "OyunTuru.hpp"
#include "Elma.hpp"
class Oyun {
private:
	sf::RenderWindow* pencere;
	OyunTuru* tur;
	Yilan* yilan;
	Elma* elma;
	int fps;
	int kareBoyut;
	bool devamMi;

public:


	Oyun(int genislik, int yukseklik, int fps, int kareBoyut);
	bool oyunBaslat();
	void setSettings(int fps, int kareBoyut);
	bool oyunBittiMi();
	~Oyun();
};