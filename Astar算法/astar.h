#pragma once
#define LINE_LEN    64
#define START       1
#define GOAL        2
#define UNWALKABLE  3
#define WALKABLE    0

struct node {
    int row;
    int col;
    char walkable;
    int f;
    int g;
    int h;
    struct node* parent = NULL;
};

void printMap(struct node** map, int row, int col);
struct node** initMap(int* r, int* c);
