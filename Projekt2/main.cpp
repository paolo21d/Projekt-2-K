//Autor Krzysztof Gorlach
// Projekt 2 - hypernimy, hiponimy i synonimy - czyli epopeja na temat słownictwa.

#include <iostream>
#include <string>
#include <limits>

#include "Vertex.h"
#include "Drzewo.h"
using namespace std;

int main() {
	int opcja;
	string word;
	string nadrzedny;
	string synonim;

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
		cout << "7 Usun slowo" << endl;
		cout << "0 Zakoncz program" << endl;
		while (!(cin >> opcja)) {
			cout << endl << "Blad wprowadzania! Podaj odpowiedni numer z menu ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cin.clear();
		cin.ignore(1024, '\n');
		if (opcja == 1) { //dodaj podrzedne
			cout << "Podaj slowo nadrzedne: ";
			//cin >> nadrzedny;
			getline(cin, nadrzedny);
			cout << "Podaj slowo ktore chcesz dodac: ";
			//cin >> word;
			getline(cin, word);
			if (!drzewo.dodajWierzcholek(nadrzedny, word)) {
				cout << "Blad!"<<endl;
				continue;
			}
			else
				cout << "Dodano slowo: " << word << endl;
		}
		else if (opcja == 2) { //dodaj synonim
			cout << "Podaj slowo ktoremu chcesz dodac synonim: ";
			//cin >> word;
			getline(cin, word);
			cout << "Podaj synonim: ";
			//cin >> synonim;
			getline(cin, synonim);
			if (!drzewo.dodajSynonim(word, synonim)) {
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
			//cin >> word;
			getline(cin, word);
			if (!drzewo.wypiszSynonimy(word))
				cout << "Blad!" << endl;
		}
		else if (opcja == 5) { //wypisz nadrzedne
			cout << "Podaj slowo ktorego hypernimu szukasz: ";
			//cin >> word;
			getline(cin, word);
			cout << endl;
			if (!drzewo.wypiszHipernim(word))
				cout << "Blad!" << endl;
		}
		else if (opcja == 6) { //wypisz podrzedne
			cout << "Podaj slowo ktorego hiponimow szukasz: ";
			//cin >> word;
			getline(cin, word);
			cout << endl;
			if (!drzewo.wypiszPodrzedne(word))
				cout << "Blad!" << endl;
		}
		else if (opcja == 7) {
			cout << "Podaj slowo ktore chcesz usunac: ";
			getline(cin, word);
			cout << endl;
			if (!drzewo.usunWierzcholek(word))
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