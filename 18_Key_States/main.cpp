#include "../WrapperClasses/LTexture.hpp"

const int screenWidth = 640;
const int screenHeight = 480;

int main(int argc,char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    LTexture upTexture,downTexture,leftTexture,rightTexture,defaultTexture;
    if(!init(window,renderer,screenWidth,screenHeight,"Key States"))
    {
        std::cerr << "SDL failed to initialize!\n";
    }
    else
    {
        if(!upTexture.load_from_file(renderer,"up.png")||!downTexture.load_from_file(renderer,"down.png")||
           !leftTexture.load_from_file(renderer,"left.png")||!rightTexture.load_from_file(renderer,"right.png")||
           !defaultTexture.load_from_file(renderer,"press.png"))
        {
            std::cerr << "Failed to load textures!\n";
        }
        else
        {
            bool running = true;
            SDL_Event event;
            LTexture* currentTexture = &defaultTexture;
            while(running)
            {
                while(SDL_PollEvent(&event)!=0)
                {
                    if(event.type==SDL_QUIT)
                    {
                        running = false;
                    }
                }
                const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
                if(currentKeyStates[SDL_SCANCODE_UP])
                {
                    currentTexture = &upTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_DOWN])
                {
                    currentTexture = &downTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_LEFT])
                {
                    currentTexture = &leftTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_RIGHT])
                {
                    currentTexture = &rightTexture;
                }
                else
                {
                    currentTexture = &defaultTexture;
                }

                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);

                currentTexture->render(renderer,0,0);

                SDL_RenderPresent(renderer);
            }
        }
    }
    upTexture.free();
    downTexture.free();
    leftTexture.free();
    rightTexture.free();
    close(window,renderer);
    return 0;
}
