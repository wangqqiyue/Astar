#include <astar.h>

int main() {
    Map myMap;
    node* start=NULL;
    node* goal = NULL;
    node* current = NULL;
    node* neibors[NEIBOR_NUM_MAX] = { 0 };
    priority_queue<node*> openList;
    int i=0;
    int g = 0;
    bool havePath = false;
    myMap.initMap();
    myMap.printMap();

    start = myMap.getStart();
    goal = myMap.getGoal();

    openList.push(start);
    start->open = true;
    while (!openList.empty()) {
        current = openList.top();
        current->moveToClose();
        openList.pop();
        if (GOAL == current->walkable){
            havePath = true;
            break;
        }
        myMap.getNeibors(current, neibors);
        for (i = 0; i < NEIBOR_NUM_MAX; i++) {
            if (!neibors[i] || UNWALKABLE == neibors[i]->walkable || true==neibors[i]->close) {
                continue;
            }

            if (false == neibors[i]->open) {
             
                neibors[i]->g= neibors[i]->getManhattan(start);
                neibors[i]->h= neibors[i]->getManhattan(goal);
                neibors[i]->f = neibors[i]->g + neibors[i]->h;
                neibors[i]->open = true;
                neibors[i]->parent = current;
                openList.push(neibors[i]);
            }
            else if (true == neibors[i]->open) {
                g = neibors[i]->getManhattan(current) + neibors[i]->g;
                if (g < neibors[i]->g) {
                    neibors[i]->g = g;
                    neibors[i]->f = neibors[i]->g + neibors[i]->h;
                    neibors[i]->parent = current;
                }
            }
        }
    }
    if (havePath) {
        myMap.printPath();
    }
    else {
        printf("Can't find a path.\n");
    }

    getchar();
    return 0;
}
