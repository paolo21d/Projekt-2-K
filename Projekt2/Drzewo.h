#ifndef DRZEWO_H
#define DRZEWO_H

#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"
class Drzewo
{
	Vertex* glowa;
	//std::vector <Vertex*> listaWierzcholkow;
	std::map <int, Vertex*> listaWierzcholkow;
	Vertex* znajdzWierzcholek(std::string nazwa)const;

public:
	Drzewo(std::string nazwa);
	~Drzewo();
	bool dodajWierzcholek(std::string nadrzedny, std::string nazwa);
	bool dodajSynonim(std::string slowo, std::string synonim);
	void wypiszWszystkieWyrazy() const;
	bool wypiszSynonimy(std::string slowo) const;
	bool wypiszHipernim(std::string slowo) const;
	bool wypiszPodrzedne(std::string slowo) const;
	bool usunWierzcholek(std::string slowo);
}; 

#endif // !DRZEWO_H