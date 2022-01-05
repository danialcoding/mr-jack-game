

void read_map(struct map *fmap,int road_x,int road_y) {
    FILE *fptr;
    int tmp;
    struct map * tmp_node;
    fptr = fopen("D://project/map.txt","r");
    FILE *fc = fptr;
    if(fptr == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    for (int i = road_y; i > 0; --i) {
        for (int j = 0; j < road_x; ++j) {
            tmp_node = append(&fmap,i,j);
            fscanf(fptr,"%d",&tmp);

            if(tmp == 0) {
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 1) {
                tmp_node->road = "N";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "H";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 2){
                tmp_node->road = "N";
                tmp_node->light = "O";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 3){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "T";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 4){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "E";
            }
            else if(tmp == 5){
                tmp_node->road = "N";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 22){
                tmp_node->road = "N";
                tmp_node->light = "L";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 33){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "C";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "N";
            }
            else if(tmp == 44){
                tmp_node->road = "N";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "N";
                tmp_node->exit = "X";
            }
            else if(tmp == 11){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "SG";
                tmp_node->exit = "N";
            }
            else if(tmp == 12){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "SH";
                tmp_node->exit = "N";
            }
            else if(tmp == 13){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "JW";
                tmp_node->exit = "N";
            }
            else if(tmp == 14){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "MS";
                tmp_node->exit = "N";
            }
            else if(tmp == 15){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "JS";
                tmp_node->exit = "N";
            }
            else if(tmp == 16){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "JB";
                tmp_node->exit = "N";
            }
            else if(tmp == 17){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "WG";
                tmp_node->exit = "N";
            }
            else if(tmp == 18){
                tmp_node->road = "R";
                tmp_node->light = "N";
                tmp_node->tunnel = "N";
                tmp_node->home = "N";
                tmp_node->person = "IL";
                tmp_node->exit = "N";
            }
        }
    }
    fclose(fc);
    tmp_node = fmap;

    for (int i = road_y; i > 0; --i) {
        for (int j = 0; j < road_x; ++j) {
            /*for (int k = 0; k < all_map; ++k) {
                while()
            }*/
            if(strcmp(tmp_node->person,"IL") == 1) {
                printf("IL ");
            }
            else if(strcmp(tmp_node->person,"WG") == 1) {
                printf("WG ");
            }
            else if(strcmp(tmp_node->person,"JB") == 1) {
                printf("JB ");
            }
            else if(strcmp(tmp_node->person,"JS") == 1) {
                printf("JS ");
            }
            else if(strcmp(tmp_node->person,"MS") == 1) {
                printf("MS ");
            }
            else if(strcmp(tmp_node->person,"JW") == 1) {
                printf("JW ");
            }
            else if(strcmp(tmp_node->person,"SH") == 1) {
                printf("SH ");
            }
            else if(strcmp(tmp_node->person,"SG") == 1) {
                printf("SG ");
            }
            else if(strcmp(tmp_node->home,"H") == 1) {
                printf("H ");
            }
            else if(strcmp(tmp_node->exit,"X") == 1) {
                printf("X");
            }
            else if(strcmp(tmp_node->exit,"E") == 1) {
                printf("E ");
            }
            else if(strcmp(tmp_node->light,"L") == 1) {
                printf("L ");
            }
            else if(strcmp(tmp_node->light,"O") == 1) {
                printf("O ");
            }
            else if(strcmp(tmp_node->tunnel,"C") == 1) {
                printf("C ");
            }
            else if(strcmp(tmp_node->tunnel,"T") == 1) {
                printf("T ");
            }
            else if(strcmp(tmp_node->road,"R") == 1) {
                printf("R ");
            }
            else {
                printf("N");
            }
            tmp_node = tmp_node->next;
        }
        printf("\n");
    }
}