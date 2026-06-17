#include "Snake.hpp"

Snake::Snake() {
    segments.push_back({3, 5, Cell::HEAD});
    segments.push_back({2, 5, Cell::BODY});
    segments.push_back({1, 5, Cell::BODY});
}

std::vector<Tile>& Snake::get_segments() {
    return segments;
}

Direction Snake::get_dir() const {
    return dir;
}

void Snake::set_dir(const Direction dir) {
    this->dir = dir;
}
