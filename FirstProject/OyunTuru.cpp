#include <SFML/Graphics.hpp>
#include "OyunTahtasi.cpp"
#include "Yilan.cpp"
#include "Elma.cpp"

class OyunTuru {
private:
	float cerceveSuresi;
	sf::RenderWindow* pencere; // Bu dýþardan geliyor benim Oyun sýnýf kontrolünde dokunma
	OyunTahtasi* tahta; // Bu dýþardan geliyor benim Oyun sýnýf kontrolünde dokunma
	Yilan* yilan; // Bu dýþardan geliyor benim Oyun sýnýf kontrolünde dokunma
	Elma* elma;
public:
	OyunTuru( sf::RenderWindow* pencere, OyunTahtasi* tahta,int fps,Yilan * yilan ,Elma* elma) {
		this->cerceveSuresi = (float)1 / fps;
		this->pencere = pencere;
		this->tahta = tahta;
		this->yilan = yilan;
		this->elma = elma;
	}


	bool turBaslat() {
		
		sf::Clock* saat = new sf::Clock();
		Yon hareketYonu;
		hareketYonu = Yon::SAG;
		while (yilan->isAlive())
		{
			float gecenSure = saat->getElapsedTime().asSeconds();

			if (gecenSure >= cerceveSuresi) {
				hareketYonu= keyOku();
				yilan->hareketEttir(hareketYonu);
				ekranaCizdir();
				pencere->display();
				saat->restart();
			}
			else {
				sf::sleep(sf::seconds(cerceveSuresi - gecenSure));
			}
		}

		// Burada oyunun bittiði ile giligili bir hata yazdýrabilrisn.
		delete saat;
	}




	void ekranaCizdir() {
		tahtaCizdir();
		yilanCiz();
		elmaCiz();
	}

	void tahtaCizdir() {
		std::vector<sf::RectangleShape>* liste =  tahta->oyunTahtasiOlustur();
		for (size_t i = 0; i < liste->size(); i++)
		{
			pencere->draw(liste->at(i));
		}
	}
	void yilanCiz() {
		std::vector<sf::RectangleShape>* liste = yilan->getYilanBogum();
		for (size_t i = 0; i < liste->size(); i++)
		{
			pencere->draw(liste->at(i));
		}
	}
	void elmaCiz() {
		sf::CircleShape* daire = elma->getElma();
		pencere->draw(*daire);
	}

	Yon keyOku() {
		Yon hareketYonu;
		sf::Event olay;
		while (pencere->pollEvent(olay))
		{
			if (olay.type == sf::Event::Closed) {
				pencere->close();
			}
			else if (olay.type == sf::Event::KeyPressed) {
				switch (olay.key.code)
				{
				case sf::Keyboard::Up:
					hareketYonu = Yon::YUKARI;
					break;
				case sf::Keyboard::Down:
					hareketYonu = Yon::ASAGÝ;
					break;
				case sf::Keyboard::Right:
					hareketYonu = Yon::SAG;
					break;
				case sf::Keyboard::Left:
					hareketYonu = Yon::SOL;
					break;
				default:
					break;
				}
			}
		}
		hareketYonu;
	}
	~OyunTuru() {

	}

};