#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <astar.h>





int main() {
    int row, col;
    struct node** map;

    map = initMap(&row, &col);
    printMap(map, row, col);
    

    getchar();
    return 0;
}
