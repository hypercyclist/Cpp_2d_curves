#include "SdlGraphics.h"

#include "SdlPainter.h"
#include "Size.h"

#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL2/SDL_timer.h"

#include <iostream>

SdlGraphics::SdlGraphics(Size _windowSize)
    : 
    windowSize(std::make_shared<Size>(_windowSize)),
    window(nullptr, SDL_DestroyWindow)
{
}

SdlGraphics::~SdlGraphics()
{
    destructWindow();
}

void SdlGraphics::initializeContext()
{
    initializeWindow();
    initializePainter();
}

void SdlGraphics::initializeWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }
    window.reset(
        SDL_CreateWindow("Curves", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, windowSize->getWidth(), windowSize->getHeight(), SDL_WINDOW_SHOWN),
        SDL_DestroyWindow
    );
}

void SdlGraphics::initializePainter()
{
    painter = std::make_shared<SdlPainter>(shared_from_this());
    painter->setRenderer(std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED), 
            SDL_DestroyRenderer
        )
    );
}

void SdlGraphics::destructWindow()
{
    SDL_Quit();
}

void SdlGraphics::pollEvents()
{
    bool run = true;
    while (run)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if( event.type == SDL_QUIT )
            {
                run = false;
            }
        }
    }
}

void SdlGraphics::updateWindow()
{
    SDL_RenderPresent(painter->getRenderer().get());
}

std::shared_ptr<SdlPainter> SdlGraphics::getPainter()
{
    return painter;
}

Size SdlGraphics::getWindowSize()
{
    return *windowSize;
}

// void SdlGraphics::initializeThread()
// {
//     needRender = true;
//     renderThread = std::make_shared<std::thread>(&SdlGraphics::render, this);
// }
// void SdlGraphics::render()
// {
//     while (needRender)
//     {
//         SDL_RenderPresent(painter->getRenderer().get());
//         SDL_Delay(1000 / 60);
//     }
// }
// void SdlGraphics::startRender()
// {
//     renderThread->detach();
// }
