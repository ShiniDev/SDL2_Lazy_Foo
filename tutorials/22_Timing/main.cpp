#include <MySdlFunctions.hpp>
#include <LTexture.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <sstream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc,char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* currentFont = nullptr;
    LTexture textRender;
    LTexture textTime;
    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Timing"))
    {
        std::cerr << "SDL failed to initialize!\n";
    }
    else
    {
        currentFont = TTF_OpenFont(appendBasePath("lazy.ttf").c_str(),28);
        SDL_Color textColor = {0,0,0,255};
        textRender.load_from_rendered_text(renderer,currentFont,"Press enter to reset start time.",textColor);
        
        bool running = true;
        SDL_Event event;
        Uint32 startTime = 0;
        std::stringstream timeText;
        while(running)
        {
            while(SDL_PollEvent(&event)!=0)
            {
                if(event.type==SDL_QUIT)
                {
                    running = false;
                }
                else if(event.type==SDL_KEYDOWN&&event.key.keysym.sym == SDLK_RETURN)
                {
                    startTime = SDL_GetTicks();
                }
            }
            timeText.str("");
            timeText << "Milliseconds since start time: " << SDL_GetTicks() - startTime;
            textTime.load_from_rendered_text(renderer,currentFont,timeText.str().c_str(),textColor);

            SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
            SDL_RenderClear(renderer);

            textRender.render(renderer,(SCREEN_WIDTH-textRender.get_width())/2,0);
            textTime.render(renderer,(SCREEN_WIDTH-textTime.get_width())/2,(SCREEN_HEIGHT-textTime.get_height())/2);

            SDL_RenderPresent(renderer);
        }
    }
    textRender.free();
    textTime.free();
    close(window,renderer,currentFont);
    return 0;
}