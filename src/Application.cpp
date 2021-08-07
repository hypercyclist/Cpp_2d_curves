#include "Application.h"

#include "Curve.h"
#include "Ellipse.h"
#include "GeometricObject.h"
#include "Point.h"
#include "SdlGraphics.h"
#include "SdlPainter.h"
#include "Size.h"

#include <memory>
#include <time.h>
#include <vector>

Application::Application()
    :
    windowSize(std::make_shared<Size>(800, 800)),
    netSize(std::make_shared<Size>(3, 3))
{
    cellSpace = std::make_shared<Size>
    (
        windowSize->getWidth() / netSize->getWidth(),
        windowSize->getHeight() / netSize->getHeight()
    );
    sdlGraphics = std::make_shared<SdlGraphics>(*windowSize);
    sdlGraphics->initializeContext();
    
    srand(time(nullptr));
    drawRandomObjects();

    sdlGraphics->updateWindow();
    sdlGraphics->pollEvents();
}

Application::~Application()
{
    
}

void Application::drawRandomObjects()
{
    std::shared_ptr<SdlPainter> painter = sdlGraphics->getPainter();
    painter->clearWindow();

    painter->drawNet(*netSize);

    std::vector<std::shared_ptr<GeometricObject>> geometricObjects;
    for (int i = 0; i < netSize->getHeight(); i++)
    {
        for (int j = 0; j < netSize->getWidth(); j++)
        {
            switch(rand() % 2)
            {
                case 0: geometricObjects.push_back(std::make_shared<Curve>()); break;
                case 1: geometricObjects.push_back(std::make_shared<Ellipse>()); break;
            }
            int currentObjectInder = i * netSize->getHeight() + j;
            geometricObjects[currentObjectInder]->generateObject(
                Point(
                    j * cellSpace->getWidth(), 
                    i * cellSpace->getHeight()
                ), 
                *cellSpace
            );
            geometricObjects[currentObjectInder]->draw(painter);
        }
    }
}

// Вернуть точку и вектор в момент Т
// Вернуть точку и вектор в момент PI / 4