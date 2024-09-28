#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define xSize      32
#define ySize      16
#define wallcount   3

struct{
    int x,y;
}bird,wall[3];

void Draw(){
    char buff[6000];                                   //buff holds data for output
    strcpy(buff, "\x1b[17A");                          //move the cursor up 17 lines

    for (int y = 0; y <= ySize; y++)                   //Loop over each row
    {
        for (int x = 0; x <= xSize; x++)               //Loop over each column
        {
            if                                         //If its a screen edge
            (y == 0 || y == ySize || x == 0 || x == xSize){
                strcat(buff, "\x1b[31;42m[]");
                continue;                              //Move to the next column
            }
            for (int i = 0; i < wallcount; i++)        //Loop over each wall
            {
                if(wall[i].x >= x-1 && wall[i].x <= x+1 && 
                  (wall[i].y >= y+3 || wall[i].y <= y-3)){
                    strcat(buff,"\e[37;41m""[]");
                    goto bottom;                       // Move to next column as cursor moved
                }
            }
            if(bird.y == y &&  bird.x == x)
                strcat(buff,"\x1b[46;30m)>");
            
            else if(bird.y == y && bird.x == x+1)
                strcat(buff,"\x1b[46;30m_(");

            else if(bird.y == y && bird.x == x+2)
                strcat(buff,"\x1b[46;30m _");

            else if(bird.y == y-1 && bird.x == x)
                strcat(buff,"\x1b[46;30m) ");
            
            else if(bird.y == y-1 && bird.x == x+1)
                strcat(buff,"\x1b[46;30m__");
            
            else if(bird.y == y-1 && bird.x == x+2)
                strcat(buff,"\x1b[46;30m \\");
    
            else strcat(buff,"\e[37;46m""  ");           //fill rest with cyan colour       
            bottom:;
        }
        strcat(buff, "\e[0m\n");
    }
    printf(buff);
}

void walls(){
    for (int i = 0; i < wallcount; i++){
        if (wall[i].x == -1){                           //wall comes at end
            (i == 0) ? (wall[i].x = wall[2].x+14) : (wall[i].x = wall[i-1].x+14);
            wall[i].y = (rand()%7)+5;
        }
    }
}

void HitTest(){
    if (bird.y == 15 || bird.y == 0){                    //If the bird collides with screen
        Beep(400,600);                                   //Beep at 400 Hz for 600 milliseconds
        printf("\x1b[1;34mGame Over!\x1b[0m");
        exit(0);
    }
    for (int i = 0; i < wallcount; i++)
    {
        /*  A is the bird and B is the wall
            A1  A2
             +--+
             |  |
             +--+
            A3
            B1  B2
             +--+
             |  |
             +--+
            B3
        */
        if (
            (bird.x-2 < wall[i].x+2) &&           // A1 < B2
            (bird.x > wall[i].x-2) &&             // A2 > B1
            (
                (bird.y < wall[i].y-2) ||         // A3 < B3
                (bird.y > wall[i].y+1)            // A3 > B3
            )
           )
        {
            Beep(400,600);
            printf("\x1b[1;34mGame Over!\x1b[0m");
            exit(0);
        }
    }
}

int main(){
    srand(time(NULL));                              // Sets the seed for the random number generator to the current time stamp

    bird.x = 10;                                    //bird starting position
    bird.y = 10;

    for (int i = 0; i < wallcount; i++){
        wall[i].x = 24 + 14 * i;                   // Set the wall x to be spaced 14 blocks apart
        wall[i].y = (rand()%7) +5;                 // Set the wall y to a random number between 5 and 11 
    }
    int frame = 0;                                  // Variable to hold the passed frames
    printf("\x1b[1;34mPress 'SPACE' to jump or 'q' to quit.\e[0m\n");

    for (int i = 0; i <= ySize; i++)
        printf("\n");                               //Making Game Space

    Draw();

    if(getch()=='q')  return 0;    
    else bird.y-=2;

    do
    {
        if(_kbhit()){
            char key=_getch();
            if(key==' ')          bird.y-=2;
            else if(key=='q')     break;
        }
        if (frame == 2)                             //in every third loop
        {
            bird.y++;                               //Drop the bird by 1 pixel

            for (int i = 0; i < 3; i++)             //Move the wall forward
                wall[i].x--;

            frame = 0;                              //Reset the frames
        }
        Draw();                                     //Draw the game
        HitTest();                                  //Test for collisions
        walls();                                    //Update the wall

        frame++;
        Sleep(95);                                 //in milliseconds
    }while(1);

    return 0;
}