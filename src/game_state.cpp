#include "Game_State.hpp"
#include <random>

Game::Game() :
    WIDTH{11},
    HEIGHT{11},
    food{10, 5, Cell::FOOD},
    runtime_state{Runtime::RUNNING},
    ate_food{false},
    snake()
{
    update();
}

int Game::get_WIDTH() const {
    return WIDTH;
}

int Game::get_HEIGHT() const {
    return HEIGHT;
}

Runtime Game::get_runtime_state() const {
    return runtime_state;
}

void Game::update() {
    ate_food = false;
    board_state.clear();

    for (int y{0}; y <= HEIGHT; y++) {
        for (int x{0}; x <= WIDTH; x++) {
            Tile T(x, y, Cell::EMPTY);

            if (y == 0 || y == HEIGHT || x == 0 || x == WIDTH) T.set_type(Cell::WALL);
            else if (food.get_x() == x && food.get_y() == y) T.set_type(Cell::FOOD);
            else {
                auto& segments{snake.get_segments()};
                for (size_t i{0}; i < segments.size(); i++) {
                    if (segments[i].get_x() == x && segments[i].get_y() == y) {
                        if (i == 0) {
                            T.set_type(Cell::HEAD);
                            break;
                        }

                        T.set_type(Cell::BODY);
                        break;
                    }
                }
            }

            board_state.push_back(T);
        }
    }

    empty_tiles.clear();
    for (const Tile& T: board_state) {
        if (T.get_type() == Cell::EMPTY) empty_tiles.push_back(T);
    }
}

void Game::move(const Direction dir) {
    auto snake_dir = snake.get_dir();
    const bool opposite =
        (snake_dir == Direction::UP && dir == Direction::DOWN) ||
        (snake_dir == Direction::DOWN && dir == Direction::UP) ||
        (snake_dir == Direction::LEFT && dir == Direction::RIGHT) ||
        (snake_dir == Direction::RIGHT && dir == Direction::LEFT);

    const Tile& head = snake.get_segments().front();
    Tile new_head({}, {}, Cell::HEAD);

    switch (snake_dir) {
        case Direction::UP:
            new_head.set_x(head.get_x());
            new_head.set_y(head.get_y() - 1);
            break;
        case Direction::DOWN:
            new_head.set_x(head.get_x());
            new_head.set_y(head.get_y() + 1);
            break;
        case Direction::LEFT:
            new_head.set_x(head.get_x() - 1);
            new_head.set_y(head.get_y());
            break;
        case Direction::RIGHT:
            new_head.set_x(head.get_x() + 1);
            new_head.set_y(head.get_y());
            break;            
    }
    
    auto& segments = snake.get_segments();
    segments.insert(segments.begin(), new_head);

    check_collisions();
    if (!ate_food) segments.pop_back();
    else {
        update();
        generate_food();
    }

    update();
}

void Game::check_collisions() {
    const auto& segments = snake.get_segments();
    const Tile& head = segments.front();
    const int x{head.get_x()}, y{head.get_y()};

    if (x == 0 || x == WIDTH || y == 0 || y == HEIGHT) {
        runtime_state = Runtime::LOSE;
        return;
    }

    for (size_t i{1}; i < segments.size(); i++) {
        if (x == segments[i].get_x() && y == segments[i].get_y()) {
            runtime_state = Runtime::LOSE;
            return;
        }
    }

    if (x == food.get_x() && y == food.get_y()) ate_food = true;
}

void Game::check_win() {
    if (empty_tiles.empty()) runtime_state = Runtime::WIN;
}

void Game::generate_food() {
