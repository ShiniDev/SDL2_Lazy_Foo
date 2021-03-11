#include "LTexture.hpp"

LTexture::LTexture()
    :texture(nullptr),imgwidth(0),imgheight(0)
{}

LTexture::~LTexture()
{
    free();
}

bool LTexture::load_from_file_trans(SDL_Renderer*& rend,const std::string &filepath,Uint8 r,Uint8 g,Uint8 b)
{
    free();
    SDL_Surface* loaded_surface = IMG_Load(filepath.c_str());
    if(!loaded_surface)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetColorKey(loaded_surface,SDL_TRUE,SDL_MapRGB(loaded_surface->format,r,g,b));
    texture = SDL_CreateTextureFromSurface(rend,loaded_surface);
    if(!texture)
    {
        std::cerr << "Unable to create texture from " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    imgwidth = loaded_surface->w;
    imgheight = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    return true;
}

bool LTexture::load_from_file(SDL_Renderer *&rend, const std::string &filepath)
{
    free();
    SDL_Surface* loaded_surface = IMG_Load(filepath.c_str());
    if(!loaded_surface)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    texture = SDL_CreateTextureFromSurface(rend,loaded_surface);
    if(!texture)
    {
        std::cerr << "Unable to create texture from " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    imgwidth = loaded_surface->w;
    imgheight = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    return true;
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool LTexture::load_from_rendered_text(SDL_Renderer*& renderer,TTF_Font *&font, const std::string &text, SDL_Color color)
{
    free();
    SDL_Surface* text_surface = TTF_RenderText_Solid(font,text.c_str(),color);
    if(!text_surface)
    {
        std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << '\n';
        return false;
    }
    texture = SDL_CreateTextureFromSurface(renderer,text_surface);
    if(!texture)
    {
        std::cerr << "Unable to create texture from rendered text! SDL Error : " << SDL_GetError() << '\n';
        return false;
    }
    imgwidth = text_surface->w;
    imgheight = text_surface->h;
    SDL_FreeSurface(text_surface);
    return texture!=nullptr;
}
#endif

void LTexture::free()
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        imgwidth = 0;
        imgheight = 0;
    }
}

void LTexture::set_color(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(texture,r,g,b);
}

void LTexture::set_alpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture,alpha);
}

void LTexture::set_blend_mode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(texture,blending);
}

void LTexture::render(SDL_Renderer *& rend, int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    SDL_Rect img_properties = {x,y,imgwidth,imgheight};
    if(clip)
    {
        img_properties.w = clip->w;
        img_properties.h = clip->h;
    }
    SDL_RenderCopyEx(rend,texture,clip,&img_properties,angle,center,flip);
}

int LTexture::get_width()
{
    return imgwidth;
}

int LTexture::get_height()
{
    return imgheight;
}
