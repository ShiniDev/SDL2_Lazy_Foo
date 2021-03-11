#include <LTexture.hpp>
#include <SDL2/SDL_mixer.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc,char* argv[])
{
     Mix_Music* music = nullptr;
     Mix_Chunk* scratch = nullptr;
     Mix_Chunk* high = nullptr;
     Mix_Chunk* medium = nullptr;
     Mix_Chunk* low = nullptr;
     SDL_Window* window = nullptr;
     SDL_Renderer* renderer = nullptr;
     LTexture prompt;
     if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Sound Effects and Music"))
     {
          std::cerr << "Failed to initialize SDL!\n";
     }
     else
     {
          music = Mix_LoadMUS(appendBasePath("Assets/Sounds/beat.wav").c_str());
          scratch = Mix_LoadWAV(appendBasePath("Assets/Sounds/scratch.wav").c_str());
          high = Mix_LoadWAV(appendBasePath("Assets/Sounds/high.wav").c_str());
          medium = Mix_LoadWAV(appendBasePath("Assets/Sounds/medium.wav").c_str());
          low = Mix_LoadWAV(appendBasePath("Assets/Sounds/low.wav").c_str());
          prompt.load_from_file(renderer,appendBasePath("Assets/Images/prompt.png"));
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
               }
               const Uint8* keyState = SDL_GetKeyboardState(nullptr);
               if(keyState[SDL_SCANCODE_ESCAPE])
               {
                    running = false;
               }
               else if(keyState[SDL_SCANCODE_1])
               {
                    Mix_PlayChannel(-1,scratch,0);
               }
               else if(keyState[SDL_SCANCODE_2])
               {
                    Mix_PlayChannel(-1,high,0);
               }
               else if(keyState[SDL_SCANCODE_3])
               {
                    Mix_PlayChannel(-1,medium,0);
               }
               else if(keyState[SDL_SCANCODE_4])
               {
                    Mix_PlayChannel(-1,low,0);
               }
               else if(keyState[SDL_SCANCODE_9])
               {
                    if(Mix_PlayingMusic()==0)
                    {
                         Mix_PlayMusic(music,0);
                    }
                    else
                    {
                         if(Mix_PausedMusic()==0)
                         {
                              Mix_ResumeMusic();
                         }
                         else
                         {
                              Mix_PausedMusic();
                         }
                    }
               }
               else if(keyState[SDL_SCANCODE_0])
               {
                    Mix_HaltMusic();
               }
               SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
               SDL_RenderClear(renderer);

               prompt.render(renderer,(SCREEN_WIDTH-prompt.get_width())/2,(SCREEN_HEIGHT-prompt.get_height())/2);

               SDL_RenderPresent(renderer);
          }
     }
     Mix_FreeMusic(music);
     music = nullptr;
     Mix_FreeChunk(scratch);
     Mix_FreeChunk(high);
     Mix_FreeChunk(medium);
     Mix_FreeChunk(low);
     scratch = nullptr;
     high = nullptr;
     medium = nullptr;
     low = nullptr;
     prompt.free();
     close(window,renderer);
     return 0;
}
