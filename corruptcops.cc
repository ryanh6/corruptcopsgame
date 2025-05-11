#include <iostream>

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
	public:
		int stationID;
		bool chest;
		bool thiefTrace;
		// List of Players on the current station
		// List of connected nodes / stations
	private:
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