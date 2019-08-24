
void imageRead (
      image_t *in_image
      ) {
   int x_size, y_size, z_size;
   int i, j, k;
   FILE        *fp;

   fp=fopen("in_image_test.dat","r");
   int tmp;
   float tmp2;
   fscanf(fp, "%d", &tmp);
   x_size = tmp;
   fscanf(fp, "%d", &tmp);
   y_size = tmp;
   fscanf(fp, "%d", &tmp);
   z_size = tmp;


   in_image->x_size = x_size;
   in_image->y_size = y_size;
   in_image->z_size = z_size;

   for (i = 0; i < x_size; i++) {
      for (j = 0; j < y_size; j++) {
    	  for (k = 0; k < z_size; k++){
			 fscanf(fp, "%f", &tmp2);
			 in_image->data3D[i][j][k] = tmp2;
    	  }
      }
   }
   fclose(fp);
}
