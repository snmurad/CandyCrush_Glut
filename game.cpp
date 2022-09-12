//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "Candy.h"
#include "Board.h"
#include "Menu.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;




// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */

Board screen(6,8);


void makingScreen ()
{
	srand(time (0) );


	if (screen.getcheck() == 0)
	{
	screen.randomCandiesInitializer(  );
	screen.increasecheck();
	}
	else
	{
		screen.oldCandies(  );
	}
	
	
}


int y_pos(int a)
{
	for (int q = 30, w = 100, ret = 7, orignal = 50;      orignal <= 750;      q+=80, w+=80, orignal+=100, ret--)
	{
		if (a>= q && a<=w)
		{
			return ret;
		}
	}

}


int x_pos(int a)
{
	for (int q = 50, w = 150, ret = 0, orignal = 100; orignal<=600; q+=100, w+=100, orignal+=100, ret++)
	{
		if (a>= q && a<=w)
		{
			return ret;
		}
	}
}


void LevelDeclarer()
{
	screen.set_Level_string();
	DrawString (770,750, "LEVEL", colors[LIGHT_CYAN]);
	DrawString (870,750, screen.get_Level_string(), colors[LIGHT_CYAN]);
	Torus2d (875, 760, 45, 360, 25, 2, 4, colors[LIGHT_CYAN]);	

}

void ProgressBarMaker()
{

	if (screen.get_points() >= 200*screen.get_Level() + screen.get_Level()*1000)
	{
		screen.increase_Level();
		screen.set_Moves(30 + screen.get_Level()*6);
	}

	for (int sc = 200*(screen.get_Level()-1) + (screen.get_Level()-1)*1000, x_side = 655; sc <= 200*screen.get_Level() + screen.get_Level()*1000; sc+=100, x_side+=20)
	{
		DrawString(770,470,"Progress Bar", colors[LIGHT_CYAN]);
		if (screen.get_points() >= sc)
		{
			DrawRoundRect(x_side,400,40,20,colors[DARK_SEA_GREEN],10);
		}
	}
}


void Game_Display_Text()
{
	screen.set_points_string();
	DrawString( 700, 650, " Score:" , colors[CADET_BLUE]);
	DrawLine (705,640, 835, 640, 1, colors[DARK_SEA_GREEN]);
	DrawString( 700, 600, " Target:" , colors[CADET_BLUE]);
	DrawString( 800, 600, Num2Str(200*screen.get_Level() + screen.get_Level()*1000)  , colors[CADET_BLUE]);
	DrawString( 800, 650, screen.get_points_string() , colors[CADET_BLUE]);
	DrawString(860, 150, "Hint", colors[LIGHT_CYAN]);
	Torus2d (883, 160, 90, 360, 35, 1, 360, colors[DARK_SEA_GREEN]);
	if (screen.get_check_display() == 1)
	DrawString(820, 60, "Pause", colors[LIGHT_CYAN]);
	else if (screen.get_check_display() == 2)
	DrawString(820, 60, "Return To Menu", colors[LIGHT_CYAN]);
	DrawLine (820, 40, 880, 40, 4, colors[LIGHT_CYAN] );
	screen.set_Moves_str();
	DrawString (870, 300, "Moves: ", colors[LIGHT_CYAN]);
	DrawString (950, 300, screen.get_Moves_str(), colors[LIGHT_CYAN]);
	DrawString (870, 250, "Lives: ", colors[LIGHT_CYAN]);
	DrawString (950, 250, screen.get_lives_str(), colors[LIGHT_CYAN]);
}




// void swapCandy (Candy a, Candy b)
// {
// 	Candy temp;
// 	temp = a;
// 	a = b;
// 	b = temp;
// }

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	Menu dis;
	if ( screen.get_Moves() < 1 )
	{
		screen.set_lives( screen.get_lives() - 1 );
		screen.set_Moves(30 + screen.get_Level()*6);
		screen.set_points(  200*(screen.get_Level()-1) + (screen.get_Level()-1)*1000  + 1  );
	}
	{

	}

	if (screen.get_check_display() == 10)
	{
		dis.YouLose();
	}
	if (screen.get_check_display() == 0)
	{
		dis.displayMenu();
	}
	if (screen.get_check_display() == 2)
	{
		dis.directions_Game();
	}
	if (screen.get_check_display() == 6)
	{
		dis.ResumeMenu();
	}
	if (screen.get_check_display() == 3)
	{
		//screen.set_highscores(screen.get_points());
		//screen.write_Scores();
		dis.HighScores();
		screen.highscore();
		
	}
	if (screen.get_check_display() == 1){
	screen.planeDisplay();
	makingScreen();
	screen.candiesPopper();
	screen.set_points_string();
	Game_Display_Text();

	ProgressBarMaker();
	LevelDeclarer();
	}

	if (screen.get_check_display() == 7)
	{
		screen.set_Level(1);
		screen.set_lives(3);
		screen.set_points(0);
		screen.setcheck(0);
		screen.set_Moves(30);
		screen.set_check_display(1);
	}
	
	if (screen.get_lives() < 1)
	{
		screen.set_check_display(10);
	}


	//glFlush();	

	glutPostRedisplay();
	

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		
		//screen.swapCandy(0,0,1,0);
		
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		//screen.set_highscores(screen.get_points());
		screen.write_Scores();
		
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
			// 	if (x > 824 &&  x < 866 && y > 561 && y < 580)
			// {
			// 	cout << "Hint Called" << endl;
			// 	screen.set_hint_checker(0);
			// }

	//cout << x << " " << y << endl;
	// if (x > screen.get_mouse_x() && x < screen.get_mouse_x()+100 && screen.get_mouse_click() == true)
	// {
	// 	int a,b,c,d;
	// 	if (screen.get_mouse_x())
	// 	// cout << "Right Movement Detected";
	// 	screen.swapCandy( screen.get_mouse_x()/100,8 - (screen.get_mouse_y() - 50)/100, (screen.get_mouse_x()/100) + 1,  8 - (screen.get_mouse_y() - 50)/100  );
	// 	screen.set_mouse_click(false);
		
	// }

	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

		static int x1 = 0  , x2 =  0 , diff_x = 0 ;
		static int y1 = 0  , y2 = 0 , diff_y = 0;


	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			
	{
		//cout << x << "  " << y << endl << "---\n";
			// int x1 = 0, x2 = 0, diff_x = 0;
			// int y1 = 0, y2 = 0, diff_y=  0;

		if (state == GLUT_DOWN)
		{

			x1 = x;
			y1 = y;


			if (x1 > 479 &&  x1 < 588 && y1 > 273 && y1 < 293)
			{
				screen.set_check_display(1);
			}
			if (x1 > 479 &&  x1 < 588 && y1 > 305 && y1 < 321 && screen.get_check_display() != 1)
			{
				screen.set_check_display(2);
			}
			if (x1 > 479 &&  x1 < 588 && y1 > 334 && y1 < 353 && screen.get_check_display() != 1)
			{
				screen.set_check_display(3);
				cout << "HighScore Called" << endl;
				//screen.set_check_display(2);
			}
			if (x1 > 479 &&  x1 < 588 && y1 > 368 && y1 < 383 && screen.get_check_display() != 1)
			{
				cout << "Completed Levels Called" << endl;
				//screen.set_check_display(2);
			}

			if (x1 > 479 &&  x1 < 588 && y1 > 397 && y1 < 412)
			{
				cout << "Exit" << endl;
				screen.Ww_Scores();
				exit(1);
			}
			if (x1 > 825 &&  x1 < 990 && y1 > 589 && y1 < 608 && screen.get_check_display() != 1 && screen.get_check_display() != 10)
			{
				// Simple Game Menu
				screen.set_check_display(6);
				cout << "NEW GAME";
			}
			if (x1 > 825 &&  x1 < 990 && y1 > 589 && y1 < 608 && screen.get_check_display() == 10 && screen.get_check_display() != 1)
			{
				// Game is Lost and Starting a New Game
				screen.set_lives(3);
				screen.set_check_display(7);
			}
			if (x1 > 825 &&  x1 < 990 && y1 > 589 && y1 < 608 && screen.get_check_display() == 1)
			{
				screen.set_check_display(6);   /// Resume Menu Calling
			}
			if (x1 > 479 &&  x1 < 607 && y1 > 431 && y1 < 448 && screen.get_check_display() == 6)
			{
				screen.set_check_display(7);   /// Resume Menu Calling
			}

			if (x1 > 851 &&  x1 < 923 && y1 > 503 && y1 < 560)
			{
				cout << "Hint Called" << endl;
				screen.set_hint_checker(0);
			}


		}
		 //cout << GLUT_DOWN << " " << GLUT_UP << endl;
		
		cout << x << " " << y << endl;
// int x1 = 0, x2 = 0, diff_x = 0;
// int y1 = 0, y2 = 0, diff_y=  0;
		if(state == GLUT_UP)
		{
 			//cout << "released";
			x2 = x;
			y2 = y;
			

			diff_x = x2 - x1;
		diff_y = y2 - y1;

		// cout << "Difference of x:  " << diff_x << endl;
		// cout << "Difference of y:  " << diff_y << endl;
		cout << "---------------\n\n\n\n";
		
// 		if (state == GLUT_UP)
// 		{
// 			//cout << "pressed";
// 			x1 = x;
// 			y1 = y;
// 		}
		
// 		diff_x = x2 - x1;
// 		diff_y = y2 - y1;

// 		cout << "Difference of x:  " << diff_x << endl;;
// 		cout << "Difference of y:  " << diff_y << endl;
// 		cout << "---------------\n\n\n\n";

		// screen.set_mouse_x(x);
		// screen.set_mouse_y(y);
		// screen.set_mouse_click(true);

	
	
	//if (diff_x > -diff_y && diff_x > x1 + 50)
	if (x2 > x1+30 && diff_y <10 && diff_y > -10)
	{
		if (screen.swipe_check(x_pos(x1), y_pos(y1), 'r') == true)
		{	
		screen.swapCandy ( x_pos(x1), y_pos(y1), x_pos(x1) + 1, y_pos(y1) );
		screen.set_Moves(screen.get_Moves() - 1);
		screen.set_hint_checker(1);
		}

		//cout << x_pos(x1) <<  " <- xpos "  << y_pos(y1) <<  " --ypos "  <<  x_pos(x1) + 1 <<  " -xp yp--  "  <<  y_pos(y1) << endl;
		//cout << "Condition Detect/n" << x1 << "<-x1   " << y1 << "<- y1" << endl;
		//screen.swapCandy(0,0,1,0);
	}

		if (x2 < x1-30 && diff_y <10 && diff_y > -10)
	{
		if (screen.swipe_check(x_pos(x1), y_pos(y1), 'l') == true)
		{
		screen.swapCandy ( x_pos(x1), y_pos(y1), x_pos(x1) - 1, y_pos(y1) );
		screen.set_Moves(screen.get_Moves() - 1);
		screen.set_hint_checker(1);
		}

		cout << x_pos(x1) <<  " <- xpos "  << y_pos(y1) <<  " --ypos "  <<  x_pos(x1) + 1 <<  " -xp yp--  "  <<  y_pos(y1) << endl;
		//cout << "Condition Detect/n" << x1 << "<-x1   " << y1 << "<- y1" << endl;
		//screen.swapCandy(0,0,1,0);
	}

	if (y2 > y1+30 && diff_x <10 && diff_x > -10)
	{
				cout << x_pos(x1) <<  " <- xpos "  << y_pos(y1) <<  " --ypos "  <<  x_pos(x1) + 1 <<  " -xp yp--  "  <<  y_pos(y1) << endl;


		if (screen.swipe_check(x_pos(x1), y_pos(y1), 'd') == true)
		{
		screen.swapCandy ( x_pos(x1), y_pos(y1), x_pos(x1), y_pos(y1) - 1 );
		screen.set_Moves(screen.get_Moves() - 1);
		screen.set_hint_checker(1);
		}
	}

	if (y2 < y1-30 && diff_x <10 && diff_x > -10)
	{
		if (screen.swipe_check(x_pos(x1), y_pos(y1), 'u') == true)
		{
		screen.swapCandy ( x_pos(x1), y_pos(y1), x_pos(x1), y_pos(y1) + 1 );
		screen.set_Moves(screen.get_Moves() - 1);
		screen.set_hint_checker(1);
		}

		cout << x_pos(x1) <<  " <- xpos "  << y_pos(y1) <<  " --ypos "  <<  x_pos(x1) + 1 <<  " -xp yp--  "  <<  y_pos(y1) << endl;
	}

		}
	
	
	
	}
 if (state == GLUT_UP)
	{
		x2 = x;
		y2 = y;


			if (x2 > 824 &&  x2 < 866 && y2 > 561 && y2 < 580)
			{
				cout << "Hint Called" << endl;
				screen.set_hint_checker(0);
			}
	}




	if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	screen.write_Scores();
	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse




	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
