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
struct characters {
    char *name;
    char *jack;
    int move;
    int number;
    char *info;
    struct characters* next;
};

#include "func.h"

#define road_x 13
#define road_y 9
int rounds = 1;

int main() {
    struct map *fmap = NULL;
    struct characters *character_ptr = NULL;

    start_menu(fmap,road_x,road_y,character_ptr,rounds);


}