#include "Tile.h"

Tile::Tile(const int x, const int y, const Cell type) :
    x(x), y(y), type(type)
{}

int Tile::get_x() const {
    return x;
}

int Tile::get_y() const {
    return y;
}

Cell Tile::get_type() const {
    return type;
}

void Tile::set_x(const int x) {
    this->x = x;
}

void Tile::set_y(const int y) {
    this->y = y;
}

void Tile::set_type(const Cell type) {
    this->type = type;
}
