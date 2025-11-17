#include <iostream>
#include "engine.h"

#include <SDL3/SDL.h>

void engine_print() {
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "[Engine] Error occurred while initializing SDL3.\n";
        return;
    } else {
        std::cout << "[Engine] SDL initialized correctly.\n";
    }
    std::cout << "[Engine] ShadowFall engine initialized!\n";
}
