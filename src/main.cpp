#include <pybind11/pybind11.h>

#include <libnest2d/libnest2d.hpp>


int add(int i, int j) {
    return i + j;
}


namespace py = pybind11;


//using Point = CDT::Point;
//using Point = libnest2d::PointImpl;
using Point = libnest2d::Point;

PYBIND11_MODULE(nest2d, m)
{
    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    py::class_<Point>(m, "Point")
        .def(py::init<int, int>(),  py::arg("x"), py::arg("y"))
        //.def(py::init<double, double>(), py::arg("x"), py::arg("y"))
        //.def_property_readonly("x", &Point::x)
        //.def_property_readonly("y", &Point::y)
        /*.def("__repr__",
             [](const Point &p) {
                 std::string r("Point(");
                 r += boost::lexical_cast<std::string>(p.x());
                 r += ", ";
                 r += boost::lexical_cast<std::string>(p.y());
                 r += ")";
                 return r;
             }
        )*/
        .def("__eq__",
            [](const Point &p, const Point & q) {
                return p == q;
            }
        );
}