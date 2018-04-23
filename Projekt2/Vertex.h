#pragma once
#include <vector>
#include <string>
class Vertex
{
	std::string wyraz;
	
public:
	Vertex *ojciec;
	std::vector <Vertex*> dzieci;
	std::vector <std::string> synonim;

	Vertex(std::string wyraz_, std::string synonim_);
	Vertex(std::string wyraz_);
	
	std::string getWyraz()const;
};

