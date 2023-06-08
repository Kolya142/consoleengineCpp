#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "player.h"
#include "settings.h"
#include "Map.h"

void setConsoleSize() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console screen buffer size
    COORD bufferSize = { width, height };
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);

    // Set the console window size and position
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
}

// Function to set the cursor position in the console
void setCursor(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;  // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
Map map = Map();
void draw() {
    setCursor(0, 0);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            std::cout << map.screen_map[row][col];
        }
    }
}

int main()
{
    setConsoleSize();
    map.init();
    hideCursor();
    Player player = Player(0, 0);
    while (GetKeyState(VK_ESCAPE) >= 0) {
        map.clear();
        player.update(&map, width, height);
        draw();
    }
    return 0;
}
