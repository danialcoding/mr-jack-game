
void play_rounds(int *ptr_card_array,int rounds,struct characters *character_ptr,struct map *fmap) {
    int tmp,n;

    if(rounds % 2 == 1) {
        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp - 1;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

    }
    else {
        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("Inspector turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);

        printf("jack turn.\n");
        printf("choose a card and type card number :\n");
        scanf("%d",&tmp);

        n = tmp + 3;
        n = *(ptr_card_array + n);
        choose_move_abl(character_ptr,n,fmap);
    }
}