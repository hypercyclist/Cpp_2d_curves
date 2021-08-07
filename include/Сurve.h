#ifndef CURVE_H
#define CURVE_H

class Point;
class SdlPainter;
class Size;

#include "GeometricObject.h"

#include <vector>
#include <memory>

class Curve : public GeometricObject
{
    protected:
        std::vector<Point> controlLinePoints;
    public:
        Curve();
        ~Curve();
        virtual void generateObject(Point _position, Size _size);
        
        void draw(std::shared_ptr<SdlPainter> _painter);
        void drawPartOfCurve(Point _a, Point _b, Point _c, std::shared_ptr<SdlPainter> _painter);
        void drawCoordinateAndDerivativeAtT(
            Point _a, Point _b, Point _c, 
            float _momentT, std::shared_ptr<SdlPainter> _painter);

        Point getPointInMomentT(Point _a, Point _b, float _momentT);

        std::vector<Point>& getControlLinePoints();
};

#endif
