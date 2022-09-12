#include "Menu.h"
#include "util.h"
#include <iostream>


Menu :: Menu()
{

}


void Menu :: displayMenu()
{
    DrawString(495,600,"MENU", colors[CORAL]);
    Torus2d (530,610,45,360,60,1,4,colors[SKY_BLUE]);
    Torus2d (530,390,45,360,200,1,4,colors[SKY_BLUE]);
    //DrawLine (450,510, 560,510, 5, colors[WHITE]);
    DrawString(430,470,"->   New Game", colors[PALE_GREEN]);
    DrawString(430,430,"->   How To Play", colors[PALE_GREEN]);
    DrawString(430,390,"->   High Scores", colors[PALE_GREEN]);
    DrawString(430,350,"->   Completed Levels", colors[PALE_GREEN]);
    DrawString(430,310,"->   EXIT", colors[PALE_GREEN]);
}

void Menu :: ResumeMenu()
{
    DrawString(495,600,"MENU", colors[CORAL]);
    Torus2d (530,600,45,360,60,1,4,colors[WHITE]);
    Torus2d (530,390,45,360,200,1,4,colors[WHITE]);
    //DrawLine (450,510, 560,510, 5, colors[WHITE]);
    DrawString(430,470,"->   Resume", colors[PALE_GREEN]);
    DrawString(430,430,"->   How To Play", colors[PALE_GREEN]);
    DrawString(430,390,"->   High Scores", colors[PALE_GREEN]);
    DrawString(430,350,"->   Completed Levels", colors[PALE_GREEN]);
    DrawString(430,310,"->   EXIT", colors[PALE_GREEN]);
    DrawString(430,270,"->   NEW GAME", colors[PALE_GREEN]);
}

void Menu :: directions_Game()
{
    DrawString(150,600,"Any matching candies more than THREE will POP", colors[OLIVE]);
    DrawString(150,550,"You have following SIX type of Shapes", colors[OLIVE]);

        Torus2d(250, 430, 90, 360, 15, 15, 4, colors[ORANGE]);
        Torus2d(350, 430, 90, 360, 15, 15, 360, colors[FOREST_GREEN]);
        Torus2d(450, 430, 90, 360, 15, 15, 3, colors[PALE_TURQUOISE]);
        Torus2d(550, 430, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
        Torus2d(650, 430, 90, 360, 15, 15, 6, colors[CRIMSON]);
        Torus2d(750, 430, 45, 360, 0, 30, 4, colors[ORANGE_RED]);

    Torus2d(200, 330, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    Torus2d(270, 230, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    Torus2d(200, 130, 90, 360, 15, 15, 5, colors[DEEP_PINK]);

    DrawString (350, 250, "Swipe Left for a Match", colors[WHITE]);
    DrawLine (350,230, 570, 230,4, colors[WHITE]);

    Torus2d(650, 330, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    Torus2d(650, 230, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    Torus2d(650, 130, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    //Torus2d(200, 350, 90, 360, 15, 15, 5, colors[DEEP_PINK]);
    
    // DrawString(350,450,"Candies with the combination of three, four, or five will get pop", colors[OLIVE]);
    // DrawString(300,400,"Use your Mouse to swipe left, right, up, or down", colors[OLIVE]);
    // DrawString(300,350,"NOTE: Only Valid Swipe will get counted", colors[OLIVE]);
    // DrawString(600,250,"STAY SWIPING :)", colors[OLIVE]);
    DrawString(820, 60, "Return To Menu", colors[WHITE]);

}

void Menu :: YouLose()
{
    DrawString(550, 550, "YOU LOSE", colors[ORANGE_RED]);
    DrawString(820, 60, "New Game", colors[WHITE]);
}


void Menu :: HighScores()
{
    DrawString (100, 650, "High Scores", colors[SPRING_GREEN]);
    DrawString (100, 500, "1.", colors[SPRING_GREEN]);
    DrawString (100, 450, "2.", colors[SPRING_GREEN]);
    DrawString (100, 400, "3.", colors[SPRING_GREEN]);
    DrawString (100, 350, "4.", colors[SPRING_GREEN]);
    DrawString (100, 300, "5.", colors[SPRING_GREEN]);
    DrawString (100, 250, "6.", colors[SPRING_GREEN]);
}

Menu :: ~Menu()
{

}


