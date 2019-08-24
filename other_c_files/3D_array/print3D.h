#ifndef PRINT3D
#define PRINT3D



void printToFile(float data3D[X_SIZE][Y_SIZE][Z_SIZE], int *x_size, int *y_size, int *z_size, char *dir_out) {

	int i, j, k;
    float tmp;
    
    FILE *fp;
    
    fp = fopen(dir_out, "w");
    for(i = 0; i < x_size; i++){
        for(j = 0; j < y_size; j++){
            for(k = 0; k < z_size; k++){

                tmp = data3D[i][j][k]; 
                fprintf(fp, "%f\n", tmp);
                
            }     
        }
    }  
    fclose(fp);

}



/*void print3D(image_t *in){

	int i, j, k;

    for(i = 0; i < in->x_size; i++){
        for(j = 0; j < in->y_size; j++){
            for(k = 0; k < in->z_size; k++){
             
                
                printf("%.2f\t",in->data3D[i][j][k]);
                
             }
            printf("\n");
        }     
        printf("\n");
    }
    
    
    printf("\n\n\n");
}



void printMatlabFormat(image_t *in) {
    
	int i, j, k;
    FILE *fp;
    
    fp = fopen("outArrayForMatlab.txt", "w");
    
    fprintf(fp, "X = [");
    
    for(i = 0; i < in->x_size; i++){
            for(j = 0; j < in->y_size; j++){
                for(k = 0; k < in->z_size; k++){
                
                fprintf(fp, "%.2f ", in->data3D[i][j][k]);
                
             }
            if (j < in->y_size- 1){
                
                fprintf(fp, ";");
            }
        }    
        
        if (i < in->x_size- 1){
            fprintf(fp, "]\n X(:,:,%d) = [", i+2);
        }

        
    }
    fprintf(fp, "]");
    
    fclose(fp);
    
}*/

#endif
