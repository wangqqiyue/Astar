#pragma once
#define LINE_LEN    64
#define START       1
#define GOAL        2
#define UNWALKABLE  3
#define WALKABLE    0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct node {
    int row;
    int col;
    char walkable;
    int f;
    int g;
    int h;
    struct node* parent = NULL;
    friend bool operator<(node n1, node n2) {
        return n1.f > n2.f;
    }
};


class Map {
public:
    int row, col;
    node* start;
    node* goal;
    node** map;
    void initMap();
    void printMap();

};
