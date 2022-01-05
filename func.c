


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
