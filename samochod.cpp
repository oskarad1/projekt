#include <iostream>
#include "samochod.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void samochod::wczytaj()
{
	fstream plik;
	plik.open("samochody.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}

	int nr_linii = (nr_samochodu - 1) * 6 + 1;
	int aktualny_nr=1;
	string linia;

	while (getline(plik, linia))
	{
		if (aktualny_nr == nr_linii) marka = linia; 
		if (aktualny_nr == nr_linii+1) model = linia;
		if (aktualny_nr == nr_linii+2) skrzynia = linia;
		if (aktualny_nr == nr_linii+3) rocznik = linia;
		if (aktualny_nr == nr_linii+4) pojemnosc = linia;
		if (aktualny_nr == nr_linii+5) przebieg = linia;
		aktualny_nr++;
	}
	plik.close();

}

void samochod::wyswietl()
{
	cout << marka << " " << model << " " << skrzynia << " " << rocznik << " " << pojemnosc << " " << przebieg << endl;
}

void samochod::dodaj()
{
	fstream plik;
	plik.open("samochody.txt", ios::out | ios::app);
	string linia;

	cout << "Wpisz marke samochodu" << endl;
	cin >> marka;
	plik << marka << endl;
	cout << "Wpisz model samochodu" << endl;
	cin >> model;
	plik << model << endl;
	cout << "Wpisz typ skrzyni biegow samochodu" << endl;
	cin >> skrzynia;
	plik << skrzynia << endl;
	cout << "Wpisz rocznik samochodu" << endl;
	cin >> rocznik;
	plik << rocznik << endl;
	cout << "Wpisz pojemnosc silnika samochodu w cm3" << endl;
	cin >> pojemnosc;
	plik << pojemnosc << endl;
	cout << "Wpisz przebieg samochodu w kilometrach" << endl;
	cin >> przebieg;
	plik << przebieg << endl;
	
	plik.close();
}

void samochod::wyswietl_warunkowo()
{
	int wynik;
	stringstream s(rocznik);
	s >> wynik;

	if (wynik >= 2010)
	{
		cout << marka << " " << model << " " << skrzynia << " " << rocznik << " " << pojemnosc << " " << przebieg << endl;
	}
}

void samochod::wyswietl_pojedynczo()
{
	int n;
	cout << "podaj numer auta, ktorego parametry chcesz wyswielic" << endl;
	cin >> n;

	fstream plik;
	plik.open("samochody.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}

	int nr_linii = (n - 1) * 6 + 1;
	int aktualny_nr = 1;
	string linia;

	while (getline(plik, linia))
	{
		if (aktualny_nr == nr_linii) marka = linia;
		if (aktualny_nr == nr_linii + 1) model = linia;
		if (aktualny_nr == nr_linii + 2) skrzynia = linia;
		if (aktualny_nr == nr_linii + 3) rocznik = linia;
		if (aktualny_nr == nr_linii + 4) pojemnosc = linia;
		if (aktualny_nr == nr_linii + 5) przebieg = linia;
		aktualny_nr++;
	}
	plik.close();

	cout << marka << " " << model << " " << skrzynia << " " << rocznik << " " << pojemnosc << " " << przebieg << endl;
}

void samochod::sortuj()
{
	fstream plik;
	plik.open("samochody.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}

	int n;
	cout << "wpisz ilosc aut w katalogu" << endl;
	cin >> n;
	string** tablica = new string * [6];

	for (int i = 0; i < n; i++) 
	{
		tablica[i] = new string [6];
			for (int j = 0; j < 6; j++) 
			{
				getline(plik, tablica[i][j]);
			}
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (tablica[j - 1][3] > tablica[j][3])
			{
				swap(tablica[j - 1][0], tablica[j][0]);
				swap(tablica[j - 1][1], tablica[j][1]);
				swap(tablica[j - 1][2], tablica[j][2]);
				swap(tablica[j - 1][3], tablica[j][3]);
				swap(tablica[j - 1][4], tablica[j][4]);
				swap(tablica[j - 1][5], tablica[j][5]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << tablica[i][0] << " " << tablica[i][1] << " " << tablica[i][2] << " " << tablica[i][3] << " " << tablica[i][4] << " " << tablica[i][5] << endl;
	}


	plik.close();
}

void samochod::usun()
{
	ifstream plik;
	plik.open("samochody.txt", ios::in);
	ofstream temp;
	temp.open("temp.txt", ios::out);
	string usunlinie;
	string linia;
	cout << "Ktory samochod chcesz usunac? ";
	cin >> usunlinie;

	while (getline(plik, linia))
	{
		if (linia != usunlinie)
		temp << linia << endl;
	}

	temp.close();
	plik.close();
	
	remove("samochody.txt");
	rename("temp.txt", "samochody.txt");
}

