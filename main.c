struct map {
    char *road;
    char *light;
    char *tunnel;
    char *home;
    char *person;
    char *exit;
    int x;
    int y;
    struct map* next;
};

#include "func.h"

#define road_x 13
#define road_y 9
int rounds = 8;

int main() {
    struct map *fmap = NULL;

    read_map(fmap,road_x,road_y);

}