#ifndef LTIMER_HPP_
#define LTIMER_HPP_

#include <SDL2/SDL.h>

class LTimer{
    public:
        //Initializes variables
        LTimer();

        //Class methods
        void start();
        void pause();
        void unpause();
        void stop();

        //Getters
        Uint32 getTicks();

        bool isStarted(){return started;}
        bool isPaused(){return started&&paused;}
    private:
        Uint32 startTicks;
        Uint32 pausedTicks;
        bool started;
        bool paused;
};


#endif