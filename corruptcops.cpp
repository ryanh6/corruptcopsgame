#include <iostream>
#include <string>
#include <vector>

class Player {
	int id;
	bool corrupt;
	std::string name;
	std::string role;
	std::string team;
};

class Node {
	int id;
	bool hasTreasure;
	bool hasTrace;
	std::vector<int> connections;
};

class Board {
	std::vector<Node> stations;
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