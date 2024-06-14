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

The minimax algorithm is a recursive strategy used in decision-making and game theory to find the optimal move for a player, assuming that the opponent also plays optimally. Here's how it works in this game:

1. **Maximizing Player (RED)**: The algorithm tries to maximize the score for RED. It looks for the move that gives the highest possible score.
2. **Minimizing Player (BLUE)**: Conversely, the algorithm tries to minimize the score for BLUE. It looks for the move that gives the lowest possible score for RED.
3. **Recursion**: The algorithm recursively explores all possible moves, simulating each player's turn until it reaches a terminal state (a win, loss, or draw).
4. **Evaluation**: At each terminal state, the board is evaluated to determine if RED has won, BLUE has won, or if the board is full (draw).
5. **Backtracking**: The algorithm backtracks, updating scores based on the outcomes of the recursive calls, and selects the move that leads to the best outcome for the current player.
## Game Explanation

- The board consists of 15 lines connecting points.
- Players are represented by `RED` and `BLUE`.
- Players take turns selecting lines.
- The goal is to create a line of three connected points.
- The computer uses a recursive minimax algorithm to determine the optimal move.

For more information on the game, refer to the [Sim (game)](https://en.wikipedia.org/wiki/Sim_(game)) Wikipedia page.

# Sudoku Solver

This project implements a Sudoku solver using a depth-first search (DFS) approach with backtracking. It reads a Sudoku board from the input, solves it, and prints the solution.

## Explanation of the Game

- **Sudoku**: A 9x9 grid puzzle where each cell must contain a number from 1 to 9.
- **Objective**: Fill the grid so that each row, each column, and each of the nine 3x3 subgrids contains all the digits from 1 to 9 exactly once.

## Solution Approach

1. **Validity Check**: Ensures no duplicate numbers exist in any row, column, or 3x3 subgrid.
2. **Placement**: Attempts to place numbers in empty cells one by one.
3. **Backtracking**: If a placement leads to an invalid state, the algorithm backtracks and tries the next number.
4. **Depth-First Search**: Uses a stack to explore all possible placements until a valid solution is found.

