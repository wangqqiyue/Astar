#include <astar.h>

int main() {
    Map map;
    node* start;
    node* goal;
    priority_queue<node> openList;
    map.initMap();
    map.printMap();

    getchar();
    return 0;
}
