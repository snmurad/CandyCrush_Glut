#ifndef SCORE_H_
#define SCORE_H_

#include "util.h"
#include <iostream>


class score
{
    protected:
    int points_calculator;
    string points_string;

    public:

    score (int = 0, string = "0");

    // int get_points();
    // void set_points(int);

    // string get_points_string();
    // void set_points_string();

    ~score();
};

#endif