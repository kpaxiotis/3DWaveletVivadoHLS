#ifndef PRINT3D
#define PRINT3D



void printToFile(float *out, char *dir_out) {

	int i, j, k, l;
    float tmp;
    
    FILE *fp;
    
    l = 3;
    
    fp = fopen(dir_out, "w");
    for(i = 0; i < out[0]; i++){
        for(j = 0; j < out[1]; j++){
            for(k = 0; k < out[2]; k++){

                tmp = out[l]; 
                fprintf(fp, "%f\n", tmp);
                l++;
                
            }     
        }
    }  
    fclose(fp);

}



void print3D(image_t *in){

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
    
}

#endif
