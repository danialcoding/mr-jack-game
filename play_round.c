
int repetition(int i,int *array,int tmp) {
    array[i] = tmp;

    for (int j = 0; j < i; ++j) {
        if(array[j] == array[i]) {
            printf("The card you selected is a duplicate. Select another card :\n");
            scanf("%d",&tmp);
            tmp = repetition(i,array,tmp);
            return tmp;
        }
    }
    return tmp;
}

void play_rounds(int *ptr_card_array,int rounds,struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y) {
    int tmp,n;
    int array[4];
    int i = 0;
    struct map *first_mptr2 = first_map_ptr;

    if(rounds % 2 == 1) {
        show_character(ptr_card_array,rounds,character_ptr);
        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        tmp = repetition(i,array,tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        tmp = repetition(i,array,tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        tmp = repetition(i,array,tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        tmp = repetition(i,array,tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;
    }
    else {
        show_character(ptr_card_array,rounds,character_ptr);
        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        repetition(i,array,tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        repetition(i,array,tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        repetition(i,array,tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;

        show_character(ptr_card_array,rounds,character_ptr);
        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        repetition(i,array,tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,first_map_ptr,tunnel_out_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        print_map(first_map_ptr,road_x,road_y);
        first_map_ptr = first_mptr2;
        ++i;
    }
}