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


if __name__ == '__main__':
    main()
