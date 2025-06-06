#include <iostream>
#include <string>
#include <vector>

class Player {
	private:
		int id;
		bool corrupt;
		std::string name;
		std::string role;
		std::string team;
	public:
};

class Station {
	private:
		int id;
		bool hasTreasure;
		bool hasTrace;
		std::vector<int> connections;
	public:
};

class Map {
	private:
	public:
};

class CorruptCopsGame {
	private:
		int maxRounds;
		std::vector<Player> playerList;
		Map gameBoard;
	public:
		void play();
};

int main() {
	CorruptCopsGame game;
	game.play();

	return 0;
}