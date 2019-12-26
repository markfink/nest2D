from nest2d import Point, Item


def main():
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
    print(f"repr: {repr(i1)}")
    print(Item.__doc__)


if __name__ == '__main__':
    main()



