#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Game_State.hpp"

namespace py = pybind11;

PYBIND11_MODULE(libgame, m) {
    m.doc() = "Snake game bindings";

    py::enum_<Cell>(m, "Cell")
        .value("EMPTY", Cell::EMPTY)
        .value("WALL", Cell::WALL)
        .value("HEAD", Cell::HEAD)
        .value("BODY", Cell::BODY)
        .value("FOOD", Cell::FOOD)
        .export_values();

    py::enum_<Direction>(m, "Direction")
        .value("LEFT", Direction::LEFT)
        .value("RIGHT", Direction::RIGHT)
        .value("UP", Direction::UP)
        .value("DOWN", Direction::DOWN)
        .export_values();

    py::enum_<Runtime>(m, "Runtime")
        .value("RUNNING", Runtime::RUNNING)
        .value("WIN", Runtime::WIN)
        .value("LOSE", Runtime::LOSE)
        .export_values();

    py::class_<Tile>(m, "Tile")
        .def(py::init<int, int, Cell>())
        .def("get_x", &Tile::get_x)
        .def("get_y", &Tile::get_y)
        .def("get_type", &Tile::get_type)
        .def("set_x", &Tile::set_x)
        .def("set_y", &Tile::set_y)
        .def("set_type", &Tile::set_type);

    py::class_<Snake>(m, "Snake")
        .def(py::init<>())
        .def("get_segments", &Snake::get_segments)
        .def("get_dir", &Snake::get_dir)
        .def("set_dir", &Snake::set_dir);

    py::class_<Game>(m, "Game")
        .def(py::init<>())
        .def("get_WIDTH", &Game::get_WIDTH)
        .def("get_HEIGHT", &Game::get_HEIGHT)
        .def("update", &Game::update)
        .def("move", &Game::move)
        .def("check_win", &Game::check_win);
}
