
struct map* map_append(struct map** head) {

    struct map *new_node = (struct map*) malloc(sizeof(struct map));

    struct map *last = *head;

    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return new_node;
}

struct characters* character_append(struct characters** head) {

    struct characters *new_node = (struct characters*) malloc(sizeof(struct characters));

    struct characters *last = *head;

    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;

    return new_node;
}

struct out_tunnel* out_tunnel_append(struct out_tunnel** head) {

    struct out_tunnel *new_node = (struct out_tunnel*) malloc(sizeof(struct out_tunnel));

    struct out_tunnel *last = *head;

    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return new_node;
}

int random_num_1_8() {
    int tmp;
    srand(time(0));
    tmp = rand() % 8 + 1;

    return tmp;
}

void rand_select_jack(struct characters *character_ptr) {
    int tmp;
    struct characters *first = character_ptr;
    tmp = random_num_1_8();

    for (int i = 0; i < 8; ++i) {
        if(first->number == tmp) {
            printf("jack is : %s\n\n",first->name);
            first->jack = "YES";
            return;
        }
        first = first->next;
    }
}

int * rand_cards() {
    int tmp,r;
    static int card_array[8];

    srand(time(0));
    for (int i = 0; i < 8; ++i) {
        card_array[i] = i + 1;
    }
    for(int i = 7;i > 0; i--){
        r = rand() % i;
        tmp = card_array[i];
        card_array[i] = card_array[r];
        card_array[r] = tmp;
    }

    return card_array;

}

void check_lighting(struct map *first_map_ptr2,struct characters *character_ptr,int road_x,int road_y) {
    struct map *tmp_node1 = first_map_ptr2;
    struct map *tmp_node2 = first_map_ptr2;
    struct map *tmp_node3 = first_map_ptr2;
    struct characters *tmp_char = character_ptr;


    while(tmp_node1 != NULL) {
        tmp_node1->Lighting = 0;
        tmp_node1 = tmp_node1->next;
    }

    tmp_node1 = first_map_ptr2;

    while(tmp_node1 != NULL) {

        if(!strcmp(tmp_node1->person1,"JW")) {
            int xi = 0;
            int yj = 1;
            int t = 0;

            while (tmp_char != NULL) {
                if (!strcmp(tmp_char->name, "JW")) {
                    break;
                }
                tmp_char = tmp_char->next;
            }

            if (!strcmp(tmp_char->SG_ability_Direction, "UR")) {

                if (tmp_node1->y % 2 == 1) {
                    xi = 1;
                } else {
                    xi = 0;
                }

                while (tmp_node2->y <= road_y - 1 && tmp_node2->x <= road_x - 1) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x + xi && tmp_node2->y == tmp_node1->y + yj &&
                            tmp_node2->y <= road_y - 1 && tmp_node2->x <= road_x - 1) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++yj;
                    if (t == 0) {
                        t = 1;
                    } else {
                        ++xi;
                        t = 0;
                    }
                }
            }
            if (!strcmp(tmp_char->SG_ability_Direction, "UL")) {

                if (tmp_node1->y % 2 == 1) {
                    xi = 0;
                } else {
                    xi = 1;
                }

                while (tmp_node2->y <= road_y - 1 && tmp_node2->x >= 0) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x - xi && tmp_node2->y == tmp_node1->y + yj &&
                            tmp_node2->y <= road_y - 1 && tmp_node2->x >= 0) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++yj;
                    if (t == 0) {
                        ++xi;
                        t = 1;
                    } else {
                        t = 0;
                    }
                }

            }
            else if (!strcmp(tmp_char->SG_ability_Direction, "DR")) {

                if (tmp_node1->y % 2 == 1) {
                    xi = 1;
                } else {
                    xi = 0;
                }


                while (tmp_node2->y >= 0 && tmp_node2->x <= road_x - 1) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x + xi && tmp_node2->y == tmp_node1->y - yj &&
                            tmp_node2->y >= 0 && tmp_node2->x <= road_x - 1) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++yj;
                    if (t == 0) {
                        t = 1;
                    } else {
                        ++xi;
                        t = 0;
                    }
                }

            }
            else if (!strcmp(tmp_char->SG_ability_Direction, "DL")) {

                if (tmp_node1->y % 2 == 1) {
                    xi = 0;
                } else {
                    xi = 1;
                }

                while (tmp_node2->x >= 0 && tmp_node2->y >= 0) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x - xi && tmp_node2->y == tmp_node1->y - yj &&
                            tmp_node2->x >= 0 && tmp_node2->y >= 0) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++yj;
                    if (t == 0) {
                        ++xi;
                        t = 1;
                    } else {
                        t = 0;
                    }
                }
            }
            else if (!strcmp(tmp_char->SG_ability_Direction, "R")) {

                while (tmp_node2->x <= road_x - 1) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x + xi && tmp_node2->y == tmp_node1->y &&
                            tmp_node2->x <= road_x - 1) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++xi;
                }

                /*
                while (tmp_node2 != NULL) {

                    while(tmp_node3 != NULL) {
                        if(tmp_node3->x == tmp_node1->x + xi && tmp_node3->y == tmp_node1->y) {
                            break;
                        }
                        tmp_node3 = tmp_node3->next;
                    }

                    if(tmp_node3 == NULL) {
                        break;
                    }

                    if (tmp_node2->x == tmp_node1->x + xi && tmp_node2->y == tmp_node1->y && !(!strcmp(tmp_node3->home,"HM")) && tmp_node3->x <= road_x - 1) {
                        tmp_node2->Lighting = 1;
                        ++xi;
                        tmp_node2 = first_map_ptr2;
                    }
                    else if(!strcmp(tmp_node3->home,"HM")) {
                        break;
                    }

                    tmp_node3 = first_map_ptr2;
                    tmp_node2 = tmp_node2->next;
                }
                 */
            }
            else if (!strcmp(tmp_char->SG_ability_Direction, "L")) {

                while (tmp_node2->x >= 0) {

                    tmp_node2 = first_map_ptr2;

                    while (tmp_node2 != NULL) {
                        if (tmp_node2->x == tmp_node1->x - xi && tmp_node2->y == tmp_node1->y && tmp_node2->x >= 0) {
                            break;
                        }
                        tmp_node2 = tmp_node2->next;
                    }
                    if (tmp_node2 == NULL) {
                        break;
                    }
                    if (!strcmp(tmp_node2->home, "HM")) {
                        break;
                    }
                    tmp_node2->Lighting = 1;
                    ++xi;
                }

                /*
                while (tmp_node2 != NULL) {

                    while(tmp_node3 != NULL) {
                        if(tmp_node3->x == abs(tmp_node1->x - xi) && tmp_node3->y == tmp_node1->y) {
                            break;
                        }
                        tmp_node3 = tmp_node3->next;
                    }

                    if(tmp_node3 == NULL) {
                        break;
                    }

                    if (tmp_node2->x == abs(tmp_node1->x - xi) && tmp_node2->y == tmp_node1->y && !(!strcmp(tmp_node3->home,"HM")) && tmp_node3->x >= 0) {
                        tmp_node2->Lighting = 1;
                        ++xi;
                        tmp_node2 = first_map_ptr2;

                    }
                    else if(!strcmp(tmp_node3->home,"HM")) {
                        break;
                    }

                    tmp_node3 = first_map_ptr2;
                    tmp_node2 = tmp_node2->next;
                }
            }

            tmp_node2 = first_map_ptr2;
            */
            }

        }

        if(!(!strcmp(tmp_node1->person1,"NN"))) {
            while (tmp_node2 != NULL) {
                if(tmp_node1->y % 2 == 1) {
                    if (tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                }
                else {
                    if (tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                }
                tmp_node2 = tmp_node2->next;
            }
        }

        else if(!strcmp(tmp_node1->light,"LN")) {
            while (tmp_node2 != NULL) {
                if(tmp_node1->y % 2 == 1) {
                    if (tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                }
                else {
                    if (tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x + 1 && tmp_node2->y == tmp_node1->y) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y + 1) {
                        tmp_node2->Lighting = 1;
                    }
                    else if(tmp_node2->x == tmp_node1->x - 1 && tmp_node2->y == tmp_node1->y - 1) {
                        tmp_node2->Lighting = 1;
                    }
                }
                tmp_node2 = tmp_node2->next;
            }
        }


        tmp_node2 = first_map_ptr2;
        tmp_node3 = first_map_ptr2;
        tmp_node1 = tmp_node1->next;
    }

    for (int i = road_y; i > 0; --i) {
        if(i % 2 == 0) {
            printf("  ");
        }
        else {

        }
        for (int j = 0; j < road_x; ++j) {
            printf("%d%d  ",tmp_node2->Lighting,tmp_node2->Lighting);
            tmp_node2 = tmp_node2->next;
        }
        printf("\n");
    }

}

void jack_check_visible(struct map *first_map_ptr3,struct characters *character_ptr) {
    struct map *tmp_node1 = first_map_ptr3;
    struct characters *first_char = character_ptr;

    while(first_char != NULL) {
        if(!strcmp(first_char->jack,"YES")) {
            break;
        }
        first_char = first_char->next;
    }

    while(tmp_node1 != NULL) {
        if(!strcmp(tmp_node1->person1,first_char->name)) {
            break;
        }
        tmp_node1 = tmp_node1->next;
    }

    if(tmp_node1->Lighting == 1) {
        printf("\nJack is visible.\n\n");
    }
    else {
        printf("\nJack is invisible.\n\n");
    }
}
/// add if jack out win and if next 8 rounds jack win

void win_func(struct characters *character_ptr,struct map *first_map_ptr) {
    struct characters *first_char = character_ptr;
    struct map *tmpnode1 = first_map_ptr;

    while(first_char != NULL) {
        if(!strcmp(first_char->jack,"YES")) {
            break;
        }
        first_char = first_char->next;
    }

    while(tmpnode1 != NULL) {
        if(!strcmp(tmpnode1->person1,first_char->name)) {
            break;
        }
        tmpnode1 = tmpnode1->next;
    }

    if(!strcmp(tmpnode1->exit,"EO")) {
        printf("\njack wins.\n");
        exit(0);
    }
}