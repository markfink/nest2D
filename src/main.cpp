#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <libnest2d/libnest2d.hpp>


int add(int i, int j) {
    return i + j;
}


namespace py = pybind11;

using Point = libnest2d::Point;
using Box = libnest2d::Box;
using Item = libnest2d::Item;

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

    // see lib/libnest2d/include/libnest2d/geometry_traits.hpp
    py::class_<Box>(m, "Box", "2D Box point pair")
        .def(py::init<int, int>())
        ;

    // Item is a shape defined by points
    // see lib/libnest2d/include/libnest2d/nester.hpp
    py::class_<Item>(m, "Item", "An item to be placed on a bin.")
        .def(py::init<std::vector<Point>>())
        .def("__repr__",
             [](const Item &i) {
                 std::string r("Item area: ");
                 r += boost::lexical_cast<std::string>(i.area());
                 return r;
             }
        )
        ;

    // The nest function takes two parameters input and box
    // see lib/libnest2d/include/libnest2d/libnest2d.hpp
    m.def("nest", py::overload_cast<std::vector<Item>&, const Box&>(&libnest2d::nest)
        )
        ;

}