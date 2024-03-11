#include <astar.h>

void Map::printMap() {
    int r, c;
    printf("======Map======\n");
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            printf("%d ", map[r][c].walkable);
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

    printf("Please input Map content:\n");
    rewind(stdin);
    for (i = 0; i < row; i++) {
        fgets(line, LINE_LEN - 1, stdin);
        token = strtok_s(line, delim, &context);
        for (j = 0; j < col; j++) {
            map[i][j].walkable = atoi(token);
            token = strtok_s(NULL, delim, &context);
        }
    }
    this->map = map;
    this->row = row;
    this->col = col;
}
