#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <libnest2d/libnest2d.hpp>

#include "../tools/printer_parts.hpp"
#include "../tools/svgtools.hpp"


namespace py = pybind11;

using Point = libnest2d::Point;
using Box = libnest2d::Box;
using Item = libnest2d::Item;
using PackGroup = libnest2d::PackGroup;
using SVGWriter = libnest2d::svg::SVGWriter<libnest2d::PolygonImpl>;

PYBIND11_MODULE(nest2D, m)
{
    m.doc() = "2D irregular bin packaging and nesting for python";

    py::class_<Point>(m, "Point", "2D Point")
        .def(py::init<int, int>(),  py::arg("x"), py::arg("y"))
        //.def_property_readonly("x", &Point::X)
        .def_property_readonly("x", [](const Point &p) { return p.X; })
        .def_property_readonly("y", [](const Point &p) { return p.Y; })
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
        //.def(py::init<int, int>())
        // custom constructor to define box center
        .def(py::init([](int x, int y) {
            return std::unique_ptr<Box>(new Box(x, y, {x/2, y/2}));
        }))
        ;

    // Item is a shape defined by points
    // see lib/libnest2d/include/libnest2d/nester.hpp
    py::class_<Item>(m, "Item", "An item to be placed on a bin.")
        .def(py::init<std::vector<Point>>())
        .def("__repr__",
             [](const Item &i) {
                 std::string r("Item(area: ");
                 r += boost::lexical_cast<std::string>(i.area());
                 r += ", bin_id: ";
                 r += boost::lexical_cast<std::string>(i.binId());
                 r += ", vertices: ";
                 r += boost::lexical_cast<std::string>(i.vertexCount());
                 r += ")";
                 return r;
             }
        )
        ;

    // The nest function takes two parameters input and box
    // see lib/libnest2d/include/libnest2d/libnest2d.hpp
    m.def("nest", [](std::vector<Item>& input, const Box& box) {
            size_t bins = libnest2d::nest(input, box);

            PackGroup pgrp(bins);

            for (Item &itm : input) {
                if (itm.binId() >= 0) pgrp[size_t(itm.binId())].emplace_back(itm);
                //py::print("bin_id: ", itm.binId());
                //py::print("vertices: ", itm.vertexCount());
            }

            //return pgrp;
            // we need to convert c++ type to python using py::cast
            py::object obj = py::cast(pgrp);
            return obj;
        },
        py::arg("input"),
        py::arg("box"),
        "Nest and pack the input items into the box bin."
        )
        ;

    py::class_<SVGWriter>(m, "SVGWriter", "SVGWriter tools to write pack_group to SVG.")
        .def(py::init([]() {
            // custom constructor
            SVGWriter::Config conf;
            conf.mm_in_coord_units = libnest2d::mm();
            return std::unique_ptr<SVGWriter>(new SVGWriter(conf));
        }))
        .def("write_packgroup", [](SVGWriter & sw, const PackGroup & pgrp) {
            sw.setSize(Box(libnest2d::mm(250), libnest2d::mm(210)));  // TODO make own call
            sw.writePackGroup(pgrp);
        })
        .def("save", [](SVGWriter & sw) {
            sw.save("out");
        })
        .def("__repr__",
             [](const SVGWriter &sw) {
                 std::string r("SVGWriter(");
                 r += ")";
                 return r;
             }
        );

}
