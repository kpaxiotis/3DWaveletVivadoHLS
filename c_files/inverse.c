#include "image_aux.h"



void dwt1D(array_t *data){

    float temp[MAX_SIZE]; // The size should be data_size but it's not synthesizable
    int h = data->size / 2; //data_size >> 1;
    int i = 0;
    
    CALC_LOOP:
    for ( i = h - 1 ; i >= 0; i--){
    #pragma HLS loop_tripcount min=2 max=12
        
        int k = i*2; //data_size << 1;
        temp[i] = data->data1D[k]*0.5*1.41421356 + data->data1D[k + 1]*0.5*1.41421356;
        temp[i + h] = data->data1D[k]*0.5*1.41421356 - data->data1D[k + 1]*0.5*1.41421356;
        
    }
    
    SEND_LOOP://Can be merged with the loop abolve
    for ( i = data->size - 1; i >= 0; i--)
    #pragma HLS loop_tripcount min=4 max=24
        data->data1D[i] = temp[i];

}


void dwt3D(float in[13.824]){
#pragma HLS INTERFACE bram port = in

    
    int iterations = 2;
    
//Internal image buffers
#ifndef __SYNTHESIS__
    image_t *temp = (image_t *)malloc(sizeof(image_t));
    array_t *x = (array_t *)malloc(sizeof(array_t));
    array_t *y = (array_t *)malloc(sizeof(array_t));
    array_t *z = (array_t *)malloc(sizeof(array_t));
#else
	image_t _temp;
	image_t *temp = &_temp;
    array_t _x, _y, _z;
    array_t *x = &_x;
    array_t *y = &_y;
    array_t *z = &_z;
#endif


    int i, j, k, n, l;
    

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



        x->size = temp->x_size / sub;
        y->size = temp->y_size / sub;
		z->size = temp->z_size / sub;

        
        X_J_LOOP:
        for ( j = y->size - 1; j >= 0; j--){
        #pragma HLS loop_tripcount min=4 max=24
            X_K_LOOP:
            for ( k = z->size - 1; k >= 0; k--){
            #pragma HLS loop_tripcount min=4 max=24
                X_I_LOOP:
                for ( i = x->size - 1; i >= 0; i--)
                #pragma HLS loop_tripcount min=4 max=24
                                       
                    x->data1D[i] = temp->data3D[i][j][k];
                    
                dwt1D(x);
                
                RES_X_LOOP:
                for ( i = x->size - 1; i >= 0; i--)
                #pragma HLS loop_tripcount min=4 max=24
                    temp->data3D[i][j][k] = x->data1D[i];
                
            }    
        }
        
        Y_K_LOOP:
        for ( k = z->size - 1; k >= 0; k--){
        #pragma HLS loop_tripcount min=4 max=24
            Y_I_LOOP:
            for ( i = x->size - 1; i >= 0; i--){
            #pragma HLS loop_tripcount min=4 max=24
                Y_J_LOOP:
                dwt3D_label1:for ( j = y->size - 1; j >= 0; j--)
                #pragma HLS loop_tripcount min=4 max=24
            
                    y->data1D[j] = temp->data3D[i][j][k];

                dwt1D(y);
                
                RES_Y_LOOP:
                for ( j = y->size - 1; j >= 0; j--)
                #pragma HLS loop_tripcount min=4 max=24
                    temp->data3D[i][j][k] = y->data1D[j];
                
            }    
        }
        
        
        Z_I_LOOP:
        for( i = x->size - 1; i >= 0; i--){    
        #pragma HLS loop_tripcount min=4 max=24
            Z_J_LOOP:
            for(j = y->size - 1; j >= 0; j--){
            #pragma HLS loop_tripcount min=4 max=24
                Z_K_LOOP:
                dwt3D_label0:for(k = z->size - 1; k >= 0; k--)
                #pragma HLS loop_tripcount min=4 max=24                    
                    
                	z->data1D[k] = temp->data3D[i][j][k];
                        
                    dwt1D(z);
                    
                    RES_Z_LOOP:
                    for ( k = z->size - 1; k >= 0; k--)
                    #pragma HLS loop_tripcount min=4 max=24
                        temp->data3D[i][j][k] = z->data1D[k];
                    
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

