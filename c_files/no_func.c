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
    image_t *temp = (image_t *)malloc(sizeof(image_t));
    // array_t *x = (array_t *)malloc(sizeof(array_t));
    // array_t *y = (array_t *)malloc(sizeof(array_t));
    // array_t *z = (array_t *)malloc(sizeof(array_t));
#else
	image_t _temp;
	image_t *temp = &_temp;
    // array_t _x, _y, _z;
    // array_t *x = &_x;
    // array_t *y = &_y;
    // array_t *z = &_z;
#endif


    int i, j, k, n, l, h, m, x_size, y_size, z_size;
    float tmp[MAX_SIZE];

    temp->x_size = in[0];
    temp->y_size = in[1];
    temp->z_size = in[2];

    
    
    l = 3;
    
    IN_I_LOOP:
    for( i = 0; i < temp->x_size; i++){    
        #pragma HLS loop_tripcount min=4 max=24
        IN_J_LOOP:
        for(j = 0; j < temp->y_size; j++){
        #pragma HLS loop_tripcount min=4 max=24
            IN_K_LOOP:
            for(k = 0; k < temp->z_size; k++){
            #pragma HLS loop_tripcount min=4 max=24
                
                temp->data3D[i][j][k] = in[l];
                l++;
                    
            }
        }
    }

    DWT_LEVEL_LOOP:
    for(n = 0; n < iterations; n++){
        #pragma HLS loop_tripcount min=1 max=2
        
        int sub = 1 << n;



        x_size = temp->x_size / sub;
        y_size = temp->y_size / sub;
		z_size = temp->z_size / sub;

        h = x_size / 2;
        X_J_LOOP:
        for ( j = y_size - 1; j >= 0; j--){
        #pragma HLS loop_tripcount min=4 max=24
            X_K_LOOP:
            for ( k = z_size - 1; k >= 0; k--){
            #pragma HLS loop_tripcount min=4 max=24
                X_I_LOOP:
                for ( i = h - 1 ; i >= 0; i--){
                #pragma HLS loop_tripcount min=4 max=24
                    //printf("in = %f\n%f\n%f\n%f\n", temp->data3D[0][j][k], temp->data3D[1][j][k], temp->data3D[2][j][k], temp->data3D[3][j][k]);
                    m = i*2; //data_size << 1;
                    tmp[i] = temp->data3D[m][j][k]*0.5*1.41421356 + temp->data3D[m+1][j][k]*0.5*1.41421356;
                    tmp[i+h] = temp->data3D[m][j][k]*0.5*1.41421356 - temp->data3D[m+1][j][k]*0.5*1.41421356;
                    
                    //printf("out = %f\n%f\n%f\n%f\n", temp->data3D[0][j][k], temp->data3D[1][j][k], temp->data3D[2][j][k], temp->data3D[3][j][k]);
                }
                I_I_LOOP:
                for ( i = x_size - 1; i >= 0; i--){
                #pragma HLS loop_tripcount min=4 max=24
                    temp->data3D[i][j][k] = tmp[i];
                }
            }
        }
        //printf("no_func = %f\n", temp->data3D[0][0][0]);

        
        h = y_size / 2;
        Y_K_LOOP:
        for ( k = z_size - 1; k >= 0; k--){
        #pragma HLS loop_tripcount min=4 max=24
            Y_I_LOOP:
            for ( i = x_size - 1; i >= 0; i--){
            #pragma HLS loop_tripcount min=4 max=24
                Y_J_LOOP:
                for ( j = h - 1 ; j >= 0; j--){
                #pragma HLS loop_tripcount min=4 max=24
                
                    m = j*2; //data_size << 1;
                    tmp[j] = temp->data3D[i][m][k]*0.5*1.41421356 + temp->data3D[i][m+1][k]*0.5*1.41421356;
                    tmp[j+h] = temp->data3D[i][m][k]*0.5*1.41421356 - temp->data3D[i][m+1][k]*0.5*1.41421356;
                    
                }
                J_J_LOOP:
                for ( j = y_size - 1; j >= 0; j--){
                #pragma HLS loop_tripcount min=4 max=24
                    temp->data3D[i][j][k] = tmp[j];
                }                
            }    
        }
        
        
        h = z_size / 2;
        Z_I_LOOP:
        for( i = x_size - 1; i >= 0; i--){    
        #pragma HLS loop_tripcount min=4 max=24
            Z_J_LOOP:
            for(j = y_size - 1; j >= 0; j--){
            #pragma HLS loop_tripcount min=4 max=24
                Z_K_LOOP:
                for(k = h - 1 ; k >= 0; k--){
                #pragma HLS loop_tripcount min=4 max=24
                                       
                   m = k*2; //data_size << 1;
                    tmp[k] = temp->data3D[i][j][m]*0.5*1.41421356 + temp->data3D[i][j][m+1]*0.5*1.41421356;
                    tmp[k+h] = temp->data3D[i][j][m]*0.5*1.41421356 - temp->data3D[i][j][m+1]*0.5*1.41421356;
                    
                }
                K_K_LOOP:
                for ( k = z_size - 1; k >= 0; k--){
                #pragma HLS loop_tripcount min=4 max=24
                    temp->data3D[i][j][k] = tmp[k];
                }
            }    
        }    
    }
    
    l = 3;
    
    OUT_I_LOOP:
    for( i = 0; i < temp->x_size; i++){    
    #pragma HLS loop_tripcount min=4 max=24
        OUT_J_LOOP:
        for(j = 0; j < temp->y_size; j++){
        #pragma HLS loop_tripcount min=4 max=24
            OUT_K_LOOP:
            for(k = 0; k < temp->z_size; k++){
            #pragma HLS loop_tripcount min=4 max=24
                
                in[l] = temp->data3D[i][j][k];
                l++;
            
            }
        }
    }
}