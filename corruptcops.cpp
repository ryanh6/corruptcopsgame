#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class Player {
	private:
		int id;
		bool corrupt;
		std::string name;
		std::string role;
	public:
		Player(int newId, std::string newName) {
			this->id = newId;
			this->name = newName;
			this->corrupt = false;
			this->role = "None";
		}
		friend std::ostream& operator<<(std::ostream& outputStream, const Player& newPlayer) {
			outputStream << "(Player " << newPlayer.id << ") " << newPlayer.name << " is " << newPlayer.role;
			
			if (newPlayer.corrupt == true) {
				outputStream << " (CORRUPT)";
			}

			outputStream << std::endl;

			return outputStream;
		}
		int getID() {
			return this->id;
		}
		bool getCorrupt() {
			return this->corrupt;
		}
		std::string getName() {
			return this->name;
		}
		std::string getRole() {
			return this->role;
		}
		void setCorrupt() {
			this->corrupt = !(this->corrupt);
		}
		void setRole(std::string newRole) {
			this->role = newRole;
		}
};

class Station {
	private:
		int stationID;
		bool chest;
		bool trace;
		std::vector<int> connections;
	public:
		Station(int newId, std::vector<int> connectedStations) {
			this->stationID = newId;
			this->chest = false;
			this->trace = false;
			this->connections = connectedStations;
		}
		int getStationID() {
			return this->stationID;
		}
		std::vector<int> getConnectedStations() {
			return this->connections;
		}
		bool getChest() {
			return this->chest;
		}
		void setChest() {
			this->chest = !(this->chest);
		}
		bool getTrace() {
			return this->trace;
		}
		void setTrace(bool newTraceValue) {
			this->trace = newTraceValue;
		}
};

class Map {
	private:
		std::vector<Station> stations;
		std::vector<int> chestLocations;
	public:
		void readMapLayout(std::string fileName){
			int count = 1;
			std::string output;
			std::ifstream myFile(fileName);

			while (getline(myFile, output)) {
				std::istringstream iss(output);

				int value;
				std::vector<int> numbers;

				while (iss >> value) {
					numbers.push_back(value);
				}
			
				Station newStation = Station(count, numbers);
				stations.push_back(newStation);
				count++;
			}
		}
};

class CorruptCops {
	private:
		int rounds = 10;
		std::vector<Player> playerList;
		std::vector<Player> blueTeam;
		std::vector<Player> redTeam;
		std::vector<Player> greenTeam;
		std::vector<Player> thievesTeam;
		std::vector<std::vector<Player>> copsTeam;
		std::vector<std::vector<Player>> turnOrder;
		Map gameMap;
	public:
		void play() {
			std::cout << "Main Game Loop Starts Here" << std::endl;

			playerList.push_back(Player(1, "Alice"));
			playerList.push_back(Player(2, "Bob"));
			playerList.push_back(Player(3, "Charlie"));
			playerList.push_back(Player(4, "Dennis"));
			playerList.push_back(Player(5, "Edward"));
			playerList.push_back(Player(6, "Fiona"));
			playerList.push_back(Player(7, "George"));
			playerList.push_back(Player(8, "Harry"));
			playerList.push_back(Player(9, "Iris"));
			playerList.push_back(Player(10, "Joshua"));
			playerList.push_back(Player(11, "Kenny"));
			playerList.push_back(Player(12, "Logan"));
			playerList.push_back(Player(13, "Mary"));
			playerList.push_back(Player(14, "Nathan"));

			// Shuffling The Players
			for (int i = playerList.size() - 1; i >= 0; i--) {
				int j = rand() % (i + 1);
				std::swap(playerList[i], playerList[j]);
			}
		
			// Assigning Roles
			for (int i = 0; i < playerList.size(); i++) {
				if (i >= 0 && i <= 3) {
					playerList[i].setRole("Blue " + std::to_string(i + 1));
					blueTeam.push_back(playerList[i]);
				} else if (i >= 4 && i <= 7) {
					playerList[i].setRole("Red " + std::to_string(i - 3));
					redTeam.push_back(playerList[i]);
				} else if (i >= 8 && i <= 11) {
					playerList[i].setRole("Green " + std::to_string(i - 7));
					greenTeam.push_back(playerList[i]);
				} else {
					playerList[i].setRole("Thief " + std::to_string(i - 11));
					thievesTeam.push_back(playerList[i]);
				}
			}

			copsTeam.push_back(blueTeam);
			copsTeam.push_back(redTeam);
			copsTeam.push_back(greenTeam);

			int index1 = rand() % copsTeam.size();
			int index2 = (index1 + 1 + (rand() % 2)) % copsTeam.size();
			int index3 = rand() % copsTeam[index1].size();
			int index4 = rand() % copsTeam[index2].size();

			// std::cout << index1 << ":" << index3 << std::endl;
			// std::cout << index2 << ":" << index4 << std::endl;

			copsTeam[index1][index3].setCorrupt();
			copsTeam[index2][index4].setCorrupt();

			// Printing Players Out
			// for (int i = 0; i < playerList.size(); i++) {
			// 	std::cout << playerList[i];
			// }

			std::cout << "Cops" << std::endl;
			for (int i = 0; i < copsTeam.size(); i++) {
				for (int j = 0; j < copsTeam[i].size(); j++) {
					std::cout << copsTeam[i][j];
				}
			}

			std::cout << "Thieves Team" << std::endl;
			for (int i = 0; i < thievesTeam.size(); i++) {
				std::cout << thievesTeam[i];
			}

			gameMap = Map();
			gameMap.readMapLayout("seoulsubwaystationgraph.txt");

			for (int i = 0; i < rounds; i++) {
				std::cout << "Round " + std::to_string(i + 1) << std::endl;

				turnOrder.clear();
				turnOrder.push_back(thievesTeam);

				int startingTeam = rand() % copsTeam.size();
				int movementDirection = (rand() % 2) + 1;

				for (int j = 0; j < 3; j++) {
					turnOrder.push_back(copsTeam[startingTeam]);
					startingTeam = ((startingTeam + movementDirection) % 3);
				}

				for (int j = 0; j < turnOrder.size(); j++) {
					for (int k = 0; k < turnOrder[j].size(); k++) {
						std::cout << " It is now " + turnOrder[j][k].getName() + "'s Turn" << std::endl;
					}
				}
			}
		}
};

int main() {
	srand(time(0));

	CorruptCops game;
	game.play();

	return 0;
}

// class Game {
	
// };

// class Player {
// 	public:
// 		int id;
// 		int role;
// 		bool corrupt;
// };

// class Map {
// 	public:
// 		// list of all edges / connections
// 		// list of XX locations where there is chest
// 	private:
// 		// init (empty list locations, empty list chests)
// 		// make graph given file
// 		// generate chest locations (number of chests)
// 		// get station / cell
// };

// class Station {
// 	private:
// 		int stationID;
// 		bool chest;
// 		bool thiefTrace;
// 		// List of Players on the current station
// 		std::vector<Player> occupiedPlayerList;
// 		// List of connected nodes / stations
// 		std::vector<Station> connectedStationsList;
// 	public:
// 		int getID() {
// 			return stationID;
// 		}

// 		bool getThiefTrace() {
// 			return thiefTrace;
// 		}

// 		void setThiefTrace() {
// 			thiefTrace = !thiefTrace;
// 		}

// 		bool getChest() {
// 			return chest;
// 		}

// 		void setChest() {
// 			chest = !chest;
// 		}

// 		std::vector<Player> getPlayerList() {
// 			return occupiedPlayerList;
// 		}

// 		void addPlayer(const Player& newPlayer) {
//         	occupiedPlayerList.push_back(newPlayer);
//     	}


// 		std::vector<Station> getConnectedStations() {
// 			return connectedStationsList;
// 		}
// 		// init (id, no chest, no trace, no players, given nodes)
// 		// getID
// 		// getThief trace
// 		// set thief trace
// 		// get chest
// 		// set chest
// 		// get player list
// 		// add player to list
// 		// remove player from list
// 		// list connected nodes / stations
// };