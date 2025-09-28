
#include "habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void readCreatures(const char *filename, Creature ***grid, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int r = 0, c = 0;
    char line[1024];
    Creature **tempGrid = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        c = 0;
        Creature *row = NULL;

        while (token) {
            row = realloc(row, (c + 1) * sizeof(Creature));
            int strength = atoi(token);
            char type = 'X'; 
            if (strength >= 1 && strength <= 9) type = 'B';  
            else if (strength >= 10 && strength <= 20) type = 'C'; 
            else if (strength >= 21 && strength <= 50) type = 'S'; 
            else if (strength >= 51 && strength <= 99) type = 'P'; 

            row[c++] = (Creature){type, strength};
            token = strtok(NULL, " ");
        }
        tempGrid = realloc(tempGrid, (r + 1) * sizeof(Creature*));
        tempGrid[r++] = row;
        if (r == 1) *cols = c; 
    }
    fclose(file);

    *grid = tempGrid;
    *rows = r;
}

void simulate(Creature **grid, int rows, int cols) {
    int currentRow = 0;
    int winnerCol = 0;  
    Creature *winner = findRowWinner(grid[currentRow], cols, &winnerCol);

    for (currentRow = 1; currentRow < rows; currentRow++) {
        int newWinnerCol = 0;  
        Creature *newWinner = competeWithRow(grid, currentRow, winner, winnerCol, cols, &newWinnerCol);

        if (newWinner == NULL) {
            grid[currentRow - 1][winnerCol].type = 'X';  
            winner = findRowWinner(grid[currentRow], cols, &winnerCol); 
        } else {
            winner = newWinner;
            winnerCol = newWinnerCol; 
        }
    }

    printf("Kazanan: %c : (%d,%d)\n", winner->type, currentRow - 1, winnerCol - 1);
}


Creature *findRowWinner(Creature *row, int cols, int *winnerCol) {
    Creature *winner = &row[0];
    *winnerCol = 0;
    for (int i = 1; i < cols; i++) {
        if (shouldEat(*winner, row[i])) {
            row[i].type = 'X';
        } else {
            winner = &row[i];
            *winnerCol = i;
        }
    }
    return winner;
}

Creature *competeWithRow(Creature **grid, int currentRow, Creature *winner, int winnerCol, int cols, int *newWinnerCol) {
    *newWinnerCol = winnerCol; 
    for (int i = 0; i < cols; i++) {
        if (i != winnerCol && shouldEat(*winner, grid[currentRow][i])) {
            grid[currentRow][i].type = 'X';
        } else if (i != winnerCol && shouldEat(grid[currentRow][i], *winner)) {
            *newWinnerCol = i;
            return NULL;  
        }
    }
    return winner;  
}

int findWinnerPosition(Creature *row, int cols, char type) {
    for (int i = 0; i < cols; i++) {
        if (row[i].type == type) return i;
    }
    return -1;  
}

bool shouldEat(Creature first, Creature second) {
    if ((first.type == 'C' && second.type == 'B') ||
        (first.type == 'S' && second.type == 'P') ||
        (first.type == 'P' && second.type == 'B') ||
        (first.type == 'B' && second.type == 'S')) {
        return true;
    }
    return false;
}





void printWinner(Creature **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].type != 'X') {
                printf("Kazanan : %c : (%d,%d)\n", grid[i][j].type, i, j);
                return; 
            }
        }
    }
}

void printGrid(Creature **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].type == 'X') {
                printf("X ");
            } else {
                printf("%c ", grid[i][j].type); 
            }
        }
        printf("\n");
    }
}

void freeGrid(Creature **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}