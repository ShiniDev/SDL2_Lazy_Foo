#include <dot.hpp>
#include <LTimer.hpp>
#include <MySdlFunctions.hpp>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 60;
const int SCREEN_TICK_PER_SECOND = 1000/60;

int main(int argc,char* argv[])
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    if (!init(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "Motion"))
    {
        std::cerr << "Failed to initialize SDL SDL Error: " << SDL_GetError() << '\n';
    }
    else
    {
        Dot movingDot(renderer);
        //Somehow vsync doesn't work on my computer so I'm going to limit the frames
        LTimer timer, capTimer;

        SDL_Event e;

        bool quit = false;
        Uint32 frames = 0;
        timer.start();
        while (!quit)
        {
            capTimer.start();
            while (SDL_PollEvent(&e))
            {
                movingDot.handleEvent(e);
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if (e.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }
            movingDot.move(window);
            SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(renderer);
            movingDot.render(renderer);
            SDL_RenderPresent(renderer);
            frames++;
            int timeElapsed = capTimer.getTicks();
            if (timeElapsed < SCREEN_TICK_PER_SECOND)
            {
                SDL_Delay(SCREEN_TICK_PER_SECOND - timeElapsed);
            }
        }
    }
    close(window,renderer);
    return 0;
}