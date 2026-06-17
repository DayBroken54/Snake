#pragma once

enum class Cell {
    EMPTY,
    WALL,
    HEAD,
    BODY,
    FOOD
};

class Tile {
public:
    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;
    [[nodiscard]] Cell get_type() const;

    void set_x(int x);
    void set_y(int y);
    void set_type(Cell type);

private:
    int x{}, y{};
    Cell type{};
};
