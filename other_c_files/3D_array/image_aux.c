#include <stdio.h>
#include "image_aux.h"


void image_read (
      image_t *in_image
      ) {
   int x_size, y_size, z_size;
   int i, j, k;
   FILE        *fp;

   fp=fopen("in_image.dat","r");
   int tmp;
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
			 fscanf(fp, "%d", &tmp);
			 in_image->data3D[i][j][k] = tmp;
    	  }
      }
   }
   fclose(fp);
}
