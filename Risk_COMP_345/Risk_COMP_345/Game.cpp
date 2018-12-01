#include <iostream>
#include <vector>
#include <filesystem>
#include "Game.h"
#include "UserStrategy.h"
#include "BenevolentStrategy.h"
#include "AggressiveStrategy.h"
#include "View.h"
#include "GameStatView.h"


using namespace std;
namespace fs = std::experimental::filesystem;

Game::Game() 
{
	cout << "WELCOME TO THE GAME OF RISK, YOUR GAME HAS BEEN STARTED" << endl;
	gameOver = false; // game is obviously not over, it has just started
	setup();
	placeInitialArmies();
	//Create a View that is connected to the Game  
    View *view = new View(this); 
	//startGameLoop();
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
	chooseMap();
	setNumberOfPlayers();
	giveCountriesToPlayers();
}

void Game::giveCountriesToPlayers() {
	cout << "Assigning countries randomly to each player..." << endl;
	int numOfPlayers = players.size();
	int assignedPlayer = rand() % numOfPlayers;//start with a random one
	vector<Country*> allCountries = worldMap->GetAllCountries();
	int numOfCountries = allCountries.size();
	for (int i = 0; i < numOfCountries; i++) {
		allCountries[i]->setOwner(players[assignedPlayer]);
		players[assignedPlayer]->addCountry(allCountries[i]);
		cout << "Player "<< players[assignedPlayer]->getName() << " has been assigned the country "<< allCountries[i]->getCountryName() << endl;
		assignedPlayer++;
		if (assignedPlayer == numOfPlayers) {
			assignedPlayer = 0;
		}
	}
}

void Game::incrementTurn() {
	setTurnNumber(getTurnNumber() + 1);
}

void Game::startGameLoop() {
	setTurnNumber(0);
	//reinforcementPhase();
	//attackPhase();
	//fortificationPhase();
	//while the game has not ended yet,
	//each player gets a reinforce, then each player gets an attack, then each player gets a fortify
	while (players.size() != 1) {
		cout << "The players currently still alive are: "<< endl;
		for (int i = 0; i < players.size(); i++) {
			cout << players[i]->getName();
		}
		cout << endl;
		///////for each player, reinforce
		for (int i = 0; i < players.size(); i++) {
			if (players[i]->getStrategy() != NULL) {
				players[i]->getStrategy()->reinforce(players[i]);
				players[i]->getStrategy()->attack(players[i]);
				players[i]->getStrategy()->fortify(players[i]);
			}
			else {
				reinforcementPhase(i);
				attackPhase(i);
				checkDeath();
				fortificationPhase(i);
			}
		}
		incrementTurn();
	}
	cout << "THERE IS ONLY ONE PLAYER LEFT IN THE GAME> WE HAVE A WINNER!" << endl;
	cout << "CONGRATULATIONS " << players[0]->getName() << "!!!!!!" << endl;
}

void Game::checkDeath() {
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getCountries().size() == 0) {
			//then youre dead
			cout << "ATTENTION! PLAYER " << players[i]->getName() << " HAS DIED. WE HAVE ONE LESS PLAYER IN OUR MIDST!" << endl;
			Notify();
			cout << endl;
			players.erase(players.begin() + i);
		}
	}
}

void Game::chooseMap() {
	cout << "CHOOSE WHICH MAP YOU WOULD LIKE TO PLAY WITH" << endl;
	for (auto & p : fs::directory_iterator("Maps")) {
		auto filename = p.path().filename();
		if (p.path().extension() == ".map")
			cout << filename << endl;
	}
	string mapname;
	cin >> mapname;
   // string mapname = "/Users/stevenmoore/Desktop/RISK/Aden.map";
	cout << "YOU CHOSE " << mapname << endl;

	MapLoader* map = new MapLoader();

	cout << "MAP IS NOW CREATED" << endl;

	worldMap = map->MapLoad(mapname);

	vector<Country*> allCountries = worldMap->GetAllCountries();
	vector<Country*> allNeighbors;
	cout << "MAP IS NOW LOADED" << endl;
	cout << "Here are the list of all the countries - and their neighbors:" << endl;
	for (int i = 0; i < allCountries.size(); i++)
	{
		cout << allCountries[i]->getCountryName() << endl;
		for (int j = 0; j < (allCountries[i]->getNeighbors()).size(); j++)
		{
			allNeighbors = allCountries[i]->getNeighbors();
			cout << "     -";
			cout << allNeighbors[j]->getCountryName() << endl;
		}
	}
}


void Game::setNumberOfPlayers()
{
	int MAX_PLAYERS = 6;
	int numberOfPlayers;
	int armyAllocation;
	cout << "How many players are in the game? There is a maximum of 6. " << endl;
	cin >> numberOfPlayers;

	//keep searching
	while ( (numberOfPlayers < 2) || (numberOfPlayers > MAX_PLAYERS) || cin.fail())
	{
		cout << "INVALID ENTRY - Please enter an integer between 2 and 6: " << endl;
		cin >> numberOfPlayers;
	}
	cout << endl;
	//determine the number of armies they get to place
	switch (numberOfPlayers) 
	{
	case 2:
		//changed for testing from 40 to 30
		armyAllocation = 30;
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
		armyAllocation = 20; //should be 20 but im testing
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
		cout << "Player " << players[i]->getName() << " owns the following countries: " << endl;
		int sizeOfCountriesList = players[i]->getCountries().size();
		for (int j = 0; j <sizeOfCountriesList; j++) 
		{
			cout << "Country named " << players[i]->getCountries()[j]->getCountryName() << " in continent " << players[i]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
		cout << endl;
	}
}

void Game::setTurnNumber(int x) {
	turnNumber = x;
}

void Game::placeInitialArmies() 
{
	int numberOfInitialArmiesLeft = players[0]->getArmies();
	bool allArmiesAllocated = false;
	assignFirstRound();
	//must reduce the num of army allocation
	//take nuymber of countries player 1 has, remvoe that number from everyone
	int allocationReduction = players[0]->getCountries().size();
	numberOfInitialArmiesLeft = numberOfInitialArmiesLeft - allocationReduction;
	while (!allArmiesAllocated) {
		assignOneRound();
		numberOfInitialArmiesLeft--;
		cout << "Number of armies left to allocate :"<< numberOfInitialArmiesLeft <<endl;
		if (numberOfInitialArmiesLeft == 0) {
			allArmiesAllocated = true;
		}
	}
}

void Game::assignFirstRound() {
	cout << "assigning one army to each country owned by player by default. The rest will be chosen by the player." << endl;
	for (int i = 0; i < players.size(); i++) {
		vector<Country*> playerCountries = players[i]->getCountries();
		for (int ii = 0; ii < playerCountries.size(); ii++) {
			playerCountries[ii]->addArmy();
			players[i]->removeAnArmy();
		}
	}
}

void Game::assignOneRound() 
{
	string choice;
	for (int i = 0; i < players.size(); i++)
	{
		cout << "It is Player " << i << "'s, " << players[i]->getName() << ",  turn to assign an army to a country" << endl;
		cout << players[i]->getArmies() << ",  Armies left" << endl;
		cout << "Here are your choices: " << endl;
		int sizeOfCountriesList = players[i]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << "Country named " << players[i]->getCountries()[j]->getCountryName() << " in continent " << players[i]->getCountries()[j]->GetContinent()->GetName() << " - " << players[i]->getCountries()[j]->getNumberOfArmies() << " units" << endl;
		}
		cout << "Enter the name of the country to add an army to it" << endl;
		bool choosenProperCountry = false;
		while (!choosenProperCountry) {
			cout << "Type a valid country" << endl;
			cin >> choice;
			if(players[i]->getCountry(choice) == NULL)
			{
				choosenProperCountry = false;
			}
			else
			{
				choosenProperCountry = true;
			}
		}
		players[i]->getCountry(choice)->addArmy();
		players[i]->removeAnArmy();
	}
}

void Game::reinforcementPhase(int playerNumber) {
	////Dynamically change the strategy
	//cout << "Current strategy is " << players[playerNumber]->getStrategyName() << ". ";
	//string response;
	//cout << "Would you like to change strategies? (Y/N)" << endl;
	//cin >> response;
	//if (response == "y" || response == "Y") {
	//	
	//	cout << "Which strategy would you like to use? U (user), A (aggressive) or B (benevolent)?" << endl;
	//	string strategy;
	//	cin >> strategy;
	//	if (strategy == "U") {
	//		UserStrategy* s = new UserStrategy();
	//		players[playerNumber]->setStrategy(s);
	//	}
	//	if (strategy == "A") {
	//		AggressiveStrategy* s = new AggressiveStrategy();
	//		players[playerNumber]->setStrategy(s);
	//	}
	//	if (strategy == "B") {
	//		BenevolentStrategy* s = new BenevolentStrategy();
	//		players[playerNumber]->setStrategy(s);
	//	}
	//}
	//
	int numberOfCountriesOfPlayer = (players[playerNumber]->getCountries()).size();
	int extraReinforcements = 3;
	int selectedCountryForReinforcement;
	currentPlayer = players[playerNumber];
	phaseName = "REINFORCEMENT";
	Notify();
	//step 1: number of countries / 3
	if (numberOfCountriesOfPlayer > 3)
	{
		extraReinforcements += (int)numberOfCountriesOfPlayer / 3;
	}//end of step 1

	//step 2: check bonus for continents 
	for (int i = 0; i < worldMap->GetContinentCount(); i++) {
		//initialize how many countries are in the continent
		int continentCount = worldMap->GetMapContinents()[i]->GetCountryCount();
		int playerCount = 0;

		//go through all of the players' countries and see which ones are from that continent
		for (int j = 0; j < players[playerNumber]->getCountries().size(); j++) {

			//every time a players' country belongs to the continent we are checking, add to playerCount
			if (players[playerNumber]->getCountries()[j]->GetContinent()->GetName() == worldMap->GetMapContinents()[i]->GetName())
			{
				playerCount++;
			}			
		}
		//if we have all the countries in that continent
		if (playerCount == continentCount) {
			//get the bonus of that continent
			extraReinforcements += worldMap->GetMapContinents()[i]->GetNumberOfArmiesPerTurn();
		}
	}//end of step 2
	/*

	//step 3: exchange cards
	//check the player's hand
	cout << "HAND: " << endl;
	//get the type of cards for each card in the hand
	for (int i = 0; i < players[playerNumber]->getHand()->getCards().size(); i++) {
		cout << "[" << i+1 << "]" << players[playerNumber]->getHand()->getCards()[i]->getType() << endl;
	}
	cout << "WOULD YOU LIKE TO EXCHANGE YOUR CARDS? [Y/N]" << endl;
	//call the exchange function if Y
	string response;
	cin >> response;
	if (response == "Y") {
		cout << "WHICH CARDS WOULD YOU LIKE TO EXCHANGE? CHOOSE NUMBER AND PRESS ENTER" << endl;
		int card1;
		int card2;
		int card3;
		cin >> card1;
		cin >> card2;
		cin >> card3;
		//check if they can exchange with the cards they chose
		if (players[playerNumber]->getHand()->exchange(players[playerNumber]->getHand()->getCards()[card1 - 1], players[playerNumber]->getHand()->getCards()[card2 - 1], players[playerNumber]->getHand()->getCards()[card3 - 1])) {
			extraReinforcements += getBonus();
			cout << "CARDS EXCHANGED" << endl;
			//increment the bonus
			setBonus(getBonus());
		}
		else
			cout << "THESE CARDS CANNOT BE TRADED" << endl;
	}//end of step 3

	*/

	//place the reinforcements
	while (extraReinforcements > 0)
	{
        cout << "Amount of armies left to place: " << extraReinforcements << endl;
		//Select an owned country
		cout << "Here are your choices: " << endl;
		int sizeOfCountriesList = players[playerNumber]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << j << " - " << "Country named " << players[playerNumber]->getCountries()[j]->getCountryName() << " in continent " << players[playerNumber]->getCountries()[j]->GetContinent()->GetName() << " with " << (players[playerNumber]->getCountries()[j])->getNumberOfArmies() << " armies" << endl;
		}
        //THIS IS THE STRATEGY
            players[playerNumber]->getStrategy()->reinforce(players[playerNumber]);
        
		cout << "Enter the number of the country to add armies to " << endl;
		cin >> selectedCountryForReinforcement;
		(players[playerNumber]->getCountries()[selectedCountryForReinforcement])->addArmy();
		cout << (players[playerNumber]->getCountries()[selectedCountryForReinforcement])->getCountryName() << " now has " << (players[playerNumber]->getCountries()[selectedCountryForReinforcement])->getNumberOfArmies() << " number of armies " << endl;

		extraReinforcements--;
	}
	cout << "REINFORCEMENT PHASE DONE!" << endl;
}

void Game::setBonus(int b)
{
	if (b < 60) {
		bonus = b + 5;
	}
	else {
		return;
	}
}

int Game::getBonus() const
{
	return bonus;
}

void Game::attackPhase(int attackerPlayerNum)
{

	string attackPhaseInputString;
	bool isAttackPhase;
	currentPlayer = players[attackerPlayerNum];
	phaseName = "ATTACK";
	Notify();
	cout << "Do you want to attack? y/n" << endl;
	cin >> attackPhaseInputString;

	if (attackPhaseInputString == "y" || attackPhaseInputString == "Y") {
		isAttackPhase = true;
	}
	else {
		isAttackPhase = false;
	}

	while (isAttackPhase) {
		string countrySelectedIn;
		int neighborSelectedIndex;
		Country* countrySelected = NULL;
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
		
        //THIS IS THE STRATEGY
        players[attackerPlayerNum]->getStrategy()->attack(players[attackerPlayerNum]);

        
		//Player selects a owned country
		while (countryNotEnoughArmy) {
			do {
				cout << "Please select one of your own countries, type the exact name" << endl;
				cin >> countrySelectedIn;
				countrySelected = (players[attackerPlayerNum]->getCountry(countrySelectedIn));
			} while (countrySelected == NULL);
			if (players[attackerPlayerNum]->getCountry(countrySelected->getCountryName())->getNumberOfArmies() < 2)
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
		do {
			cin >> neighborSelectedIndex;
		} while (neighborSelectedIndex >= ListOfneighbors.size());

		//Roll correct number of dices to attack selected neighbor country
		attackerCountry = players[attackerPlayerNum]->getCountry(countrySelected->getCountryName());
		defenderCountry = (ListOfneighbors[neighborSelectedIndex]);
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
			} while (attNumDices < 1 || attNumDices > 2);
			attDicesRolled = players[attackerPlayerNum]->rollDice(attNumDices);
		}
		if (attackerNumberOfArmy > 3)
		{
			do {
				cout << "\n ATTACKER - The country has a lot armies. Choose to throw 1, 2 or 3 dices" << endl;
				cin >> attNumDices;
			} while (attNumDices < 1 || attNumDices > 3);
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
			} while (defNumDices < 1 || defNumDices > 2);
			defDicesRolled = neighborPlayer->rollDice(defNumDices);
		}
		cout << endl;
		cout << "ATTACKER DICES: ";
		for (int i = 0; i < attDicesRolled.size(); i++) { cout << attDicesRolled[i] << ", "; }
		cout << endl;
		cout << "DEFFENDER DICES: ";
		for (int i = 0; i < defDicesRolled.size(); i++) { cout << defDicesRolled[i] << ", "; }
		cout << endl;
		//Remove defender armies and attacker armies
		int defendersEliminated = compareThrownDicesDef(attDicesRolled, defDicesRolled);
		defenderCountry->removeArmy(defendersEliminated);
		cout << "Attacker has eliminated " << defendersEliminated << "  defenders" << endl;
		int attackersEliminated = compareThrownDicesAtt(attDicesRolled, defDicesRolled);
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
			players[attackerPlayerNum]->addCountry(ListOfneighbors[neighborSelectedIndex]);
			neighborPlayer->removeCountry(ListOfneighbors[neighborSelectedIndex]);
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
			Notify();
			cout << "\nAttacking phase done!" << endl;
			isAttackPhase = false;
		}
		else {
			cout << "\nWould you like to attack again? y/n" << endl;
			cin >> attackPhaseInputString;
			if (attackPhaseInputString == "y" || attackPhaseInputString == "yes") {
				isAttackPhase = true;
			}
			else {
				isAttackPhase = false;
			}
		}
	}
} 

void Game::fortificationPhase(int playerNumber) {
	vector<Country*> allCurrentPlayerCountries = players[playerNumber]->getCountries();
	vector<Country*> ownedNeighborCountry;
	string selectedCountryString;
	int selectedNeighborNum;
	Country* countrySelected;
	Country* neighborSelected;
	bool fortificationPhase = true;
	currentPlayer = players[playerNumber];
	phaseName = "FORTIFICATION";
	Notify();
	cout << "Player " + playerNumber;

	do {
		//Select an owned country
		cout << "Here are your choices: " << endl;
		int sizeOfCountriesList = players[playerNumber]->getCountries().size();
		for (int j = 0; j < sizeOfCountriesList; j++)
		{
			cout << "Country named " << players[playerNumber]->getCountries()[j]->getCountryName() << " in continent " << players[playerNumber]->getCountries()[j]->GetContinent()->GetName() << endl;
		}
        
        //THIS IS THE STRATEGY
        players[playerNumber]->getStrategy()->fortify(players[playerNumber]);
        
		cout << "Enter the name of the country to move armies from " << endl;
		cin >> selectedCountryString;

		countrySelected = (players[playerNumber]->getCountry(selectedCountryString));

		//Check owned neighbors
		int sizeOfNeighborList = (countrySelected->getNeighbors()).size();
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
				cout << "Country named " << ownedNeighbors[j]->getCountryName() << " in continent " << ownedNeighbors[j]->GetContinent()->GetName() << endl;
			}
			cout << "\nSelect a number from the list" << endl;
			cin >> selectedNeighborNum;
			neighborSelected = players[playerNumber]->getCountry((ownedNeighbors[selectedNeighborNum]->getCountryName()));

			//Proceed to the moving of army
			int moveArmy = 0;
			cout << "Your neighbor " << neighborSelected->getCountryName() << " has " << neighborSelected->getNumberOfArmies() << " army units" <<endl;
			cout << "\nHow many army units would you like to move?" << endl;
			do {
				cout << "Currently you have " << countrySelected->getNumberOfArmies() << " units in " << countrySelected->getCountryName() << " must leave 1 behind" << endl;
				cin >> moveArmy;
			} while (!(moveArmy <= countrySelected->getNumberOfArmies() - 1));
			countrySelected->removeArmy(moveArmy);
			neighborSelected->addMovedArmy(moveArmy);
			cout << "You have successfully moved some units to a neighboring country" << endl;
			cout << countrySelected->getCountryName() << " now has " << countrySelected->getNumberOfArmies() << " army units and your neighbor " << neighborSelected->getCountryName() << " now has " << neighborSelected->getNumberOfArmies() << " army units" <<endl;
			fortificationPhase = false;
		}
		else
		{
			cout << "\nYOU HAVE NO NEIGHBORS FOR THE COUNTRY!" << endl;
			if(players[playerNumber]->getCountries().size() == 1)
			fortificationPhase = false;
			else {
			fortificationPhase = true;
			}
		}
	} while (fortificationPhase);
	cout << "\n\nFORTIFICATION PHASE DONE\n\n";
}

//For Demo
void Game::addDemoPlayers(Player* player) {
	players.push_back(player);
}

void Game::addArmiesToCountry(int amount, Country* c) 
{
	for (int i = 0; i < amount; i++) 
	{
		c->addArmy();
	}
}

int Game::compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled) {
	int defendersEliminated = 0;
	int attackersEliminated = 0;
	int LastIndexOfAttDices = attDicesRolled.size();
	int LastIndexOfDefDices = defDicesRolled.size();
	LastIndexOfAttDices--;
	LastIndexOfDefDices--;
	for (int i = 0; i < defDicesRolled.size(); i++) {
		if (LastIndexOfAttDices >= 0 && LastIndexOfDefDices>= 0) {
			if (attDicesRolled[LastIndexOfAttDices] > defDicesRolled[LastIndexOfDefDices]) {
				defendersEliminated++;
			}
			LastIndexOfAttDices--;
			LastIndexOfDefDices--;
		}
	}
	return defendersEliminated;
}

int Game::compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled) {
	int defendersEliminated = 0;
	int attackersEliminated = 0;
	int LastIndexOfAttDices = attDicesRolled.size();
	int LastIndexOfDefDices = defDicesRolled.size();
	LastIndexOfAttDices--;
	LastIndexOfDefDices--;
	for (int i = 0; i < defDicesRolled.size(); i++) {
		if (LastIndexOfAttDices >= 0 && LastIndexOfDefDices >= 0) {
			if (defDicesRolled[LastIndexOfDefDices] >= attDicesRolled[LastIndexOfAttDices]) {
				attackersEliminated++;
			}
			LastIndexOfAttDices--;
			LastIndexOfDefDices--;
		}
	}
	return attackersEliminated;
}
