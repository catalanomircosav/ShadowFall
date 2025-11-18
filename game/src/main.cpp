#include <game/Game.h>

int main(int argc, char** argv) {
    game::Game* game = new game::Game();

    if(!game->init("ShadowFall", 1280, 720)) return -1;

    game->run();

    return 0;
}