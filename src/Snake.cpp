#include "Snake.hpp"

Snake::Snake() :
    segments{
        {3, 5, Cell::HEAD},
        {2, 5, Cell::BODY},
        {1, 5, Cell::BODY}
    },
    dir{Direction::RIGHT}
{}

std::vector<Tile>& Snake::get_segments() {
    return segments;
}

Direction Snake::get_dir() const {
    return dir;
}

void Snake::set_dir(const Direction dir) {
    this->dir = dir;
}