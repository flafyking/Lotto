#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <stdlib.h>

using namespace std;

int * tLosowane;

bool Sprawdzanie(int ileLiczb, int liczba)
{
	for (int i = 0; i < ileLiczb; i++)
	{
		if (liczba == tLosowane[i])
		{
			return false;
		}
	}
	return true;
}
int Porownaj()
{
	return 0;
}
int Wypisz(int ileLiczb)
{
	for (int i = 0; i < ileLiczb; i++)
	{
		cout << "Wylosowano: " << tLosowane[i] << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return 0;
}
int Losuj(int ileLiczb) 
{
	int liczba;
	bool test=false;
	srand(time(NULL));
	


	for (int i = 0; i < ileLiczb; i++)
	{
		liczba = rand() % 49 + 1;
		if (Sprawdzanie(i, liczba) == false)
		{
			i--;
		}
		else
		{
			tLosowane[i] = liczba;
		}
	}



	return 0;
}

int main()
{
	int ileLiczb = 0;
	string zmienna;
	bool wynik = true;
	do
	{
		cout << "Ile liczb chcesz losowac? (7 - 12): " << endl;
		cin >> zmienna;
	
		wynik = true;
		for (int i=0; i < zmienna.length(); i++)
		{
			if ((int)zmienna[i] < 48 || (int)zmienna[i] > 57)
				wynik = false;
		}
		if (wynik == true)
			ileLiczb = atoi(zmienna.c_str());

	} while (wynik == false || ileLiczb < 6 || ileLiczb > 12);
	ileLiczb = atoi(zmienna.c_str());

	tLosowane = new int[ileLiczb];
	Losuj(ileLiczb);
	Wypisz(ileLiczb);
	delete[] tLosowane;

}