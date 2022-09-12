#include <iostream>
#include "Candy.h"
#include "util.h"
using namespace std;

Candy :: Candy (int g_x, int g_y, string g_type)
{
    x = g_x;
    y = g_y;
    type = g_type;
}

Candy :: Candy ()
{
    x = 0;
    y = 0;
    type = "Shape";
}

int Candy :: get_x()
{
    return x;
}
int Candy :: get_y()
{
    return y;
}
string Candy :: get_type()
{
    return type;
}
bool Candy :: get_selected()
{
    return selected;
}



void Candy :: set_x(int s_x)
{
    x = s_x;
}
void Candy :: set_y(int s_y)
{
    y = s_y;
}
void Candy :: set_selected(bool given_selection)
{
    selected = given_selection;
}
void Candy :: set_type(string given_type)
{
    type = given_type;
}


void Candy :: draWshape(string type_given, int x_given, int y_given)
{
    if (type_given == "square")
    {
        Torus2d(x_given, y_given, 90, 360, 15, 15, 4, colors[ORANGE]);
    }

    if (type_given == "circle")
    {
        Torus2d(x_given, y_given, 90, 360, 15, 15, 360, colors[FOREST_GREEN]);
    }

    if (type_given == "triangle")
    {
        Torus2d(x_given, y_given, 90, 360, 15, 15, 3, colors[PALE_TURQUOISE]);
    }

    if (type_given == "pentagon")
    {
        Torus2d(x_given, y_given, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    }

    if (type_given == "hexagon")
    {
        Torus2d(x_given, y_given, 90, 360, 15, 15, 6, colors[CRIMSON]);
    }

    if (type_given == "filledsquare")
    {
        Torus2d(x_given, y_given, 45, 360, 0, 30, 4, colors[ORANGE_RED]);
    }
}

Candy& Candy :: operator= (Candy &copy)
{
    x = copy.x;
    y = copy.y;
    type = copy.type;
    selected = copy.selected;

    return *this;
}

Candy :: ~Candy ()
{

}