#include "NodoAlbero.h"

NodoAlbero::NodoAlbero(){
	//info = "";
	right = NULL;
	left = NULL;
}

NodoAlbero::NodoAlbero(std::string x){
	info = x;
	right = NULL;
	left = NULL;
}

void NodoAlbero::setInfo(std::string x){
	info = x;
}

void NodoAlbero::setRight(NodoAlbero* r){
	right = r;
}

void NodoAlbero::setLeft(NodoAlbero* l){
	left = l;
}

NodoAlbero* NodoAlbero::getRight()
{
	return right;
}

NodoAlbero* NodoAlbero::getLeft()
{
	return left;
}

std::string NodoAlbero::getInfo()
{
	return info;
}
