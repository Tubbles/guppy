#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <algorithm>
#include <sstream>

#include <iostream>

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
    float r = 0, g = 0, b = 0;

    Example()
    {
        sAppName = "Example";
    }
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override
    {
        // called once per frame, draws random coloured pixels
        for (int x = 0; x < ScreenWidth(); x++)
        {
            for (int y = 0; y < ScreenHeight(); y++)
            {
                Draw(x, y, olc::Pixel(static_cast<int>(r), static_cast<int>(g), static_cast<int>(b)));
            }
        }

        if(GetKey(olc::Key::Q).bHeld && GetKey(olc::Key::CTRL).bHeld)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Example demo;
    if (demo.Construct(256, 240, 4, 4))
    demo.Start();
    return 0;
}
