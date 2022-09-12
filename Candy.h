#ifndef CANDY_H_
#define CANDY_H_

#include <iostream>
#include "util.h"
using namespace std;


class Candy
{
    protected:
    string type;
    int x;
    int y;
    bool selected;

    public:

    Candy (int , int, string );
    Candy ();
    ~Candy ();
    int get_x();
    int get_y();
    string get_type();
    bool get_selected();

    void set_x(int);
    void set_y(int);
    void set_type(string);
    void set_selected(bool);
    void draWshape(string, int, int);

    Candy& operator= (Candy &);
};


#endif