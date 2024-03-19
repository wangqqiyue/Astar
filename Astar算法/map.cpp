#include <astar.h>

void Map::printMap() {
    int r, c;
    printf("======Map======\n");
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            printf("%c ", map[r][c].walkable);
        }
        printf("\n");
    }
}

void Map::initMap() {
    struct node** map;
    int row, col, i, j;
    char line[LINE_LEN] = { 0 };
    const char* delim = " ";
    char* token = NULL;
    char* context = NULL;

    printf("Please input the row number of Map:");
    scanf_s("%d", &row);
    printf("Please input the column number of Map:");
    scanf_s("%d", &col);

    map = (struct node**)malloc(row * sizeof(struct node*));
    for (i = 0; i < row; i++)
    {
        map[i] = (struct node*)malloc(col * sizeof(struct node));
    }

    printf("Please input Map content(%c is Start, %c is Goal, %c is walkable, %c is unwalkable):\n", START, GOAL, WALKABLE, UNWALKABLE);
    rewind(stdin);
    for (i = 0; i < row; i++) {
        fgets(line, LINE_LEN - 1, stdin);
        token = strtok_s(line, delim, &context);
        for (j = 0; j < col; j++) {
            map[i][j].walkable = token[0];
            map[i][j].row = i;
            map[i][j].col = j;
            map[i][j].close = false;
            map[i][j].open = false;
            map[i][j].parent = NULL;
            token = strtok_s(NULL, delim, &context);
        }
    }
    this->map = map;
    this->row = row;
    this->col = col;
}

node* Map::getStart() {
    int i, j;
    if (start) {
        return start;
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if(START==map[i][j].walkable){
                start= &map[i][j];
                return start;
            }
        }
    }
}

node* Map::getGoal() {
    int i, j;
    if (goal) {
        return goal;
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if(GOAL== map[i][j].walkable){
                goal = &map[i][j];
                return goal;
            }
        }
    }
}

void Map::getNeibors(node* center, node** neibors) {
    int r, c,i;
    
    for (i = 0; i < NEIBOR_NUM_MAX; i++) {
        neibors[i] = NULL;
    }

    r = center->row;
    c = center->col;

    if (r > 0)
        neibors[UP] = &map[r - 1][c];

    if (r < row-1)
        neibors[DOWN] = &map[r + 1][c];

    if (c > 0)
        neibors[LEFT] = &map[r][c - 1];

    if (c < col-1)
        neibors[RIGHT] = &map[r][c + 1];

}

void Map::printPath() {
    node* n = goal;
    while (n) {
        n->walkable = PATH;
        n = n->parent;
    }
    printMap();
}