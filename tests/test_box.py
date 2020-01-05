from nest2D import Box


def test_box():
    b = Box(150000000, 150000000)
    #assert repr(b) == ''  # TODO
    assert Box.__doc__ == '2D Box point pair'
