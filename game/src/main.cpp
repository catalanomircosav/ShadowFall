#include <core/Game.h>

int main(int argc, char** argv) {
    core::Game* game = new core::Game();

    if(!game->init("ShadowFall", 1280, 720)) return -1;

    game->run();

    return 0;
}