#ifndef LBUTTON_HPP
#define LBUTTON_HPP

#include <LTexture.hpp>

#include <SDL2/SDL.h>
#include <vector>

enum ButtonSpriteEvents
{
    Button_Sprite_Mouse_Out,
    Button_Sprite_Mouse_Over_Motion,
    Button_Sprite_Mouse_Down,
    Button_Sprite_Mouse_Up,
    Button_Sprite_Mouse_Total
};

class LButton
{
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
