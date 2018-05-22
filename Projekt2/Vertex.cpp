#include "Vertex.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


Vertex::Vertex(std::string wyraz_, std::string synonim_)
{
	wyraz = wyraz_;
	synonim.push_back(synonim_);
}

Vertex::Vertex(std::string wyraz_)
{
	wyraz = wyraz_;
	ojciec = nullptr;
}


Vertex::~Vertex()
{
	/*for (unsigned i = 0; i < dzieci.size(); ++i) {
		delete dzieci[i];
	}
	for (unsigned i = 0; i < ojciec->dzieci.size(); ++i) {
		if (ojciec->dzieci[i] == this) {
			ojciec->dzieci.erase(ojciec->dzieci.begin() + i);
			break;
		}
	}*/
	for (unsigned i = 0; i < dzieci.size(); ++i) {
		dzieci[i]->ojciec = ojciec;
		ojciec->dzieci.push_back(dzieci[i]);
	}
	for (unsigned i = 0; i < ojciec->dzieci.size(); ++i) {
		if (ojciec->dzieci[i] == this) {
			ojciec->dzieci.erase(ojciec->dzieci.begin() + i);
			break;
		}
	}
}

