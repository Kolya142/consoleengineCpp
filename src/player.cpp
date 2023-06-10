#include "player.h"

Player::Player(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Player::update(Map *map, int width, int height)
{
    if (GetKeyState('A') < 0) x -= 1;
    if (GetKeyState('D') < 0) x += 1;
    if (GetKeyState(VK_SPACE) < 0 && !jump && y == height-1) jump = true;

    // Make sure the player stays within the bounds of the map
    if (x <= 0)
        x = 0;
    if (x >= width)
        x = width - 1;
    if (y < height-1 && !jump)
        y += 1;
    if (jump) {
        if (y <= height - 5) jump = false;
        y -= 1;
    }

    // Modify the map to reflect the player's position
    map->screen_map[y][x] = 'p';
}
