#ifndef SDLPAINTER_H
#define SDLPAINTER_H

class Color;
class Point;
class SdlGraphics;
class SDL_Renderer;
class Size;

#include <memory>

class SdlPainter
{
    private:
        std::shared_ptr<SdlGraphics> parent;
        std::shared_ptr<SDL_Renderer> renderer;

        std::shared_ptr<Color> backgroundColor;
        std::shared_ptr<Color> borderColor;
        std::shared_ptr<Color> lineColor;
        std::shared_ptr<Color> curveColor;
        std::shared_ptr<Color> ellipseColor;

        void initializeColors();
        
    public:
        SdlPainter(std::shared_ptr<SdlGraphics> _parent);
        ~SdlPainter();
        void setDrawColor(Color _color);
        std::shared_ptr<SDL_Renderer> getRenderer();
        void setRenderer(std::shared_ptr<SDL_Renderer> _renderer);
        void clearWindow();
        void drawNet(Size _netSize);
        void drawLine(Point _a, Point _b);
        void drawDot(Point _point, int _thickness);

        Color getBackgroundColor();
        Color getBorderColor();
        Color getLineColor();
        Color getCurveColor();
        Color getEllipseColor();
};

#endif
