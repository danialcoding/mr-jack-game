
int rand_num_SH(int jack_num) {
    int tmp;
    srand(time(0));
    tmp = rand() % 9;
    if(tmp == 0) {
        tmp = tmp + 1;
    }

    if(tmp == jack_num) {
        return rand_num_SH(jack_num);
    }

    return tmp;
}

void card_ability(struct characters *character_ptr,struct characters *character_ptr_head) {
    struct characters *jack_ptr = character_ptr_head;
    struct characters *tmp_character_ptr = character_ptr_head;
    int number;

    if(!strcmp(character_ptr->name,"SH")) {
        while(jack_ptr != NULL) {
            if(!strcmp(jack_ptr->jack,"YES")) {
                break;
            }
            jack_ptr = jack_ptr->next;
        }

        number = rand_num_SH(jack_ptr->number);

        while(tmp_character_ptr != NULL) {
            if(tmp_character_ptr->number == number) {
                break;
            }
            tmp_character_ptr = tmp_character_ptr->next;
        }
        printf("%s character is not jack.\n",tmp_character_ptr->name);
    }
    else if() {
        
    }
}