#include <iostream>
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

class CorruptCops {
	private:
		int rounds = 10;
		std::vector<std::string> gameRoles = {"Blue 1", "Blue 2", "Blue 3", "Blue 4", "Red 1", "Red 2", "Red 3", 
												"Red 4", "Green 1", "Green 2", "Green 3", "Green 4", "Thief 1", "Thief 2"};
		std::vector<Player> playerList;
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

			// Choosing Indices For Corrupts
			int index1 = rand() % (playerList.size() - 2);
			int index2 = (index1 + 4 + (rand() % 4)) % (playerList.size() - 2);

			// std::cout << index1 << std::endl;
			// std::cout << index2 << std::endl;

			// Shuffling The Players
			for (int i = playerList.size() - 1; i >= 0; i--) {
				int j = rand() % (i + 1);
				std::swap(playerList[i], playerList[j]);
			}
		
			// Assigning Roles
			for (int i = 0; i < playerList.size(); i++) {
				playerList[i].setRole(gameRoles[i]);

				if (i == index1 || i == index2){
					playerList[i].setCorrupt();
				}
			}

			// Printing Players Out
			for (int i = 0; i < playerList.size(); i++) {
				std::cout << playerList[i];
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