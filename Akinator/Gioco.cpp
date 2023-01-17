#include "Gioco.h"
#include<iostream>
#include<fstream>
using namespace std;


void Gioco::Play() {

	NodoAlbero* aux = tree.getR();	// Puntatore ausiliario sulla radice.

	bool end = false;	// Nodi foglia
	string answer;  // Risposta dell'utente, si o no 


	while (!end) 
	{
		if (aux->getLeft() == NULL && aux->getRight() == NULL) {
			end = true;	// Fine albero
		}
		else 
		{
			// Domanda 
			cout << "\n\n" << aux->getInfo() << " (si/no)" << "\nRisposta: ";
			cin >> answer;

			if (answer != "si" && answer != "no")	// Syntax error
				cout << "Risposta non accettata riprovare";

			if (answer == "si")	// Left
				aux = aux->getLeft();
			

			if (answer == "no")	// Right
				aux = aux->getRight();
		}

	}

	cout << "\nAnimale pensato: " <<  aux->getInfo();	// Check
	cout << "\nE' l'animale che pensavi? (si/no)\nRisposta: ";

	do
	{
		cin >> answer;

		if (answer == "si")	// Exit door
		{
			victory = true; // Victory PC
			UpdateClassifica();
			return;
		}

		if (answer == "no") {	// Add animal
			string question, animal, oldAn;

			cout << "Qual è la caratteristica del tuo animale?\nCaratteristica: ";
			cin >> question;

			cout << "A che animale pensavi?\nAnimale: ";
			cin >> animal;

			oldAn = aux->getInfo();
			aux->setInfo(question);

			NodoAlbero* Si = new NodoAlbero(animal);
			NodoAlbero* No = new NodoAlbero(oldAn);

			aux->setLeft(Si);
			aux->setRight(No);

			victory = false; // Victory user

			UpdateClassifica();

		}

	} while (answer != "si" && answer != "no");


}

/*
Gioco::Gioco(NodoAlbero* p) {

	cout << "\n Inserire nome player: ";
	cin >> namePlayer;

	SaveAllPlayers();



	R = new NodoAlbero("\n\n\nE' un vertebrato?");
	p = R;

	NodoAlbero* right = new NodoAlbero("E' un mollusco?");
	R->setRight(right);

	NodoAlbero* left = new NodoAlbero("E'un mammifero");
	R->setLeft(left);
}*/

Gioco::Gioco() {
	
	cout << "Inserire nome del giocatore: ";
	cin >> namePlayer;
	SaveAllPlayers();
}

void Gioco::Game(){

	if (tree.isEmpty()) {
		PlayFromZero();
		Play();
	}
	else {
		Play();
	}

}

void Gioco::PlayFromZero(){

	NodoAlbero* seme = new NodoAlbero("Mammifero?");
	NodoAlbero* left = new NodoAlbero("Mucca");	// Animal OK
	NodoAlbero* right = new NodoAlbero("Salmone");	// Animal not OK

	/*
	* PREPARO ALBERO
	*/
	seme->setLeft(left);	
	seme->setRight(right);	

	// Set LINK
	tree.setR(seme);
}

void Gioco::setPlayer(string x){
	namePlayer = x;
}

string Gioco::getPlayer(){
	return namePlayer;
}

void Gioco::LoadGameFromFile(){


	ifstream OpenFile;
	OpenFile.open("Akinator.txt", ios::app);
	tree.CaricaDaFileP(OpenFile);

}

void Gioco::SavePlay(){
	ofstream OpenFile;
	OpenFile.open("Akinator.txt", ios::in);
	
	tree.ScriviSuFileP(OpenFile);

	OpenFile.close();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Gioco::SaveAllPlayers(){
	ofstream OpenFile;
	OpenFile.open("AllPlyers.txt", ios::app);
	OpenFile << "\n" << namePlayer;
	OpenFile.close();

}

void Gioco::UpdateClassifica(){
	ofstream OpenFile; // File players Vincenti e file players Perdenti

	if (victory) {
		OpenFile.open("ClassificaPerdenti.txt", ios::app); // SE HA VINTO IL COMPUTER MODIFICO IL FILE DEI GIOCATORI CHE HANNO PERSO
		OpenFile << "\n" << namePlayer;
		OpenFile.close();
	}
	else {
		OpenFile.open("ClassificaVincenti.txt", ios::app);
		OpenFile << "\n" << namePlayer;
		OpenFile.close();
	}
}

void Gioco::ViewAllPlayers(){
	string names, tot;
	ifstream OpenFile("AllPlyers.txt", ios::in);

	while (!OpenFile.eof()) {
		getline(OpenFile, names);
		tot += names + "\n";
	}
	OpenFile.close();

	cout << "\n" << tot << endl;
}

void Gioco::ViewWinnerPlayers(){
	string names, tot;
	ifstream OpenFile("ClassificaVincenti.txt", ios::in);

	while (!OpenFile.eof()) {
		getline(OpenFile, names);
		tot += names + "\n";
	}
	OpenFile.close();

	cout << "\n" << tot << endl;
}

void Gioco::ViewLoserPlayers(){
	string names, tot;
	ifstream OpenFile("ClassificaPerdenti.txt", ios::in);

	while (!OpenFile.eof()) {
		getline(OpenFile, names);
		tot += names + "\n";
	}
	OpenFile.close();

	cout << "\n" << tot << endl;
}
