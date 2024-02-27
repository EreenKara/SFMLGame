#include "Oyun.hpp"


Oyun::Oyun(int genislik, int yukseklik, int fps, int kareBoyut) {
	this->devamMi = false;
	this->fps = fps;
	this->kareBoyut = kareBoyut;
	this->pencere = new sf::RenderWindow(sf::VideoMode(genislik, yukseklik), "Merhaba");
	this->yilan = new Yilan(3, kareBoyut);
	this->elma = new Elma(4, new Renk{ 255,0,0 });
}


bool Oyun::oyunBaslat() {
	this->devamMi = true;
	this->tur = new OyunTuru(pencere, fps, yilan, elma);
	this->tur->turBaslat();
	delete this->tur;
	return true;

}


void Oyun::setSettings(int fps, int kareBoyut) {
	this->fps = fps;
	this->kareBoyut = kareBoyut;
}

bool Oyun::oyunBittiMi() {
	return devamMi;
}
Oyun::~Oyun() {
	delete elma;
	delete yilan;
	delete pencere;
}
