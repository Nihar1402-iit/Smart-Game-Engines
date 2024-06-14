# Smart Game Engines
## UpItUp 

This project implements a sliding puzzle game where you move an empty space to arrange the board such that all `1`s are on the top row. It uses Breadth-First Search (BFS) to find the shortest sequence of moves to solve the puzzle. Moves include shifting the empty space up, down, left, or right.
## Rubik's Cube Solver

This project implements a solver for a 2x2x2 Rubik's Cube using Breadth-First Search (BFS). It simulates cube moves and finds the shortest sequence to solve the cube from any given configuration.
### Moves Explanation

- `R` - Rotate the right face clockwise
- `U` - Rotate the upper face clockwise
- `F` - Rotate the front face clockwise
- `Rp` - Rotate the right face counterclockwise
- `Up` - Rotate the upper face counterclockwise
- `Fp` - Rotate the front face counterclockwise
- `R2` - Rotate the right face 180 degrees
- `U2` - Rotate the upper face 180 degrees
- `F2` - Rotate the front face 180 degrees
# Sim Game Solver

This project implements a simple two-player line game where players take turns to select lines on a board. The objective is to create a line of three connected points. The computer uses a recursive minimax strategy to find the best move.

## Game Explanation

- The board consists of 15 lines connecting points.
- Players are represented by `RED` and `BLUE`.
- Players take turns selecting lines.
- The goal is to create a line of three connected points.
- The computer uses a recursive minimax algorithm to determine the optimal move.

For more information on the game, refer to the [Sim (game)](https://en.wikipedia.org/wiki/Sim_(game)) Wikipedia page.
