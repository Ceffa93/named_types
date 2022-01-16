#include "Named.h"
#include <iostream>

using Width = Named<int, struct _Width>;
using Height = Named<int, struct _Height>;
using Area = Named<int, struct _Area>;

struct Rectangle
{
    Rectangle(Width, Height);
    Area getArea();

    Width width;
    Height height;
};

Rectangle::Rectangle(Width width, Height height)
    : width(width), height(height)
{
}

Area Rectangle::getArea()
{
    return Area(width * height);
}

using ScreenSize = Named<Rectangle, struct _ScreenSize>;
using Supersampling = Named<Rectangle, struct _Supersampling>;
using Resolution = Named<Rectangle, struct _Resolution>;

Resolution getResolution(ScreenSize screenSize, Supersampling supersampling)
{
    int w = screenSize.get().width / supersampling.get().width;
    int h = screenSize.get().height / supersampling.get().height;
    return Resolution(Width(w), Height(h));
}

int main()
{
    ScreenSize screenSize{ Width(1920), Height(1080) };
    Supersampling supersampling{ Width(2), Height(2) };

    Rectangle resolution = getResolution(screenSize, supersampling);

    std::cout << "Width: " << resolution.width << std::endl;
    std::cout << "Height: " << resolution.height << std::endl;
    std::cout << "PixelCount: " << resolution.getArea() << std::endl;
}