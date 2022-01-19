struct map {
    char *road;
    char *light;
    char *tunnel;
    char *home;
    char *person1;
    char *person2;
    char *exit;
    int Lighting;
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
    char *ability_time;
    char *SG_ability_Direction;
    struct characters* next;
};
struct out_tunnel {
    int x;
    int y;
    struct out_tunnel *next;
};

#include "func.h"

#define road_x 13
#define road_y 9
int rounds = 1;

int main() {
    struct map *fmap = NULL;
    struct characters *character_ptr = NULL;
    struct out_tunnel *tunnel_out_ptr = NULL;

    start_menu(fmap,road_x,road_y,character_ptr,rounds,tunnel_out_ptr);


}