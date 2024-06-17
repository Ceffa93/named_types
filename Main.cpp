#include "Named.h"
#include <iostream>

NAMED(Width, int);
NAMED(Height, int);
NAMED(Area, int32_t);

struct Rectangle
{
    Rectangle(Width width, Height height) : width(width), height(height) {}
    Area getArea() { return Area(width * height); }

    Width width;
    Height height;
};

NAMED(ScreenSize, Rectangle, struct _ScreenSize>);
NAMED(Supersampling, Rectangle, struct _Supersampling>);
NAMED(Resolution, Rectangle, struct _Resolution>);

Resolution getResolution(ScreenSize screenSize, Supersampling supersampling)
{
    int w = screenSize->width / supersampling.get().width;
    int h = (*screenSize).height / ((Rectangle)supersampling).height;
    return Resolution(Width(w), Height(h));
}

int main()
{
    ScreenSize screenSize{ Width(1920), Height(1080) };
    Supersampling supersampling{ Width(2), Height(2) };

    Resolution resolution = getResolution(screenSize, supersampling);

    std::cout << "Width: " << resolution->width << std::endl;
    std::cout << "Height: " << resolution->height << std::endl;
    std::cout << "PixelCount: " << resolution->getArea() << std::endl;
}