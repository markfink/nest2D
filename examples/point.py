import nest2d


def main():
    p = nest2d.Point(-5000000, 8954050)
    print(f"repr: {repr(p)}")
    #print(f"x: {p.x}")  # TODO
    #print(f"y: {p.y}")
    print(nest2d.__doc__)
    print(nest2d.Point.__doc__)


if __name__ == '__main__':
    main()
