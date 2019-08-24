#include "image_aux.h"



void dwt1D(float* data, int data_size){

    float temp[X_SIZE]; // The size should be data_size but it's not syntesizable
    int h = data_size / 2; //data_size >> 1;
    int i = 0;
    
    for ( i = 0; i <h; i++){
        #pragma HLS loop_tripcount min=25 max=100
        
        int k = i*2; //data_size << 1;
        temp[i] = data[k]*0.5*1.41421356 + data[k + 1]*0.5*1.41421356;
        temp[i + h] = data[k]*0.5*1.41421356 - data[k + 1]*0.5*1.41421356;
        
    }
    
    for ( i = 0; i < data_size; i++)
    #pragma HLS loop_tripcount min=50 max=200
        data[i] = temp[i];

}


void dwt3D(float data3D[X_SIZE][Y_SIZE][Z_SIZE],int iterations){
#pragma HLS INTERFACE bram port=data3D

	//image_t _data3D;
	//image_t *data3D = &_data3D;
    
    int i, j, k, n;
    float x_axis[X_SIZE], y_axis[Y_SIZE], z_axis[Z_SIZE];

    
    for(n = 0; n < iterations; n++){
        #pragma HLS loop_tripcount min=1 max=2
        
        int sub = 1 << n;

        int sub_x_size = X_SIZE / sub, sub_y_size = Y_SIZE /sub ,
        sub_z_size = Z_SIZE / sub;
        

        for ( k = 0; k < sub_z_size; k++){
        #pragma HLS loop_tripcount min=50 max=200
            for ( i = 0; i < sub_x_size; i++){
            #pragma HLS loop_tripcount min=50 max=200
                for ( j = 0; j < sub_y_size; j++)
                #pragma HLS loop_tripcount min=50 max=200
            
                    y_axis[j] = data3D[i][j][k];

                dwt1D(y_axis, sub_y_size);
            
                for ( j = 0; j < sub_y_size; j++)
                #pragma HLS loop_tripcount min=50 max=200
                    data3D[i][j][k] = y_axis[j];
                
            }    
        }
                
        for ( j = 0; j < sub_y_size; j++){
        #pragma HLS loop_tripcount min=50 max=200
            for ( k = 0; k < sub_z_size; k++){
            #pragma HLS loop_tripcount min=50 max=200
                for ( i = 0; i < sub_x_size; i++)
                #pragma HLS loop_tripcount min=50 max=200
                                       
                    x_axis[i] = data3D[i][j][k];
                    
                dwt1D(x_axis, sub_x_size);
                
                for ( i = 0; i < sub_x_size; i++)
                #pragma HLS loop_tripcount min=50 max=200
                    data3D[i][j][k] = x_axis[i];
                
            }    
        }
        
        for( i = 0; i < X_SIZE; i++){
        #pragma HLS loop_tripcount min=50 max=200            
            for(j = 0; j < Y_SIZE; j++){
            #pragma HLS loop_tripcount min=50 max=200
                for(k = 0; k < Z_SIZE; k++)
                #pragma HLS loop_tripcount min=50 max=200                    
                    
                    z_axis[k] = data3D[i][j][k];
                        
                dwt1D(z_axis, sub_z_size);
                
                for ( k = 0; k < sub_z_size; k++)               
                    data3D[i][j][k] = z_axis[k];
                    
            }    
        }      

    }
}

