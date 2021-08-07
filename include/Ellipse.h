#ifndef ELLIPSE_H
#define ELLIPSE_H

class Point;
class SdlPainter;
class Size;

#include "Curve.h"

class Ellipse : public Curve
{
    public:
        Ellipse();
        ~Ellipse();
        void generateObject(Point _position, Size _size);

        void draw(std::shared_ptr<SdlPainter> _painter);
};

#endif
