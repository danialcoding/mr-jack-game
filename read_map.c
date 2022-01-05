

void read_map(struct map *fmap,int road_x,int road_y) {
    FILE *fptr;
    int tmp;
    struct map * tmp_node;
    fptr = fopen("/c-code/project/map.txt","r");
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

    for (int i = 0; i < road_y; --i) {
        for (int j = 0; j < road_x; ++j) {
            printf("%s ",tmp_node->road);
        }
    }



}