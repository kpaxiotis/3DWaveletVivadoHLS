#include "image_aux.h"



// void dwt1D(array_t *data){

    // float temp[MAX_SIZE]; // The size should be data_size but it's not synthesizable
    // int h = data->size / 2; //data_size >> 1;
    // int i = 0;
    
    // CALC_LOOP:
    // for ( i = h - 1 ; i >= 0; i--){
    // #pragma HLS loop_tripcount min=2 max=125
        
        // int k = i*2; //data_size << 1;
        // temp[i] = data->data1D[k]*0.5*1.41421356 + data->data1D[k + 1]*0.5*1.41421356;
        // temp[i + h] = data->data1D[k]*0.5*1.41421356 - data->data1D[k + 1]*0.5*1.41421356;
        
    // }
    
    // SEND_LOOP://Can be merged with the loop abolve
    // for ( i = data->size - 1; i >= 0; i--)
    // #pragma HLS loop_tripcount min=50 max=200
        // data->data1D[i] = temp[i];

// }


void dwt3D(float in[13824]){
#pragma HLS INTERFACE bram port = in

    int iterations = 2;
   
//Internal image buffers
#ifndef __SYNTHESIS__
    image_t *temp1 = (image_t *)malloc(sizeof(image_t));
    image_t *temp2 = (image_t *)malloc(sizeof(image_t));
    // array_t *x = (array_t *)malloc(sizeof(array_t));
    // array_t *y = (array_t *)malloc(sizeof(array_t));
    // array_t *z = (array_t *)malloc(sizeof(array_t));
#else
	image_t _temp1;
	image_t *temp1 = &_temp1;
    image_t _temp2;
	image_t *temp2 = &_temp2;
    // array_t _x, _y, _z;
    // array_t *x = &_x;
    // array_t *y = &_y;
    // array_t *z = &_z;
#endif


    int i, j, k, n, l, h, m, x_size, y_size, z_size;
    //float tmp[MAX_SIZE];

    temp1->x_size = in[0];
    temp1->y_size = in[1];
    temp1->z_size = in[2];

    
    l = 3;
    
    IN_I_LOOP:
    for( i = 0; i < temp1->x_size; i++){    
        IN_J_LOOP:
        for(j = 0; j < temp1->y_size; j++){
            IN_K_LOOP:
            for(k = 0; k < temp1->z_size; k++){
                
                temp1->data3D[i][j][k] = in[l];
                l++;
                    
            }
        }
    }


        
        
        
    DWT_LEVEL_LOOP:
    for(n = 0; n < iterations; n++){
        #pragma HLS loop_tripcount min=1 max=2   
        
        int sub = 1 << n;



        x_size = temp1->x_size / sub ;
        y_size = temp1->y_size / sub ;
		z_size = temp1->z_size / sub ;

        X_J_LOOP:
        for ( j = x_size - 1; j >= 0; j--){
            X_K_LOOP:
            for ( k = x_size - 1; k >= 0; k--){
                X_I_LOOP:
                for ( i = x_size - 1 ; i >= 0; i --){
                    
                    m = i*2; //data_size << 1;
                    if (i < x_size/2){
                    temp2->data3D[i][j][k] = temp1->data3D[m][j][k]*0.5*1.41421356 + temp1->data3D[m+1][j][k]*0.5*1.41421356;
                    temp2->data3D[i+x_size/2][j][k] = temp1->data3D[m][j][k]*0.5*1.41421356 - temp1->data3D[m+1][j][k]*0.5*1.41421356;
                    }
                }
            }
        }

        Y_K_LOOP:
        for ( k = x_size - 1; k >= 0; k--){
            Y_I_LOOP:
            for ( i = x_size - 1; i >= 0; i--){
                Y_J_LOOP:
                for ( j = x_size - 1 ; j >= 0; j --){
                
                    m = j*2; //data_size << 1;
                    if (j < x_size/2){
                    temp1->data3D[i][j][k] = temp2->data3D[i][m][k]*0.5*1.41421356 + temp2->data3D[i][m+1][k]*0.5*1.41421356;
                    temp1->data3D[i][j+y_size/2][k] = temp2->data3D[i][m][k]*0.5*1.41421356 - temp2->data3D[i][m+1][k]*0.5*1.41421356;
                    }
                }             
            }    
        }
        

        Z_I_LOOP:
        for( i = x_size - 1; i >= 0; i--){    
            Z_J_LOOP:
            for(j = x_size - 1; j >= 0; j--){
                Z_K_LOOP:
                for(k = x_size - 1 ; k >= 0; k--){
               
                    m = k*2; //data_size << 1;
                    if (k < x_size/2){
                    temp2->data3D[i][j][k] = temp1->data3D[i][j][m]*0.5*1.41421356 + temp1->data3D[i][j][m+1]*0.5*1.41421356;
                    temp2->data3D[i][j][k+z_size/2] = temp1->data3D[i][j][m]*0.5*1.41421356 - temp1->data3D[i][j][m+1]*0.5*1.41421356;
                    }
                }
            }    
        }


        COPY_X:
        for(i = x_size - 1; i >= 0; i--){
            COPY_Y:
            for(j = x_size - 1; j >= 0; j--){
                COPY_Z:
                for(k = x_size -1; k >= 0; k--){
                    
                    temp1->data3D[i][j][k] = temp2->data3D[i][j][k];
                    
                }
            }
        }
    }

    l = 3;
    
    OUT_I_LOOP:
    for( i = 0; i < temp1->x_size; i++){    
        OUT_J_LOOP:
        for(j = 0; j < temp1->y_size; j++){
            OUT_K_LOOP:
            for(k = 0; k < temp1->z_size; k++){
                
                in[l] = temp1->data3D[i][j][k];
                l++;
            
            }
        }
    }
}

