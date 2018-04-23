#include "Drzewo.h"
#include "Vertex.h"
#include <iostream>
#include <vector>
using namespace std;

Drzewo::Drzewo(string nazwa)
{
	glowa = new Vertex(nazwa);
	listaWierzcholkow.push_back(glowa);
}

Drzewo::~Drzewo()
{
	//delete glowa;
	for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
		delete listaWierzcholkow[i];
	}
}

Vertex * Drzewo::znajdzWierzcholek(string nazwa) const
{
	for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
		if (listaWierzcholkow[i]->getWyraz() == nazwa)
			return listaWierzcholkow[i];
		for (unsigned k = 0; k < listaWierzcholkow[i]->synonim.size(); ++k) {
			if (listaWierzcholkow[i]->synonim[k] == nazwa)
				return listaWierzcholkow[i];
		}
	}
	return nullptr;
}

int Drzewo::dodajWierzcholek(string nadrzedne_, string wyraz_)
{
	//0-blad, 1-udalo sie
	Vertex *nadrzedny = znajdzWierzcholek(nadrzedne_);
	if (nadrzedny == nullptr) { //nie znalaziono ojca!
		return 0;
	}
	Vertex *v = new Vertex(wyraz_);
	if (v == nullptr) {
		return 0;
	}
	v->ojciec = nadrzedny;
	listaWierzcholkow.push_back(v);
	nadrzedny->dzieci.push_back(v);
	return 1;
}

int Drzewo::dodajSynonim(string slowo, string synonim)
{
	Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return 0;
	v->synonim.push_back(synonim);
	return 1;
}

void Drzewo::wypiszWszystkieWyrazy() const
{
	for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
		cout << listaWierzcholkow[i]->getWyraz() << " ";
		for (unsigned k = 0; k < listaWierzcholkow[i]->synonim.size(); ++k) {
			cout << listaWierzcholkow[i]->synonim[k] << " ";
		}
		cout << endl;
	}
}

int Drzewo::wypiszSynonimy(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return 0;
	cout << v->getWyraz() << " ";
	for (unsigned i = 0; i < v->synonim.size(); ++i)
		cout << v->synonim[i] << " ";
	cout << endl;
	return 1;
}

int Drzewo::wypiszHipernim(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return 0;
	if (v->ojciec == nullptr)
		return 0;
	cout << v->ojciec->getWyraz() << endl;
	return 1;
}

int Drzewo::wypiszPodrzedne(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return 0;
	if (v->dzieci.size() == 0)
		return 0;
	for (unsigned i = 0; i < v->dzieci.size(); ++i)
		cout << v->dzieci[i]->getWyraz() << " ";
	return 1;
}
