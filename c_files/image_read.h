
void imageRead (
      float *in, char *dir_in
      ) {
    int x_size, y_size, z_size;
    int i, j, k, l;
    
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


    in[0] = x_size;
    in[1] = y_size;
    in[2] = z_size;
    
    l = 3;
    for (i = 0; i < x_size; i++) {
      for (j = 0; j < y_size; j++) {
          for (k = 0; k < z_size; k++){
              
             fscanf(fp, "%f", &tmp2);
             in[l] = tmp2;
             l++;
             
          }
      }
    }
    fclose(fp);

}
