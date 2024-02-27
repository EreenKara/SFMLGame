#pragma once
#include <SFML/Graphics.hpp>
#include "OyunTahtasi.hpp"
#include "Yilan.hpp"
#include "Elma.hpp"

class OyunTuru {
private:
	float cerceveSuresi;
	sf::RenderWindow* pencere; // Bu d��ardan geliyor benim Oyun s�n�f kontrol�nde dokunma
	Yilan* yilan; // Bu d��ardan geliyor benim Oyun s�n�f kontrol�nde dokunma
	Elma* elma;
public:
	OyunTuru(sf::RenderWindow* pencere,  int fps, Yilan* yilan, Elma* elma);


	bool turBaslat();
	bool isYilanGottaLive();
	bool yilanIsInWindow();
	bool yilanCollision();
	void elmaKonumlandir();
	void ekranaCizdir();

	void yilanCiz();
	void elmaCiz();
	Yon keyOku(Yon& hareketYonu);
	~OyunTuru();

};