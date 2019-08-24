
void imageRead (
      float data3D[X_SIZE][Y_SIZE][Z_SIZE], int x_size, 
      int y_size, int z_size, char *dir_in
      ) {
    int i, j, k;
    
    FILE        *fp;
    
    fp=fopen(dir_in,"r");
    int tmp;
    float tmp2;
    fscanf(fp, "%d", &tmp);
    x_size = tmp;
    fscanf(fp, "%d", &tmp);
    y_size = tmp;
    fscanf(fp, "%d", &tmp);
    z_size = tmp;

    printf("%d\n", x_size);

    for (i = 0; i < x_size; i++) {
      for (j = 0; j < y_size; j++) {
          for (k = 0; k < z_size; k++){
             fscanf(fp, "%f", &tmp2);
             data3D[i][j][k] = tmp2;
          }
      }
    }
    fclose(fp);

}
