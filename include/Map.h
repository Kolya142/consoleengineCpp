#ifndef MAP_H
#define MAP_H
#include "settings.h"


class Map {
public:
    char screen_map[height-1][width];
    char tmap[height-1][width];
    int* load();
    void init();
    void clear();
};

#endif // MAP_H
