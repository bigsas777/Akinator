#pragma once
#include <string>

class NodoAlbero{
private:
	std::string info;
	NodoAlbero *right, *left;
public:
	NodoAlbero();
	NodoAlbero(std::string);

	void setInfo(std::string x);
	void setRight(NodoAlbero* r);
	void setLeft(NodoAlbero* l);

	NodoAlbero* getRight();
	NodoAlbero* getLeft();
	std::string getInfo();
};

