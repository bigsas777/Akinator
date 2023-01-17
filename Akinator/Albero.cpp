#include "Albero.h"
#include<iostream>
#include<fstream>
using namespace std;


void Albero::SaveTree(NodoAlbero* a, ofstream& f){
	
	if (a != NULL) {
		f << a->getInfo() << endl;

		SaveTree(a->getLeft(), f);
		if (a->getLeft() == NULL)
			f << "<" << endl;

		SaveTree(a->getRight(), f);
		if (a->getRight() == NULL)
			f << ">" << endl;
	}
}

NodoAlbero* Albero::ChargeTree(ifstream& f){
	
	string info;
	//fflush(stdin);
	getline(f, info);
	NodoAlbero* fistNode = new NodoAlbero(info);

	if (!f.eof()) {
		
		if (info == "<" || info == ">")
			return 0;

		fistNode->setLeft(ChargeTree(f));
		fistNode->setRight(ChargeTree(f));
	}

	return fistNode;
}

Albero::Albero(){
	R = NULL;
}

void Albero::ScriviSuFileP(ofstream& f){
	SaveTree(R, f);
	f.close();
}

void Albero::CaricaDaFileP(ifstream& f) { R = ChargeTree(f); }



void Albero::Preorder(NodoAlbero* p){
	if (p != 0) {
		cout << p->getInfo() <<" ";
		Preorder(p->getLeft());
		Preorder(p->getRight());
	}
}

void Albero::Inorder(NodoAlbero* p){
	if (p != 0) {
		Inorder(p->getLeft());
		cout << p->getInfo() << " ";
		Inorder(p->getRight());
	}
}

void Albero::Postorder(NodoAlbero* p){
	if (p != 0) {
		Postorder(p->getLeft());
		Postorder(p->getRight());
		cout << p->getInfo() << " ";
	}
}

NodoAlbero* Albero::AggiungiABR(NodoAlbero* p, string x){
	if (p == 0) {
		p = new NodoAlbero(x);
		return p;
	}
	else {
		if (x > p->getInfo())
			p->setRight(AggiungiABR(p->getRight(), x));
		else
			p->setLeft(AggiungiABR(p->getLeft(), x));
	}
	return p;
}
