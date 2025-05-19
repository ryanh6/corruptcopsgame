#include <iostream>
#include <string>
#include <vector>

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
		}

		std::string getName() {
			return this->name;
		}
};

class CorruptCops {
	private:
		std::vector<std::string> gameRoles = {"Blue 1", "Blue 2", "Blue 3", "Red 1", "Red 2", "Red 3", "Green 1", "Green 2", "Green 3", "Thief 1", "Thief 2"};
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

			for (int i = 0; i < playerList.size(); i++) {
				std::cout << playerList[i].getName() << std::endl;
			}
		}
};

int main() {
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