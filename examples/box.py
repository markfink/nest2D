import nest2d


def main():
    b = nest2d.Box(150000000, 150000000)
    print(f"repr: {repr(b)}")
    #print(f"x: {p.x}")  # TODO
    #print(f"y: {p.y}")
    print(nest2d.Box.__doc__)


if __name__ == '__main__':
    main()
