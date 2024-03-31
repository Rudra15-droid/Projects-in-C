# Tic-Tac-Toe Game in C

This README describes a C program for a simple Tic-Tac-Toe game.

**Features:**

* Two-player gameplay (X and O)
* Displays the game board after each turn
* Checks for win conditions (rows, columns, diagonals)
* Announces the winner or a tie

**How to Play:**

1. Compile the code:
2. Run the executable:


## Gameplay:

The program displays the empty board and prompts the current player (X or O) to choose a position by entering a letter (a-i) corresponding to the board squares. The chosen position is marked on the board, and the turn switches to the other player.

The game continues until a player wins by forming a complete row, column, or diagonal of their mark, or all squares are filled (resulting in a tie).

## Known Issues:

* The code doesn't handle invalid input (e.g., non-letter characters, positions already occupied). 
* The code doesn't display a message for a tie outcome.

## Future Improvements:

* Implement input validation to check for invalid characters and occupied positions.
* Add a check for a tie scenario when all squares are filled.

## Code Breakdown:

The code utilizes a 2D character array (`table`) to represent the game board. The program iterates between players, taking turns to mark their positions and checking for win conditions after each turn.


