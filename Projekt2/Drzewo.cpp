#include "Drzewo.h"
#include "Vertex.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

Drzewo::Drzewo(string nazwa)
{
	glowa = new Vertex(nazwa);
	listaWierzcholkow.insert(pair<int, Vertex*>(listaWierzcholkow.size(), glowa));
}

Drzewo::~Drzewo()
{
	//delete glowa;
	/*for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
		delete listaWierzcholkow[i];
	}*/
	for (auto i = listaWierzcholkow.begin(); i != listaWierzcholkow.end(); i++)
		delete i->second;
	//for (auto i = listaWierzcholkow.end(); i != listaWierzcholkow.begin(); --i)
	//	delete i->second;
}

//Vertex * Drzewo::znajdzWierzcholek(string nazwa) const
//{
//	for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
//		if (listaWierzcholkow[i]->wyraz == nazwa)
//			return listaWierzcholkow[i];
//		for (unsigned k = 0; k < listaWierzcholkow[i]->synonim.size(); ++k) {
//			if (listaWierzcholkow[i]->synonim[k] == nazwa)
//				return listaWierzcholkow[i];
//		}
//	}
//	return nullptr;
//}
Vertex * Drzewo::znajdzWierzcholek(string nazwa) const
{
	for (auto i=listaWierzcholkow.begin(); i!=listaWierzcholkow.end(); ++i) {
		auto &w = i->second;
		if (w->wyraz == nazwa)
			return w;
		for (unsigned k = 0; k < w->synonim.size(); ++k) {
			if (w->synonim[k] == nazwa)
				return w;
		}
	}
	return nullptr;
}

//bool Drzewo::dodajWierzcholek(string nadrzedne_, string wyraz_)
//{
//	//0-blad, 1-udalo sie
//	Vertex *nadrzedny = znajdzWierzcholek(nadrzedne_);
//	if (nadrzedny == nullptr) { //nie znalaziono ojca!
//		return false;
//	}
//	Vertex *v = new Vertex(wyraz_);
//	if (v == nullptr) {
//		return true;
//	}
//	v->ojciec = nadrzedny;
//	listaWierzcholkow.push_back(v);
//	nadrzedny->dzieci.push_back(v);
//	return 1;
//}
bool Drzewo::dodajWierzcholek(string nadrzedne_, string wyraz_)
{
	//0-blad, 1-udalo sie
	Vertex *nadrzedny = znajdzWierzcholek(nadrzedne_);
	if (nadrzedny == nullptr) { //nie znalaziono ojca!
		return false;
	}
	Vertex *v = new Vertex(wyraz_);
	if (v == nullptr) {
		return true;
	}
	v->ojciec = nadrzedny;
	//nadrzedny->dzieci.push_back(v);
	listaWierzcholkow.insert(pair<int, Vertex*>(listaWierzcholkow.size(), v));
	nadrzedny->dzieci.push_back(v);
	return 1;
}

bool Drzewo::dodajSynonim(string slowo, string synonim)
{
	Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return false;
	v->synonim.push_back(synonim);
	return true;
}

//void Drzewo::wypiszWszystkieWyrazy() const
//{
//	for (unsigned i = 0; i < listaWierzcholkow.size(); ++i) {
//		cout << listaWierzcholkow[i]->wyraz << " ";
//		for (unsigned k = 0; k < listaWierzcholkow[i]->synonim.size(); ++k) {
//			cout << listaWierzcholkow[i]->synonim[k] << " ";
//		}
//		cout << endl;
//	}
//}
void Drzewo::wypiszWszystkieWyrazy() const
{
	for (auto i=listaWierzcholkow.begin(); i !=listaWierzcholkow.end(); ++i) {
		auto &w = i->second;
		if (i->second == nullptr) continue;
		cout << w->wyraz << " ";
		for (unsigned k = 0; k < w->synonim.size(); ++k) {
			cout << w->synonim[k] << " ";
		}
		cout << endl;
	}
}

bool Drzewo::wypiszSynonimy(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return false;
	cout << v->wyraz << " ";
	for (unsigned i = 0; i < v->synonim.size(); ++i)
		cout << v->synonim[i] << " ";
	cout << endl;
	return true;
}

bool Drzewo::wypiszHipernim(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return false;
	if (v->ojciec == nullptr)
		return false;
	cout << v->ojciec->wyraz << endl;
	return true;
}

bool Drzewo::wypiszPodrzedne(string slowo) const
{
	const Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr)
		return false;
	if (v->dzieci.size() == 0)
		return false;
	for (unsigned i = 0; i < v->dzieci.size(); ++i)
		cout << v->dzieci[i]->wyraz << " ";
	return true;
}

bool Drzewo::usunWierzcholek(std::string slowo)
{
	Vertex *v = znajdzWierzcholek(slowo);
	if (v == nullptr || v==glowa)
		return false;
	for (auto i = listaWierzcholkow.begin(); i != listaWierzcholkow.end(); ++i) {
		if (i->second == v) {
			delete i->second;
			listaWierzcholkow.erase(listaWierzcholkow.find(i->first));
			break;
		}
	}
	/*for (auto i = listaWierzcholkow.begin(); i != listaWierzcholkow.end(); ++i) {
		if (i->second == nullptr) {
			listaWierzcholkow.erase(i);
		}
	}*/
	return true;
}