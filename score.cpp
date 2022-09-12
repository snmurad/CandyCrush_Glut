#include "score.h"
#include "util.h"
#include <iostream>
using namespace std;


score :: score (int a, string b)
{
    points_calculator = a;
    points_string = b;
}

// void score :: set_points(int given)
// {
//     points_calculator = given;
// }

// int score :: get_points ()
// {
//     return points_calculator;
// }

// void score :: set_points_string()
// {
//     points_string = Num2Str(points_calculator);
// }

// string score :: get_points_string ()
// {
//     return points_string;
// }

score :: ~score()
{

}