#include "LTimer.hpp"

LTimer::LTimer()
    :startTicks{0},pausedTicks{0},started{false},paused{false}
    {
    }

void LTimer::start()
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void LTimer::pause()
{
    if(started && !paused)
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void LTimer::unpause()
{
    if(started && paused)
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

void LTimer::stop()
{
    if(started)
    {
        started = false;
        paused = false;
        startTicks = 0;
        pausedTicks = 0;
    }
}

Uint32 LTimer::getTicks()
{
    if(started)
    {
        if(paused)
        {
            return pausedTicks;
        }
        else
        {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}