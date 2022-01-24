

void tow_character_inone(struct characters *character_ptr,struct map *tmpnode1,struct map *tmpnode2,int yasli,int xasli,struct out_tunnel *tunnel_out_ptr,int *T2,int road_x,int road_y) {
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

        come_back(xasli,yasli,character_ptr->name,first_m,T2);
        card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
        return;
    }
    else {
        tmpnode1 = first_m;
    }
}

void tow_character_inone_ms(struct characters *character_ptr,struct map *tmpnode1,struct map *tmpnode2,int yasli,int xasli,struct out_tunnel *tunnel_out_ptr,int *T2,int road_x,int road_y) {
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

        come_back(xasli,yasli,character_ptr->name,first_m,T2);
        card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
        return;
    }
    else {
        tmpnode1 = first_m;
    }
}

void tow_character_inone_Inspector(struct characters *character_ptr,struct map *tmpnode1,struct map *tmpnode2,int yasli,int xasli,struct out_tunnel *tunnel_out_ptr,int *T2,int road_x,int road_y,struct characters *first_character_ptr) {
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

        come_back(xasli,yasli,character_ptr->name,first_m,T2);
        card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
        return;
    }
    else {
        tmpnode1 = first_m;
    }
}

void tow_character_inone_Inspector_ms(struct characters *character_ptr,struct map *tmpnode1,struct map *tmpnode2,int yasli,int xasli,struct out_tunnel *tunnel_out_ptr,int *T2,int road_x,int road_y,struct characters *first_character_ptr) {
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

        come_back(xasli,yasli,character_ptr->name,first_m,T2);
        card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
        return;
    }
    else {
        tmpnode1 = first_m;
    }
}

void come_back(int xasli,int yasli,char *character_name,struct map *first_m,int *T2) {
    struct map *tmpnode2 = first_m;
    struct map *tmpnode1= first_m;

    if(*T2 == 1) {

    }
    else if(*T2 == 0) {
        while(tmpnode2 != NULL) {
            if(!strcmp(tmpnode2->person1,character_name) || !strcmp(tmpnode2->person2,character_name)) {
                break;
            }
            tmpnode2 = tmpnode2->next;
        }

        if(!strcmp(tmpnode2->person1,character_name)) {
            tmpnode2->person1 = "NN";
        }
        else if(!strcmp(tmpnode2->person2,character_name)) {
            tmpnode2->person2 = "NN";
        }

        while(tmpnode1 != NULL) {
            if(tmpnode1->x == xasli && tmpnode1->y == yasli) {
                break;
            }
            tmpnode1 = tmpnode1->next;
        }
        tmpnode1->person1 = character_name;
    }
}


void card_movement(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y) {
    char *choose_move = malloc(2 * sizeof(char));
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;
    struct characters *first_ch = character_ptr;
    struct out_tunnel *tunnel_new_node;
    struct out_tunnel *first_tunnel;
    int serachx,serachy;
    int xasli,yasli,T = 1,T2 = 0;
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode1->tunnel,"TO")) {
                int count = 1;
                printf("choose the tunnel you want to exit and type number :\n");

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && (tmpnode2->x != tmpnode1->x || tmpnode2->y != tmpnode1->y)) {
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
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                    return;
                }

                tunnel_out_ptr = first_tunnel;
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
            else{
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;

            if(serachy <= road_y - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y <= road_y - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) - 1;

            if(serachy >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) + 1;
            serachy = tmpnode1->y;

            if(serachx <= road_x - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x <= road_x - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) - 1;
            serachy = tmpnode1->y;

            if(serachx >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if((!strcmp(choose_move,"X")) && i != 0) {
            tow_character_inone(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
            return;
        }
        else {
            if(T == 1) {
                T2 = 1;
            }
            else {
                T2 = 0;
            }
            come_back(xasli,yasli,character_ptr->name,first_m,&T2);
            card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
            return;
        }
    }
    tow_character_inone(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
}


void card_movement_ms(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y) {
    char *choose_move = malloc(2 * sizeof(char));
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;
    struct characters *first_ch = character_ptr;
    struct out_tunnel *tunnel_new_node;
    struct out_tunnel *first_tunnel;
    int serachx,serachy;
    int xasli,yasli,T = 1,T2 = 0;
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode1->tunnel,"TO")) {
                int count = 1;
                printf("choose the tunnel you want to exit and type number :\n");

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && (tmpnode2->x != tmpnode1->x || tmpnode2->y != tmpnode1->y)) {
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

                if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
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
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                    return;
                }

                tunnel_out_ptr = first_tunnel;
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
            else{
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;

            if(serachy <= road_y - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y <= road_y - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) - 1;

            if(serachy >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y >= 0) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) + 1;
            serachy = tmpnode1->y;

            if(serachx <= road_x - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x <= road_x - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) - 1;
            serachy = tmpnode1->y;

            if(serachx >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x >= 0) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if((!strcmp(choose_move,"X")) && i != 0) {
            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }
            if(!strcmp(tmpnode1->road,"RD")) {
                T2 = 0;
                tmpnode1 = first_m;
                tow_character_inone_ms(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
                return;
            }
            else {
                tmpnode1 = first_m;
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else {
            if(T == 1) {
                T2 = 1;
            }
            else {
                T2 = 0;
            }
            come_back(xasli,yasli,character_ptr->name,first_m,&T2);
            card_movement_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y);
            return;
        }
    }
    tow_character_inone_ms(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
}


void card_movement_Inspector(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y,struct characters *first_character_ptr) {
    char *choose_move = malloc(2 * sizeof(char));
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;
    struct characters *first_ch = character_ptr;
    struct out_tunnel *tunnel_new_node;
    struct out_tunnel *first_tunnel;
    int serachx,serachy;
    int xasli,yasli,T = 1,T2 = 0;
    int tmp,TX = 1;

    printf("You can do 1 to %d moves (up = U , down = D , right = R , left = L , use unnel = T , stop = X).\n",character_ptr->move);
    printf("To arrest any character, go to the house of that character and after stopping, agree to the arrest request.\n");

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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode1->tunnel,"TO")) {
                int count = 1;
                printf("choose the tunnel you want to exit and type number :\n");

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && (tmpnode2->x != tmpnode1->x || tmpnode2->y != tmpnode1->y)) {
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
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                    return;
                }

                tunnel_out_ptr = first_tunnel;
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
            else{
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;

            if(serachy <= road_y - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y <= road_y - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) - 1;

            if(serachy >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) + 1;
            serachy = tmpnode1->y;

            if(serachx <= road_x - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x <= road_x - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) - 1;
            serachy = tmpnode1->y;

            if(serachx >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if((!strcmp(choose_move,"X")) && i != 0) {
            TX = 0;

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            if(!(!strcmp(tmpnode1->person1,"NN")) && !(!strcmp(tmpnode1->person2,"NN"))) {
                printf("Do you want to arrest the character in question ?\n");
                printf("1)Yes 2)No\n");
                scanf("%d",&tmp);

                if(tmp == 1) {
                    tmpnode2 = first_m;

                    char *person1;
                    char *person2;
                    char *jackmood1;
                    char *jackmood2;

                    while(tmpnode1 != NULL) {
                        if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                            break;
                        }
                        tmpnode1 = tmpnode1->next;
                    }

                    if(T == 1) {
                        xasli = tmpnode1->x;
                        yasli = tmpnode1->y;
                        T = 0;
                        T2 = 1;
                    }

                    person1 = tmpnode1->person1;
                    person2 = tmpnode1->person2;

                    if(!strcmp(person1,"NN") || !strcmp(person2,"NN")) {
                        come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                        card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                        return;
                    }
                    else {
                        T2 = 0;
                    }

                    character_ptr = first_character_ptr;

                    while(character_ptr != NULL) {
                        if(!strcmp(character_ptr->name,person1)) {
                            jackmood1 = character_ptr->jack;
                            break;
                        }
                        character_ptr = character_ptr->next;
                    }

                    character_ptr = first_character_ptr;

                    while(character_ptr != NULL) {
                        if(!strcmp(character_ptr->name,person2)) {
                            jackmood2 = character_ptr->jack;
                            break;
                        }
                        character_ptr = character_ptr->next;
                    }

                    if(!strcmp(jackmood1,"YES") || !strcmp(jackmood2,"YES")) {
                        printf("\ninspector wins.\n");
                        exit(0);
                    }
                    else {
                        printf("\njack wins.\n");
                        exit(0);
                    }

                    tmpnode1 = tmpnode2 = first_m;
                    character_ptr = first_ch;
                }

                else if(tmp == 2) {
                    tmpnode1 = tmpnode2 = first_m;
                    character_ptr = first_ch;
                }
            }


            tow_character_inone(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
            return;
        }
        else {
            if(T == 1) {
                T2 = 1;
            }
            else {
                T2 = 0;
            }
            come_back(xasli,yasli,character_ptr->name,first_m,&T2);
            card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
            return;
        }
    }

    if(TX == 1) {
        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                break;
            }
            tmpnode1 = tmpnode1->next;
        }

        if(!(!strcmp(tmpnode1->person1,"NN")) && !(!strcmp(tmpnode1->person2,"NN"))) {
            printf("Do you want to arrest the character in question ?\n");
            printf("1)Yes 2)No\n");
            scanf("%d",&tmp);

            if(tmp == 1) {
                tmpnode2 = first_m;

                char *person1;
                char *person2;
                char *jackmood1;
                char *jackmood2;

                while(tmpnode1 != NULL) {
                    if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                        break;
                    }
                    tmpnode1 = tmpnode1->next;
                }

                if(T == 1) {
                    xasli = tmpnode1->x;
                    yasli = tmpnode1->y;
                    T = 0;
                    T2 = 1;
                }

                person1 = tmpnode1->person1;
                person2 = tmpnode1->person2;

                if(!strcmp(person1,"NN") || !strcmp(person2,"NN")) {
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement_Inspector(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                    return;
                }
                else {
                    T2 = 0;
                }

                character_ptr = first_character_ptr;

                while(character_ptr != NULL) {
                    if(!strcmp(character_ptr->name,person1)) {
                        jackmood1 = character_ptr->jack;
                        break;
                    }
                    character_ptr = character_ptr->next;
                }

                character_ptr = first_character_ptr;

                while(character_ptr != NULL) {
                    if(!strcmp(character_ptr->name,person2)) {
                        jackmood2 = character_ptr->jack;
                        break;
                    }
                    character_ptr = character_ptr->next;
                }

                if(!strcmp(jackmood1,"YES") || !strcmp(jackmood2,"YES")) {
                    printf("\ninspector wins.\n");
                    exit(0);
                }
                else {
                    printf("\njack wins.\n");
                    exit(0);
                }

                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }

            else if(tmp == 2) {
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
        }
    }

    tow_character_inone_Inspector(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y,first_character_ptr);
}


void card_movement_Inspector_ms(struct characters *character_ptr,struct map *first_map_ptr,struct out_tunnel *tunnel_out_ptr,int road_x,int road_y,struct characters *first_character_ptr) {
    char *choose_move = malloc(2 * sizeof(char));
    struct map *first_m = first_map_ptr;
    struct map *tmpnode1 = first_map_ptr;
    struct map *tmpnode2 = first_map_ptr;
    struct characters *first_ch = character_ptr;
    struct out_tunnel *tunnel_new_node;
    struct out_tunnel *first_tunnel;
    int serachx,serachy;
    int xasli,yasli,T = 1,T2 = 0;
    int tmp,TX = 1;

    printf("You can do 1 to %d moves (up = U , down = D , right = R , left = L , use unnel = T , stop = X).\n",character_ptr->move);
    printf("To arrest any character, go to the house of that character and after stopping, agree to the arrest request.\n");

    for (int i = 0; i < (character_ptr->move); ++i) {
        printf("move %d :",i+1);
        scanf("%s",choose_move);

        for (int j = 0; j < 8; ++j) {
            printf("%s\n",first_character_ptr->name);
            first_character_ptr = first_character_ptr->next;
        }

        if(!strcmp(choose_move,"T")) {
            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
            }

            if(!strcmp(tmpnode1->tunnel,"TO")) {
                int count = 1;
                printf("choose the tunnel you want to exit and type number :\n");

                while(tmpnode2 != NULL) {
                    if(!strcmp(tmpnode2->tunnel,"TO") && (tmpnode2->x != tmpnode1->x || tmpnode2->y != tmpnode1->y)) {
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

                if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
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
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                    return;
                }

                tunnel_out_ptr = first_tunnel;
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
            else{
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;

            if(serachy <= road_y - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y <= road_y - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) - 1;

            if(serachy >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->y >= 0) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) + 1;
            serachy = tmpnode1->y;

            if(serachx <= road_x - 1) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x <= road_x - 1) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
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

            if(T == 1) {
                xasli = tmpnode1->x;
                yasli = tmpnode1->y;
                T = 0;
                T2 = 1;
            }

            serachx = (tmpnode1->x) - 1;
            serachy = tmpnode1->y;

            if(serachx >= 0) {
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }

            while(tmpnode2 != NULL) {
                if(tmpnode2->y == serachy && tmpnode2->x == serachx) {
                    break;
                }
                tmpnode2 = tmpnode2->next;
            }

            if((!strcmp(tmpnode2->road,"RD") || !strcmp(tmpnode2->home,"HM") || !(!strcmp(tmpnode2->light,"NN"))) && (tmpnode2->x != xasli || tmpnode2->y != yasli) && tmpnode2->x >= 0) {
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
                T2 = 0;
            }
            else {
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else if((!strcmp(choose_move,"X")) && i != 0) {
            TX = 0;
            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }
            if(!strcmp(tmpnode1->road,"RD")) {
                T2 = 0;
                tmpnode1 = first_m;

                while(tmpnode1 != NULL) {
                    if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                        break;
                    }
                    tmpnode1 = tmpnode1->next;
                }
                if(!(!strcmp(tmpnode1->person1,"NN")) && !(!strcmp(tmpnode1->person2,"NN"))) {
                    printf("Do you want to arrest the character in question ?\n");
                    printf("1)Yes 2)No\n");
                    scanf("%d",&tmp);

                    if(tmp == 1) {
                        tmpnode2 = first_m;

                        char *person1;
                        char *person2;
                        char *jackmood1;
                        char *jackmood2;

                        while(tmpnode1 != NULL) {
                            if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                                break;
                            }
                            tmpnode1 = tmpnode1->next;
                        }

                        if(T == 1) {
                            xasli = tmpnode1->x;
                            yasli = tmpnode1->y;
                            T = 0;
                            T2 = 1;
                        }

                        person1 = tmpnode1->person1;
                        person2 = tmpnode1->person2;

                        if(!strcmp(person1,"NN") || !strcmp(person2,"NN")) {
                            come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                            card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                            return;
                        }
                        else {
                            T2 = 0;
                        }

                        character_ptr = first_character_ptr;

                        while(character_ptr != NULL) {
                            if(!strcmp(character_ptr->name,person1)) {
                                jackmood1 = character_ptr->jack;
                                break;
                            }
                            character_ptr = character_ptr->next;
                        }

                        character_ptr = first_character_ptr;

                        while(character_ptr != NULL) {
                            if(!strcmp(character_ptr->name,person2)) {
                                jackmood2 = character_ptr->jack;
                                break;
                            }
                            character_ptr = character_ptr->next;
                        }

                        if(!strcmp(jackmood1,"YES") || !strcmp(jackmood2,"YES")) {
                            printf("\ninspector wins.\n");
                            exit(0);
                        }
                        else {
                            printf("\njack wins.\n");
                            exit(0);
                        }

                        tmpnode1 = tmpnode2 = first_m;
                        character_ptr = first_ch;
                    }

                    else if(tmp == 2) {
                        tmpnode1 = tmpnode2 = first_m;
                        character_ptr = first_ch;
                    }
                }

                tow_character_inone_ms(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y);
                return;
            }
            else {
                tmpnode1 = first_m;
                come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                return;
            }
            tmpnode1 = tmpnode2 = first_m;
            character_ptr = first_ch;
        }
        else {
            if(T == 1) {
                T2 = 1;
            }
            else {
                T2 = 0;
            }
            come_back(xasli,yasli,character_ptr->name,first_m,&T2);
            card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
            return;
        }
    }

    if(TX == 1) {
        while(tmpnode1 != NULL) {
            if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                break;
            }
            tmpnode1 = tmpnode1->next;
        }

        if(!(!strcmp(tmpnode1->person1,"NN")) && !(!strcmp(tmpnode1->person2,"NN"))) {
            printf("Do you want to arrest the character in question ?\n");
            printf("1)Yes 2)No\n");
            scanf("%d",&tmp);

            if(tmp == 1) {
                tmpnode2 = first_m;

                char *person1;
                char *person2;
                char *jackmood1;
                char *jackmood2;

                while(tmpnode1 != NULL) {
                    if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                        break;
                    }
                    tmpnode1 = tmpnode1->next;
                }

                if(T == 1) {
                    xasli = tmpnode1->x;
                    yasli = tmpnode1->y;
                    T = 0;
                    T2 = 1;
                }

                person1 = tmpnode1->person1;
                person2 = tmpnode1->person2;

                if(!strcmp(person1,"NN") || !strcmp(person2,"NN")) {
                    come_back(xasli,yasli,character_ptr->name,first_m,&T2);
                    card_movement_Inspector_ms(character_ptr,first_m,tunnel_out_ptr,road_x,road_y,first_character_ptr);
                    return;
                }
                else {
                    T2 = 0;
                }

                character_ptr = first_character_ptr;

                while(character_ptr != NULL) {
                    if(!strcmp(character_ptr->name,person1)) {
                        jackmood1 = character_ptr->jack;
                        break;
                    }
                    character_ptr = character_ptr->next;
                }

                character_ptr = first_character_ptr;

                while(character_ptr != NULL) {
                    if(!strcmp(character_ptr->name,person2)) {
                        jackmood2 = character_ptr->jack;
                        break;
                    }
                    character_ptr = character_ptr->next;
                }

                if(!strcmp(jackmood1,"YES") || !strcmp(jackmood2,"YES")) {
                    printf("\ninspector wins.\n");
                    exit(0);
                }
                else {
                    printf("\njack wins.\n");
                    exit(0);
                }

                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }

            else if(tmp == 2) {
                tmpnode1 = tmpnode2 = first_m;
                character_ptr = first_ch;
            }
        }
    }

    tow_character_inone_Inspector_ms(character_ptr,tmpnode1,tmpnode2,yasli,xasli,tunnel_out_ptr,&T2,road_x,road_y,first_character_ptr);
}
