#pragma once
#include "NodoAlbero.h"
#include <string>
using namespace std;
class Albero{
private:
	NodoAlbero* R;
	//string Parentetica(NodoAlbero* p);
	void Preorder(NodoAlbero* p);
	void Inorder(NodoAlbero* p);
	void Postorder(NodoAlbero* p);
	NodoAlbero* AggiungiABR(NodoAlbero* p, string x);
	//int Profondita(NodoAlbero* p);
	//int NumNodi(NodoAlbero* p);
	//int NumFoglie(NodoAlbero* p);

	//void ScriviSuFile(NodoAlbero* p);
	//void CaricaDaFile(NodoAlbero* p);
	void SaveTree(NodoAlbero* a, ofstream& f);

	NodoAlbero* ChargeTree(ifstream& f);
public:
	Albero();
	Albero(NodoAlbero* r) { this->R = r; };

	void InitAlbero() { R = NULL; }
	bool isEmpty() { return R == NULL; }
	//string Parentetica(NodoAlbero* p);
	void PreorderP(NodoAlbero* p) { Preorder(R); }
	void InorderP(NodoAlbero* p) { Inorder(R); }
	void PostorderP(NodoAlbero* p) { Postorder(R); }
	NodoAlbero* AggiungiABRP(NodoAlbero* p, string x) { R = AggiungiABR(R, x); }
	//int Profondita(NodoAlbero* p);
	//int NumNodi(NodoAlbero* p);
	//int NumFoglie(NodoAlbero* p);

	NodoAlbero* getR() { return R; };
	void setR(NodoAlbero* x) { R = x; };

	bool Check(NodoAlbero* p) { return p->getLeft() == NULL; };

	void ScriviSuFileP(ofstream& f);
	void CaricaDaFileP(ifstream& f);


};

