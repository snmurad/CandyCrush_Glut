#ifndef LEVELS_H_
#define LEVELS_H_
#include <iostream>
using namespace std;

class levels
{
    protected:
    int Level;
    string Level_string;

    public:
    levels(int = 1, string = "1");
    ~levels();
};

#endif