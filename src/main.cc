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
    int x,y;
    std::vector<olc::vi2d> pixels;

    Guppy()
    {
        sAppName = "Guppy";
    }
    bool OnUserCreate() override
    {
        x = y = 0;
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override
    {
        // time += fElapsedTime;
        // auto gray = static_cast<int>(time*255);
        // auto now = std::chrono::high_resolution_clock::now();

        Clear(olc::BLACK);
        // Draw(x, y, olc::Pixel(gray, gray, gray));
        // Draw(x, y, olc::Pixel(255, 255, 255));
        Draw(GetMouseX(), GetMouseY(), olc::Pixel(255, 255, 255));

        for(auto p : pixels)
        {
            Draw(p.x, p.y, olc::Pixel(255, 255, 255));
        }

        if(GetMouse(0).bPressed)
        {
            olc::vi2d p = {GetMouseX(), GetMouseY()};
            pixels.push_back(p);
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
    if (app.Construct(256, 240, 4, 4))
    {
        app.Start();
        return 0;
    }
    return 1;
}
