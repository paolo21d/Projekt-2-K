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




