#ifndef LTEXTURE_HPP
#define LTEXTURE_HPP
#include "../MySdlFunctions.hpp"

class LTexture{
    public:
        //Initializes class variables
        LTexture();
        //Calls free() which deallocates memory
        ~LTexture();

        //Initializes texture class variable from a filepath, and makes the Uint8 argument transparent
        bool load_from_file_trans(SDL_Renderer*&,const std::string&,Uint8,Uint8,Uint8);

        //Deallocates memory
        void free();
        //Renders the texture class variable to the SDL_Renderer argument
        void render(SDL_Renderer*&,int,int);

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
