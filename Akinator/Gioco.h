#pragma once
#include"Albero.h";
#include<string>
using namespace std;
class Gioco{
private:
	Albero tree;
	string namePlayer;
	bool victory;

public:

	Gioco();

	void Game();
	
	void PlayFromZero();
	void Play();

	void setPlayer(string);
	string getPlayer();



	void LoadGameFromFile();
	void SavePlay();

	void SaveAllPlayers();
	void UpdateClassifica();

	void ViewAllPlayers();
	void ViewWinnerPlayers();
	void ViewLoserPlayers();

};

