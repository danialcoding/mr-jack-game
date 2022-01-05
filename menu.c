
void start_menu(struct map *fmap,int road_x,int road_y) {
    int tmp;
    printf("1)Start \n2)Load\n3)Exit");
    scanf("%d",&tmp);
    if(tmp == 1) {
        read_map(fmap,road_x,road_y);
    }
    else if(tmp == 2) {
        ///problem
    }
    else if(tmp == 3) {
        exit(0);
    }
    else {
        start_menu(fmap,road_x,road_y);
    }
}