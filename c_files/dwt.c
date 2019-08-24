#include "image_aux.h"



void dwt1D(array_t *data){

    float temp[MAX_SIZE]; // The size should be data_size but it's not synthesizable
    int h = data->size / 2; //data_size >> 1;
    int i = 0;
    
    for ( i = 0; i <h; i++){
    #pragma HLS loop_tripcount min=2 max=125
        
        int k = i*2; //data_size << 1;
        temp[i] = data->data1D[k]*0.5*1.41421356 + data->data1D[k + 1]*0.5*1.41421356;
        temp[i + h] = data->data1D[k]*0.5*1.41421356 - data->data1D[k + 1]*0.5*1.41421356;
        
    }
    
    for ( i = 0; i < data->size; i++)
    #pragma HLS loop_tripcount min=50 max=200
        data->data1D[i] = temp[i];

}


void dwt3D(image_t *in, int iterations){
#pragma HLS INTERFACE bram port=in->data3D


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


    int i, j, k, n;
    

    temp->x_size = in->x_size;
    temp->y_size = in->y_size;
    temp->z_size = in->z_size;

    
    for( i = 0; i < in->x_size; i++){    
        #pragma HLS loop_tripcount min=4 max=128
        for(j = 0; j < in->y_size; j++){
        #pragma HLS loop_tripcount min=4 max=128
            for(k = 0; k < in->z_size; k++){
            #pragma HLS loop_tripcount min=4 max=128
                
                temp->data3D[i][j][k] = in->data3D[i][j][k];
                    
            }
        }
    }

    
    for(n = 0; n < iterations; n++){
        #pragma HLS loop_tripcount min=1 max=2
        
        int sub = 1 << n;



        x->size = temp->x_size / sub;
        y->size = temp->y_size / sub;
		z->size = temp->z_size / sub;

        
        for ( j = 0; j < y->size; j++){
        #pragma HLS loop_tripcount min=4 max=128
            for ( k = 0; k < z->size; k++){
            #pragma HLS loop_tripcount min=4 max=128
                for ( i = 0; i < x->size; i++)
                #pragma HLS loop_tripcount min=4 max=128
                                       
                    x->data1D[i] = temp->data3D[i][j][k];
                    
                dwt1D(x);
                
                for ( i = 0; i < x->size; i++)
                #pragma HLS loop_tripcount min=4 max=128
                    temp->data3D[i][j][k] = x->data1D[i];
                
            }    
        }
        
        for ( k = 0; k < z->size; k++){
        #pragma HLS loop_tripcount min=4 max=128
            for ( i = 0; i < x->size; i++){
            #pragma HLS loop_tripcount min=4 max=128
                dwt3D_label1:for ( j = 0; j < y->size; j++)
                #pragma HLS loop_tripcount min=4 max=128
            
                    y->data1D[j] = temp->data3D[i][j][k];

                dwt1D(y);
            
                for ( j = 0; j < y->size; j++)
                #pragma HLS loop_tripcount min=4 max=128
                    temp->data3D[i][j][k] = y->data1D[j];
                
            }    
        }
        
        
        for( i = 0; i < x->size; i++){    
        #pragma HLS loop_tripcount min=4 max=128
            for(j = 0; j < y->size; j++){
            #pragma HLS loop_tripcount min=4 max=128
                dwt3D_label0:for(k = 0; k < z->size; k++)
                #pragma HLS loop_tripcount min=4 max=128                    
                    
                	z->data1D[k] = temp->data3D[i][j][k];
                        
                dwt1D(z);
                    
                for ( k = 0; k < z->size; k++)
                #pragma HLS loop_tripcount min=4 max=128
                    temp->data3D[i][j][k] = z->data1D[k];
                    
            }    
        }
    
    }
    
    for( i = 0; i < in->x_size; i++){    
    #pragma HLS loop_tripcount min=4 max=128
        for(j = 0; j < in->y_size; j++){
        #pragma HLS loop_tripcount min=4 max=128
            for(k = 0; k < in->z_size; k++){
            #pragma HLS loop_tripcount min=4 max=128
                
                in->data3D[i][j][k] = temp->data3D[i][j][k];
                    
            }
        }
    }
}

