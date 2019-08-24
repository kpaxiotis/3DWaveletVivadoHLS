#include "image_aux.h"



void dwt1D(array_t *data){

    float temp[MAX_SIZE]; // The size should be data_size but it's not synthesizable
    int h = data->size / 2; //data_size >> 1;
    int i = 0;
    
    CALC_LOOP:
    for ( i = h - 1 ; i >= 0; i--){
    #pragma HLS loop_tripcount min=2 max=125
        
        int k = i*2; //data_size << 1;
        temp[i] = data->data1D[k]*0.5*1.41421356 + data->data1D[k + 1]*0.5*1.41421356;
        temp[i + h] = data->data1D[k]*0.5*1.41421356 - data->data1D[k + 1]*0.5*1.41421356;
        
    }
    
    SEND_LOOP://Can be merged with the loop abolve
    for ( i = 0; i < data->size; i++)
    #pragma HLS loop_tripcount min=50 max=200
        data->data1D[i] = temp[i];

}


void dwt3D(image_t *in, int iterations){
#pragma HLS INTERFACE bram port=in->data3D

	//image_t _data3D;
	//image_t *data3D = &_data3D;

    
    int i, j, k, n;
    array_t _x, _y, _z;
    array_t *x = &_x;
    array_t *y = &_y;
    array_t *z = &_z;
    
    DWT_LEVEL_LOOP:
    for(n = iterations - 1; n >= 0; n--){
        #pragma HLS loop_tripcount min=1 max=2
        
        int sub = 1 << n;



        x->size = in->x_size / sub;
        y->size = in->y_size / sub;
		z->size = in->z_size / sub;

        
        X_J_LOOP:
        for ( j = y->size - 1; j >= 0; j--){
        #pragma HLS loop_tripcount min=4 max=128
            X_K_LOOP:
            for ( k = z->size - 1; k >= 0; k--){
            #pragma HLS loop_tripcount min=4 max=128
                X_I_LOOP:
                for ( i = x->size - 1; i >= 0; i--)
                #pragma HLS loop_tripcount min=4 max=128
                                       
                    x->data1D[i] = in->data3D[i][j][k];
                    
                dwt1D(x);
                
                RES_X_LOOP:
                for ( i = x->size - 1; i >= 0; i--)
                #pragma HLS loop_tripcount min=4 max=128
                    in->data3D[i][j][k] = x->data1D[i];
                
            }    
        }
        
        Y_K_LOOP:
        for ( k = z->size - 1; k >= 0; k--){
        #pragma HLS loop_tripcount min=4 max=128
            Y_I_LOOP:
            for ( i = x->size - 1; i >= 0; i--){
            #pragma HLS loop_tripcount min=4 max=128
                Y_J_LOOP:
                dwt3D_label1:for ( j = y->size - 1; j >= 0; j--)
                #pragma HLS loop_tripcount min=4 max=128
            
                    y->data1D[j] = in->data3D[i][j][k];

                dwt1D(y);
                
                RES_Y_LOOP:
                for ( j = y->size - 1; j >= 0; j--)
                #pragma HLS loop_tripcount min=4 max=128
                    in->data3D[i][j][k] = y->data1D[j];
                
            }    
        }
        
        
        Z_I_LOOP:
        for( i = x->size - 1; i >= 0; i--){    
        #pragma HLS loop_tripcount min=4 max=128
            Z_J_LOOP:
            for(j = y->size - 1; j >= 0; j--){
            #pragma HLS loop_tripcount min=4 max=128
                Z_K_LOOP:
                dwt3D_label0:for(k = z->size - 1; k >= 0; k--)
                #pragma HLS loop_tripcount min=4 max=128                    
                    
                	z->data1D[k] = in->data3D[i][j][k];
                        
                    dwt1D(z);
                    
                    RES_Z_LOOP:
                    for ( k = z->size - 1; k >= 0; k--)
                    #pragma HLS loop_tripcount min=4 max=128
                        in->data3D[i][j][k] = z->data1D[k];
                    
            }    
        } 
    
    }
}

