#include <iostream>
#include "samochod.h"
#include <conio.h>

using namespace std;

int main()
{ 
	samochod s[50];
	int ilosc_samochodow = 10;
	char wybor;

	cout << "Katalog samochodow" << endl;
	cout << endl;
	cout << "MENU GLOWNE: " << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "1. Wprowadz nowy samochod do katalogu." << endl;
	cout << "2. Wyswietl liste wszystkich samochodow w katalogu." << endl;
	cout << "3. Wyswietl liste samochodow o roczniku 2010 i wyzszym." << endl;
	cout << "4. Wyswietl dane jednego samochodu." << endl;
	cout << "5. Posortuj samochody wedlug rocznika produkcji rosnaco." << endl;
	cout << "6. Usun samochod z katalogu." << endl;
	cout << "7. Wyjdz z programu." << endl;
	
	while (true)
	{
		cout << endl;
		wybor = _getch();

		switch (wybor)
		{
		case '1':
			s[1].dodaj();
			ilosc_samochodow++;
			break;
		case '2':
			for (int i = 0; i <= ilosc_samochodow; i++)
			{
				s[i].nr_samochodu = i + 1;
				s[i].wczytaj();
				s[i].wyswietl();
			}
			break;
		case '3':
			for (int i = 0; i <= ilosc_samochodow; i++)
			{
				s[i].nr_samochodu = i + 1;
				s[i].wczytaj();
				s[i].wyswietl_warunkowo();
			}
			break;
		case '4':
			s[1].wyswietl_pojedynczo();
			break;
		case '5':
			s[1].sortuj();
			break;
		case '6':
			s[1].usun();
			ilosc_samochodow--;
			break;
		case '7':
			exit(0);
			break;
		default:
			cout << "Nie ma takiej opcji w menu." << endl;
			break;
		}
	}
	system("pause");
}
