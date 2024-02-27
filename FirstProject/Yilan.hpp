#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Yon.hpp"



class Yilan
{
private:
	int size;
	int boyut;
	std::vector<sf::RectangleShape>* liste;
	sf::Vector2f konum; // Bas k�sm�n�n knoumu zaten �nemli olan
	bool yasiyormu;
public:

	Yilan(int yilanBoyut, int kareBoyut);
	sf::RectangleShape& basKismi();
	std::vector<sf::RectangleShape>* getYilanBogum();

	void setYasiyormu(bool yasiyormu);
	void hareketEttir(Yon yon);


	void yemekYendi();
	bool isAlive();

};