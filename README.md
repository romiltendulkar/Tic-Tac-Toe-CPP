# Tic Tac Toe CPP
 
This is my implementation of an MNK game in C++. This is a usual programming test question and this is my attempt at the question. The code could use some improvements which I shall perform in the future as it becomes feasible. This is a console application and uses only STL at most.

The functionality that is provided in the implementation includes
* MNK game
* Move Undo
* Early Draw Detection

## Classes

### Board
This class declares the board that the game is played on, as this is an mnk board the size shall be declared within the constructor. Default constructor makes a Tic Tac Toe board.

### Move
The Move class is used to record moves made. We store this in a stack so that we can perform undo operations.

### Game
The Game class provides the turn by turn functionality we need for actual gameplay. It stores the movestack and performs moves and undoes them as well.

### Solver
The Solver class is used to check the board for win and draw conditions. The Game class calls the functions in solver as required based on the current gameplay

## Possible Updates
Some future changes that i might make in further updates include
* Name convention changes. (Polish some of the code to the naming convention otherwise used)
* Redo functionality
* Draw check optimisations (I am aware of some ways i can optimize the row and column checks)
* Win check optimisation (I am not aware of any optimisations for this as of the moment)
