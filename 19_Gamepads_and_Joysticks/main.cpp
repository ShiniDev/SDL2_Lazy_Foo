#include "../WrapperClasses/LTexture.hpp"

#include <iostream>
#include <cmath>

//Defined a macro instead of using a global variable

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define JOYSTICK_DEAD_ZONE 8000

int main(int argc,char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Joystick* joystick = nullptr;
    LTexture arrowTexture;
    if(!init_with_joystick(window,renderer,joystick,SCREEN_WIDTH,SCREEN_HEIGHT,"Gamepads and Joysticks"))
    {
        std::cerr << "SDL failed to initialize!\n";
    }
    else
    {
        if(!arrowTexture.load_from_file(renderer,"arrow.png"))
        {
            std::cerr << "Failed to load arrow.png!\n";
        }
        else
        {
            bool running = true;
            SDL_Event event;
            int xDir = 0;
            int yDir = 0;
            while(running)
            {
                while(SDL_PollEvent(&event)!=0)
                {
                    if(event.type==SDL_QUIT)
                    {
                        running = false;
                    }
                    else if(event.type == SDL_JOYAXISMOTION)
                    {
                        if(event.jaxis.which == 0)
                        {
                            if(event.jaxis.axis == 0)
                            {
                                if(event.jaxis.value < -JOYSTICK_DEAD_ZONE)
                                {
                                    xDir = -1;
                                }
                                else if(event.jaxis.value > JOYSTICK_DEAD_ZONE)
                                {
                                    xDir = 1;
                                }
                                else
                                {
                                    xDir = 0;
                                }
                            }
                            else if(event.jaxis.axis == 1)
                            {
                                if(event.jaxis.value < -JOYSTICK_DEAD_ZONE)
                                {
                                    yDir = -1;
                                }
                                else if(event.jaxis.value > JOYSTICK_DEAD_ZONE)
                                {
                                    yDir = 1;
                                }
                                else
                                {
                                    yDir = 0;
                                }
                            }
                        }
                    }
                }
                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);

                double joystickAngle = std::atan2((double)yDir,(double)xDir)*(180.0/M_PI);
                if(xDir == 0&&yDir == 0)
                {
                    joystickAngle = 0;
                }

                arrowTexture.render(renderer,(SCREEN_WIDTH-arrowTexture.get_width())/2,(SCREEN_HEIGHT-arrowTexture.get_height())/2,nullptr,joystickAngle);
                SDL_RenderPresent(renderer);
            }
        }
    }
    SDL_JoystickClose(joystick);
    joystick = nullptr;
    arrowTexture.free();
    close(window,renderer);
    return 0;
}
