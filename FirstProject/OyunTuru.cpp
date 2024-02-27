#include "OyunTuru.hpp"
#include <iostream>
#include <string>
#include <cmath>


OyunTuru::OyunTuru(sf::RenderWindow* pencere, int fps, Yilan* yilan, Elma* elma) {
	this->cerceveSuresi = (float)1 / fps;
	this->pencere = pencere;
	this->yilan = yilan;
	this->elma = elma;
	elmaKonumlandir();
}


bool OyunTuru::turBaslat() {

	sf::Clock* saat = new sf::Clock();
	Yon hareketYonu;
	hareketYonu = Yon::SAG;
	while (yilan->isAlive())
	{
		float gecenSure = saat->getElapsedTime().asSeconds();

		if (gecenSure >= cerceveSuresi) {
			keyOku(hareketYonu);
			
			yilan->hareketEttir(hareketYonu);
			if (!isYilanGottaLive()) {
				continue;
			}
			pencere->clear();
			if (yilan->basKismi().getPosition() == elma->getElma()->getPosition())
			{
				elmaKonumlandir();
				yilan->yemekYendi();
			}
			ekranaCizdir();
			pencere->display();
			saat->restart();
		}
		else {
			sf::sleep(sf::seconds(cerceveSuresi - gecenSure));
		}
	}


	//std::string wait;
	//std::cin >> wait;

	// Burada oyunun bittiði ile ilgili bir hata yazdýrabilrisn.
	delete saat;
	return true;
}

bool OyunTuru::isYilanGottaLive() {
	if (yilanIsInWindow() && !yilanCollision()) return true;
	yilan->setYasiyormu(false);
	return false;
}

void textYazdir(std::string text) {
	//sf::Text text;
//text.setString("Oyun Bitti");
//text.setCharacterSize(50);
//text.setFillColor(sf::Color::Green); // Set the fill color
//text.setPosition(100.f, 100.f); // Set the position
//pencere->clear();
//pencere->draw(text);

//pencere->display();
//sf::sleep(sf::seconds(5));
}

void OyunTuru::elmaKonumlandir() {
	bool collision = false;
	sf::Vector2f yeniKonum(0, 0);
	do{
		collision = false;
		int randomX = (std::rand() % (pencere->getSize().x / 20)) * 20;
		int randomY = (std::rand() % (pencere->getSize().y / 20)) * 20;
		yeniKonum.x = randomX;
		yeniKonum.y = randomY;
		auto yilanListe = yilan->getYilanBogum();
		for (int i = 0; i < yilanListe->size(); i++)
		{
			if (yilanListe->at(i).getPosition() == yeniKonum) {
				collision = true;
			}
		}
	} while (collision);

	this->elma->konumDegistir(yeniKonum);
}

void OyunTuru::ekranaCizdir() {
	yilanCiz();
	elmaCiz();
}
bool OyunTuru::yilanCollision(){
	auto yilanListe = yilan->getYilanBogum();
	for (int i = 0; i < yilanListe->size(); i++)
	{

		for (size_t j = i+1; j < yilanListe->size(); j++)
		{
			if (yilanListe->at(i).getPosition() == yilanListe->at(j).getPosition()) {
				return true;
			}
		}
	}
	return false;

}


bool OyunTuru::yilanIsInWindow() {
	auto yilanListe = yilan->getYilanBogum();
	for (int i = 0; i < yilanListe->size(); i++)
	{
		
		if (yilanListe->at(i).getPosition().x <0|| yilanListe->at(i).getPosition().x >= pencere->getSize().x ||
			yilanListe->at(i).getPosition().y < 0 || yilanListe->at(i).getPosition().y >= pencere->getSize().y) {
			return false;
		}
	}
	return true;
}



void OyunTuru::yilanCiz() {
	std::vector<sf::RectangleShape>* liste = yilan->getYilanBogum();
	for (size_t i = 0; i < liste->size(); i++)
	{
		pencere->draw(liste->at(i));
	}
}
void OyunTuru::elmaCiz() {
	sf::CircleShape* daire = elma->getElma();
	pencere->draw(*daire);
}

Yon OyunTuru::keyOku(Yon& hareketYonu) {
	sf::Event olay;
	while (pencere->pollEvent(olay))
	{
		if (olay.type == sf::Event::Closed) {
			pencere->close();
		}
		if (olay.type == sf::Event::KeyPressed) {
			switch (olay.key.code)
			{
			case sf::Keyboard::Up:
				if (hareketYonu == Yon::ASAGÝ);
				else
					hareketYonu = Yon::YUKARI;
				break;
			case sf::Keyboard::Down:
				if (hareketYonu == Yon::YUKARI);
				else
				hareketYonu = Yon::ASAGÝ;
				break;
			case sf::Keyboard::Right:
				if (hareketYonu == Yon::SOL);
				else
				hareketYonu = Yon::SAG;
				break;
			case sf::Keyboard::Left:
				if (hareketYonu == Yon::SAG);
				else
				hareketYonu = Yon::SOL;
				break;
			default:
				break;
			}
		}
	}
	return hareketYonu;
}
OyunTuru::~OyunTuru() {

}
	