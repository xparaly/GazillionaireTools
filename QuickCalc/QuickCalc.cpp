// QuickCalc.cpp : Defines the entry point for the application.
//

#include "QuickCalc.h"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

static bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

static void print_map(map<int, string> map) {
	for (int i = 1; i < 19; i++) {
		std::cout << i << ": " << map[i] << endl;
	}
	std::cout << endl;
}

int main(int argc, char* argv[])
{
	map<int, string> prod_index;
	prod_index[1] = "exotic";
	prod_index[2] = "gems";
	prod_index[3] = "x fuels";
	prod_index[4] = "kryptoons";
	prod_index[5] = "oggle sand";
	prod_index[6] = "oxygen";
	prod_index[7] = "lava lamps";
	prod_index[8] = "hair tonic";
	prod_index[9] = "polyester";
	prod_index[10] = "toasters";
	prod_index[11] = "umbrellas";
	prod_index[12] = "diapers";
	prod_index[13] = "babel seeds";
	prod_index[14] = "whip cream";
	prod_index[15] = "frog legs";
	prod_index[16] = "moon ferns";
	prod_index[17] = "jelly beans";
	prod_index[18] = "cantaloupe";

	map<string, float> prod_price;
	prod_price["exotic"] = 270;
	prod_price["gems"] = 255;
	prod_price["x fuels"] = 240;
	prod_price["kryptoons"] = 225;
	prod_price["oggle sand"] = 210;
	prod_price["oxygen"] = 195; 
	prod_price["lava lamps"] = 180;
	prod_price["hair tonic"] = 165;
	prod_price["polyester"] = 150;
	prod_price["toasters"] = 135;
	prod_price["umbrellas"] = 120;
	prod_price["diapers"] = 105;
	prod_price["babel seeds"] = 90;
	prod_price["whip cream"] = 75;
	prod_price["frog legs"] = 60;
	prod_price["moon ferns"] = 45;
	prod_price["jelly beans"] = 30;
	prod_price["cantaloupe"] = 15;

	int index, tons;
	string commodity;
	float percent1, percent2, profit_per_ton, total_profit;
	profit_per_ton = 0;

	int difficulty = 0;

	cout << "Difficulty?" << endl
		<< "1: Novice" << endl
		<< "2: Beginner" << endl
		<< "3: Intermediate" << endl
		<< "4: Expert" << endl
		<< "5: Master" << endl;
	cin >> difficulty;
	cout << endl;

	float multiplier;
	switch (difficulty) {
	case 1:
		multiplier = (float)35 / 15;
		break;
	case 2:
		multiplier = 2;
		break;
	case 3:
		multiplier = (float)25 / 15;
		break;
	case 4:
		multiplier = (float)20 / 15;
		break;
	case 5:
		multiplier = 1;
		break;
	}


	print_map(prod_index);

	string inString;
	int arg = 1;
	while (true) {

		cin >> inString;

		if (is_number(inString)) {
			//cout << inString << " is a number! " << endl;
			switch (arg) {
			case 1:
				index = stoi(inString);
				//cout << "Now index = " << index << endl;
				break;
			case 2:
				percent1 = stof(inString);
				//cout << "Now percent1 = " << percent1 << endl;

				if (percent1 < 0 || percent1 > 100) {
					cout << "PERCENTAGE MUST BE BETWEEN 0 AND 100" << endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				break;
			case 3:
				percent2 = stof(inString);
				//cout << "Now percent2 = " << percent2 << endl;
				if (percent2 < 0 || percent2 > 100) {
					cout << "PERCENTAGE MUST BE BETWEEN 0 AND 100" << endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				arg = 1;
				profit_per_ton = multiplier*prod_price[prod_index[index]] * (percent1 - percent2) / 100;
				cout << prod_index[index] << ": " << percent1 << "% - " << percent2 << "%: $" << profit_per_ton << endl << endl;
				continue;
			}
			arg++;
		} else {	// not an int
			if (inString == "exit") {
				cout << "exiting... " << endl;
				return 0;
			} else if (inString == "map") {
				print_map(prod_index);
			} else if (inString.front()=='*') {
				inString = inString.substr(1, inString.length() - 1);
				if (is_number(inString)) {
					tons = stoi(inString);
					total_profit = profit_per_ton * tons;
					cout << "total profit: $" << total_profit << endl;
				} else {
					cout << "received '*', but rest of string was not an integer." << endl;
				}
			} else {
				cout << "invalid string input." << endl;
				arg = 1;
			}
		}
	}

	return 0;
}