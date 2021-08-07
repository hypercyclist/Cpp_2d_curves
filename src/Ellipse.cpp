#include "Ellipse.h"

#include "Color.h"
#include "Point.h"
#include "SdlPainter.h"
#include "Size.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_timer.h"
#define PI 3.1415

#include <memory>
#include <vector>

Ellipse::Ellipse()
    :
    Curve()
{
}

Ellipse::~Ellipse()
{
}

void Ellipse::generateObject(Point _position, Size _size)
{
    position = std::make_shared<Point>(_position);
    size = std::make_shared<Size>(_size);
    int controlLinePointsCount = 4;
    controlLinePoints.resize(controlLinePointsCount);

    controlLinePoints[0] = Point(rand() % _size.getWidth(), rand() % _size.getHeight());
    controlLinePoints[2] = Point(rand() % _size.getWidth(), rand() % _size.getHeight());

    controlLinePoints[1] = Point(controlLinePoints[0].getX(), controlLinePoints[2].getY());
    controlLinePoints[3] = Point(controlLinePoints[2].getX(), controlLinePoints[0].getY());
}

void Ellipse::draw(std::shared_ptr<SdlPainter> _painter)
{
    for (int i = 0; i < controlLinePoints.size() - 2; i++)
    {
        _painter->setDrawColor(_painter->getLineColor());
        _painter->drawLine(*position + controlLinePoints[i], *position + controlLinePoints[i + 1]);
        _painter->drawLine(*position + controlLinePoints[i + 1], *position + controlLinePoints[i + 2]);

        _painter->setDrawColor(_painter->getEllipseColor());
        drawPartOfCurve(*position + controlLinePoints[i], *position + controlLinePoints[i + 1],
            *position + controlLinePoints[i + 2], _painter);
        drawCoordinateAndDerivativeAtT(*position + controlLinePoints[i], *position + controlLinePoints[i + 1],
        *position + controlLinePoints[i + 2], PI / 4, _painter);
    }
    _painter->setDrawColor(_painter->getLineColor());
    _painter->drawLine(*position + controlLinePoints[controlLinePoints.size() - 2], *position + controlLinePoints[controlLinePoints.size() - 1]);
    _painter->drawLine(*position + controlLinePoints[controlLinePoints.size() - 1], *position + controlLinePoints[0]);

    _painter->setDrawColor(_painter->getEllipseColor());
    drawPartOfCurve(*position + controlLinePoints[controlLinePoints.size() - 2], *position + controlLinePoints[controlLinePoints.size() - 1],
        *position + controlLinePoints[0], _painter);
    drawPartOfCurve(*position + controlLinePoints[controlLinePoints.size() - 1], *position + controlLinePoints[0],
    *position + controlLinePoints[1], _painter);
    
    drawCoordinateAndDerivativeAtT(*position + controlLinePoints[controlLinePoints.size() - 2], *position + controlLinePoints[controlLinePoints.size() - 1],
        *position + controlLinePoints[0], PI / 4, _painter);
    drawCoordinateAndDerivativeAtT(*position + controlLinePoints[controlLinePoints.size() - 1], *position + controlLinePoints[0],
    *position + controlLinePoints[1], PI / 4, _painter);
}

// void Ellipse::generateObjectParallelogram(Size _size)
// {
//     switch (rand() % 2)
//     {
//         case 0:
//             std::cout << "1" << std::endl;
//             controlLinePoints[0] = Point(rand() % _size.getWidth(), rand() % _size.getHeight());
//             controlLinePoints[1] = Point(controlLinePoints[0].getX(), rand() % _size.getHeight());
//             controlLinePoints[2] = Point(rand() % _size.getWidth(), 
//                 (controlLinePoints[0].getY() - controlLinePoints[1].getY()) + rand() % (_size.getHeight() - controlLinePoints[0].getY() - controlLinePoints[1].getY()));
//             controlLinePoints[3] = Point(controlLinePoints[2].getX(), controlLinePoints[2].getY() + controlLinePoints[0].getY() - controlLinePoints[1].getY());
            
//             break;
//         case 1:
//             std::cout << "2" << std::endl;
//             controlLinePoints[0] = Point(rand() % _size.getWidth(), rand() % _size.getHeight());
//             controlLinePoints[1] = Point(rand() % _size.getWidth(), controlLinePoints[0].getY());
//             controlLinePoints[2] = Point((controlLinePoints[0].getX() - controlLinePoints[1].getX()) + rand() % (_size.getWidth() - controlLinePoints[0].getX() - controlLinePoints[1].getX()), 
//                 rand() % _size.getHeight());
//             controlLinePoints[3] = Point(controlLinePoints[2].getX() + controlLinePoints[0].getX() - controlLinePoints[1].getX(), controlLinePoints[2].getY());
//             break;
//     }
// }
