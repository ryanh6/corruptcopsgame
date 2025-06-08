#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class Player {
	int id;
	bool corrupt;
	std::string name;
	std::string role;
	std::string team;

	public:
		Player(int newID, std::string newName) {
			this->id = newID;
			this->corrupt = false;
			this->name = newName;
			this->role = "None";
			this->team = "None";
		}
		int getID() {
			return this->id;
		}
		bool getCorrupt() {
			return this->corrupt;
		}
		void setCorrupt() {
			this->corrupt = !this->corrupt;
		}
		std::string getName() {
			return this->name;
		}
		std::string getRole() {
			return this->role;
		}
		void setRole(std::string newRole) {
			this->role = newRole;
		}
		std::string getTeam() {
			return this->team;
		}
		void setTeam(std::string newTeam) {
			this->team = newTeam;
		}
};

class Node {
	int stationID;
	bool hasTreasure;
	bool hasTrace;
	std::vector<int> connections;

	public:
		Node(int newID, std::vector<int> newConnections) {
			this->stationID = newID;
			this->hasTreasure = false;
			this->hasTrace = false;
			this->connections = newConnections;
		}
		int getID() {
			return this->stationID;
		}
		bool getTreasure() {
			return this->hasTreasure;
		}
		void setTreasure() {
			this->hasTreasure = !this->hasTreasure;
		}
		bool getTrace() {
			return this->hasTrace;
		}
		void setTrace() {
			this->hasTrace = !this->hasTrace;
		}

};

class Board {
	std::vector<Node> stations;

	public:
		void readMapLayout(std::string fileName) {
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
			
				Node newStation = Node(count, numbers);
				stations.push_back(newStation);
				count++;
			}
		}
};

class CorruptCopsGame {
	int maxRounds;
	std::vector<Player> playerList;
	Board gameBoard;

	public:
		void play() {
			// call assign roles
			// make the game board (one line call, no function needed)
			// placing pieces order
			// actual rounds
		}
	private:
		void assignRoles() {
			// Shuffle the current player list
			// Assign first 4 to blue, next to red, then to green, last 2 to thieves
			// Choose 2 cops from different teams to be cops
		}
};

int main() {
	CorruptCopsGame game;
	game.play();

	return 0;
}