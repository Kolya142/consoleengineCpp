#include "Map.h"
#include "iostream"

void Map::init() {
    screen_map[height][width] = '\0';
}
void Map::clear() {
    std::fill_n(&screen_map[0][0], width * (height-1), '.');
}
