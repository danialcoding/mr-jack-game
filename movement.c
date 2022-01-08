
void tow_character_inone(struct characters *character_ptr,struct map *tmpnode1,struct map *tmpnode2,int yasli,int xasli,struct out_tunnel *tunnel_out_ptr) {
    struct characters *first_ch = character_ptr;
    struct map *first_m = tmpnode1;

    while(tmpnode1 != NULL) {
        if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
            break;
        }
        tmpnode1 = tmpnode1->next;
    }
    if(!(!strcmp(tmpnode1->person1,"NN")) && !(!strcmp(tmpnode1->person2,"NN"))) {
        if(!strcmp(tmpnode1->person1,character_ptr->name)) {
            tmpnode1->person1 = "NN";
        }
        else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
            tmpnode1->person2 = "NN";
        }


        while(tmpnode2 != NULL) {
            if(tmpnode2->y == yasli && tmpnode2->x == xasli) {
                break;
            }
            tmpnode2 = tmpnode2->next;
        }
        tmpnode2->person1 = character_ptr->name;

        tmpnode1 = tmpnode2 = first_m;
        character_ptr = first_ch;

        card_movement(character_ptr,first_m,tunnel_out_ptr);
        return;
    }
    else {
        tmpnode1 = first_m;
    }
}



void card_movement(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr) {
    char *choose_move = malloc(2 * sizeof(char));
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;
    struct characters *first_ch = character_ptr;
    struct out_tunnel *tunnel_new_node;
    struct out_tunnel *first_tunnel;
    int serachx,serachy;
    int xasli,yasli,T = 1;
    int tmp;

    printf("You can do 1 to %d moves (up = U , down = D , right = R , left = L , use unnel = T , stop = X).\n",character_ptr->move);

    for (int i = 0; i < (character_ptr->move); ++i) {
        printf("move %d :",i+1);
        scanf("%s",choose_move);

        if(!strcmp(choose_move,"T")) {
            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            if(!strcmp(tmpnode1->tunnel,"TO")) {
                int count = 1;
                printf("choose the tunnel you want to exit and type number :\n");

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && tmpnode2->x != tmpnode1->x && tmpnode2->y != tmpnode1->y) {
                        printf("%d)x: %d Y: %d\n",count,tmpnode2->x,tmpnode2->y);
                        tunnel_new_node = out_tunnel_append(&tunnel_out_ptr);
                        tunnel_new_node->x = tmpnode2->x;
                        tunnel_new_node->y = tmpnode2->y;
                        ++count;
                    }
                    tmpnode2 = tmpnode2->next;
                }
                --count;
                tmpnode2 = first_m;
                first_tunnel = tunnel_out_ptr;
                scanf("%d",&tmp);
                for (int j = 1; j < tmp; ++j) {
                    tunnel_out_ptr = tunnel_out_ptr->next;
                }

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && tmpnode2->x == tunnel_out_ptr->x && tmpnode2->y == tunnel_out_ptr->y) {
                        break;
                    }
                    tmpnode2 = tmpnode2->next;
                }

                if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                    if(!strcmp(tmpnode1->person1,character_ptr->name)) {
                        tmpnode1->person1 = "NN";
                    }
                    else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
                        tmpnode1->person2 = "NN";
                    }

                    if(!strcmp(tmpnode2->person1,"NN")) {
                        tmpnode2->person1 = character_ptr->name;
                    }
                    else if(!strcmp(tmpnode2->person2,"NN")) {
                        tmpnode2->person2 = character_ptr->name;
                    }
                }
                else {
                    card_movement(character_ptr,first_m,tunnel_out_ptr);
                    return;
                }

                tunnel_out_ptr = first_tunnel;
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
            else{
                card_movement(character_ptr,first_m,tunnel_out_ptr);
                return;
            }
        }
        else if(!strcmp(choose_move,"U")) {

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }
            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y <= 9) {
                if(!strcmp(tmpnode1->person1,character_ptr->name)) {
                    tmpnode1->person1 = "NN";
                }
                else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
                    tmpnode1->person2 = "NN";
                }

                if(!strcmp(tmpnode2->person1,"NN")) {
                    tmpnode2->person1 = character_ptr->name;
                }
                else if(!strcmp(tmpnode2->person2,"NN")) {
                    tmpnode2->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,first_m,tunnel_out_ptr);
                return;
            }

            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if(!strcmp(choose_move,"D")) {

            while(tmpnode1 != NULL) {
                if((!strcmp(tmpnode1->person1,character_ptr->name)) || (!strcmp(tmpnode1->person2,character_ptr->name))) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) - 1;

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }
            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y >= 0) {
                if(!strcmp(tmpnode1->person1,character_ptr->name)) {
                    tmpnode1->person1 = "NN";
                }
                else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
                    tmpnode1->person2 = "NN";
                }

                if(!strcmp(tmpnode2->person1,"NN")) {
                    tmpnode2->person1 = character_ptr->name;
                }
                else if(!strcmp(tmpnode2->person2,"NN")) {
                    tmpnode2->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,first_m,tunnel_out_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if(!strcmp(choose_move,"R")) {

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            serachx = (tmpnode1->x) + 1;
            serachy = tmpnode1->y;
            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }
            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x <= 13) {
                if(!strcmp(tmpnode1->person1,character_ptr->name)) {
                    tmpnode1->person1 = "NN";
                }
                else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
                    tmpnode1->person2 = "NN";
                }

                if(!strcmp(tmpnode2->person1,"NN")) {
                    tmpnode2->person1 = character_ptr->name;
                }
                else if(!strcmp(tmpnode2->person2,"NN")) {
                    tmpnode2->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,first_m,tunnel_out_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if(!strcmp(choose_move,"L")) {

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            serachx = (tmpnode1->x) - 1;
            serachy = tmpnode1->y;
            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }
            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x >= 0) {
                if(!strcmp(tmpnode1->person1,character_ptr->name)) {
                    tmpnode1->person1 = "NN";
                }
                else if(!strcmp(tmpnode1->person2,character_ptr->name)) {
                    tmpnode1->person2 = "NN";
                }

                if(!strcmp(tmpnode2->person1,"NN")) {
                    tmpnode2->person1 = character_ptr->name;
                }
                else if(!strcmp(tmpnode2->person2,"NN")) {
                    tmpnode2->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,first_m,tunnel_out_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if((!strcmp(choose_move,"X")) && i != 0) {
            tow_character_inone(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr);
            return;
        }
        else {
            card_movement(character_ptr,first_m,tunnel_out_ptr);
            return;
        }
    }
    tow_character_inone(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr);
}