

void card_movement(struct characters *character_ptr,struct map *fmap) {
    char choose_move;
    struct map *first_m = fmap,*tmpnode1 = fmap,*tmpnode2 = fmap;
    struct characters *first_ch = character_ptr;
    int serachx,serachy;
    int xasli,yasli,T = 1;

    printf("You can choose up to %d moves (up = U , down = D , right = R , left = L , stop = X).\n",character_ptr->move);

    for (int i = 0; i < character_ptr->move; ++i) {
        printf("move %d :\n",i+1);
        scanf("%c",&choose_move);

        if(choose_move == 'U') {

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
                    break;
                }
                tmpnode1 = tmpnode1->next;
            }

            /// ch
            serachx = tmpnode1->x;
            serachy = (tmpnode1->y) + 1;
            /// ch
            while(tmpnode2 != NULL) {
                /// ch
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

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                if(!strcmp(fmap->person1,character_ptr->name)) {
                    fmap->person1 = "NN";
                }
                else if(!strcmp(fmap->person2,character_ptr->name)) {
                    fmap->person2 = "NN";
                }

                if(!(!strcmp(fmap->person1,"NN"))) {
                    fmap->person1 = character_ptr->name;
                }
                else if(!(!strcmp(fmap->person2,"NN"))) {
                    fmap->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,fmap);
                return;
            }
            tmpnode1 = tmpnode2 = fmap;
            character_ptr = first_ch;
        }
        else if(choose_move == 'D') {

            while(tmpnode1 != NULL) {
                if(!strcmp(tmpnode1->person1,character_ptr->name) || !strcmp(tmpnode1->person2,character_ptr->name)) {
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

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                if(!strcmp(fmap->person1,character_ptr->name)) {
                    fmap->person1 = "NN";
                }
                else if(!strcmp(fmap->person2,character_ptr->name)) {
                    fmap->person2 = "NN";
                }

                if(!(!strcmp(fmap->person1,"NN"))) {
                    fmap->person1 = character_ptr->name;
                }
                else if(!(!strcmp(fmap->person2,"NN"))) {
                    fmap->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,fmap);
                return;
            }
            tmpnode1 = tmpnode2 = fmap;
            character_ptr = first_ch;
        }
        else if(choose_move == 'R') {

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

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                if(!strcmp(fmap->person1,character_ptr->name)) {
                    fmap->person1 = "NN";
                }
                else if(!strcmp(fmap->person2,character_ptr->name)) {
                    fmap->person2 = "NN";
                }

                if(!(!strcmp(fmap->person1,"NN"))) {
                    fmap->person1 = character_ptr->name;
                }
                else if(!(!strcmp(fmap->person2,"NN"))) {
                    fmap->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,fmap);
                return;
            }
            tmpnode1 = tmpnode2 = fmap;
            character_ptr = first_ch;
        }
        else if(choose_move == 'L') {

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

            if(!strcmp(tmpnode2->road,"RD") && (tmpnode2->x != xasli || tmpnode2->y != yasli)) {
                if(!strcmp(fmap->person1,character_ptr->name)) {
                    fmap->person1 = "NN";
                }
                else if(!strcmp(fmap->person2,character_ptr->name)) {
                    fmap->person2 = "NN";
                }

                if(!(!strcmp(fmap->person1,"NN"))) {
                    fmap->person1 = character_ptr->name;
                }
                else if(!(!strcmp(fmap->person2,"NN"))) {
                    fmap->person2 = character_ptr->name;
                }
            }
            else {
                card_movement(character_ptr,fmap);
                return;
            }
            tmpnode1 = tmpnode2 = fmap;
            character_ptr = first_ch;
        }
        else if(choose_move == 'X' && i != 0) {
            return;
        }
        else {
            card_movement(character_ptr,fmap);
        }
    }
}