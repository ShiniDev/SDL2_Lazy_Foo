#ifndef LBUTTON_HPP
#define LBUTTON_HPP

#include "LTexture.hpp"

#include <SDL2/SDL.h>
#include <vector>

enum ButtonSpriteEvents{
    BUTTON_SPRITE_MOUSE_OUT,
    BUTTON_SPRITE_MOUSE_OVER_MOTION,
    BUTTON_SPRITE_MOUSE_DOWN,
    BUTTON_SPRITE_MOUSE_UP,
    BUTTON_SPRITE_MOUSE_TOTAL
};

class LButton{
    public:
        //Initializes internal variables
        LButton(LTexture&,std::vector<SDL_Rect>&);

        //Sets top left position
        void set_position(int x,int y);

        //Handles mouse events
        void handle_event(SDL_Event* e);

        //Shows button sprite
        void render(SDL_Renderer*&);

    private:
        SDL_Point position;
        std::vector<SDL_Rect>& sprites;
        LTexture& button_sprite_sheet_renderer;
        ButtonSpriteEvents current_button;
};

#endif
