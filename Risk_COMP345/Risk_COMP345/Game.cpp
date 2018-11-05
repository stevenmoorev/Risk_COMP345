#include <iostream>
#include <vector>
#include "Game.h"
#include "MapLoader.h"

using namespace std;

Game::Game() 
{
	cout << "WELCOME TO THE GAME OF RISK, YOUR GAME HAS BEEN STARTED" << endl;
	gameOver = false; // game is obviously not over, it has just started
	setup();
	//placeInitialArmies();
}

Game::Game(Map* newMap)
{
	cout << "WELCOME TO THE GAME OF RISK, YOUR GAME HAS BEEN STARTED" << endl;
	gameOver = false; // game is obviously not over, it has just started
	//setup();
	worldMap = newMap;
	//placeInitialArmies();
}

void Game::setup()
{
	setNumberOfPlayers();
    chooseMap();
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
        {
            armyAllocation = 40;
            Player* player1;
            Player* player2;
            player1 = new Player(armyAllocation);
            player1->setName();
            player2 = new Player(armyAllocation);
            player2->setName();
            players.push_back(player1);
            players.push_back(player2);
            break;
        }
        case 3:
        {
            armyAllocation = 35;
            Player* player1;
            Player* player2;
            Player* player3;
            player1 = new Player(armyAllocation);
            player1->setName();
            players.push_back(player1);
            player2 = new Player(armyAllocation);
            player2->setName();
            player3 = new Player(armyAllocation);
            player3->setName();
            players.push_back(player2);
            players.push_back(player3);
            break;
        }
        case 4:
        {
            armyAllocation = 30;
            Player* player1;
            player1 = new Player(armyAllocation);
            player1->setName();
            players.push_back(player1);
            Player* player2;
            player2 = new Player(armyAllocation);
            player2->setName();
            players.push_back(player2);
            Player* player3;
            player3 = new Player(armyAllocation);
            player3->setName();
            players.push_back(player3);
            Player* player4;
            player4 = new Player(armyAllocation);
            player4->setName();
            players.push_back(player4);
            break;
        }
        case 5:
        {
            armyAllocation = 25;
            Player* player1;
            player1 = new Player(armyAllocation);
            player1->setName();
            players.push_back(player1);
            Player* player2;
            player2 = new Player(armyAllocation);
            player2->setName();
            players.push_back(player2);
            Player* player3;
            player3 = new Player(armyAllocation);
            player3->setName();
            players.push_back(player3);
            Player* player4;
            player4 = new Player(armyAllocation);
            player4->setName();
            players.push_back(player4);
            Player* player5;
            player5 = new Player(armyAllocation);
            player5->setName();
            players.push_back(player5);
            break;
        }
        case 6:
        {
            armyAllocation = 20;
            Player* player1;
            player1 = new Player(armyAllocation);
            player1->setName();
            players.push_back(player1);
            Player* player2;
            player2 = new Player(armyAllocation);
            player2->setName();
            players.push_back(player2);
            Player* player3;
            player3 = new Player(armyAllocation);
            player3->setName();
            players.push_back(player3);
            Player* player4;
            player4 = new Player(armyAllocation);
            player4->setName();
            players.push_back(player4);
            Player* player5;
            player5 = new Player(armyAllocation);
            player5->setName();
            players.push_back(player5);
            Player* player6;
            player6 = new Player(armyAllocation);
            player6->setName();
            players.push_back(player6);
            break;
        }
    }
    
    
    // introduce the players
    cout << "We have " << numberOfPlayers << " players battling it out! Here they are: " << endl;
    for (int i = 0; i < numberOfPlayers; i++)
    {
        cout << i+1 << ") " << players[i]->getName() << endl;
    }
    cout << "Welcome to the game, and may the odds be in your favor!" << endl << endl;
}


void Game::assignCountries(){
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

void Game::placeInitialArmies() {
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
		vector<int> defDicesRolled;
		vector<Country*> ListOfneighbors;
		Player* neighborPlayer;
		Country * attackerCountry;
		Country * defenderCountry;
		bool countryNotEnoughArmy = true;
		
		//Player selects a owned country
		while (countryNotEnoughArmy) {

			cout << "Please select one of your own countries, type the exact name" << endl;
			cin >> countrySelectedIn;
			countrySelected = (players[attackerPlayerNum]->getCountry(countrySelectedIn));
            int j = countrySelected->getNumberOfArmies();
			if (j < 2)
			{
				cout << "You do not have enough armies in the region to attack! Must have atleast 2. Try Again";
			}
			else {
				countryNotEnoughArmy = false;
			}
		}

		//Display all neighbors of the selected country and player chooses neighbor to attack
		cout << "\nPlease select any neighboring country (choose a number)" << endl;
		ListOfneighbors = countrySelected->getNeighbors();
		for(int i = 0; i < ListOfneighbors.size(); i++)
		{	
			cout << i << " - ";

			cout << ListOfneighbors[i]->getCountryName() << endl;
		}
		cin >> neighborSelectedIndex;

		//Roll correct number of dices to attack selected neighbor country
		attackerCountry = players[attackerPlayerNum]->getCountry(countrySelected->getCountryName());
		defenderCountry = (ListOfneighbors[neighborSelectedIndex]->getOwner())->getCountry(countrySelected->getCountryName());
		neighborPlayer = ListOfneighbors[neighborSelectedIndex]->getOwner();

		attackerNumberOfArmy = attackerCountry->getNumberOfArmies();
		defenderNumberOfArmy = defenderCountry->getNumberOfArmies();
		if (attackerNumberOfArmy == 2)
		{
			attNumDices = 1;
			cout << "\n ATTACKER - Your country has only 2 armies. You will throw 1 dice only" << endl;
			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (attackerNumberOfArmy == 3)
		{
			do {
				cout << "\n ATTACKER - The country has 3 armies. Choose to throw 1 or 2 dices" << endl;
				cin >> attNumDices;

			} while (attNumDices == 1 && attNumDices == 2);

			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (attackerNumberOfArmy > 3)
		{
			do {
				cout << "\n ATTACKER - The country has a lot armies. Choose to throw 1, 2 or 3 dices" << endl;
				cin >> attNumDices;

			} while (attNumDices >= 1 && attNumDices <= 3);

			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (defenderNumberOfArmy == 1) {
			defNumDices = 1;
			cout << "\n DEFENDER - You will roll 1 dice" << endl;
			defDicesRolled = neighborPlayer->rollDice(defNumDices);
		}
		if (defenderNumberOfArmy >= 2) {
			do { 
				cout << "\n DEFENDER - please select 1 or 2 dices" << endl; 
				cin >> defNumDices;

			} while (defNumDices >= 1 && defNumDices <= 2);

			defDicesRolled = neighborPlayer->rollDice(defNumDices);
		}

		//Remove defender armies and attacker armies
		int defendersEliminated = compareThrownDicesDef(attDicesRolled, defDicesRolled);
		defenderCountry->removeArmy(defendersEliminated);
		cout << "Attacker has eliminated " << defendersEliminated << "  defenders" << endl;
		int attackersEliminated = compareThrownDicesDef(attDicesRolled, defDicesRolled);
		attackerCountry->removeArmy(attackersEliminated);
		cout << "Defender has eliminated " << attackersEliminated << "  attackers" << endl;

		//Update number of armies on each of those two country
		attackerNumberOfArmy = attackerCountry->getNumberOfArmies();
		defenderNumberOfArmy = defenderCountry->getNumberOfArmies();

		//Check if neighbor country is fully defeated, if so, then attacker may take over
		if (defenderNumberOfArmy == 0) {
			int moveArmy = 0;
			bool moveArmyCheck = false;
			//Should delete defender pointer to the country defeated - must implement later -
			ListOfneighbors[neighborSelectedIndex]->setOwner(players[attackerPlayerNum]);
			cout << "You have conquered a country! How many units would you like to move from the current to new country (must leave 1 behind)" << endl;
			do {
				cout << "Please enter a correct amount " << endl;
				cout << "Number of armies in current country : " << attackerNumberOfArmy << endl;
				cin >> moveArmy;
				if (moveArmy <= (attackerNumberOfArmy - 1) && moveArmy > 0)
				{
					attackerCountry->removeArmy(moveArmy);
					players[attackerPlayerNum]->addCountry(ListOfneighbors[neighborSelectedIndex]);
					ListOfneighbors[neighborSelectedIndex]->addMovedArmy(moveArmy);

					cout << "\nYou moved " << moveArmy << " units to " << ListOfneighbors[neighborSelectedIndex]->getCountryName() << endl;

					moveArmyCheck = true;
				}
			} while (!moveArmyCheck);

			cout << "\nAttacking phase done!" << endl;
			isAttackPhase = false;
		}
		else {
			cout << "\nWould you like to attack again? y/n" << endl;
			cin >> attackPhaseInputString;
			if (attackPhaseInputString.compare("y") || attackPhaseInputString.compare("yes")) {
				isAttackPhase = true;
			}
			else {
				isAttackPhase = false;
			}
		}
	}
}


int Game::compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled) {

	int defendersEliminated = 0;
	for (int i = 0; i < defDicesRolled.size(); i++) {

		if (attDicesRolled[i] > defDicesRolled[i])
		{
			defendersEliminated++;
		}
	}
	return defendersEliminated;
}


int Game::compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled) {

	int attackersEliminated = 0;
	for (int i = 0; i < defDicesRolled.size(); i++) {

		if (defDicesRolled[i] >= attDicesRolled[i])
		{
			attackersEliminated++;
		}
	}
	return attackersEliminated;
}

void Game::fortificationPhase(int playerNumber) {

	vector<Country*> allCurrentPlayerCountries = players[playerNumber]->getCountries();

	vector<Country*> ownedNeighborCountry;
	string selectedCountryString;
	int selectedNeighborNum;
	Country* countrySelected;
	Country* neighborSelected;
	bool fortificationPhase = true;

	cout << "===================";
	cout << "FORTIFICATION PHASE";
	cout << "===================";
	cout << "Player " + playerNumber;

	do {
		//Select an owned country
		cout << "Here are your choices: " << endl;
		int sizeOfCountriesList = players[playerNumber]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << "Country named " << players[playerNumber]->getCountries()[j]->getCountryName() << "in continent" << players[playerNumber]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
		cout << "Enter the name of the country to move armies from" << endl;
		cin >> selectedCountryString;

		countrySelected = (players[playerNumber]->getCountry(selectedCountryString));

		//Check owned neighbors
		int sizeOfNeighborList = countrySelected->getNeighbors().size();
		vector<Country*> allNeighbors = countrySelected->getNeighbors();
		vector<Country*> ownedNeighbors;
		for (int i = 0; i < allNeighbors.size(); i++)
		{
			if (((allNeighbors[i]->getOwner())->getName()).compare(players[playerNumber]->getName()) == 0)
			{
				ownedNeighbors.push_back(allNeighbors[i]);
			}
		}

		//Select an owned neighboring country & Display the owned neighboring countries
		cout << "Here are your owned neighboring countries: " << endl;
		if (ownedNeighbors.size() > 0) {
			for (int j = 0; j < ownedNeighbors.size(); j++)
			{
				cout << j << " - ";
				cout << "Country named " << ownedNeighbors[j]->getCountryName() << "in continent" << ownedNeighbors[j]->GetContinent()->GetName() << endl;
			}
			cout << "\nSelect a number from the list" << endl;
			cin >> selectedNeighborNum;
			neighborSelected = players[playerNumber]->getCountry((ownedNeighbors[selectedNeighborNum]->getCountryName()));

			//Proceed to the moving of army
			int moveArmy = 0;
			cout << " How many army units would you like to move?" << endl;
			do {
				cout << " Currently you have " << countrySelected->getNumberOfArmies() << " units in " << countrySelected->getCountryName() << "must leave 1 behind";
				cin >> moveArmy;
			} while (moveArmy <= countrySelected->getNumberOfArmies() - 1);
			countrySelected->removeArmy(moveArmy);
			neighborSelected->addMovedArmy(moveArmy);
			cout << "You have successfully moved some units to a neighboring country" << endl;
			fortificationPhase = false;
		}
		else
		{
			cout << "\nYOU HAVE NO NEIGHBORS FOR THE COUNTRY!" << endl;
			fortificationPhase = true;
		}
	} while (fortificationPhase);
	cout << "FORTIFICATION PHASE DONE";

}

void Game::chooseMap(){
    //MapLoader* ml;
    //Map *m;
    cout << "Which map would you like to use?" << endl;
    cout << "[1] Aden" << endl;
    cout << "[2] Canada" <<endl;
    cout << "Choose a number" << endl;
    int answer;
    cin >> answer;
    
    if (answer == 1){
        MapLoader* ml = new MapLoader("/Users/stevenmoore/Documents/GitHub/Risk_COMP345/Risk_COMP345/Risk_COMP345/Maps/Aden.map");
        worldMap = ml->getMap();
    }
    if (answer == 2){
        MapLoader* ml = new MapLoader("/Users/stevenmoore/Desktop/Risk_COMP345/Risk_COMP345/Risk_COMP345/Canada.map");
        worldMap = ml->getMap();
    }
}

