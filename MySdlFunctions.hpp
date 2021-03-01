#ifndef MYSDLFUNCTIONS_HPP
#define MYSDLFUNCTIONS_HPP
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum KeyPressSurfaces{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

enum ImageType{
    BMP_FILE,
    OTHER_IMG_FILE
};

//Declaration of Functions
inline SDL_Texture* load_texture(SDL_Renderer*&,const std::string&,ImageType);

inline SDL_Surface* load_surface(const std::string&,ImageType);
inline SDL_Surface* optimize_load_surface(SDL_Surface*&,const std::string&,ImageType);

inline bool init(SDL_Window*&,SDL_Surface*&,int,int,const std::string&);	//Initializes SDL Window with SDL_Surface
inline bool init(SDL_Window*&,SDL_Renderer*&,int,int,const std::string&);	//Initializes SDL Window with SDL_Renderer
inline bool load_media(SDL_Surface*&,const std::string&,ImageType);
inline bool init_key_surface(SDL_Surface*[]);

inline void close(SDL_Window*&,SDL_Surface*&);
inline void close(SDL_Window*&,SDL_Renderer*&);
inline void close(SDL_Window*&,SDL_Texture*&,SDL_Renderer*&);
//--End

inline SDL_Texture* load_texture(SDL_Renderer *&rend,const std::string& filepath, ImageType t){
    SDL_Texture* text = nullptr;
    SDL_Surface* img_surface = nullptr;
    if(t==ImageType::BMP_FILE)img_surface = SDL_LoadBMP(filepath.c_str());
    else img_surface = IMG_Load(filepath.c_str());
    if(!img_surface){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return text;
    }
    text = SDL_CreateTextureFromSurface(rend,img_surface);
    if(!text){
        std::cerr << "Unable to create texture from " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return text;
    }
    SDL_FreeSurface(img_surface);
    return text;
}

inline SDL_Surface* load_surface(const std::string& filepath,ImageType t){
    SDL_Surface* surf = nullptr;
    if(t==BMP_FILE)surf = SDL_LoadBMP(filepath.c_str());
    else surf =IMG_Load(filepath.c_str());
    if(!surf){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
    }
    return surf;
}

inline SDL_Surface* optimize_load_surface(SDL_Surface*& screen_surface,const std::string& filepath,ImageType t){
    SDL_Surface* optimized_surface = nullptr;
    SDL_Surface* surface = nullptr;
    if(t==BMP_FILE)surface = SDL_LoadBMP(filepath.c_str());
    else surface = IMG_Load(filepath.c_str());
    if(!surface){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return surface;
    }
    optimized_surface = SDL_ConvertSurface(surface,screen_surface->format,0);
    if(!optimized_surface)std::cerr << "Unable to optimized image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
    SDL_FreeSurface(surface);
    return optimized_surface;
}

inline bool init(SDL_Window *&win,SDL_Surface *&surf,int SCREEN_WIDTH,int SCREEN_HEIGHT,const std::string& WIN_NAME){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    win = SDL_CreateWindow(WIN_NAME.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!win){
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags)){
        std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    surf = SDL_GetWindowSurface(win);
    return true;
}

inline bool init(SDL_Window *&win,SDL_Renderer *&rend,int SCREEN_WIDTH,int SCREEN_HEIGHT,const std::string& WIN_NAME){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    win = SDL_CreateWindow(WIN_NAME.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!win){
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    rend = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    if(!rend){
        std::cerr << "Rendered could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetRenderDrawColor(rend,0xFf,0xFF,0xFF,0xFF);
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags)){
        std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    return true;
}

inline bool load_media(SDL_Surface *&surf,const std::string& filepath,ImageType t){
    if(t==BMP_FILE)surf = SDL_LoadBMP(filepath.c_str());
    else surf = IMG_Load(filepath.c_str());
    if(!surf){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    return true;
}

inline bool init_key_surface(SDL_Surface *surf[]){
    bool success = true;
    surf[KEY_PRESS_SURFACE_DEFAULT] = load_surface("images/press.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_DEFAULT]){
        success = false;
        std::cerr << "Failed to load default image!\n";
    }
    surf[KEY_PRESS_SURFACE_UP] = load_surface("images/up.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_UP]){
        success = false;
        std::cerr << "Failed to load up image!\n";
    }
    surf[KEY_PRESS_SURFACE_DOWN] = load_surface("images/down.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_DOWN]){
        success = false;
        std::cerr << "Failed to load down image!\n";
    }
    surf[KEY_PRESS_SURFACE_LEFT] = load_surface("images/left.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_LEFT]){
        success = false;
        std::cerr << "Failed to load left image!\n";
    }

    surf[KEY_PRESS_SURFACE_RIGHT] = load_surface("images/right.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_RIGHT]){
        success = false;
        std::cerr << "Failed to load right image!\n";
    }
    return success;
}

inline void close(SDL_Window *&win,SDL_Surface *&surf){
    SDL_FreeSurface(surf);
    surf = nullptr;
    SDL_DestroyWindow(win);
    win = nullptr;
    SDL_Quit();
}

inline void close(SDL_Window *&win, SDL_Renderer *&rend){
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    win = nullptr;
    rend = nullptr;
    IMG_Quit();
    SDL_Quit();
}

inline void close(SDL_Window *&win,SDL_Texture *&text,SDL_Renderer *&rend){
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
