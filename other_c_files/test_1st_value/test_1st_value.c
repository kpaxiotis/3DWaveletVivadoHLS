#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image_aux.h"
#include "print3D.h"
#include "image_read.h"


int main(){
    
    double dwttt1, dwttt2;
    double var = 0.5*1.4142;
    
    printf("\n\n\n");
    
    image_t *X = (image_t*)malloc(sizeof(image_t));

    imageRead(X);
    print3D(X);
    
    dwttt1 = ((X->data3D[0][0][0]*var + X->data3D[1][0][0]*var)*var + (X->data3D[0][1][0]*var + X->data3D[1][1][0]*var)*var)*var
    + ((X->data3D[0][0][1]*var + X->data3D[1][0][1]*var)*var + (X->data3D[0][1][1]*var + X->data3D[1][1][1]*var)*var)*var;
    dwttt2 = (((X->data3D[0][0][0]*var+X->data3D[1][0][0]*var)+(X->data3D[0][1][0]*var+X->data3D[1][1][0]*var))*var+((X->data3D[0][0][1]*var+X->data3D[1][0][1]*var)+(X->data3D[0][1][1]*var+X->data3D[1][1][1]*var))*var)*var;
    
    printf("dwttt1 = %f\n",dwttt1);
    printf("dwttt2 = %f\n", dwttt2);
    printf("var = %f\n", var);
    printf("sqrt = %f\n", sqrt(2));
    printf("X->data3D[0][0][0] = %f", X->data3D[0][0][0]);
    
}

