from nest2D import SVGWriter


def test_svgwriter():
    sw = SVGWriter()
    assert repr(sw) == 'SVGWriter()'
    assert SVGWriter.__doc__ == 'SVGWriter tools to write pack_group to SVG.'

