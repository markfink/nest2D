from nest2d import Point, Box, Item, nest


def main():
    box = Box(150000000, 150000000)

    i1 = Item([
        Point(-5000000, 8954050),
        Point(5000000, 8954050),
        Point(5000000, -45949),
        Point(4972609, -568550),
        Point(3500000, -8954050),
        Point(-3500000, -8954050),
        Point(-4972609, -568550),
        Point(-5000000, -45949),
        Point(-5000000, 8954050)
        ]
    )
    input = [i1] * 2

    bins = nest(input, box)
    print(dir(bins))
    print(f"repr: {repr(bins)}")
    print(bins.__doc__)


if __name__ == '__main__':
    main()
