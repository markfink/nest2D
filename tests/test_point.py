from nest2D import Point


def test_point():
    p = Point(-5000000, 8954050)
    assert repr(p) == 'Point(-5000000, 8954050)'
    assert Point.__doc__ == '2D Point'
    assert p.x == -5000000
    assert p.y == 8954050

