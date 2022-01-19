void rounds_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr);


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

        /// chaeck light - jack maree

        for (; rounds <= 8; ++rounds) {
            rounds_menu(first_map_ptr,road_x,road_y,character_ptr,rounds,tunnel_out_ptr);
        }
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

void rounds_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr) {
    int tmp;
    int *ptr_card_array = NULL;
    struct map *first_map_ptr = fmap;

    printf("Do you continue or save the game?\n");
    printf("1)continue \n2)Save\n3)Exit\n");
    scanf("%d",&tmp);
    if(tmp == 1) {
        /// chaeck light - jack maree - egra ghavanin ebtedaye round masala bardashtan cheragh
        ptr_card_array = rand_cards(rounds);

        show_character(ptr_card_array,rounds,character_ptr);

        print_map(fmap,road_x,road_y);

        play_rounds(ptr_card_array,rounds,character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);
    }
    else if(tmp == 2) {
        ///problem
    }
    else if(tmp == 3) {
        exit(0);
    }
    else {
        ///problem
        rounds_menu(first_map_ptr,road_x,road_y,character_ptr,rounds,tunnel_out_ptr);
    }
}
