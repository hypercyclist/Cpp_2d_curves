#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

class SdlPainter;
class SDL_Window;
class Size;

#include <memory>

class SdlGraphics : public std::enable_shared_from_this<SdlGraphics>
{
    private:
        std::shared_ptr<Size> windowSize;
        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SdlPainter> painter;

        void initializeWindow();
        void initializePainter();
        void destructWindow();

    public:
        SdlGraphics(Size _windowSize);
        ~SdlGraphics();
        void initializeContext();
        void pollEvents();
        void updateWindow();
        std::shared_ptr<SdlPainter> getPainter();
        Size getWindowSize();
};

#endif
