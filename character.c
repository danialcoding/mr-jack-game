
struct characters c_sg,c_sh,c_jw,c_ms,c_js,c_jb,c_wg,c_il;

struct characters* create_caracter_info(struct characters *character_ptr) {
    character_ptr = &c_sg;

    /** SG **/
    c_sg.name = "SG";
    c_sg.jack = "NO";
    c_sg.move = 3;
    c_sg.number = 1;
    c_sg.next = &c_sh;
    c_sg.info = "After whistling, he brings the game characters closer to him in a total of three moves";

    /** SH **/
    c_sh.name = "SH";
    c_sh.jack = "NO";
    c_sh.move = 3;
    c_sh.number = 2;
    c_sh.next = &c_jw;
    c_sh.info = "He picks up one of Jack's cards and sees it";

    /** JW **/
    c_jw.name = "JW";
    c_jw.jack = "NO";
    c_jw.move = 3;
    c_jw.number = 3;
    c_jw.next = &c_ms;
    c_jw.info = "After moving, he determines the direction of his flashlight";

    /** MS **/
    c_ms.name = "MS";
    c_ms.jack = "NO";
    c_ms.move = 4;
    c_ms.number = 4;
    c_ms.next = &c_js;
    c_ms.info = "He can pass through empty houses when he is on the move";

    /** JS **/
    c_js.name = "JS";
    c_js.jack = "NO";
    c_js.move = 3;
    c_js.number = 5;
    c_js.next = &c_jb;
    c_js.info = "He should turn off one light and turn on another light";

    /** JB **/
    c_jb.name = "JB";
    c_jb.jack = "NO";
    c_jb.move = 3;
    c_jb.number = 6;
    c_jb.next = &c_wg;
    c_jb.info = "He picks up one of the well covers and places it on another well";

    /** WG **/
    c_wg.name = "WG";
    c_wg.jack = "NO";
    c_wg.move = 3;
    c_wg.number = 7;
    c_wg.next = &c_il;
    c_wg.info = "He can move or change places with another character";

    /** IL **/
    c_il.name = "IL";
    c_il.jack = "NO";
    c_il.move = 3;
    c_il.number = 8;
    c_il.next = NULL;
    c_il.info = "He must pick up one of the blocking tokens and place it on the other exit";

    return character_ptr;
}

void show_character(int *ptr_card_array,int rounds,struct characters *character_ptr) {
    struct characters *first = character_ptr;
    int out_num;
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
            printf("%s.\n",character_ptr->info);
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
            printf("%d)character %s\n",i+1,character_ptr->name);
            printf("Move 1 to %d houses.\n",character_ptr->move);
            printf("%s.\n",character_ptr->info);
            character_ptr = first;
        }
    }
}


