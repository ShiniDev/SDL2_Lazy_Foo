#include <LTexture.hpp>

#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc,char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Joystick* gameController = nullptr;
    SDL_Haptic* controllerHaptic = nullptr;
    LTexture splashTexture;
    if(!init_with_joystick(window,renderer,gameController,controllerHaptic,SCREEN_WIDTH,SCREEN_HEIGHT,"Force Feedback"))
    {
        std::cerr << "Failed to initialize SDL!\n";
    }
    else
    {
        if(!splashTexture.load_from_file(renderer,appendBasePath("splash.png")))
        {
            std::cerr << "Failed to load splash.png!\n";
        }
        else
        {
            bool running = true;
            SDL_Event event;
            while(running)
            {
                while(SDL_PollEvent(&event)!=0)
                {
                    if(event.type==SDL_QUIT)
                    {
                        running = false;
                    }
                    else if(event.type==SDL_JOYBUTTONDOWN)
                    {
                        if(SDL_HapticRumblePlay(controllerHaptic,0.75,500)!=0)
                        {
                            std::cerr << "Warning: Unable to play rumble! " << SDL_GetError() << '\n';
                        }
                    }
                }
                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);

                splashTexture.render(renderer,(SCREEN_WIDTH-splashTexture.get_width())/2,(SCREEN_HEIGHT-splashTexture.get_height())/2);

                SDL_RenderPresent(renderer);
            }
        }
    }
    splashTexture.free();
    SDL_HapticClose(controllerHaptic);
    SDL_JoystickClose(gameController);
    controllerHaptic = nullptr;
    gameController = nullptr;

    close(window,renderer);
    return 0;
}
