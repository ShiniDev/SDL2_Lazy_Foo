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
inline SDL_Surface* loaded_surface(const std::string&,ImageType);
inline SDL_Surface* optimize_load_surface(SDL_Surface*&,const std::string&,ImageType);

inline bool init(SDL_Window*&,SDL_Surface*&,int,int);
inline bool load_media(SDL_Surface*&,const std::string&,ImageType);
inline bool init_key_surface(SDL_Surface*[]);

inline void close(SDL_Window*&,SDL_Surface*&);
//--End

inline SDL_Surface* loaded_surface(const std::string& filepath,ImageType t){
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
        std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << '\n';
    }else{
        optimized_surface = SDL_ConvertSurface(surface,screen_surface->format,0);
        if(!optimized_surface){
            std::cerr << "Unable to optimized image! SDL Error: " << SDL_GetError() << '\n';
        }
        SDL_FreeSurface(surface);
    }
    return optimized_surface;
}

inline bool init(SDL_Window *&win,SDL_Surface *&surf,int SCREEN_WIDTH,int SCREEN_HEIGHT){
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        success = false;
    }else{
        win = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(!win){
            std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
            success = false;
        }else{
            int img_flags = IMG_INIT_PNG;
            if(!(IMG_Init(img_flags) & img_flags)){
                std::cerr << "PNG SDL Image could not be initialize! SDL Error: " << SDL_GetError() << '\n';
                success = false;
            }else{
                surf = SDL_GetWindowSurface(win);
            }
        }
    }
    return success;
}

inline bool load_media(SDL_Surface *&surf,const std::string& filepath,ImageType t){
    bool success = true;
    if(t==BMP_FILE)surf = SDL_LoadBMP(filepath.c_str());
    else surf = IMG_Load(filepath.c_str());
    if(!surf){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        success = false;
    }
    return success;
}

inline bool init_key_surface(SDL_Surface *surf[]){
    bool success = true;
    surf[KEY_PRESS_SURFACE_DEFAULT] = loaded_surface("images/press.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_DEFAULT]){
        success = false;
        std::cerr << "Failed to load default image!\n";
    }
    surf[KEY_PRESS_SURFACE_UP] = loaded_surface("images/up.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_UP]){
        success = false;
        std::cerr << "Failed to load up image!\n";
    }
    surf[KEY_PRESS_SURFACE_DOWN] = loaded_surface("images/down.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_DOWN]){
        success = false;
        std::cerr << "Failed to load down image!\n";
    }
    surf[KEY_PRESS_SURFACE_LEFT] = loaded_surface("images/left.bmp",BMP_FILE);
    if(!surf[KEY_PRESS_SURFACE_LEFT]){
        success = false;
        std::cerr << "Failed to load left image!\n";
    }

    surf[KEY_PRESS_SURFACE_RIGHT] = loaded_surface("images/right.bmp",BMP_FILE);
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
#endif
