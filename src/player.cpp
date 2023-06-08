#include "player.h"

Player::Player(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Player::update(Map *map, int width, int height)
{
    if (GetKeyState('W') < 0) y -= 1;
    if (GetKeyState('A') < 0) x -= 1;
    if (GetKeyState('S') < 0) y += 1;
    if (GetKeyState('D') < 0) x += 1;

    // Make sure the player stays within the bounds of the map
    if (x <= 0)
        x = 0;
    if (y <= 0)
        y = 0;
    if (x >= width)
        x = width - 1;
    if (y >= height)
        y = height - 1;

    // Modify the map to reflect the player's position
    map->screen_map[y][x] = 'p';
}
