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
    int circle_radius{25};

    //Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int t_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //Axe coordinates
    int axe_x{width/2};
    int axe_y{0};
    int axe_lenght{50};
    
    int direction{10};

    //Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_lenght};
    int t_axe_y{axe_y};
    int b_axe_y{axe_y + axe_lenght};
    
    //Game statement
    bool collision_with_axe =   (b_axe_y >= t_circle_y) && 
                                (t_axe_y <= b_circle_y) && 
                                (l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x);

    //Setting the refreshng speed of window
    SetTargetFPS(60);

    //WindowShouldClose() = if we've hit the X or ESCAPE, true. Otherwise false
    while(WindowShouldClose() == false){
        //Start drawing
        BeginDrawing();

        //Draw white in the background
        ClearBackground(WHITE);
        if(collision_with_axe)
        {
            //Write anythings
            DrawText("Game Over", width/2, height/2, 50, RED);
        }
        else
        {
            //Update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            t_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_lenght;
            t_axe_y = axe_y;
            b_axe_y = axe_y + axe_lenght;

            //Update collision with axe
            collision_with_axe =   (b_axe_y >= t_circle_y) && 
                                (t_axe_y <= b_circle_y) && 
                                (l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x);

            //Draw a circle
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);

            //Draw a rectangle
            DrawRectangle(axe_x, axe_y, axe_lenght, axe_lenght, PURPLE);

            //Move the Axe
            axe_y+=direction;
            if(axe_y>(height-axe_lenght) || axe_y < 0)    
            {
                direction = -direction;
            }

            //Move codes
            if(IsKeyDown(KEY_D) && circle_x <= (width-circle_radius))
            {
                circle_x+=10;
            }
            if(IsKeyDown(KEY_A) && circle_x >= (circle_radius))
            {
                circle_x-=10;
            }
            if(IsKeyDown(KEY_W) && circle_y >= (circle_radius))
            {
                circle_y-=10;
            }
            if(IsKeyDown(KEY_S) && circle_y <= (height-circle_radius))
            {
                circle_y+=10;
            }
        }

        //End drawing
        EndDrawing();
    }

}