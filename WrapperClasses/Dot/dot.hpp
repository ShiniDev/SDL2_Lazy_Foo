#ifndef DOT_HPP_
#define DOT_HPP_

#include <LTexture.hpp>
#include <MySdlFunctions.hpp>
#include <SDL2/SDL.h>

class Dot
{
public:
    //Dot dimensions
    static const int DOT_WIDTH = 30;
    static const int DOT_HEIGHT = 30;

    //Dot velocity/speed
    static const int DOT_VEL = 15;

    //Initializes variables
    //Intended to have no default constructor
    //Loads the dot.bmp automatically
    Dot(SDL_Renderer* renderer);

    //Frees texture
    ~Dot();
    
    //Handle keyboard inputs
    void handleEvent(SDL_Event& e);

    //Updates position
    void move(SDL_Window* window);

    //Renders to screen
    void render(SDL_Renderer* renderer);

private:
    int xVel, yVel;
    int xPos, yPos;
    LTexture texture;
};

#endif