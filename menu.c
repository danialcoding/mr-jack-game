void rounds_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr,int *ptr_card_array);


void start_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr) {
    int tmp;
    int *ptr_card_array = NULL;
    struct map *first_map_ptr;
    struct map *first_map_ptr2;
    struct map *first_map_ptr3;

    printf("1)Start \n2)Load\n3)Exit\n");
    scanf("%d",&tmp);

    if(tmp == 1) {
        character_ptr = create_caracter_info(character_ptr);

        rand_select_jack(character_ptr);

        ptr_card_array = rand_cards(rounds);

        first_map_ptr = read_map(fmap,road_x,road_y);

        first_map_ptr2 = first_map_ptr;
        first_map_ptr3 = first_map_ptr;

        printf("\n");

        play_rounds(ptr_card_array,rounds,character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);

        check_lighting(first_map_ptr2,character_ptr,road_x,road_y);

        jack_check_visible(first_map_ptr3,character_ptr);

        ++rounds;

        rounds_menu(first_map_ptr,road_x,road_y,character_ptr,rounds,tunnel_out_ptr,ptr_card_array);
    }
    else if(tmp == 2) {
        struct map *new_node_map;
        struct characters *new_node_char;
        int card_array[8];

        char str1[150] = "/./c-code/project/save/";
        char str2[50];

        printf("Type the name of the file to load the game :\n");
        scanf("%s",str2);

        strcat(str1,str2);

        FILE *fpload = fopen(str1,"rb");

        if(fpload == NULL) {
            exit(1);
        }


        fread (&rounds,sizeof(int),1,fpload);
        fread (&road_x,sizeof(int),1,fpload);
        fread (&road_y,sizeof(int),1,fpload);
        for (int i = 0; i < 8; ++i) {
            new_node_char = character_append(&character_ptr);

            fread(&new_node_char->name,sizeof(char *),1,fpload);
            fread(&new_node_char->jack,sizeof(char *),1,fpload);
            fread(&new_node_char->move,sizeof(int),1,fpload);
            fread(&new_node_char->number,sizeof(int),1,fpload);
            fread(&new_node_char->info,sizeof(char *),1,fpload);
            fread(&new_node_char->ability_time,sizeof(char *),1,fpload);
            fread(&new_node_char->SG_ability_Direction,sizeof(char *),1,fpload);
        }

        for (int i = 0; i < road_y * road_x; ++i) {
            new_node_map = map_append(&fmap);

            fread(&new_node_map->road,sizeof(char *),1,fpload);
            fread(&new_node_map->light,sizeof(char *),1,fpload);
            fread(&new_node_map->tunnel,sizeof(char *),1,fpload);
            fread(&new_node_map->home,sizeof(char *),1,fpload);
            fread(&new_node_map->person1,sizeof(char *),1,fpload);
            fread(&new_node_map->person2,sizeof(char *),1,fpload);
            fread(&new_node_map->exit,sizeof(char *),1,fpload);
            fread(&new_node_map->Lighting,sizeof(int),1,fpload);
            fread(&new_node_map->x,sizeof(int),1,fpload);
            fread(&new_node_map->y,sizeof(int),1,fpload);
        }
        fread(card_array,sizeof(int),8,fpload);
        ptr_card_array = card_array;


        fclose(fpload);

        rounds_menu(fmap,road_x,road_y,character_ptr,rounds,tunnel_out_ptr,ptr_card_array);
    }
    else if(tmp == 3) {
        exit(0);
    }
    else {
        start_menu(fmap,road_x,road_y,character_ptr,rounds,tunnel_out_ptr);
    }
}

void rounds_menu(struct map *fmap,int road_x,int road_y,struct characters *character_ptr,int rounds,struct out_tunnel *tunnel_out_ptr,int *ptr_card_array) {
    int tmp;
    struct map *first_map_ptr = fmap;
    struct map *first_map_ptr2 = fmap;
    struct map *first_map_ptr3 = fmap;
    struct map *first_map_ptr_for_save = fmap;

    for (; rounds <= 8; ++rounds) {

        printf("Do you continue or save the game?\n");
        printf("1)continue \n2)Save\n3)Exit\n");
        scanf("%d",&tmp);
        if(tmp == 1) {
            printf("\nround %d\n\n",rounds);

            if(rounds % 2 == 1) {
                ptr_card_array = rand_cards(rounds);
            }

            print_map(fmap,road_x,road_y);

            printf("\n");

            play_rounds(ptr_card_array,rounds,character_ptr,first_map_ptr,tunnel_out_ptr,road_x,road_y);

            printf("\n");

            check_lighting(first_map_ptr2,character_ptr,road_x,road_y);

            jack_check_visible(first_map_ptr3,character_ptr);
        }
        else if(tmp == 2) {
            char str1[150] = "/./c-code/project/save/";
            char str2[50];
            int card_array[8] = {0};

            printf("Type the name of the file to save the game :\n");
            scanf("%s",&str2);

            strcat(str1,str2);

            FILE *fpsave = fopen(str1,"wb");

            if(fpsave == NULL) {
                exit(1);
            }

            fwrite(&rounds,sizeof(int),1,fpsave);
            fwrite(&road_x,sizeof(int),1,fpsave);
            fwrite(&road_y,sizeof(int),1,fpsave);
            for (int i = 0; i < 8; ++i) {
                fwrite(&character_ptr->name,sizeof(char *),1,fpsave);
                fwrite(&character_ptr->jack,sizeof(char *),1,fpsave);
                fwrite(&character_ptr->move,sizeof(int),1,fpsave);
                fwrite(&character_ptr->number,sizeof(int),1,fpsave);
                fwrite(&character_ptr->info,sizeof(char *),1,fpsave);
                fwrite(&character_ptr->ability_time,sizeof(char *),1,fpsave);
                fwrite(&character_ptr->SG_ability_Direction,sizeof(char *),1,fpsave);

                character_ptr = character_ptr->next;
            }
            for (int i = 0; i < road_y * road_x; ++i) {
                fwrite(&first_map_ptr_for_save->road,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->light,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->tunnel,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->home,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->person1,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->person2,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->exit,sizeof(char *),1,fpsave);
                fwrite(&first_map_ptr_for_save->Lighting,sizeof(int),1,fpsave);
                fwrite(&first_map_ptr_for_save->x,sizeof(int),1,fpsave);
                fwrite(&first_map_ptr_for_save->y,sizeof(int),1,fpsave);

                first_map_ptr_for_save = first_map_ptr_for_save->next;
            }
            for (int i = 0; i < 8; ++i) {
                card_array[i] = *(ptr_card_array + i);
            }
            fwrite(card_array,sizeof(int),8,fpsave);


            fclose(fpsave);

            printf("Your game with name %s has been saved.",str2);

            exit(0);
        }
        else if(tmp == 3) {
            exit(0);
        }
        else {
            rounds_menu(first_map_ptr,road_x,road_y,character_ptr,rounds,tunnel_out_ptr,ptr_card_array);
        }
    }

    printf("\njack wins.\n");
    exit(0);

}
