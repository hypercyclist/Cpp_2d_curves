#include "Color.h"

Color::Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b)
{
}

Color::~Color()
{
}

void Color::setColorRgb(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}

int Color::getR() const
{
    return r;
}

void Color::setR(int _r)
{
    r = _r;
}

int Color::getG() const
{
    return g;
}

void Color::setG(int _g)
{
    g = _g;
}

int Color::getB() const
{
    return b;
}

void Color::setB(int _b)
{
    b = _b;
}
