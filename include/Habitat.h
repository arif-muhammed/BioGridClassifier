#ifndef HABITAT_H
#define HABITAT_H
#include <stdbool.h> 

typedef struct {
    char type;  
    int strength;
} Creature;
Creature *findRowWinner(Creature *row, int cols, int *winnerCol);
Creature *competeWithRow(Creature **grid, int currentRow, Creature *winner, int winnerCol, int cols, int *newWinnerCol);
int findWinnerPosition(Creature *row, int cols, char type);

void readCreatures(const char *filename, Creature ***grid, int *rows, int *cols);
void simulate(Creature **grid, int rows, int cols);
void printGrid(Creature **grid, int rows, int cols);
void freeGrid(Creature **grid, int rows);
void printWinner(Creature **grid, int rows, int cols); 
bool shouldEat(Creature first, Creature second);
#endif
