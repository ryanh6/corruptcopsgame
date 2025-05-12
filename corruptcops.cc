#include <iostream>
#include <vector>

class Player {
	public:
		int id;
		int role;
};

class Map {
	public:
		// list of all edges / connections
		// list of XX locations where there is chest
	private:
		// init (empty list locations, empty list chests)
		// make graph given file
		// generate chest locations (number of chests)
		// get station / cell
};

class Station {
	private:
		int stationID;
		bool chest;
		bool thiefTrace;
		// List of Players on the current station
		std::vector<Player> occupiedPlayerList;
		// List of connected nodes / stations
		std::vector<Station> connectedStationsList
	public:
		int getID() {
			return stationID;
		}

		bool getThiefTrace() {
			return thiefTrace
		}

		void setThiefTrace() {
			thiefTrace = !thiefTrace
		}

		bool getChest() {
			return chest;
		}

		void setChest() {
			chest = !chest
		}

		std::vector<Player> getPlayerList() {
			return occupiedPlayerList;
		}

		void addPlayer(const Player& newPlayer) {
        	occupiedPlayerList.push_back(newPlayer);
    	}


		std::vector<Station> getConnectedStations() {
			return connectedStationsList;
		}
		// init (id, no chest, no trace, no players, given nodes)
		// getID
		// getThief trace
		// set thief trace
		// get chest
		// set chest
		// get player list
		// add player to list
		// remove player from list
		// list connected nodes / stations
};

int main() {
	printf("Hello World");
	return 0;
}