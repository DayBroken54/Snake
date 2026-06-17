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

    [[nodiscard]] std::vector<Tile>& get_segments();
    [[nodiscard]] Direction get_dir() const;

    void set_dir(const Direction dir);

private:
    std::vector<Tile> segments;
    Direction dir;
};
