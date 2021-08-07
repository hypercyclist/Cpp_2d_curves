#ifndef APPLICATION_H
#define APPLICATION_H

class SdlGraphics;
class Size;

#include <memory>

class Application
{
    private:
        std::shared_ptr<Size> windowSize;
        std::shared_ptr<Size> netSize;
        std::shared_ptr<Size> cellSpace;

        std::shared_ptr<SdlGraphics> sdlGraphics;

    public:
        Application();
        ~Application();
        void drawRandomObjects();
};

#endif
