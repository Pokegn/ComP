#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "CDado.h"

using namespace std;

class Turno {
public:
  int current_turn;
  int player;
  int position;
  int dice_roll;
  char tile_type;
  int new_position;

  // Constructor
  Turno(int current_turn, int player, int position, int dice_roll, char tile_type, int new_position)
    : current_turn(current_turn), player(player), position(position), dice_roll(dice_roll), tile_type(tile_type), new_position(new_position) {}

  // Overload the << operator
  friend std::ostream& operator<<(std::ostream& os, const Turno& turno) {
    os << turno.current_turn << " " << turno.player + 1 << " " << turno.position 
       << " " << turno.dice_roll << " " << turno.tile_type << " " << turno.new_position;
    return os;
  }
};



// Clase base para las casillas
class Tile {
public:
  virtual int interact(int position) const { return position; }
  virtual char getType() const { return 'N'; }
  virtual ~Tile() = default;
};

// Casilla normal
class NormalTile : public Tile {};

// Casilla serpiente
class SnakeTile : public Tile {
  int penalty;

public:
  explicit SnakeTile(int penalty) : penalty(penalty) {}
  int interact(int position) const override { return position - penalty; }
  char getType() const override { return 'S'; }
  friend int operator+(int position, const SnakeTile &tile) { return position - tile.penalty; // Subtract the penalty   
  }
};

// Casilla escalera
class LadderTile : public Tile {
  int reward;

public:
  explicit LadderTile(int reward) : reward(reward) {}
  int interact(int position) const override { return position + reward; }
  char getType() const override { return 'L'; }
  friend int operator+(int position, const LadderTile &tile) { return position + tile.reward; // Add the reward 
  }
};

// Clase base para el juego
// Clase base para el juego
class Game {
protected:
  int num_tiles;
  int num_players;
  int max_turns;
  vector<unique_ptr<Tile>> board;
  vector<int> positions;
  int current_turn;
  int penalty;
  int reward;

public:
  Game(int tiles, int players, int turns, int penalty, int reward)
      : num_tiles(tiles), num_players(players), max_turns(turns),
        current_turn(1), penalty(penalty), reward(reward) {
    positions.resize(players, 1);
    board.resize(tiles + 1); // Casillas de 1 a num_tiles
    for (int i = 1; i <= tiles; ++i) {
      board[i] = make_unique<NormalTile>();
    }
  }

  void configureSnakes(int count) {
    vector<int> used_positions;
    while (count > 0) {
      int pos = rand() % num_tiles + 1;
      if (find(used_positions.begin(), used_positions.end(), pos) == used_positions.end() && pos != 1 && pos != num_tiles) {
        board[pos] = make_unique<SnakeTile>(penalty);
        used_positions.push_back(pos);
        --count;
      }
    }
  }

  void configureLadders(int count) {
    vector<int> used_positions;
    while (count > 0) {
      int pos = rand() % num_tiles + 1;
      if (find(used_positions.begin(), used_positions.end(), pos) == used_positions.end() && pos != 1 && pos != num_tiles) {
        board[pos] = make_unique<LadderTile>(reward);
        used_positions.push_back(pos);
        --count;
      }
    }
  }

  virtual bool playTurn() = 0;

  void start() {
    while (current_turn <= max_turns) {
      if (playTurn()) {
        cout << "Player " << (current_turn - 1) % num_players + 1
             << " is the winner!!!\n-- GAME OVER --" << endl;
        return;
      }
      current_turn++;
    }
    cout << "Max turns reached. No winners!\n-- GAME OVER --" << endl;
  } 
  CDado dice;
};


// Juego manual
class ManualGame : public Game {
public:
  using Game::Game;

  bool playTurn() override {
    int player = (current_turn - 1) % num_players;
    cout << "Turn " << current_turn << " - Player " << player + 1
        << " (Position: " << positions[player] << ")" << endl;

    cout << "Press C to roll dice, or Q to quit: ";
    char choice;
    cin >> choice;
    if (toupper(choice) == 'Q') {
        cout << "Game ended by the user.\n-- GAME OVER --" << endl;
        return true;
    }

    int dice_roll = dice.roll();
    cout << "Dice rolled: " << dice_roll << endl;
    int new_position = positions[player] + dice_roll;

    // Ensure new_position is within the valid range
    if (new_position > num_tiles) {
        new_position = num_tiles;
    }
    if (new_position < 1) {
        new_position = 1;
    }

    Tile* current_tile = board[new_position].get();
    char tile_type = current_tile->getType();
    if (dynamic_cast<SnakeTile*>(current_tile)) {
        new_position = new_position + *dynamic_cast<SnakeTile*>(current_tile);
    } else if (dynamic_cast<LadderTile*>(current_tile)) {
        new_position = new_position + *dynamic_cast<LadderTile*>(current_tile);
    }

    // Ensure the new_position after interaction is within bounds
    if (new_position > num_tiles) {
        new_position = num_tiles;
    }
    if (new_position < 1) {
        new_position = 1;
    }

    Turno turno(current_turn, player, positions[player], dice_roll, tile_type, new_position);
    std::cout << turno << std::endl;

    positions[player] = new_position;

    return positions[player] == num_tiles;
  }


};

// Juego automático
class AutomaticGame : public Game {
public:
  using Game::Game;

  bool playTurn() override {
    int player = (current_turn - 1) % num_players;
    int dice_roll = dice.roll();
    int new_position = positions[player] + dice_roll;

    if (new_position > num_tiles) {
        new_position = num_tiles;
    }
    if (new_position < 1) {
        new_position = 1;
    }

    Tile* current_tile = board[new_position].get();
    char tile_type = current_tile->getType();
    if (dynamic_cast<SnakeTile*>(current_tile)) {
        new_position = new_position + *dynamic_cast<SnakeTile*>(current_tile);
    } else if (dynamic_cast<LadderTile*>(current_tile)) {
        new_position = new_position + *dynamic_cast<LadderTile*>(current_tile);
    }

    if (new_position > num_tiles) {
        new_position = num_tiles;
    }
    if (new_position < 1) {
        new_position = 1;
    }

    Turno turno(current_turn, player, positions[player], dice_roll, tile_type, new_position);
    std::cout << turno << std::endl;

    positions[player] = new_position;

    return positions[player] == num_tiles;
  }


};

int main() {
  srand(static_cast<unsigned>(time(0)));

  cout << "Select game size: ";
  int n; cin >> n;

  cout << "Select amount of players: ";
  int players; cin >> players;

  cout << "Select game penalty: ";
  int penalty; cin >> penalty;

  cout << "Select maximum turns: ";
  int turns; cin >> turns;

  cout << "Select game reward: ";
  int reward; cin >> reward;

  cout << "Select game type: (M) Manual or (A) Automatic: ";
  char game_type;
  cin >> game_type;
  game_type = toupper(game_type);

  Game *game;
  if (game_type == 'A') {
    game = new AutomaticGame(n, players, turns, penalty, reward);
  } else {
    game = new ManualGame(n, players, turns, penalty, reward);
  }

  cout << "Select number of snakes: ";
  int num_snakes; cin >> num_snakes;
  game->configureSnakes(num_snakes);

  cout << "Select number of ladders: ";
  int num_ladders; cin >> num_ladders;
  game->configureLadders(num_ladders);

  game->start();

  return 0;
}

