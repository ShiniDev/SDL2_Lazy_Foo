#include "dot.hpp"

Dot::Dot(SDL_Renderer* renderer)
    :xVel{0}, yVel{0}, xPos{0}, yPos{0}
    {
        std::string basePath = SDL_GetBasePath();
        texture.load_from_file_trans(renderer, appendString(basePath, "dot.png"), 0xff, 0xff, 0xff);
    }

Dot::~Dot()
{
    texture.free();
}

void Dot::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            yVel -= DOT_VEL;
            break;
        case SDLK_DOWN:
            yVel += DOT_VEL;
            break;
        case SDLK_RIGHT:
            xVel += DOT_VEL;
            break;
        case SDLK_LEFT:
            xVel -= DOT_VEL;
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            yVel += DOT_VEL;
            break;
        case SDLK_DOWN:
            yVel -= DOT_VEL;
            break;
        case SDLK_RIGHT:
            xVel -= DOT_VEL;
            break;
        case SDLK_LEFT:
            xVel += DOT_VEL;
            break;
        }
    }
}

void Dot::move(SDL_Window* window)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    xPos += xVel;
    yPos += yVel;

    if (xPos < 0 || xPos + DOT_WIDTH > screenWidth)
    {
        xPos -= xVel;
    }

    if (yPos < 0 || yPos + DOT_HEIGHT > screenHeight)
    {
        yPos -= yVel;
    }
}

void Dot::render(SDL_Renderer* renderer)
{
    texture.render(renderer,xPos,yPos);
}
