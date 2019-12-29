import nest2d


def main():
    sw = nest2d.SVGWriter()
    print(f"repr: {repr(sw)}")
    print(nest2d.SVGWriter.__doc__)


if __name__ == '__main__':
    main()
