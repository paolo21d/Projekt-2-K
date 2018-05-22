#ifndef CWIERZCHOLEK_H
#define CWIERZCHOLEK_H

#include <vector>
#include <string>
class Vertex
{
	std::string wyraz;
	Vertex *ojciec;
	std::vector <Vertex*> dzieci;
	std::vector <std::string> synonim;
public:
	friend class Drzewo;

	Vertex(std::string wyraz_, std::string synonim_);
	Vertex(std::string wyraz_);
	~Vertex();
	
};

#endif // !CWIERZCHOLEK_H