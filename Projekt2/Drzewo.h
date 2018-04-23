#pragma once
#include <iostream>
#include <vector>
#include "Vertex.h"
class Drzewo
{
	Vertex* glowa;
	std::vector <Vertex*> listaWierzcholkow;
	
public:
	Drzewo(std::string nazwa);
	~Drzewo();
	Vertex* znajdzWierzcholek(std::string nazwa)const;
	int dodajWierzcholek(std::string nadrzedny, std::string nazwa);
	int dodajSynonim(std::string slowo, std::string synonim);
	void wypiszWszystkieWyrazy() const;
	int wypiszSynonimy(std::string slowo) const;
	int wypiszHipernim(std::string slowo) const;
	int wypiszPodrzedne(std::string slowo) const;
}; 

