<title>Flappy Bird Game</title>
This project is a simple implementation of the classic Flappy Bird game in C, designed to run on Windows platforms. Below are the overview and execution instructions for the game.

OVERVIEW:
The game is implemented using basic ASCII art to represent the game elements on the console. The player controls a bird that must navigate through gaps between walls by jumping. The walls move horizontally towards the bird, and the player must avoid collision with the walls or the top and bottom edges of the screen. The game ends when the bird collides with any obstacle.

Execution Instructions:
Compile the Code: Compile the provided source code using a C compiler compatible with Windows systems. You can use GCC or any other compiler that supports Windows.

gcc BirdGame.c -o BirdGame
Run the Game: Execute the compiled binary to start the game.

BirdGame.exe
Game Controls:

Press the SPACE key to make the bird jump.
Press q to quit the game.
Gameplay:

The bird starts in the middle of the screen.
Use the jump action to navigate the bird through the gaps between walls.
Avoid collision with the walls and the top/bottom edges of the screen.
The game ends when the bird collides with any obstacle, and a "Game Over" message is displayed.

IMPORTANT:
The game utilizes Windows-specific functions for input handling and console manipulation ('conio.h' and Windows API).
Walls are randomly generated with gaps for the player to navigate through.
Sound effects are included using the Beep function for collision events
Play Flappy Bird on your Windows console!
Flappy Bird Experimented has extra obstacles to play with.
