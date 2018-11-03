#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;

Game::Game() 
{
	cout << "WELCOME TO THE GAME OF RISK, YOUR GAME HAS BEEN STARTED" << endl;
	gameOver = false; // game is obviously not over, it has just started
	setup();
	placeInitialArmies();
}

void Game::setup()
{
	setNumberOfPlayers();
	// second thing, load map
	//if (isMapValid()) {
	//	assignCountries();
	//}
	//else
	//{
	//	cout << "Critical Error: Map is invalid" << endl;
	//}
}

void Game::setNumberOfPlayers()
{
	int MAX_PLAYERS = 6;
	int numberOfPlayers;
	int armyAllocation;
	cout << "How many players are in the game? There is a maximum of 6. " << endl;
	cin >> numberOfPlayers;

	//keep searching
	while (numberOfPlayers < 2 || numberOfPlayers > MAX_PLAYERS || cin.fail())
	{
		cout << "INVALID ENTRY - Please enter an integer between 2 and 6: " << endl;
		cin >> numberOfPlayers;
	}
	cout << endl;
	//determine the number of armies they get to place
	switch (numberOfPlayers) 
	{
	case 2:
		armyAllocation = 40;
		break;
	case 3:
		armyAllocation = 35;
		break;
	case 4:
		armyAllocation = 30;
		break;
	case 5:
		armyAllocation = 25;
		break;
	case 6:
		armyAllocation = 20;
		break;
	}
	string name;
	// create our players
	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << "PLEASE ENTER NAME OF PLAYER " << i << ": ";
		cout << endl;
		cin >> name;
		Player* currentPlayer = new Player(name, armyAllocation);
		players.push_back(currentPlayer);
	}

	// introduce the players
	cout << "We have " << numberOfPlayers << " players battling it out! Here they are: " << endl;
	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << i << ") " << players[i]->getName() << endl;
	}
	cout << "Welcome to the game, and may the odds be in your favor!" << endl << endl;
}

void Game::assignCountries()
{
	vector<Country*> countries = worldMap->GetAllCountries();


	//we want to assign them
	for (int i = 0; i < countries.size(); i++)
	{
		players[i % players.size()]->addCountry(countries[i]);
		countries[i]->setOwner(players[i % players.size()]);
	}

	// show them now
	for (int i = 0; i < players.size(); i++)
	{
		cout << "Player " << players[i]->getName() << "owns the following countries: " << endl;
		int sizeOfCountriesList = players[i]->getCountries().size();
		for (int j = 0; j <sizeOfCountriesList; j++) 
		{
			cout << "Country named " << players[i]->getCountries()[j]->getCountryName() << "in continent" << players[i]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
		cout << endl;
	}
}

void Game::placeInitialArmies() 
{
	int numberOfInitialArmiesLeft = players[0]->getArmies();
	bool allArmiesAllocated = false;
	while (!allArmiesAllocated) {
		assignOneRound();
		numberOfInitialArmiesLeft--;
		if (numberOfInitialArmiesLeft == 0) {
			allArmiesAllocated = true;
		}
	}
}

void Game::assignOneRound() 
{
	string choice;
	for (int i = 0; i < players.size(); i++)
	{
		cout << "It is Player" << i << "'s, " << players[i]->getName() << ",  turn to assign an army to a country" << endl;
		cout << "Here are your choices: " << endl;
		int sizeOfCountriesList = players[i]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << "Country named " << players[i]->getCountries()[j]->getCountryName() << "in continent" << players[i]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
		cout << "Enter the name of the country to add an army to it" << endl;
		cin >> choice;
		players[i]->getCountry(choice)->addArmy();
		players[i]->removeAnArmy();
	}
}

void Game::attackPhase(int attackerPlayerNum)
{
	string attackPhaseInputString;
	bool isAttackPhase;
	cout << "=============";
	cout << "ATTACK PHASE";
	cout << "=============";
	cout << "Player " + attackerPlayerNum;
	cout << " Do you want to attack? y/n" << endl;
	cin >> attackPhaseInputString;

	if (attackPhaseInputString.compare("y") || attackPhaseInputString.compare("yes")) {
		isAttackPhase = true;
	}
	else {
		isAttackPhase = false;
	}

	while (isAttackPhase) {
		string countrySelectedIn;
		int neighborSelectedIndex;
		Country* countrySelected;
		int attackerNumberOfArmy;
		int defenderNumberOfArmy;
		int attNumDices;
		int defNumDices;
		vector<int> attDicesRolled;
		vector<int> deffDicesRolled;
		vector<Country*> ListOfneighbors;
		Player* neighborPlayer;
		bool countryNotEnoughArmy = true;
		
		//Player selects a owned country
		while (countryNotEnoughArmy) {
			cout << "Please select one of your own countries" << endl;
			cin >> countrySelectedIn;
			countrySelected = (players[attackerPlayerNum]->getCountry(countrySelectedIn));

			if (players[attackerPlayerNum]->getCountry(countrySelected->getCountryName)->getNumberOfArmies() < 2)
			{
				cout << "You do not have enough armies in the region to attack! Must have atleast 2. Try Again";
			}
			else {
				countryNotEnoughArmy = false;
			}
		}

		//Display all neighbors of the selected country and player chooses neighbor to attack
		cout << "\nPlease select any neighboring country (choose a number)" << endl;
		ListOfneighbors = countrySelected->getNeighbors;
		for(int i = 0; i < ListOfneighbors.size(); i++)
		{	
			cout << i + " - ";
			cout << ListOfneighbors[i]->getCountryName << endl;
		}
		cin >> neighborSelectedIndex;

		//Roll correct number of dices
		Player* neighborPlayer = ListOfneighbors[neighborSelectedIndex]->getOwner();
		attackerNumberOfArmy = players[attackerPlayerNum]->getCountry(countrySelected->getCountryName)->getNumberOfArmies();
		defenderNumberOfArmy = neighborPlayer->getCountry(ListOfneighbors[neighborSelectedIndex]->getCountryName)->getNumberOfArmies();
		if (attackerNumberOfArmy == 2)
		{
			attNumDices = 1;
			cout << "\n ATTACKER - Your country has only 2 armies. You will throw 1 dice only" << endl;
			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (attackerNumberOfArmy == 3)
		{
			do {
				cout << "\n ATTACKER - The country has 3 armies. You can throw 1 or 2 dices" << endl;
				cin >> attNumDices;
			} while (attNumDices == 1 && attNumDices == 2);
			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (attackerNumberOfArmy > 3)
		{
			do {
				cout << "\n ATTACKER - The country has a lot armies. You can throw 1, 2 or 3 dices" << endl;
				cin >> attNumDices;
			} while (attNumDices >= 1 && attNumDices <= 3);
			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (defenderNumberOfArmy == 1) {
			defNumDices = 1;
			cout << "\n DEFENDER - You will roll 1 dice" << endl;
			deffDicesRolled = neighborPlayer->rollDice(defNumDices);
		}
		if (defenderNumberOfArmy >= 2) {
			do { 
				cout << "\n DEFENDER - please select 1 or 2 dices" << endl; 
				cin >> defNumDices;
			} while (defNumDices >= 1 && defNumDices <= 2);
			deffDicesRolled = neighborPlayer->rollDice(defNumDices);
		}

		//compareRolls(defNumDices, deffDicesRolled, att);

		
		////// TEMP ////
		cout << "Player " << players[attackerPlayerNum]->getName() << "owns the following countries: " << endl;
		int sizeOfCountriesList = players[attackerPlayerNum]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << "Country named " << players[attackerPlayerNum]->getCountries()[j]->getCountryName() << "in continent" << players[attackerPlayerNum]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
		cout << endl;
		///// TEMP ////
	}
} 

vector<int> compareThrownDices(int* defNumOfDices, int* attNumOfDices, vector<int>* attDicesRolled, vector<int>* deffDicesRolled) {
vector<int> diceNumberCount[3];

//for (attDicesRolled)

}