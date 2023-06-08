#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "settings.h"
#include <stdio.h>
#include <Windows.h>

class Player
{
    public:
        int x = 0;
        int y = 0;
        Player(int _x, int _y);
        virtual void update(Map *map, int width, int height);

    protected:

    private:

};

#endif // PLAYER_H
