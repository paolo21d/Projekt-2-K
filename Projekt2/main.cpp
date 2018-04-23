//Autor Krzysztof Gorlach
// Projekt 2 - hypernimy, hiponimy i synonimy - czyli epopeja na temat s³ownictwa.

#include <iostream>
#include <string>
#include <limits>

#include "Vertex.h"
#include "Drzewo.h"
using namespace std;

int main() {
	int opcja;
	string word, nadrzedny, synonim;
	cout << "Podaj slowo nadrzedne (pierwszy wierzcholek drzewa): ";
	cin >> word;
	Drzewo drzewo(word);
	while (true) {
		cout << "MENU:" << endl;
		cout << "1 Dodaj hiponim (slowo podrzedne)" << endl;
		cout << "2 Dodaj synonim slowa" << endl;
		cout << "3 Wypisz wszystkie slowa" << endl;
		cout << "4 Wypisz synonimy" << endl;
		cout << "5 Wypisz hipernim (slowo nadrzedne)" << endl;
		cout << "6 Wypisz hiponimy (slowa podrzedne)" << endl;
		cout << "0 Zakoncz program" << endl;
		while (!(cin >> opcja)) {
			cout << endl << "Blad wprowadzania! Podaj odpowiedni numer z menu ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (opcja == 1) { //dodaj podrzedne
			cout << "Podaj slowo nadrzedne: ";
			cin >> nadrzedny;
			cout << "Podaj slowo ktore chcesz dodac: ";
			cin >> word;
			if (drzewo.dodajWierzcholek(nadrzedny, word) == 0) {
				cout << "Blad!"<<endl;
				continue;
			}
			else
				cout << "Dodano slowo: " << word << endl;
		}
		else if (opcja == 2) { //dodaj synonim
			cout << "Podaj slowo ktoremu chcesz dodac synonim: ";
			cin >> word;
			cout << "Podaj synonim: ";
			cin >> synonim;
			if (drzewo.dodajSynonim(word, synonim) == 0) {
				cout << "Blad!" << endl;
				continue;
			}
			cout << "Dodano synonim" << endl;
		}
		else if (opcja == 3) { //wypisz wszystkie slowa
			drzewo.wypiszWszystkieWyrazy();
		}
		else if (opcja == 4) { //wypisz synonimy
			cout << "Podaj slowo ktorego synonimy chcesz zobaczyc: ";
			cin >> word;
			if (drzewo.wypiszSynonimy(word) == 0)
				cout << "Blad!" << endl;
		}
		else if (opcja == 5) { //wypisz nadrzedne
			cout << "Podaj slowo ktorego hypernimu szukasz: ";
			cin >> word;
			if (drzewo.wypiszHipernim(word) == 0)
				cout << "Blad!" << endl;
		}
		else if (opcja == 6) { //wypisz podrzedne
			cout << "Podaj slowo ktorego hiponimow szukasz: ";
			cin >> word;
			if (drzewo.wypiszPodrzedne(word) == 0)
				cout << "Blad!" << endl;
		}
		else if (opcja == 0) {
			cout << "KONIEC PROGRAMU." << endl;
			break;
		}
		else {
			cout << "Bledny numer opcji!" << endl;
		}
	}
	return 0;
}