#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

class Point;
class SdlPainter;
class Size;

#include <memory>

class GeometricObject
{
    protected:
        std::shared_ptr<Point> position;
        std::shared_ptr<Size> size;
    public:
        GeometricObject();
        ~GeometricObject();
        virtual void generateObject(Point _position, Size _size);
        virtual void draw(std::shared_ptr<SdlPainter> _painter);
        virtual void drawCoordinateAndDerivativeAtT(
            float _momentT, std::shared_ptr<SdlPainter> _painter);
        std::shared_ptr<Point> getPosition();
};

#endif
