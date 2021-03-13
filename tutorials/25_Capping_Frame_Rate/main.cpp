#include <LTimer.hpp>
#include <LTexture.hpp>
#include <MySdlFunctions.hpp>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <sstream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

int main(int argc,char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    std::string basePath = SDL_GetBasePath();
    if (!init(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "Capping Frame Rate"))
    {
        std::cerr << "Failed to initialize SDL! SDL Error: " << SDL_GetError() << '\n';
    }
    else
    {
        LTexture fpsRenderer;
        LTimer timer, capTimer;

        font = TTF_OpenFont(appendString(basePath, "lazy.ttf").c_str(), 28);

        SDL_Color black{0, 0, 0};
        SDL_Event e;

        bool quit = false;
        Uint32 frames = 0;
        std::stringstream fpsText;

        timer.start();
        while (!quit)
        {
            capTimer.start();
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if (e.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }

            float averageFps = frames / (timer.getTicks() / 1000.0f);
            if (averageFps > 200000)
            {
                averageFps = 0;
            }

            fpsText.str("");
            fpsText << "Average fps " << averageFps;
            fpsRenderer.load_from_rendered_text(renderer, font, fpsText.str(), black);

            SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(renderer);

            fpsRenderer.render(renderer, (SCREEN_WIDTH - fpsRenderer.get_width()) / 2, (SCREEN_HEIGHT - fpsRenderer.get_height()) / 2);

            SDL_RenderPresent(renderer);

            frames++;
            int frameTicks = capTimer.getTicks();
            if (frameTicks < SCREEN_TICKS_PER_FRAME)
            {
                SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
            }
        }
        TTF_CloseFont(font);
        font = nullptr;
    }
    close(window, renderer);
    return 0;
}