
void print_map(struct map * tmp_node,int road_x,int road_y);

void read_map(struct map *fmap,int road_x,int road_y) {
    FILE *fptr;
    int tmp;
    struct map * tmp_node;
    fptr = fopen("/./c-code/project/map.txt","r");
    FILE *fc = fptr;
    if(fptr == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    for (int i = road_y; i > 0; --i) {
        for (int j = 0; j < road_x; ++j) {
            tmp_node = map_append(&fmap);
            fscanf(fptr,"%d",&tmp);

            if(tmp == 0) {
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 1) {
                tmp_node->road = "NN";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "HM";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 2){
                tmp_node->road = "NN";
                tmp_node->light = "LF";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 3){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "TO";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 4){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "EO";
            }
            else if(tmp == 5){
                tmp_node->road = "NN";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 22){
                tmp_node->road = "NN";
                tmp_node->light = "LN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 33){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "TC";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 44){
                tmp_node->road = "NN";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "NN";
                tmp_node->person2 = "NN";
                tmp_node->exit = "EC";
            }
            else if(tmp == 11){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "SG";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 12){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "SH";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 13){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "JW";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 14){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "MS";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 15){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "JS";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 16){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "JB";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 17){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "WG";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            else if(tmp == 18){
                tmp_node->road = "RD";
                tmp_node->light = "NN";
                tmp_node->tunnel = "NN";
                tmp_node->home = "NN";
                tmp_node->person1 = "IL";
                tmp_node->person2 = "NN";
                tmp_node->exit = "NN";
            }
            tmp_node->x = i;
            tmp_node->y = j;
        }
    }
    fclose(fc);
    tmp_node = fmap;

    print_map(tmp_node,road_x,road_y);
}

void print_map(struct map * tmp_node,int road_x,int road_y) {
    for (int i = road_y; i > 0; --i) {
        for (int j = 0; j < road_x; ++j) {
            if(!(!strcmp(tmp_node->person1,"NN")) && !(!strcmp(tmp_node->person2,"NN"))) {
                printf("%s,%s ",tmp_node->person1,tmp_node->person2);
            }
            else if(!(!strcmp(tmp_node->person1,"NN"))) {
                printf("%s ",tmp_node->person1);
            }
            else if(!(!strcmp(tmp_node->person2,"NN"))) {
                printf("%s ",tmp_node->person2);
            }

            /*else if(!strcmp(tmp_node->person1,"IL")) {
                printf("IL ");
            }
            else if(!strcmp(tmp_node->person1,"WG")) {
                printf("WG ");
            }
            else if(!strcmp(tmp_node->person1,"JB")) {
                printf("JB ");
            }
            else if(!strcmp(tmp_node->person1,"JS")) {
                printf("JS ");
            }
            else if(!strcmp(tmp_node->person1,"MS")) {
                printf("MS ");
            }
            else if(!strcmp(tmp_node->person1,"JW")) {
                printf("JW ");
            }
            else if(!strcmp(tmp_node->person1,"SH")) {
                printf("SH ");
            }
            else if(!strcmp(tmp_node->person1,"SG")) {
                printf("SG ");
            }*/

            else if(!strcmp(tmp_node->home,"HM")) {
                printf("HM ");
            }
            else if(!strcmp(tmp_node->exit,"EC")) {
                printf("XX ");
            }
            else if(!strcmp(tmp_node->exit,"EO")) {
                printf("ET ");
            }
            else if(!strcmp(tmp_node->light,"LN")) {
                printf("LN ");
            }
            else if(!strcmp(tmp_node->light,"LF")) {
                printf("LO ");
            }
            else if(!strcmp(tmp_node->tunnel,"TC")) {
                printf("CT ");
            }
            else if(!strcmp(tmp_node->tunnel,"TO")) {
                printf("OT ");
            }
            else if(!strcmp(tmp_node->road,"RD")) {
                printf("RD ");
            }
            else {
                printf("NN ");
            }
            tmp_node = tmp_node->next;
        }
        printf("\n");
    }
}