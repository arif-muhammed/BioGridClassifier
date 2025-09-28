#include "habitat.h"
#include <stdio.h>

int main() {
    Creature **grid;
    int rows, cols;

    readCreatures("Veri.txt", &grid, &rows, &cols);
    printf("Sonuc:\n");

    printGrid(grid, rows, cols); 

    freeGrid(grid, rows);
    simulate(grid, rows, cols); 
    

    return 0;
}
