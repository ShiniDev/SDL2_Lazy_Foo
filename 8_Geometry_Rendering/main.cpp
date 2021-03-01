#include "../MySdlFunctions.hpp"

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;


int main(int argc, char* args[]){
   SDL_Window* win = nullptr;
   SDL_Renderer* rend = nullptr;
   if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"Geometry Rendering")){
       std::cerr << "Failed to initialize SDL!\n";
   }else{
       bool running = true;
       SDL_Event e;
       while(running){
           while(SDL_PollEvent(&e)!=0){
               if(e.type==SDL_QUIT)running = false;
           }
           SDL_SetRenderDrawColor(rend,0x00,0x00,0x00,0xFF);
           SDL_RenderClear(rend);
           SDL_Rect fill_rect = {SCREEN_WIDTH/4,SCREEN_HEIGHT/4,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
           SDL_SetRenderDrawColor(rend,0xFF,0x00,0x00,0xFF);
           SDL_RenderFillRect(rend,&fill_rect);
           SDL_Rect outline_rect = {SCREEN_WIDTH/6,SCREEN_HEIGHT/6,SCREEN_WIDTH*2/3,SCREEN_HEIGHT*2/3};
           SDL_SetRenderDrawColor(rend,0x00,0xff,0x00,0xff);
           SDL_RenderDrawRect(rend,&outline_rect);
           SDL_SetRenderDrawColor(rend,0x00,0x00,0xff,0xff);
           SDL_RenderDrawLine(rend,0,SCREEN_HEIGHT/2,SCREEN_WIDTH,SCREEN_HEIGHT/2);
           SDL_SetRenderDrawColor(rend,0xff,0xff,0x00,0xff);
           for(int i = 0; i < SCREEN_HEIGHT; i+=4){
               SDL_RenderDrawPoint(rend,SCREEN_WIDTH/2,i);
           }
           SDL_SetRenderDrawColor(rend,0xff,0xff,0xff,0xff);
           for(int x = 0, y = 0; x<SCREEN_WIDTH&&y<SCREEN_HEIGHT; x+=8,y+=6){
               SDL_RenderDrawPoint(rend,x,y);
           }
           SDL_RenderPresent(rend);
       }
   }
   close(win,rend);
   return 0;
}
