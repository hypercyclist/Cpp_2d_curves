#include "SdlPainter.h"

#include "Color.h"
#include "Point.h"
#include "SdlGraphics.h"
#include "Size.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_timer.h"

SdlPainter::SdlPainter(std::shared_ptr<SdlGraphics> _parent)
    :
    parent(_parent),
    renderer(nullptr, SDL_DestroyRenderer)
{
    initializeColors();
}

SdlPainter::~SdlPainter()
{
}

void SdlPainter::initializeColors()
{
    backgroundColor = std::make_shared<Color>(30, 30, 30);
    borderColor = std::make_shared<Color>(200, 200, 200);
    lineColor = std::make_shared<Color>(50, 50, 255);
    curveColor = std::make_shared<Color>(255, 50, 50);
    ellipseColor = std::make_shared<Color>(255, 0, 255);
}

void SdlPainter::setDrawColor(Color _color)
{
    SDL_SetRenderDrawColor(renderer.get(), _color.getR(), 
        _color.getG(), _color.getB(), SDL_ALPHA_OPAQUE);
}

void SdlPainter::clearWindow()
{
    setDrawColor(*backgroundColor);
    SDL_RenderClear(renderer.get());
}

void SdlPainter::drawNet(Size _netSize)
{
    int windowWidth = parent->getWindowSize().getWidth();
    int windowHeight = parent->getWindowSize().getWidth();

    setDrawColor(*borderColor);
    drawLine( Point(0, 0), Point(windowWidth, 0));
    drawLine( Point(0, windowHeight - 1), Point(windowWidth, windowHeight - 1));
    drawLine( Point(0, 0), Point(0, windowHeight));
    drawLine( Point(windowWidth - 1, 0), Point(windowWidth - 1, windowHeight));

    for (int i = windowWidth; i >= 0; i -= windowWidth / _netSize.getWidth())
    {
        drawLine( Point(i, 0), Point(i, windowHeight) );
    }
    for (int i = -1; i < windowHeight; i += windowHeight / _netSize.getHeight())
    {
        drawLine( Point(windowWidth, i), Point(0, i) );
    }
}

void SdlPainter::drawLine(Point _a, Point _b)
{
    SDL_RenderDrawLine(renderer.get(), _a.getX(), _a.getY(), _b.getX(), _b.getY());
}

void SdlPainter::drawDot(Point _point, int _thickness)
{
    _thickness = _thickness % 2 == 0 ? _thickness + 1 : _thickness;
    Point drawPosition(
        _point.getX() - ((_thickness - 1) / 2), 
        _point.getY() - ((_thickness - 1) / 2)
    );
    for (int i = 0; i < _thickness; i++)
    {
        for (int j = 0; j < _thickness; j++)
        {
            SDL_RenderDrawPoint(renderer.get(), 
                drawPosition.getX(),
                drawPosition.getY()
            );
            drawPosition.setX(drawPosition.getX() + 1);
        }
        drawPosition.setX(drawPosition.getX() - _thickness);
        drawPosition.setY(drawPosition.getY() + 1);
    }
}

std::shared_ptr<SDL_Renderer> SdlPainter::getRenderer()
{
    return renderer;
}

void SdlPainter::setRenderer(std::shared_ptr<SDL_Renderer> _renderer)
{
    renderer = _renderer;
}

Color SdlPainter::getBackgroundColor()
{
    return *backgroundColor;
}

Color SdlPainter::getBorderColor()
{
    return *borderColor;
}

Color SdlPainter::getLineColor()
{
    return *lineColor;
}

Color SdlPainter::getCurveColor()
{
    return *curveColor;
}

Color SdlPainter::getEllipseColor()
{
    return *ellipseColor;
}
