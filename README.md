# Introduction

Nest2D is a 2D bin packaging tool for python.

Nest2D works with the C++ libnest2d backend for speed. For python C++ interoperability we use pybind11.
 
The library is written in a way that it should be usable out of the box with a very simple interface. The backend is reasonably fast and robust, being built on top of boost geometry and the 
[polyclipping](http://www.angusj.com/delphi/clipper.php) library.


# Example

A simple example may be the best way to demonstrate the usage of the library.

``` python
from nest2D import Point, Box, Item, nest, SVGWriter

def add_shape1(n, items):
    for i in range(n):
        item = Item([
            Point(-5000000, 8954050),
            Point(5000000, 8954050),
            Point(5000000, -45949),
            Point(4972609, -568550),
            Point(3500000, -8954050),
            Point(-3500000, -8954050),
            Point(-4972609, -568550),
            Point(-5000000, -45949),
            Point(-5000000, 8954050)
        ])
        items.append(item)

def add_shape2(n, items):
    for i in range(n):
        item = Item([
            Point(-11750000, 13057900),
            Point(-9807860, 15000000),
            Point(4392139, 24000000),
            Point(11750000, 24000000),
            Point(11750000, -24000000),
            Point(4392139, -24000000),
            Point(-9807860, -15000000),
            Point(-11750000, -13057900),
            Point(-11750000, 13057900)
        ])
        items.append(item)

def main():
    box = Box(150000000, 150000000)
    input = []
    add_shape1(23, input)
    add_shape2(15, input)

    pgrp = nest(input, box)

    sw = SVGWriter()
    sw.write_packgroup(pgrp)
    sw.save()
```

It is worth to note that the type of the polygon carried by the Item objects is
the type defined as a polygon by the geometry backend. In the example we use the
clipper backend and clipper works with integer coordinates.


## Example call

``` bash
$ pip install nest2D
$ python examples/simple_sample.py
```

## Example output

![Alt text](https://raw.githubusercontent.com/markfink/nest2d/master/docs/media/example_output.svg?sanitize=true)


## License

Unfortunately libnest2d is provided with a contractible GPL type license so we can not release this with better license terms. Details can be found in the LICENSE file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.


# References

- [pybind11](https://github.com/pybind/pybind11)
- [libnest2d](https://github.com/tamasmeszaros/libnest2d)
- [SVGNest](https://github.com/Jack000/SVGnest)
- [An effective heuristic for the two-dimensional irregular
bin packing problem](http://www.cs.stir.ac.uk/~goc/papers/EffectiveHueristic2DAOR2013.pdf)
- [Complete and robust no-fit polygon generation for the irregular stock cutting problem](https://www.sciencedirect.com/science/article/abs/pii/S0377221706001639)
