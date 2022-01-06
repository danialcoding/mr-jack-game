
void start_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds) {
    int tmp;
    int *ptr_card_array = NULL;
    printf("1)Start \n2)Load\n3)Exit\n");
    scanf("%d",&tmp);
    if(tmp == 1) {
        character_ptr = create_caracter_info(character_ptr);

        rand_select_jack(character_ptr);

        ptr_card_array = rand_cards(rounds);

        show_character(ptr_card_array,rounds,character_ptr);

        read_map(fmap,road_x,road_y);

        play_rounds(ptr_card_array,rounds,character_ptr,fmap);
    }
    else if(tmp == 2) {
        ///problem
    }
    else if(tmp == 3) {
        exit(0);
    }
    else {
        start_menu(fmap,road_x,road_y,character_ptr,rounds);
    }
}

void rounds_menu() {
    /// next every round run for save or resume
}