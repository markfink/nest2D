from nest2D import Point, Item


def test_item():
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
    assert repr(i1) == 'Item(area: 166258748205509, bin_id: -1, vertices: 9)'
    assert Item.__doc__ == 'An item to be placed on a bin.'
