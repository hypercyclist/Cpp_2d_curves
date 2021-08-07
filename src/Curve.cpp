#include "Curve.h"

#include "Color.h"
#include "Point.h"
#include "SdlPainter.h"
#include "Size.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_timer.h"
#define PI 3.1415

Curve::Curve()
{
}

Curve::~Curve()
{
}

void Curve::generateObject(Point _position, Size _size)
{
    position = std::make_shared<Point>(_position);
    size = std::make_shared<Size>(_size);
    int controlLinePointsCount = 5 + (rand() % 5);
    for (int i = 0; i < controlLinePointsCount; i++)
    {
        controlLinePoints.push_back(
            Point(rand() % _size.getWidth(), rand() % _size.getHeight())
        );
    }
}

void Curve::draw(std::shared_ptr<SdlPainter> _painter)
{
    for(int i = 0; i < controlLinePoints.size() - 2; i++)
    {
        _painter->setDrawColor(_painter->getLineColor());
        _painter->drawLine(*position + controlLinePoints[i], *position + controlLinePoints[i + 1]);
        _painter->drawLine(*position + controlLinePoints[i + 1], *position + controlLinePoints[i + 2]);

        _painter->setDrawColor(_painter->getCurveColor());
        drawPartOfCurve(*position + controlLinePoints[i], *position + controlLinePoints[i + 1],
            *position + controlLinePoints[i + 2], _painter);
        drawCoordinateAndDerivativeAtT(*position + controlLinePoints[i], *position + controlLinePoints[i + 1],
            *position + controlLinePoints[i + 2], PI / 4, _painter);
    }
}

void Curve::drawPartOfCurve(Point _a, Point _b, Point _c, std::shared_ptr<SdlPainter> _painter)
{
    Point middleAb = getPointInMomentT(_a, _b, 0.5);
    Point middleBc = getPointInMomentT(_b, _c, 0.5);

    for (float i = 0 ; i < 1; i += 0.01)
    {
        Point middleAbToB = getPointInMomentT(middleAb, _b, i);
        Point middleBcToB = getPointInMomentT(_b, middleBc, i);

        Point needPoint = getPointInMomentT(middleAbToB, middleBcToB, i);

        SDL_RenderDrawPoint(_painter->getRenderer().get(), needPoint.getX(), needPoint.getY());
    }
}

Point Curve::getPointInMomentT(Point _a, Point _b, float _momentT)
{
    Point pointInMomentT(
        _a.getX() + ((_b.getX() - _a.getX()) * _momentT),
        _a.getY() + ((_b.getY() - _a.getY()) * _momentT)
    );
    return pointInMomentT;
}

void Curve::drawCoordinateAndDerivativeAtT(
    Point _a, Point _b, Point _c,
    float _momentT, std::shared_ptr<SdlPainter> _painter)
{
    Point middleAb = getPointInMomentT(_a, _b, 0.5);
    Point middleBc = getPointInMomentT(_b, _c, 0.5);

    Point middleAbToB = getPointInMomentT(middleAb, _b, _momentT);
    Point middleBcToB = getPointInMomentT(_b, middleBc, _momentT);

    Point needPoint = getPointInMomentT(middleAbToB, middleBcToB, _momentT);

    _painter->setDrawColor(Color(30, 255, 30));
    _painter->drawLine(middleAbToB, middleBcToB);
    _painter->setDrawColor(Color(255, 255, 30));
    _painter->drawDot(needPoint, 9);
}

std::vector<Point>& Curve::getControlLinePoints()
{
    return controlLinePoints;
}
