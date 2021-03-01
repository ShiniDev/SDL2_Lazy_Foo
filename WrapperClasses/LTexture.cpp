#include "LTexture.hpp"

LTexture::LTexture()
    :texture(nullptr),imgwidth(0),imgheight(0)
{}

LTexture::~LTexture(){
    free();
}

bool LTexture::load_from_file_trans(SDL_Renderer*& rend,const std::string &filepath,Uint8 r,Uint8 g,Uint8 b){
    free();
    SDL_Surface* loaded_surface = IMG_Load(filepath.c_str());
    if(!loaded_surface){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetColorKey(loaded_surface,SDL_TRUE,SDL_MapRGB(loaded_surface->format,r,g,b));
    texture = SDL_CreateTextureFromSurface(rend,loaded_surface);
    if(!texture){
        std::cerr << "Unable to create texture from " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    imgwidth = loaded_surface->w;
    imgheight = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    return true;
}

void LTexture::free(){
    if(texture){
        SDL_DestroyTexture(texture);
        texture = nullptr;
        imgwidth = 0;
        imgheight = 0;
    }
}

void LTexture::render(SDL_Renderer *& rend, int x, int y){
    SDL_Rect img_properties = {x,y,imgwidth,imgheight};
    SDL_RenderCopy(rend,texture,nullptr,&img_properties);
}

int LTexture::get_width(){return imgwidth;}
int LTexture::get_height(){return imgheight;}
