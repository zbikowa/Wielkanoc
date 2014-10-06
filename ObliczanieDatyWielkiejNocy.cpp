//============================================================================
// Name        : ObliczanieDatyWielkiejNocy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;
static int x, y;

void pobierz_rok(int rok) {
	if (rok >= 1 && rok <= 1582) {
		x = 15;
		y = 16;
	} else if (rok >= 1583 && rok <= 1699) {
		x = 22;
		y = 2;
	} else if (rok >= 1700 && rok <= 1799) {
		x = 23;
		y = 3;
	} else if (rok >= 1800 && rok <= 1899) {
		x = 23;
		y = 4;
	} else if (rok >= 1900 && rok <= 2099) {
		x = 24;
		y = 5;
	} else if (rok >= 2100 && rok <= 2199) {
		x = 24;
		y = 6;
	} else {
		cout << "Nieprawidlowy rok. " << endl;
		exit(0);
	}
}
void wynik(int f, int d) {
	int wielkanoc;
	if (f == 6 && d == 29)
		cout << "Wielkanoc jest 26 kwietnia." << endl;
	else if (f == 6 && d == 28 && ((11 * x + 11) % 30 < 19))
		cout << "Wielkanoc jest 18 kwietnia." << endl;
	else if ((d + f) < 10) {
		wielkanoc = (22 + d + f);
		cout << "Wielkanoc jest " << wielkanoc << " marca." << endl;
	} else if ((d + f) > 9) {
		wielkanoc = (d + f - 9);
		cout << "Wielkanoc jest " << wielkanoc << " kwietnia." << endl;
	}
}

int main() {
	int rok, a, b, c, d, f;
	char powtorzyc = 't';

	cout << "Program do obliczania dnia wielkanocy." << endl;

	do {
		cout << "Podaj rok (1-2199):" << endl;
		cin >> rok;
		pobierz_rok(rok);

		a = rok % 19;
		b = rok % 4;
		c = rok % 7;
		d = (19 * a + x) % 30;
		f = (2 * b + 4 * c + 6 * d + y) % 7;

		wynik(f, d);
		cout << "Chcesz obliczyc jeszcze raz? [t/n]" << endl;
		cin >> powtorzyc;
	} while (powtorzyc == 't');
	cout << "Koniec programu." << endl;
	return 0;
}
