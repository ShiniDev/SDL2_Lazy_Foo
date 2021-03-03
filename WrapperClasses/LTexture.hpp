#ifndef LTEXTURE_HPP
#define LTEXTURE_HPP
#include "../MySdlFunctions.hpp"

class LTexture
{
    public:
        //Initializes class variables
        LTexture();
        //Calls free() which deallocates memory
        ~LTexture();

        //Initializes texture class variable from a filepath, and makes the Uint8 argument transparent
        bool load_from_file_trans(SDL_Renderer*&,const std::string&,Uint8,Uint8,Uint8);

        //Initializes texture class variable from a filepath
        bool load_from_file(SDL_Renderer*&,const std::string&);

        #if defined(SDL_TTF_MAJOR_VERSION)
        //Initializes texture class variable with a text texture
        bool load_from_rendered_text(SDL_Renderer*&,TTF_Font*&,const std::string&,SDL_Color);
        #endif

        //Deallocates memory
        void free();

        //Sets the color of texture class variable
        void set_color(Uint8 r, Uint8 g, Uint8 b);

        //Sets the alpha of texture class variable
        void set_alpha(Uint8 alpha);

        //Set blending
        void set_blend_mode(SDL_BlendMode blending);

        //Renders the texture class variable to the SDL_Renderer argument
        void render(SDL_Renderer*&,int,int,SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

        //Returns image width
        int get_width();
        //Returns image height
        int get_height();
    private:
        SDL_Texture* texture;
        int imgwidth;
        int imgheight;
};

#endif
