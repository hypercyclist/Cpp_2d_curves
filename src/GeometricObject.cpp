#include "GeometricObject.h"

#include "Point.h"
#include "SdlPainter.h"
#include "Size.h"

GeometricObject::GeometricObject()
{
}

GeometricObject::~GeometricObject()
{
}

void GeometricObject::generateObject(Point _position, Size _size)
{
}

void GeometricObject::draw(std::shared_ptr<SdlPainter> _painter)
{
}

void GeometricObject::drawCoordinateAndDerivativeAtT(
    float _momentT, std::shared_ptr<SdlPainter> _painter)
{
}

std::shared_ptr<Point> GeometricObject::getPosition()
{
    return position;
}
