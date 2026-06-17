#pragma once

#include "Tile.hpp"
#include <vector>

enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Snake {
public:
    Snake();

private:
    std::vector<Tile> segments;
    Direction dir;
};
