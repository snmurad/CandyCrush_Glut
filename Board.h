

#ifndef BOARD_H_
#define BOARD_H_
#include "Candy.h"
#include "score.h"
#include "levels.h"
//#include "universal.h"


class Board: public score, public levels
{
    protected:
    int rows;
    int cols;
    Candy** plane;
    static int positions[6][8];
    static int check;
    int check_display;
    int hint_button = 0;
    int Moves;
    string Moves_str;
    int High_Scores[6];

    int Lives;
    string Lives_str;




    public:

    Board(int=0, int=0);
    void planeDisplay();
    void generateCandy (int, int);
    void swap(Candy, Candy);
    void Ww_Scores();
    Candy getCandy (int, int);
    void swapCandy(int, int, int, int);
    void is_selected(bool, int, int);
    void randomCandiesInitializer ();
    void oldCandies();
    int getcheck();
    void setcheck(int );
    void increasecheck();

    void set_position(int, int, int);
    int get_position (int,int);
    int get_check_display();
    void set_check_display(int);
    void highscore();

    // void set_mouse_x(int);
    // void set_mouse_y(int);

    // int get_mouse_x();
    // int get_mouse_y();

    // void set_mouse_click(bool);
    // bool get_mouse_click();

    bool swipe_check(int, int, char);
    void candiesPopper();

    int get_points();
    void set_points(int);

    string get_points_string();
    void set_points_string();

    void increase_Level ();
    void set_Level ( int );
    int get_Level ();

    void set_Level_string();
    string get_Level_string();

    void set_hint_checker(int);
    int get_hint_checker();

    void DrawHint(int, int, string);

    void set_Moves(int);
    int get_Moves();

    void set_Moves_str();
    string get_Moves_str();

   // void set_highscores(int);
    void write_Scores();

    int get_highscore(int);

    int get_lives();
    void set_lives(int);

    string get_lives_str();
    void set_lives_str();

    ~Board();

};


#endif