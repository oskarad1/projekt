#include <iostream>

using namespace std;

class samochod 
{
public:
	string marka;
	string model;
	string skrzynia;
	string rocznik;
	string pojemnosc;
	string przebieg;
	int nr_linii;
	int nr_samochodu;
	int n;
	int usunlinie;

	void wczytaj();
	void wyswietl();
	void wyswietl_warunkowo();
	void wyswietl_pojedynczo();
	void dodaj();
	void sortuj();
	void usun();
};

using namespace std;