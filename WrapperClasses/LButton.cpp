#include "LButton.hpp"

LButton::LButton(LTexture& renderer,std::vector<SDL_Rect>& v)
    :position(SDL_Point{0,0}),sprites(v),button_sprite_sheet_renderer(renderer)
{
   current_button = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::set_position(int x, int y){
    position.x = x;
    position.y = y;
}

void LButton::handle_event(SDL_Event *e){
    if(e->type==SDL_MOUSEMOTION || e->type==SDL_MOUSEBUTTONUP || e->type==SDL_MOUSEBUTTONDOWN){
        int x,y;
        SDL_GetMouseState(&x,&y);
        if(x<position.x||x>(position.x+sprites[0].w)||y<position.y||y>(position.y+sprites[0].h)){
            current_button = BUTTON_SPRITE_MOUSE_OUT;
        }else{
            switch(e->type){
                case SDL_MOUSEMOTION:
                    current_button = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    current_button = BUTTON_SPRITE_MOUSE_DOWN;
                    break;
                case SDL_MOUSEBUTTONUP:
                    current_button = BUTTON_SPRITE_MOUSE_UP;
                    break;
                default:
                    break;
            }
        }
    }
}

void LButton::render(SDL_Renderer*& renderer){
    button_sprite_sheet_renderer.render(renderer,position.x,position.y,&sprites[current_button]);
}
