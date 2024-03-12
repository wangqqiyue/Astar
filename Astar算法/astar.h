#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define LINE_LEN    64
#define START       1
#define GOAL        2
#define UNWALKABLE  3
#define PATH        4
#define WALKABLE    0


enum NEIBOR_MACRO {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    NEIBOR_NUM_MAX
};

struct node {
    int row=0;
    int col=0;
    char walkable=0;
    int f=0;
    int g=0;
    int h=0;
    bool close = false;
    bool open = false;
    struct node* parent = NULL;
    friend bool operator<(node n1, node n2) {
        return n1.f > n2.f;
    }
    int getManhattan(node* n) {
        return abs(row - n->row) + abs(col - n->col);
    }
    void moveToClose() {
        close = true;
        open = false;
    }

};


class Map {
public:
    int row, col;
    node* start=NULL;
    node* goal=NULL;
    node** map;
    void initMap();
    void printMap();
    node* getStart();
    node* getGoal();
    void getNeibors(node* center, node** neibors);
    void printPath();
};


