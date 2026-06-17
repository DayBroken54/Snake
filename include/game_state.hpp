#pragma once

#include "Snake.hpp"

enum class Runtime {
    RUNNING,
    WIN,
    LOSE
};

class Game {
public:
    Game();

    void update();
    void move(Direction dir);
    void check_win();

private:
    const int WIDTH, HEIGHT;
    std::vector<Tile> board_state;
    Runtime runtime_state;
    std::vector<Tile> empty_tiles;
    Tile food;
    Snake snake;
    bool ate_food;

    void check_collisions();
    void generate_food();
};
