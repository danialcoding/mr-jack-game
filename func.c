
struct map* map_append(struct map** head) {

    struct map *new_node = (struct map*) malloc(sizeof(struct map));

    struct map *last = *head;

    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return new_node;
}

int random_num_1_8() {
    int tmp;
    srand(time(0));
    tmp = rand() % 9;
    if(tmp == 0) {
        tmp = tmp + 1;
    }
    return tmp;
}

void rand_select_jack(struct characters *character_ptr) {
    int tmp;
    tmp = random_num_1_8();
    for (int i = 0; i < 8; ++i) {
        if(character_ptr->number == tmp) {
            printf("jack is : %s\n\n",character_ptr->name);
            character_ptr->jack = "YES";
            return;
        }
        character_ptr = character_ptr->next;
    }
}

int * rand_cards(int rounds) {
    int tmp,r;
    static int card_array[8];
    if(rounds % 2 == 1) {
        srand(time(0));
        for (int i = 0; i < 8; ++i) {
            card_array[i] = i + 1;
        }
        for(int i = 7;i > 0; i--){
            r = rand() % i;
            tmp = card_array[i];
            card_array[i] = card_array[r];
            card_array[r] = tmp;
        }

        return card_array;
    }
}

void win_func() {
    /// next every move should run it
}