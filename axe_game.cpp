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
    int width = 1200;
    int height = 800;
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

    //WindowShouldClose() = if we've hit the X or ESCAPE, true. Otherwise false
    while(WindowShouldClose() == false){

        //Start drawing
        BeginDrawing();

        //Draw white in the background
        ClearBackground(RED);

        //Draw a circle
        DrawCircle(300, 400, 50, BLUE);

        //End drawing
        EndDrawing();
    }

}