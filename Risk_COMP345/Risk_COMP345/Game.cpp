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