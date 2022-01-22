
struct characters c_sg,c_sh,c_jw,c_ms,c_js,c_jb,c_wg,c_il;
void card_movement(struct characters *character_ptr,struct map *fmap,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y);
void card_movement_ms(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y);
void come_back(int xasli,int yasli,char *character_name,struct map *first_m,int *T2);
void card_ability(struct characters *character_ptr,struct characters *character_ptr_head,struct map *first_map_ptr,int road_x,int road_y,int rounds);

struct characters* create_caracter_info(struct characters *character_ptr) {
    character_ptr = &c_sg;

    /** SG **/
    c_sg.name = "SG";
    c_sg.jack = "NO";
    c_sg.move = 3;
    c_sg.number = 1;
    c_sg.next = &c_sh;
    c_sg.info = "After whistling, he brings the game characters closer to him in a total of three moves";
    c_sg.ability_time = "NP";

    /** SH **/
    c_sh.name = "SH";
    c_sh.jack = "NO";
    c_sh.move = 3;
    c_sh.number = 2;
    c_sh.next = &c_jw;
    c_sh.info = "He picks up one of Jack's cards and sees it";
    c_sh.ability_time = "NX";

    /** JW **/
    c_jw.name = "JW";
    c_jw.jack = "NO";
    c_jw.move = 3;
    c_jw.number = 3;
    c_jw.next = &c_ms;
    c_jw.info = "After moving, he determines the direction of his flashlight";
    c_jw.ability_time = "NX";
    c_jw.SG_ability_Direction = "N";

    /** MS **/
    c_ms.name = "MS";
    c_ms.jack = "NO";
    c_ms.move = 4;
    c_ms.number = 4;
    c_ms.next = &c_js;
    c_ms.info = "He can pass through empty houses when he is on the move";
    c_ms.ability_time = "IN";

    /** JS **/
    c_js.name = "JS";
    c_js.jack = "NO";
    c_js.move = 3;
    c_js.number = 5;
    c_js.next = &c_jb;
    c_js.info = "He should turn off one light and turn on another light";
    c_js.ability_time = "NP";

    /** JB **/
    c_jb.name = "JB";
    c_jb.jack = "NO";
    c_jb.move = 3;
    c_jb.number = 6;
    c_jb.next = &c_wg;
    c_jb.info = "He picks up one of the well covers and places it on another well";
    c_jb.ability_time = "NP";

    /** WG **/
    c_wg.name = "WG";
    c_wg.jack = "NO";
    c_wg.move = 3;
    c_wg.number = 7;
    c_wg.next = &c_il;
    c_wg.info = "He can move or change places with another character";
    c_wg.ability_time = "OR";

    /** IL **/
    c_il.name = "IL";
    c_il.jack = "NO";
    c_il.move = 3;
    c_il.number = 8;
    c_il.next = NULL;
    c_il.info = "He must pick up one of the blocking tokens and place it on the other exit";
    c_il.ability_time = "NP";

    return character_ptr;
}

void show_character(int *ptr_card_array,int rounds,struct characters *character_ptr) {
    struct characters *first = character_ptr;

    if(rounds % 2 == 1) {
        for (int i = 0; i < 4; ++i) {
            while(character_ptr != NULL) {
                if(character_ptr->number == *(ptr_card_array + i)) {
                    break;
                }
                character_ptr = character_ptr->next;
            }
            printf("%d)character %s\n",i+1,character_ptr->name);
            printf("Move 1 to %d houses.\n",character_ptr->move);
            printf("%s.\n\n",character_ptr->info);
            character_ptr = first;
        }
    }
    else {
        for (int i = 4; i < 8; ++i) {
            while(character_ptr != NULL) {
                if(character_ptr->number == *(ptr_card_array + i)) {
                    break;
                }
                character_ptr = character_ptr->next;
            }
            printf("%d)character %s\n",i-3,character_ptr->name);
            printf("Move 1 to %d houses.\n",character_ptr->move);
            printf("%s.\n\n",character_ptr->info);
            character_ptr = first;
        }
    }
}

void choose_move_abl(struct characters *character_ptr,int card_number,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y,int rounds) {
    struct characters *character_ptr_head = character_ptr;
    struct characters *first = character_ptr;

    while(character_ptr != NULL) {
        if(character_ptr->number == card_number) {
            break;
        }
        character_ptr = character_ptr->next;
    }

    char *tmp_move = character_ptr->ability_time;
    int user_choose;
    if(!strcmp(tmp_move,"NP")) {
        printf("Choose which one you want to do first :\n");
        printf("1)Move\n2)ability\n");
        scanf("%d",&user_choose);
        if(user_choose == 1) {
            printf("Move:\n");
            card_movement(character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
            printf("Ability:\n");
            card_ability(character_ptr,character_ptr_head,first_map_ptr,road_x,road_y,rounds);
        }
        else if(user_choose == 2) {
            printf("Ability:\n");
            card_ability(character_ptr,character_ptr_head,first_map_ptr,road_x,road_y,rounds);
            printf("Move:\n");
            card_movement(character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        }
        printf("\n");
    }
    else if(!strcmp(tmp_move,"NX")) {
        printf("Move:\n");
        card_movement(character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        printf("Ability:\n");
        card_ability(character_ptr,character_ptr_head,first_map_ptr,road_x,road_y,rounds);
        printf("\n");
    }
    else if(!strcmp(tmp_move,"OR")) {
        printf("1)Move OR 2)ability\n");
        scanf("%d",&user_choose);
        if(user_choose == 1) {
            card_movement(character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        }
        else if(user_choose == 2) {
            card_ability(character_ptr,character_ptr_head,first_map_ptr,road_x,road_y,rounds);
        }
        printf("\n");
    }
    else if(!strcmp(tmp_move,"IN")) {
        printf("Move with ability :\n");
        card_movement_ms(character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        printf("\n");
    }

    character_ptr = first;
}

void jack_mood() {

}


