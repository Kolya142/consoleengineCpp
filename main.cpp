#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "player.h"
#include "settings.h"
#include "Map.h"
#include <chrono>

float getCurrentTimeInMilliseconds()
{
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = now.time_since_epoch();

    // Convert the duration to milliseconds
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    // Convert the milliseconds to a float
    float timeMs = static_cast<float>(ms.count());

    return timeMs;
}


void setConsoleSize() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console screen buffer size
    COORD bufferSize = { width-1, height-1};
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);

    // Set the console window size and position
    SMALL_RECT windowSize = { 0, 0, width-1,height-1};
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
void draw(bool frist) {
    setCursor(0, 0);
    for (int row = 0; row < height-1; row++) {
        for (int col = 0; col < width; col++) {
            // if (map.screen_map[row][col] == '.') continue;
            setCursor(col,  row);
            std::cout << map.screen_map[row][col];
        }
        if (frist) Sleep(10);
    }
}

int main()
{
    setConsoleSize();
    map.init();
    hideCursor();
    Player player = Player(0, 0);
    float st;
    float et;
    bool frist = true;
    while (GetKeyState(VK_ESCAPE) >= 0) {
        getCurrentTimeInMilliseconds();
        map.clear();
        player.update(&map, width, height-1);
        draw(frist);
        setCursor(0, height-1);
        std::cout << "fps: " << 1/(et-st);
        et = getCurrentTimeInMilliseconds();
        if (frist) frist = !frist;
    }
    return 0;
}
