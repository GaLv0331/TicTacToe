# Tic-Tac-Toe Game

A two player Tic-Tac-Toe game implemented in C.

## Features
    Two Player Local Gameplay: Supports two human players (Player1 'X' and Player2 'O').
    Console Based Interface:   Runs entirely in the terminal.
    Clear Board Display:       Renders the 3x3 game board visually.
    Input Validation:          Ensures players select valid, unoccupied spots.
    Win/Draw Detection:        Accurately determines when a player wins or if the game ends in a draw.

## Getting Started
    This project is built using C and can be compiled with standard C compilers like GCC.

### Prerequisites

You need a C compiler installed on your system.
* **[GCC (GNU Compiler Collection)](https://gcc.gnu.org/)** is the recommended compiler.

### Installation and Build

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/GaLv0331/TicTacToe.git]
    cd TicTacToe
    ```

2.  **Compile the source files:**
    Use your C compiler to compile `main.c` and `tic_tac_toe.c` together, creating an executable named `tictactoe`.
    ```bash
    gcc main.c tic_tac_toe.c -o tictactoe
    ```

### Running the Game

Execute the compiled program from your terminal:

```bash
./tictactoe
