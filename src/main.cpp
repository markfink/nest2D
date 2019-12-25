#include <pybind11/pybind11.h>

#include <libnest2d/libnest2d.hpp>


int add(int i, int j) {
    return i + j;
}


namespace py = pybind11;

using Point = libnest2d::Point;

PYBIND11_MODULE(nest2d, m)
{
    m.doc() = "2D irregular bin packaging and nesting for python";

    py::class_<Point>(m, "Point", "2D Point")
        .def(py::init<int, int>(),  py::arg("x"), py::arg("y"))
        //.def_property_readonly("x", &Point::X) // TODO
        //.def_property_readonly("y", &Point::Y)
        .def("__repr__",
             [](const Point &p) {
                 std::string r("Point(");
                 r += boost::lexical_cast<std::string>(p.X);
                 r += ", ";
                 r += boost::lexical_cast<std::string>(p.Y);
                 r += ")";
                 return r;
             }
        )
        .def("__eq__",
            [](const Point &p, const Point & q) {
                return p == q;
            }
        );
}