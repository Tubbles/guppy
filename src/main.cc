// This project is based off of the olcPixelGameEngine
// See https://github.com/OneLoneCoder/olcPixelGameEngine/wiki for more info
#define OLC_PGE_APPLICATION
// #define OLC_GFX_OPENGL33
#include "olcPixelGameEngine.h"

#include <algorithm>
#include <sstream>
#include <iostream>
#include <chrono>
#include <vector>

// Override base class with your custom functionality
class Guppy : public olc::PixelGameEngine
{
public:
    constexpr static int WIDTH = 640, HEIGHT = 480;
    olc::Pixel canvas[WIDTH*HEIGHT];

    Guppy()
    {
        sAppName = "Guppy";
    }
    bool OnUserCreate() override
    {
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override
    {
        // time += fElapsedTime;
        // auto gray = static_cast<int>(time*255);
        // auto now = std::chrono::high_resolution_clock::now();

        Clear(olc::BLACK);

        for(int i = 0; i < WIDTH*HEIGHT; ++i)
        {
            Draw(i%WIDTH, i/WIDTH, canvas[i]);
        }

        Draw(GetMouseX(), GetMouseY(), olc::Pixel(255, 255, 255));

        if(GetMouse(0).bHeld)
        {
            canvas[GetMouseX() + GetMouseY()*WIDTH] = olc::Pixel(255, 255, 255);
        }

        // ++x;
        // if(x >= ScreenWidth())
        // {
        //     x = 0;
        //     ++y;
        //     if(y >= ScreenHeight())
        //     {
        //         y = 0;
        //     }
        // }

        if(GetKey(olc::Key::ESCAPE).bPressed)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Guppy app;
    if (app.Construct(Guppy::WIDTH, Guppy::HEIGHT, 2, 2))
    {
        app.Start();
        return 0;
    }
    return 1;
}
