# Flappy Bird Game

## Overview
This project is a simple implementation of the classic Flappy Bird game in C, designed to run on Windows platforms. The game uses basic ASCII art to represent elements on the console. The player controls a bird that must navigate through gaps between walls, avoiding collisions with obstacles and the edges of the screen.

## Features
- **ASCII Art**: Visual representation of the game elements.
- **Random Wall Generation**: Walls are generated with gaps for navigation.
- **Sound Effects**: Collision events trigger sound effects using the Beep function.
- **Game Over Screen**: Displays a message when the bird collides with an obstacle.

## Execution Instructions

### 1. Compile the Code
To compile the provided source code, use a C compiler compatible with Windows systems, such as GCC. Open your command prompt and run:

```bash
gcc BirdGame.c -o BirdGame
```

### 2. Run the Game
After compiling, execute the compiled binary to start the game:

```bash
BirdGame.exe
```

## Game Controls
- **Jump**: Press the SPACE key to make the bird jump.
- **Quit**: Press `q` to exit the game.

## Gameplay
- The bird starts in the middle of the screen.
- Use the jump action to navigate the bird through gaps between walls.
- Avoid collisions with walls and the top/bottom edges of the screen.
- The game ends when the bird collides with any obstacle, displaying a "Game Over" message.

## Important Notes
- The game uses Windows-specific functions for input handling and console manipulation (e.g., `conio.h` and Windows API).
- Make sure to run the game in a command line environment that supports these functions.

## Additional Features
- **Flappy Bird Experimented**: An extended version of the game featuring extra obstacles for added challenge.

Enjoy playing Flappy Bird on your Windows console!
