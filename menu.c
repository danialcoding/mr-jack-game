
void start_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr) {
    int tmp;
    int *ptr_card_array = NULL;
    struct map *first_map_ptr;
    printf("1)Start \n2)Load\n3)Exit\n");
    scanf("%d",&tmp);
    if(tmp == 1) {
        character_ptr = create_caracter_info(character_ptr);

        rand_select_jack(character_ptr);

        ptr_card_array = rand_cards(rounds);

        show_character(ptr_card_array,rounds,character_ptr);

        first_map_ptr = read_map(fmap,road_x,road_y);

        play_rounds(ptr_card_array,rounds,character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
    }
    else if(tmp == 2) {
        ///problem
    }
    else if(tmp == 3) {
        exit(0);
    }
    else {
        start_menu(fmap,road_x,road_y,character_ptr,rounds,tunnel_out_ptr);
    }
}

void rounds_menu() {
    /// next every round run for save or resume
}
