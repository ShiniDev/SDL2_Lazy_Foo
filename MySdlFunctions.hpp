#ifndef MYSDLFUNCTIONS_HPP
#define MYSDLFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//To be used in storing surface or texture that are changeable through the following keys
enum KeyPressSurfaces
{
    Key_Press_Surface_Default,
    Key_Press_Surface_Up,
    Key_Press_Surface_Down,
    Key_Press_Surface_Left,
    Key_Press_Surface_Right,
    Key_Press_Surface_Total
};

//Imagetype options
enum ImageType
{
    Bmp_File,
    Other_Img_File
};

//Declaration of Functions

//Returns an initialized texture from a path
inline SDL_Texture* load_texture(SDL_Renderer*&,const std::string&,ImageType);

//Returns an initialized surface from a path
inline SDL_Surface* load_surface(const std::string&,ImageType);

//Returns an initialized surface from a path in a more optimized way
inline SDL_Surface* optimize_load_surface(SDL_Surface*&,const std::string&,ImageType);

//Initializes SDL Window and Surface
inline bool init(SDL_Window*&,SDL_Surface*&,int,int,const std::string&);

//Initializes SDL Window and Renderer
inline bool init(SDL_Window*&,SDL_Renderer*&,int,int,const std::string&);

inline bool init_with_joystick(SDL_Window*& win,SDL_Renderer*& render,SDL_Joystick*& joystick,SDL_Haptic*& haptic,int screenWidth,int screenHeight,const std::string& title);

//Attaches the imagefile from filepath to the SDL Surface argument
inline bool load_media(SDL_Surface*&,const std::string&,ImageType);

//It was used to initialize SDL Surface array on Lesson 04
inline bool init_key_surface(SDL_Surface*[]);

//Reads a sprite sheet frame by frame to the vector of SDL Rect with the help of the int arguments
inline void load_sprite_sheet(std::vector<SDL_Rect>&,int,int,int,int);

//Destroys the SDL Window and Surface parameter, and calls SDL_Quit() and IMG_Quit()
inline void close(SDL_Window*&,SDL_Surface*&);

//Destroys the SDL Window and Renderer parameter, and calls SDL_Quit() and IMG_Quit()
inline void close(SDL_Window*&,SDL_Renderer*&);

//Destroys the SDL Window, Renderer and TTF_font parameter, and calls SDL_Quit(),IMG_Quit() and TTF_Quit()
inline void close(SDL_Window*&,SDL_Renderer*&,TTF_Font*&);

//Destroys the SDL Window,Texture,and Renderer parameter, and calls SDL_Quit() and IMG_Quit()
inline void close(SDL_Window*&,SDL_Texture*&,SDL_Renderer*&);

//--End

inline SDL_Texture* load_texture(SDL_Renderer *&rend,const std::string& filepath, ImageType t)
{
    SDL_Texture* text = nullptr;
    SDL_Surface* img_surface = nullptr;
    if(t==ImageType::Bmp_File)
    {
        img_surface = SDL_LoadBMP(filepath.c_str());
    }
    else
    {
        img_surface = IMG_Load(filepath.c_str());
    }
    if(!img_surface)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return text;
    }
    text = SDL_CreateTextureFromSurface(rend,img_surface);
    if(!text)
    {
        std::cerr << "Unable to create texture from " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return text;
    }
    SDL_FreeSurface(img_surface);
    return text;
}

inline SDL_Surface* load_surface(const std::string& filepath,ImageType t)
{
    SDL_Surface* surf = nullptr;
    if(t==Bmp_File)surf = SDL_LoadBMP(filepath.c_str());
    else surf =IMG_Load(filepath.c_str());
    if(!surf)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
    }
    return surf;
}

inline SDL_Surface* optimize_load_surface(SDL_Surface*& screen_surface,const std::string& filepath,ImageType t)
{
    SDL_Surface* optimized_surface = nullptr;
    SDL_Surface* surface = nullptr;
    if(t==Bmp_File)
    {
        surface = SDL_LoadBMP(filepath.c_str());
    }
    else
    {
        surface = IMG_Load(filepath.c_str());
    }
    if(!surface)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return surface;
    }
    optimized_surface = SDL_ConvertSurface(surface,screen_surface->format,0);
    if(!optimized_surface)std::cerr << "Unable to optimized image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
    SDL_FreeSurface(surface);
    return optimized_surface;
}

inline bool init(SDL_Window *&win,SDL_Surface *&surf,int SCREEN_WIDTH,int SCREEN_HEIGHT,const std::string& WIN_NAME)
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    win = SDL_CreateWindow(WIN_NAME.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!win)
    {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
        std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    if(TTF_Init() == -1)
    {
        std::cerr << "SDL TTF could not be initialize! SDL_ttf Error: " << TTF_GetError() << '\n';
        return false;
    }
    surf = SDL_GetWindowSurface(win);
    return true;
}

inline bool init(SDL_Window *&win,SDL_Renderer *&rend,int SCREEN_WIDTH,int SCREEN_HEIGHT,const std::string& WIN_NAME)
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    win = SDL_CreateWindow(WIN_NAME.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!win)
    {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    rend = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!rend)
    {
        std::cerr << "Rendered could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetRenderDrawColor(rend,0xFf,0xFF,0xFF,0xFF);
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
        std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    if(TTF_Init() == -1)
    {
        std::cerr << "SDL TTF could not be initialize! SDL_ttf Error: " << TTF_GetError() << '\n';
        return false;
    }
    return true;
}

inline bool init_with_joystick(SDL_Window*& win,SDL_Renderer*& render,SDL_Joystick*& joystick,SDL_Haptic*& haptic,int screenWidth,int screenHeight,const std::string& title)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC)<0)
    {
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    win = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenWidth,screenHeight,SDL_WINDOW_SHOWN);
    if(!win)
    {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    render = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!render)
    {
        std::cerr << "Rendered could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetRenderDrawColor(render,0xFf,0xFF,0xFF,0xFF);
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
        std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    if(TTF_Init() == -1)
    {
        std::cerr << "SDL TTF could not be initialize! SDL_ttf Error: " << TTF_GetError() << '\n';
        return false;
    }
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
    {
        std::cerr << "Warning: Linear texture filtering not enabled!\n";
    }
    if(SDL_NumJoysticks()<=0)
    {
        std::cerr << "Warning: No joysticks connected!\n";
    }
    joystick = SDL_JoystickOpen(0);
    if(!joystick)
    {
        std::cerr << "Warning: Unable to open game controller! SDL Error: " << SDL_GetError() << '\n';
    }
    haptic = SDL_HapticOpenFromJoystick(joystick);
    if(!haptic)
    {
        std::cerr << "Warning: Controller does not support haptics! SDL Error: " << SDL_GetError() << '\n';
    }
    if(SDL_HapticRumbleInit(haptic)<0)
    {
        std::cerr << "Warning: Unable to initialize rumble! SDL Error: " << SDL_GetError() << '\n';
    }
    return true;

}

inline bool load_media(SDL_Surface *&surf,const std::string& filepath,ImageType t)
{
    if(t==Bmp_File)
    {
        surf = SDL_LoadBMP(filepath.c_str());
    }
    else
    {
        surf = IMG_Load(filepath.c_str());
    }
    if(!surf)
    {
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    return true;
}

inline bool init_key_surface(SDL_Surface* surf[])
{
    bool success = true;
    surf[Key_Press_Surface_Default] = load_surface("images/press.bmp",Bmp_File);
    if(!surf[Key_Press_Surface_Default])
    {
        success = false;
        std::cerr << "Failed to load default image!\n";
    }
    surf[Key_Press_Surface_Up] = load_surface("images/up.bmp",Bmp_File);
    if(!surf[Key_Press_Surface_Up])
    {
        success = false;
        std::cerr << "Failed to load up image!\n";
    }
    surf[Key_Press_Surface_Down] = load_surface("images/down.bmp",Bmp_File);
    if(!surf[Key_Press_Surface_Down])
    {
        success = false;
        std::cerr << "Failed to load down image!\n";
    }
    surf[Key_Press_Surface_Left] = load_surface("images/left.bmp",Bmp_File);
    if(!surf[Key_Press_Surface_Left])
    {
        success = false;
        std::cerr << "Failed to load left image!\n";
    }

    surf[Key_Press_Surface_Right] = load_surface("images/right.bmp",Bmp_File);
    if(!surf[Key_Press_Surface_Right])
    {
        success = false;
        std::cerr << "Failed to load right image!\n";
    }
    return success;
}

inline void load_sprite_sheet(std::vector<SDL_Rect>& r,int framewidth,int frameheight,int imagewidth,int imageheight)
{
    for(int i = 0,x = 0, y = 0; y < imageheight; x+=framewidth,i++)
    {
        r.push_back(SDL_Rect{x,y,framewidth,frameheight});
        if(x+framewidth>=imagewidth)
        {
            x = -framewidth;
            y+=frameheight;
        }
    }
}

inline void close(SDL_Window *&win,SDL_Surface *&surf)
{
    SDL_FreeSurface(surf);
    surf = nullptr;
    SDL_DestroyWindow(win);
    win = nullptr;
    SDL_Quit();
}

inline void close(SDL_Window *&win, SDL_Renderer *&rend)
{
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    win = nullptr;
    rend = nullptr;
    IMG_Quit();
    SDL_Quit();
}

inline void close(SDL_Window *&window, SDL_Renderer *&renderer,TTF_Font *&font)
{
    TTF_CloseFont(font);
    font = nullptr;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

inline void close(SDL_Window *&win,SDL_Texture *&text,SDL_Renderer *&rend)
{
    SDL_DestroyTexture(text);
    text = nullptr;
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    win = nullptr;
    rend = nullptr;

    IMG_Quit();
    SDL_Quit();
}
#endif
