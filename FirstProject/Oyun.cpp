#include <SFML/Graphics.hpp>
#include "OyunTahtasi.cpp"
#include "Yilan.cpp"
#include "OyunTuru.cpp"
#include "Elma.cpp"

class Oyun {
private:
	sf::RenderWindow* pencere;
	OyunTahtasi* tahta;
	OyunTuru* tur;
	Yilan* yilan;
	Elma* elma;
	int fps;
	int kareBoyut;
	bool devamMi;


public:

	Oyun(int genislik, int yukseklik , int fps,int kareBoyut) {
		devamMi = false;
		this->fps = fps;
		this->kareBoyut = kareBoyut;
		this->pencere = new sf::RenderWindow(sf::VideoMode(genislik, yukseklik), "Merhaba");
		this->tahta = new OyunTahtasi(kareBoyut,pencere->getSize());
		this->yilan = new Yilan(3,kareBoyut);
		this->elma = new Elma(4, new Renk{ 255,0,0 });
		srand(time(0));
	}

	
	bool oyunBaslat() {
		devamMi = true;
		tur = new OyunTuru(pencere,tahta,fps,yilan,elma);
		tur->turBaslat();
		delete tur;
		return true;

	}


	void setSettings(int fps, int kareBoyut) {
		this->fps = fps;
		this->kareBoyut = kareBoyut;
	}

	bool oyunBittiMi() {
		return devamMi;
	}
	~Oyun() {
		delete elma;
		delete yilan;
		delete tahta;
		delete pencere;
	}



};