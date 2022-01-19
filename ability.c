struct swap_ability {
    int x;
    int y;
    struct swap_ability *next;
};
struct swap_ability_char {
    char *name;
    int x;
    int y;
    struct swap_ability_char *next;
};

struct swap_ability* swap_ability_append(struct swap_ability** head) {

    struct swap_ability *new_node = (struct swap_ability*) malloc(sizeof(struct swap_ability));

    struct swap_ability *last = *head;

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
struct swap_ability_char* lights_swap_append(struct swap_ability_char** head) {

    struct swap_ability_char *new_node = (struct swap_ability_char*) malloc(sizeof(struct swap_ability_char));

    struct swap_ability_char *last = *head;

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
int rand_num_SH(int jack_num) {
    int tmp;
    srand(time(0));
    tmp = rand() % 9;
    if(tmp == 0) {
        tmp = tmp + 1;
    }

    if(tmp == jack_num) {
        return rand_num_SH(jack_num);
    }

    return tmp;
}

void card_ability(struct characters *character_ptr,struct characters *character_ptr_head,struct map *first_map_ptr) {
    struct characters *jack_ptr = character_ptr_head;
    struct characters *tmp_character_ptr = character_ptr_head;
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;


    if(!strcmp(character_ptr->name,"SH")) {
        int number;
        while(jack_ptr != NULL) {
            if(!strcmp(jack_ptr->jack,"YES")) {
                break;
            }
            jack_ptr = jack_ptr->next;
        }

        number = rand_num_SH(jack_ptr->number);

        while(tmp_character_ptr != NULL) {
            if(tmp_character_ptr->number == number) {
                break;
            }
            tmp_character_ptr = tmp_character_ptr->next;
        }
        printf("%s character is not jack.\n",tmp_character_ptr->name);
    }

    else if(!strcmp(character_ptr->name,"JS")) {
        struct swap_ability *lighton = NULL;
        struct swap_ability *lighton_tmp_node = NULL;
        struct swap_ability *lightoff = NULL;
        struct swap_ability *lightoff_tmp_node = NULL;
        int tmp,count = 1,xasli,yasli;

        printf("Lights on :\n");
        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->light,"LN")) {
                printf("%d)x: %d Y: %d\n",count,tmpnode1->x,tmpnode1->y);

                lighton_tmp_node = swap_ability_append(&lighton);
                lighton_tmp_node->x = tmpnode1->x;
                lighton_tmp_node->y = tmpnode1->y;

                ++count;
            }
            tmpnode1 = tmpnode1->next;
        }
        count = 1;
        lighton_tmp_node = lighton;
        tmpnode1 = first_m;

        printf("Which light do you want to turn off?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            lighton_tmp_node = lighton_tmp_node->next;
        }

        while(tmpnode1 != NULL) {
            if(tmpnode1->x == lighton_tmp_node->x && tmpnode1->y == lighton_tmp_node->y) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                tmpnode1->light = "LF";
            }
            tmpnode1 = tmpnode1->next;
        }

        printf("Lights off :\n");
        while(tmpnode2 != NULL) {
            if(!strcmp(tmpnode2->light,"LF") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                printf("%d)x: %d Y: %d\n",count,tmpnode2->x,tmpnode2->y);

                lightoff_tmp_node = swap_ability_append(&lightoff);
                lightoff_tmp_node->x = tmpnode2->x;
                lightoff_tmp_node->y = tmpnode2->y;

                ++count;
            }
            tmpnode2 = tmpnode2->next;
        }
        tmpnode2 = first_m;
        lightoff_tmp_node = lightoff;

        printf("Which light do you want to turn on?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            lightoff_tmp_node = lightoff_tmp_node->next;
        }

        while(tmpnode2 != NULL) {
            if(tmpnode2->x == lightoff_tmp_node->x && tmpnode2->y == lightoff_tmp_node->y) {
                tmpnode2->light = "LN";
            }
            tmpnode2 = tmpnode2->next;
        }
    }

    else if(!strcmp(character_ptr->name,"JB")) {
        struct swap_ability *opentunnel = NULL;
        struct swap_ability *opentunnel_tmp_node = NULL;
        struct swap_ability *Closetunnel = NULL;
        struct swap_ability *Closetunnel_tmp_node = NULL;
        int tmp,count = 1,xasli,yasli;

        printf("Closed tunnels :\n");
        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->tunnel,"TC")) {
                printf("%d)x: %d Y: %d\n",count,tmpnode1->x,tmpnode1->y);

                opentunnel_tmp_node = swap_ability_append(&opentunnel);
                opentunnel_tmp_node->x = tmpnode1->x;
                opentunnel_tmp_node->y = tmpnode1->y;

                ++count;
            }
            tmpnode1 = tmpnode1->next;
        }
        count = 1;
        opentunnel_tmp_node = opentunnel;
        tmpnode1 = first_m;

        printf("Which tunnel do you want to open?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            opentunnel_tmp_node = opentunnel_tmp_node->next;
        }

        while(tmpnode1 != NULL) {
            if(tmpnode1->x == opentunnel_tmp_node->x && tmpnode1->y == opentunnel_tmp_node->y) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                tmpnode1->tunnel = "TO";
            }
            tmpnode1 = tmpnode1->next;
        }

        printf("Open tunnels :\n");
        while(tmpnode2 != NULL) {
            if(!strcmp(tmpnode2->tunnel,"TO") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                printf("%d)x: %d Y: %d\n",count,tmpnode2->x,tmpnode2->y);

                Closetunnel_tmp_node = swap_ability_append(&Closetunnel);
                Closetunnel_tmp_node->x = tmpnode2->x;
                Closetunnel_tmp_node->y = tmpnode2->y;

                ++count;
            }
            tmpnode2 = tmpnode2->next;
        }
        tmpnode2 = first_m;
        Closetunnel_tmp_node = Closetunnel;

        printf("Which tunnel do you want to close?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            Closetunnel_tmp_node = Closetunnel_tmp_node->next;
        }

        while(tmpnode2 != NULL) {
            if(tmpnode2->x == Closetunnel_tmp_node->x && tmpnode2->y == Closetunnel_tmp_node->y) {
                tmpnode2->tunnel = "TC";
            }
            tmpnode2 = tmpnode2->next;
        }
    }

    else if(!strcmp(character_ptr->name,"IL")) {
        struct swap_ability *open_escapeway = NULL;
        struct swap_ability *open_escapeway_tmp_node = NULL;
        struct swap_ability *close_escapeway = NULL;
        struct swap_ability *close_escapeway_tmp_node = NULL;
        int tmp,count = 1,xasli,yasli;

        printf("close escape ways :\n");
        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->exit,"EC")) {
                printf("%d)x: %d Y: %d\n",count,tmpnode1->x,tmpnode1->y);

                open_escapeway_tmp_node = swap_ability_append(&open_escapeway);
                open_escapeway_tmp_node->x = tmpnode1->x;
                open_escapeway_tmp_node->y = tmpnode1->y;

                ++count;
            }
            tmpnode1 = tmpnode1->next;
        }
        count = 1;
        open_escapeway_tmp_node = open_escapeway;
        tmpnode1 = first_m;

        printf("Which escape way do you want to open?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            open_escapeway_tmp_node = open_escapeway_tmp_node->next;
        }

        while(tmpnode1 != NULL) {
            if(tmpnode1->x == open_escapeway_tmp_node->x && tmpnode1->y == open_escapeway_tmp_node->y) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                tmpnode1->exit = "EO";
            }
            tmpnode1 = tmpnode1->next;
        }

        printf("open escape ways :\n");
        while(tmpnode2 != NULL) {
            if(!strcmp(tmpnode2->exit,"EO") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                printf("%d)x: %d Y: %d\n",count,tmpnode2->x,tmpnode2->y);

                close_escapeway_tmp_node = swap_ability_append(&close_escapeway);
                close_escapeway_tmp_node->x = tmpnode2->x;
                close_escapeway_tmp_node->y = tmpnode2->y;

                ++count;
            }
            tmpnode2 = tmpnode2->next;
        }
        tmpnode2 = first_m;
        close_escapeway_tmp_node = close_escapeway;

        printf("Which escape way do you want to close?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            close_escapeway_tmp_node = close_escapeway_tmp_node->next;
        }

        while(tmpnode2 != NULL) {
            if(tmpnode2->x == close_escapeway_tmp_node->x && tmpnode2->y == close_escapeway_tmp_node->y) {
                tmpnode2->exit = "EC";
            }
            tmpnode2 = tmpnode2->next;
        }
    }

    else if(!strcmp(character_ptr->name,"WG")) {
        struct swap_ability_char *WG_loc = (struct swap_ability_char *)malloc(sizeof(struct swap_ability_char));
        struct swap_ability_char *characters_loc = NULL;
        struct swap_ability_char *characters_loc_tmp_node = NULL;
        int tmp,count = 1;

        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->person1,"WG")) {

                WG_loc->x = tmpnode1->x;
                WG_loc->y = tmpnode1->y;
                WG_loc->name = tmpnode1->person1;
                WG_loc->next = NULL;
                break;
            }
            tmpnode1 = tmpnode1->next;
        }


        printf("characters :\n");
        while(tmpnode2 != NULL) {
            if(!(!strcmp(tmpnode2->person1,"NN")) && (tmpnode2->x != WG_loc->x || tmpnode2->y != WG_loc->y)) {
                printf("%d)%s\n",count,tmpnode2->person1);

                characters_loc_tmp_node = lights_swap_append(&characters_loc);
                characters_loc_tmp_node->x = tmpnode2->x;
                characters_loc_tmp_node->y = tmpnode2->y;
                characters_loc_tmp_node->name = tmpnode2->person1;

                ++count;
            }
            tmpnode2 = tmpnode2->next;
        }
        tmpnode2 = first_m;
        characters_loc_tmp_node = characters_loc;

        printf("you want replace WG with wich character?\n");
        scanf("%d",&tmp);
        for (int j = 1; j < tmp; ++j) {
            characters_loc_tmp_node = characters_loc_tmp_node->next;
        }

        while(tmpnode2 != NULL) {
            if(tmpnode2->x == characters_loc_tmp_node->x && tmpnode2->y == characters_loc_tmp_node->y) {
                tmpnode1->person1 = tmpnode2->person1;
                tmpnode2->person1 = WG_loc->name;
            }
            tmpnode2 = tmpnode2->next;
        }
    }
}