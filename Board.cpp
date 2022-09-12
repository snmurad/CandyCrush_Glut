#include <iostream>
using namespace std;
#include "Board.h"
#include "Candy.h"
#include <time.h>
#include <fstream>
// void delay(float secs)
// {
// 	float end = clock()/CLOCKS_PER_SEC + secs;
// 	while((clock()/CLOCKS_PER_SEC) < end);
// }

// for (int i = 0; i < 8; i++)
// {
//     for (int j = 0; j < 6; j++)
//     {
//         int Board :: positions[i][j] = 0;
//     }
// }

int Board :: positions[6][8] = {0};
int Board :: check = 0;

// int** Board :: positions = new int* [8];

// int* Board :: positions[0] = new int [6];
// int* Board :: positions[1] = new int [6];
// int* Board :: positions[2] = new int [6];
// int* Board :: positions[3] = new int [6];
// int* Board :: positions[4] = new int [6];
// int* Board :: positions[5] = new int [6];
// int* Board :: positions[6] = new int [6];
// int* Board :: positions[7] = new int [6];

Board :: Board (int r, int c): score (0, "0"), levels (1, "1")
{
    plane = new Candy* [r];

    for (int i = 0; i < r; i++)
    {
        plane[i]  = new Candy [c]; 
    }

    points_calculator = 0;
    points_string = "0";

    Level = 1;
    Level_string = "1";
    check_display = 0;
    hint_button = 1;
    Lives = 3;
    Lives_str = "3";
    Moves = 30;
    for (int i = 0; i < 4; i++)
    {
        High_Scores[i] = 0;
    }


    // positions[6][8] = {0};
    // check = 0;
}

void Board :: planeDisplay()
{
    for (int i = 50; i<750 ;  i+=100)
    DrawLine( i,  810,  i, 10,  1, colors[LIGHT_SKY_BLUE]);

    for (int i = 10; i<=810; i+=100)
    DrawLine( 50,  i,  650, i,  1, colors[LIGHT_SKY_BLUE]);


}

void Board :: generateCandy(int xp, int yp)
{
    write_Scores();
   
   int random = rand()%6;

    // if (random == positions[(xp-50)/100][(yp)/100] - 1)
    // {
    //     if (random != 5)
    //     {
    //         random++;
    //     }
    //     else
    //     {
    //         random--;
    //     }
    // }

    if (random == 0)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "square" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 1;
    }

    if (random == 1)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "circle" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 2;
    }

    if (random == 2)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "triangle" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 3;
    }

    if (random == 3)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "pentagon" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 4;
    }
    
    if (random == 4)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "hexagon" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 5;
    }

    if (random == 5)
    {
        plane[(xp-50)/100][(yp)/100].set_x( xp );
        plane[(xp-50)/100][(yp)/100].set_y( yp );
        plane[(xp-50)/100][(yp)/100].set_type( "filledsquare" );
        plane[(xp-50)/100][(yp)/100].set_selected ( true );
        positions[(xp-50)/100][(yp)/100] = 6;
    }

    plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][yp/100].get_type( ) , xp, yp );



    // if ( plane[xp/100][(yp-50)/100].get_type() == "square"  &&  plane[xp/100][(yp-50)/100].get_selected() == true )
    // {
    //    // square s(xp,yp);
       

    //  if ( plane[xp/100][(yp-50)/100].get_type() == "circle"  &&  plane[xp/100][(yp-50)/100].get_selected() == true  )
    // {
    //     // circle c(xp,yp);
    //     // c.Draw();
    // }

    //  if ( plane[xp/100][(yp-50)/100].get_type() == "triangle"  &&  plane[xp/100][(yp-50)/100].get_selected() == true  )
    // {
    //     // triangle t(xp,yp);
    //     // t.Draw();
    // }
}

// void Board :: set_highscores(int points)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         if (High_Scores[i] == 0)
//         {
//             High_Scores[i] = points_calculator;
//             break;
//         }
//     }
// }

void Board :: write_Scores()
{





    string score1;
	ifstream fin ("high score .txt"); //name of the file it is supposed to read
	if (fin.is_open()){
		int i=0;
      while( getline (fin, score1) ) //this loop will run depending on the number of lines in the file
		{
		  cout << score1 << '\n';
		  if(i<6 && High_Scores[i]<stoi(score1)){
            High_Scores[i]=stoi(score1) ;
		 i++;
          }

		}
		fin.close();
	}
    int temp;
    int faz=0;
    //bubbule sort
			for(int i=0;i<6;i++){
         for(int j=i+1;j<6;j++){
			   if(High_Scores[i]<High_Scores[j]){
			    temp=High_Scores[i];
				High_Scores[i]=High_Scores[j];
			    High_Scores[j]=temp;
			    }
				    }
				}

}


void Board::Ww_Scores(){

    ofstream fout;
	fout.open ("high score .txt",ios::app); 
	int number=0;
	int temp;
   int mob=0;
				for(int i=0;i<6;i++){
				    for(int j=i+1;j<6;j++){
					    if(High_Scores[i]<High_Scores[j]){
						    temp=High_Scores[i];
						    High_Scores[i]=High_Scores[j];
						    High_Scores[j]=temp;
					    }
				    }
				}
   int i=0;
   while(i<6)
   {
		if (points_calculator>High_Scores[i]){
				High_Scores[i]=points_calculator;
				fout << High_Scores[i] << endl;
                break;
			}
	i++;}
	
	fout.close();
}

int Board :: get_highscore(int pos)
{
    return High_Scores[pos];
}

void Board :: swap (Candy a, Candy b)
{
    Candy temp;
    temp = a;
    a = b;
    b = temp;
}

Candy Board :: getCandy(int i, int y)
{
    return plane[i][y];
}



void Board :: swapCandy (int a, int b, int q, int w)
{
    
    int t;
    t = positions[a][b];
    positions[a][b] = positions[q][w];
    positions[q][w] = t;

    Candy temp;
    temp = plane[a][b];
    plane[a][b] = plane [q][w];
    plane [q][w] = temp;

}

void Board :: is_selected(bool cond, int xp, int yp)
{
    plane[(xp-50)/100][yp/100].set_selected ( cond );
}


int Board :: get_lives()
{
    return Lives;
}

void Board :: set_lives( int l )
{
    Lives = l;
}

void Board :: set_lives_str()
{
    Lives_str = Num2Str(Lives);
}

string Board :: get_lives_str()
{
    return Lives_str;
}



void Board ::  randomCandiesInitializer ()
{
    for (int i = 100; i <= 600; i+=100)
	{
		for (int j = 50; j <= 750; j+=100)
		{
			generateCandy(i,j);
		}
	}

    
}



void Board ::  oldCandies ()
{
    for (int xp = 100; xp <= 600; xp+=100)
	{
		for (int yp = 50; yp <= 750; yp+=100)
		{
			if ( positions[(xp-50)/100][(yp)/100] == 1 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "square" );
                //plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true )
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }

            if ( positions[(xp-50)/100][(yp)/100] == 2 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "circle" );
               // plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true );
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }

            if ( positions[(xp-50)/100][(yp)/100] == 3 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "triangle" );
              //  plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true );
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }

            if ( positions[(xp-50)/100][(yp)/100] == 4 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "pentagon" );
              //  plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true );
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }

            if ( positions[(xp-50)/100][(yp)/100] == 5 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "hexagon" );
              //  plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true );
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }

            if ( positions[(xp-50)/100][(yp)/100] == 6 )
            {
                plane[(xp-50)/100][(yp)/100].set_x( xp );
                plane[(xp-50)/100][(yp)/100].set_y( yp );
                plane[(xp-50)/100][(yp)/100].set_type( "filledsquare" );
              //  plane[(xp-50)/100][(yp)/100].set_selected ( true );
                if ( plane[(xp-50)/100][(yp)/100].get_selected() == true );
                plane[(xp-50)/100][(yp)/100].draWshape( plane[(xp-50)/100][(yp)/100].get_type( ) , xp, yp );
            }
            
		}
        
	}
    
}

int Board :: getcheck()
{
    return check;
}

void Board :: increasecheck()
{
    check++;
}

void Board :: setcheck(int given)
{
    check = given;
}


void Board :: highscore()
{
    DrawString (200, 500, Num2Str(High_Scores[0]), colors[SPRING_GREEN]);
    DrawString (200, 450, Num2Str(High_Scores[1]), colors[SPRING_GREEN]);
    DrawString (200, 400, Num2Str(High_Scores[2]), colors[SPRING_GREEN]);
    DrawString (200, 350, Num2Str(High_Scores[3]), colors[SPRING_GREEN]);
    DrawString (200, 300, Num2Str(High_Scores[4]), colors[SPRING_GREEN]);
    DrawString (200, 250, Num2Str(High_Scores[5]), colors[SPRING_GREEN]);

    DrawString(820, 60, "Return To Menu", colors[WHITE]);
}

// void Board :: set_mouse_x(int mx)
// {
//     mouse_x = mx;
// }


// void Board :: set_mouse_y(int my)
// {
//     mouse_x = my;
// }



// int Board :: get_mouse_x()
// {
//     return mouse_x;
// }

// int Board :: get_mouse_y()
// {
//     return mouse_y;
// }

// void Board :: set_mouse_click(bool mc)
// {
//     mouse_click = mc;
// }

// bool Board :: get_mouse_click()
// {
//     return mouse_click;
// }



int Board :: get_check_display()
{
    return check_display;
}

void Board :: set_check_display(int cd)
{
    check_display = cd;
}


void Board :: set_position(int position_value, int q, int w)
{
    positions[q][w] = position_value;
}

int Board :: get_position (int q, int w)
{
    return positions[q][w];
}


void Board :: set_points(int given)
{
    points_calculator = given;
}

int Board :: get_points ()
{
    return points_calculator;
}

void Board :: set_points_string()
{
    points_string = Num2Str(points_calculator);
}

string Board :: get_points_string ()
{
    return points_string;
}

void Board :: increase_Level ( )
{
    Level++;
}

void Board :: set_Level ( int lvl )
{
    Level = lvl;
}

int Board :: get_Level ()
{
    return Level;
}

void Board :: set_Level_string()
{
    Level_string = Num2Str(Level);
}

string Board :: get_Level_string()
{
    return Level_string;
}


int Board :: get_Moves()
{
    return Moves;
}

void Board :: set_Moves(int m)
{
    Moves = m;
}

void Board :: set_Moves_str()
{
    Moves_str = Num2Str (Moves);
}

string Board :: get_Moves_str()
{
    return Moves_str;
}

void Board :: DrawHint(int x_given, int y_given, string type_given)
{

    if (type_given == "right")
    {
        DrawLine (x_given, y_given, x_given + 100, y_given, 5, colors[PINK]);
        DrawLine (x_given+100, y_given, x_given + 100 - 20, y_given - 15, 5, colors[PINK]);
        DrawLine (x_given+100, y_given, x_given + 100 - 20, y_given + 15, 5, colors[PINK]);
    }


    if (type_given == "left")
    {
        DrawLine (x_given, y_given, x_given - 100, y_given, 5, colors[PINK]);
        DrawLine (x_given - 100, y_given, x_given -100  + 20, y_given +15, 5, colors[PINK]);
        DrawLine (x_given - 100, y_given, x_given -100  + 20, y_given - 15, 5, colors[PINK]);
    }

    if (type_given == "up")
    {
        DrawLine (x_given, y_given, x_given, y_given + 100, 5, colors[PINK]);
        DrawLine (x_given, y_given+100, x_given-15, y_given + 100 - 20, 5, colors[PINK]);
        DrawLine (x_given, y_given+100, x_given+15, y_given + 100 - 20, 5, colors[PINK]);
    }

    if (type_given == "down")
    {
        DrawLine (x_given, y_given, x_given, y_given - 100, 5, colors[PINK]);
        DrawLine (x_given, y_given - 100 , x_given + 15, y_given - 100 + 20, 5, colors[PINK]);
        DrawLine (x_given, y_given - 100 , x_given - 15, y_given - 100 + 20, 5, colors[PINK]);
        
    }















//     if (type_given == "square")
//     {
// //         int i = 90;
// //         // for (int i = 90; i <= 450; i++ )
// //         // Torus2d(x_given, y_given, i, 360, 15, 15, 4, colors[ORANGE]);

// //         //for (auto start = std::chrono::steady_clock::now(), now = start; now < start + std::chrono::seconds{5}; now = std::chrono::steady_clock::now()) 
// // clock_t start = clock();
// // while ( (clock() - start)/2 <= 5)
// // {}


//     Torus2d(x_given, y_given, 90, 360, 0, 60, 4, colors[0]);
//     }

//     if (type_given == "circle")
//     {
//         Torus2d(x_given, y_given, 90, 360, 0, 40, 360, colors[9]);
//     }

//     if (type_given == "triangle")
//     {
        
//         Torus2d(x_given, y_given, 90, 360, 0, 40, 3, colors[9]);
        
    
//     }

//     if (type_given == "pentagon")
//     {
        
//         Torus2d(x_given, y_given, 90, 360, 0, 40, 5, colors[9]);
        
//     }

//     if (type_given == "hexagon")
//     {
        
//         Torus2d(x_given, y_given, 90, 360, 0, 40, 6, colors[9]);
        
//     }

//     if (type_given == "filledsquare")
//     {
        
        
//         Torus2d(x_given, y_given, 45, 360, 0, 40, 4, colors[9]);
        
//     }

}


bool Board :: swipe_check(int i, int j, char movement)
{
    if (movement == 'r' && i != 5)
    {
        if (i < 3 && plane[i][j].get_type() == plane[i+2][j].get_type() && plane[i][j].get_type() == plane[i+3][j].get_type())
        {
            return true;
        }

        else if ( j != 0 && j != 7 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j-1].get_type()   )
        {
            return true;
        }
        else if (j > 1 && plane[i][j].get_type() == plane[i+1][j-1].get_type() && plane[i][j].get_type() == plane[i+1][j-2].get_type())
        {
            return true;
        }
        else if (j < 6 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j+2].get_type())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

        if (movement == 'l' && i != 0)
    {
        if (i > 2 && plane[i][j].get_type() == plane[i-2][j].get_type() && plane[i][j].get_type() == plane[i-3][j].get_type())
        {
            return true;
        }
        else if ( j != 0 && j != 7 &&  plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-1][j-1].get_type()  )
        {
            return true;
        }
        else if (j > 1 && plane[i][j].get_type() == plane[i-1][j-1].get_type() && plane[i][j].get_type() == plane[i-1][j-2].get_type())
        {
            return true;
        }
        else if (j < 6 && plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-1][j+2].get_type())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

        if (movement == 'u' && j != 7)
    {
        if ( j < 5  && plane[i][j].get_type() == plane[i][j+2].get_type() && plane[i][j].get_type() == plane[i][j+3].get_type())
        {
            return true;
        }

        else if ( i != 0 && i != 5 &&  plane[i][j].get_type() == plane[i+1][j+1].get_type()  &&  plane[i][j].get_type() == plane[i-1][j+1].get_type()  )
        {
            return true;
        }
        else if (i<4 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+2][j+1].get_type())
        {
            return true;
        }
        else if (i > 1 && plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-2][j+1].get_type())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }


        if (movement == 'd' && j != 0)
    {
        if (j > 2 && plane[i][j].get_type() == plane[i][j-2].get_type() && plane[i][j].get_type() == plane[i][j-3].get_type())
        {
            return true;
        }
        else if (i != 0 && i != 5 && plane[i][j].get_type() == plane[i-1][j-1].get_type() &&  plane[i][j].get_type() == plane[i+1][j-1].get_type()  )
        {
            return true;
        }
        else if (i<4 && plane[i][j].get_type() == plane[i+1][j-1].get_type() && plane[i][j].get_type() == plane[i+2][j-1].get_type())
        {
            return true;
        }
        else if (i > 1 && plane[i][j].get_type() == plane[i-1][j-1].get_type() && plane[i][j].get_type() == plane[i-2][j-1].get_type())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}


void Board :: set_hint_checker (int hc)
{
    hint_button = hc;
}


int Board :: get_hint_checker ()
{
    return hint_button;
}



void Board :: candiesPopper()
{
    int hint_checker;
    if (hint_button == 0)
    {
        hint_checker = 0;
    }

    int r_s = 0, l_s = 0, u_s = 0, d_s = 0, inside_check_i = 0, inside_check_j = 0, random_position = 0;

    for (int i = 0; i < 6; i++)
    {
        inside_check_i = i;

        for (int j = 0; j < 8; j++)
        {
            inside_check_j = j;

            while (i < 4 && inside_check_i <=5)
            {
                if (plane[i][j].get_type() == plane[inside_check_i][inside_check_j].get_type())
                {
                    inside_check_i++;
                    r_s++;
                }
                else
                {
                    break;
                }
                
            }
                inside_check_i = i;
                inside_check_j = j;

            while (i > 1 && inside_check_i >=0)
            {
                if (  plane [i][j].get_type() == plane[inside_check_i][inside_check_j].get_type())
                {
                    inside_check_i--;
                    l_s++;
                }
                else
                {
                    break;
                }
                
            }
                inside_check_i = i;
                inside_check_j = j;

            while (j < 6 && inside_check_j <= 7)
            {
                if (plane[i][j].get_type() == plane[inside_check_i][inside_check_j].get_type())
                {
                    inside_check_j++;
                    u_s++;
                }
                else
                {
                    break;
                }
                
            }  
                inside_check_i = i;
                inside_check_j = j;

            while (j > 1  && inside_check_j >= 0)
            {
                if (plane[i][j].get_type() == plane[inside_check_i][inside_check_j].get_type())
                {
                    inside_check_j--;
                    d_s++;
                }
                else
                {
                    break;
                }
                
            }

                inside_check_i = i;
                inside_check_j = j;

                if (r_s > 2)
                {
                    points_calculator = points_calculator + (r_s*5);
                while (r_s > 0)
                {
                    random_position = rand()%6 + 1;
                    if (random_position ==  positions[i][j])
                    {
                        if (random_position != 6)
                        {
                            random_position++;
                        }
                        else
                        {
                            random_position--;
                        }
                        
                    }
                    positions[inside_check_i][inside_check_j] = random_position;
                    inside_check_i++;
                    r_s--;
                }
                }
                // else if (r_s > 1  )
                // {
                //     if ( i < 3 && plane[i][j].get_type() == plane[i+3][j].get_type()   )
                //     {
                //         DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) + 300 , (j*100) + 50, 20, colors[PINK]  );
                //     }

                //     hint_checker++;
                // }

                if (r_s == 2 && hint_checker == 0)// && hint_checker == 0 )
                {

                    if (i < 3 && plane[i][j].get_type() == plane[i+3][j].get_type())
                    {
                        //DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) + 300 , (j*100) + 50, 20, colors[PINK]  );
                        DrawHint ((i+3)*100 + 100, j*100 + 50, "left");
                        hint_checker++;
                    }

        // else if ( i < 5 && j != 0 && j != 7 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j-1].get_type()   )
        // {
        //     DrawLine ((i+1)*100 + 100, (j+1)*100 + 50,  ((i+1)*100 + 100) + 300 , ((j-1)*100) + 50, 20, colors[PINK]  );
        // }
        // else if (i < 5 && j > 1 && plane[i][j].get_type() == plane[i+1][j-1].get_type() && plane[i][j].get_type() == plane[i+1][j-2].get_type())
        // {
        //     DrawLine ((i+1)*100 + 100, (j-1)*100 + 50,  ((i+1)*100 + 100) + 300 , ((j-2)*100) + 50, 20, colors[PINK]  );
        // }
        // else if (i < 5 &&j < 6 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j+2].get_type())
        // {
        //     DrawLine ((i+1)*100 + 100, (j+1)*100 + 50,  ((i+1)*100 + 100) + 300 , ((j+2)*100) + 50, 20, colors[PINK]  );
        // }
        // else
        // {
        //     DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) + 300 , (j*100) + 50, 20, colors[PINK]  );
        // }



                    // if ( i < 3 && plane[i][j].get_type() == plane[i+2][j].get_type() && plane[i][j].get_type() == plane[i+3][j].get_type()    )
                    // {
                    //     DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) + 300 , (j*100) + 50, 20, colors[PINK]  );
                    // }

                    
                }
                if (r_s == 1 &&  hint_checker == 0)
                {
                    if ( j != 0 && j != 7 && i < 6 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j-1].get_type()   )
                    {
                       DrawHint (i*100+100, j*100 + 50, "right" );
                       hint_checker++;
                    }

                    else if (i != 5 && j > 1 && plane[i][j].get_type() == plane[i+1][j-1].get_type() && plane[i][j].get_type() == plane[i+1][j-2].get_type())
                    {
                        DrawHint (i*100+100, j*100 + 50, "right" );
                        hint_checker++;
                    }

                    else if (i != 5 && j < 6 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+1][j+2].get_type())
                    {
                        DrawHint (i*100+100, j*100 + 50, "right" );
                        hint_checker++;
                    }

                    
                }

                inside_check_i = i;
                inside_check_j = j;

                if (l_s > 2)
                {
                    points_calculator = points_calculator +  (l_s*5);

                while (l_s > 0)
                {
                    
                    random_position = rand()%6+1;
                    if (random_position ==  positions[i][j])
                    {
                        if (random_position != 6)
                        {
                            random_position++;
                        }
                        else
                        {
                            random_position--;
                        }
                        
                    }
                    positions[inside_check_i][inside_check_j] = random_position;
                    inside_check_i--;
                    l_s--;
                }

                }
                // else if (l_s > 1  )
                // {
                //     if ( i > 2 && plane[i][j].get_type() == plane[i-3][j].get_type()  )
                //     {
                //         DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) - 300 , (j*100) + 50, 20, colors[PINK]  );
                //     }

                //     hint_checker++;
                // }

                if (l_s == 2 &&  hint_checker == 0 )// && hint_checker == 0 )
                {
                    if ( i > 2 &&   plane[i][j].get_type() == plane[i-3][j].get_type()  )
                    {
                        //DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100) - 300 , (j*100) + 50, 20, colors[PINK]  );
                        DrawHint ((i-3)*100 + 100, j*100 + 50, "right");
                        hint_checker++;
                    }

                    
                }
                if (l_s == 1 &&  hint_checker == 0)
                {
                    if( j != 0 && j != 7 && i > 0 &&  plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-1][j-1].get_type()  )
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "left");
                        hint_checker++;
                    }

                    else if (i != 0 && j > 1 && plane[i][j].get_type() == plane[i-1][j-1].get_type() && plane[i][j].get_type() == plane[i-1][j-2].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "left");
                        hint_checker++;
                    }
                    else if (i != 0 && j < 6 && plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-1][j+2].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "left");
                        hint_checker++;
                    }

                    
                }
                  
                inside_check_i = i;
                inside_check_j = j;

                if (u_s > 2)
                {
                    points_calculator = points_calculator +  (u_s * 5);
                while (u_s > 0)
                {
                    random_position = rand()%6+1;
                    if (random_position ==  positions[i][j])
                    {
                        if (random_position != 6)
                        {
                            random_position++;
                        }
                        else
                        {
                            random_position--;
                        }
                        
                    }
                    positions[inside_check_i][inside_check_j] = random_position;
                    inside_check_j++;
                    u_s--;
                }

                }
                // else if (u_s > 1   )
                // {
                //     if ( j < 5 && plane[i][j].get_type() == plane[i][j+3].get_type()   )
                //     {
                //         DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100)  , ((j*100) + 50) + 300, 20, colors[PINK]  );
                //     }

                //     hint_checker++;
                // }

                if (u_s == 2 &&  hint_checker == 0 )// && hint_checker == 0 )
                {
                    if ( j < 5 && plane[i][j].get_type() == plane[i][j+3].get_type()    )
                    {
                       // DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100)  , ((j*100) + 50) + 300, 20, colors[PINK]  );
                       DrawHint (i*100 + 100, (j+3)*100 + 50, "down");
                       hint_checker++;
                    }

                    
                }
                if (u_s == 1 &&  hint_checker == 0)
                {
                    if ( i != 0 && i != 5 && j < 7 && plane[i][j].get_type() == plane[i+1][j+1].get_type()  &&  plane[i][j].get_type() == plane[i-1][j+1].get_type()  )
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "up");
                        hint_checker++;
                    }

                    else if (j != 7 && i<4 && plane[i][j].get_type() == plane[i+1][j+1].get_type() && plane[i][j].get_type() == plane[i+2][j+1].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "up");
                        hint_checker++;
                    }
                    else if (j != 7 && i > 1 && plane[i][j].get_type() == plane[i-1][j+1].get_type() && plane[i][j].get_type() == plane[i-2][j+1].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "up");
                        hint_checker++;
                    }

                    
                }

                inside_check_i = i;
                inside_check_j = j;

                if (d_s > 2)
                {
                    points_calculator = points_calculator +  (d_s*5);

                while (d_s > 0)
                {
                    random_position = rand()%6+1;
                    if (random_position ==  positions[i][j])
                    {
                        if (random_position != 6)
                        {
                            random_position++;
                        }
                        else
                        {
                            random_position--;
                        }
                        
                    }
                    positions[inside_check_i][inside_check_j] = random_position;
                    inside_check_j--;
                    d_s--;
                }

                }
                // else if (d_s > 1   )
                // {
                //     if ( j > 2 && plane[i][j].get_type() == plane[i][j-3].get_type()   )
                //     {
                //         DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100)  , ((j*100) + 50) - 300, 20, colors[PINK]  );
                //     }

                //     hint_checker++;
                // }

                if (d_s == 2  &&  hint_checker == 0 )//&& hint_checker == 0  )
                {
                    if ( j > 2 &&  plane[i][j].get_type() == plane[i][j-3].get_type()    )
                    {
                       // DrawLine (i*100 + 100, j*100 + 50,  (i*100 + 100)  , ((j*100) + 50) - 300, 20, colors[PINK]  );
                        DrawHint (i*100 + 100, (j-3)*100 + 50, "up");
                        hint_checker++;
                    }

                    
                }
                if (d_s == 1 &&  hint_checker == 0)
                {
                    if (i != 0 && i != 5 && j > 0 && plane[i][j].get_type() == plane[i-1][j-1].get_type() &&  plane[i][j].get_type() == plane[i+1][j-1].get_type()  )
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "down");
                        hint_checker++;
                    }

                    else if (j != 0 && i<4 && plane[i][j].get_type() == plane[i+1][j-1].get_type() && plane[i][j].get_type() == plane[i+2][j-1].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "down");
                        hint_checker++;
                    }
                    else if (j != 0 && i > 1 && plane[i][j].get_type() == plane[i-1][j-1].get_type() && plane[i][j].get_type() == plane[i-2][j-1].get_type())
                    {
                        DrawHint (i*100 + 100, j*100 + 50, "down");
                        hint_checker++;
                    }

                    
                }

                inside_check_i = i;
                inside_check_j = j;
                r_s = 0;
                l_s = 0;
                u_s = 0;
                d_s = 0;
        }
    }


}





// int main ()
// {
//     Board (5,5);
// }

// if (random == 0)
//     {
//         square s(xp,yp);
//         plane[(xp-100)/80][(yp-100)/80].set_x( s.get_x());
//         s.Draw();
//     }

//     if (random == 1)
//     {
//         circle s(xp,yp);
//         plane[(xp-100)/80][(yp-100)/80].set_x( s.get_x());
//         s.Draw();
//     }

//     if (random == 2)
//     {
//         triangle s(xp,yp);
//         plane[(xp-100)/80][(yp-100)/80].set_x( s.get_x());
//         s.Draw();
//     }


Board :: ~Board()
{
    delete []plane;
}