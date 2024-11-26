/*
axe_game.cpp
Axe Game
by Eren
*/

//Our library
#include "raylib.h"

int main()
{
    //Creating a popup window
    int width{1200};
    int height{800};
    InitWindow(width, height, "AXE GAME");

    //Data Types and Variables
    float root_beer = 1.99;
    double cheese_burger = 5.99;
    bool shouldHaveLunch;

    //Comparison Operators
    bool equal{4==9};
    bool notEqual{4!=9};
    bool less{4<9};
    bool greater{4>9};
    bool lessEqual{4<=9};
    bool greaterEqual{4>=9};

    //Circle coordinates
    int circle_x{100};
    int circle_y{200};

    //Axe coordinates
    int axe_x{width/2};
    int axe_y{0};

    int direction{10};

    //Setting the refreshng speed of window
    SetTargetFPS(60);

    //WindowShouldClose() = if we've hit the X or ESCAPE, true. Otherwise false
    while(WindowShouldClose() == false){

        //Start drawing
        BeginDrawing();

        //Draw white in the background
        ClearBackground(RED);

        //Draw a circle
        DrawCircle(circle_x, circle_y, 50, BLUE);

        //Draw a rectangle
        DrawRectangle(axe_x, axe_y, 50, 50, PURPLE);

        //Move the Axe
        axe_y+=direction;
        if(axe_y>height || axe_y < 0)    
        {
            direction = -direction;
        }

        //Move codes
        if(IsKeyDown(KEY_D) && circle_x <= width)
        {
            circle_x+=10;
        }
         if(IsKeyDown(KEY_A) && circle_x >= 0)
        {
            circle_x-=10;
        }
        if(IsKeyDown(KEY_W) && circle_y >= 0)
        {
            circle_y-=10;
        }
         if(IsKeyDown(KEY_S) && circle_y <= height)
        {
            circle_y+=10;
        }

        //End drawing
        EndDrawing();
    }

}