/*
Gia na doulepsei prepei oi diastaseis na einai enas pinakas
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAIN

#include "directories_dim.h"
#include "directories_in.h"
#include "directories_out.h"
#include "directories_out_gold_r.h"
#include "comp_str.h"
#include "image_aux.h"
#include "image_read.h"
#include "print3D.h"

#define ITERATIONS 2



int main(){

    char dir_in[200], dir_dim[200], dir_out[200], dir_out_gold[200], comp_str[400];
    
	int x_size, y_size, z_size;
	float data3D[X_SIZE][Y_SIZE][Z_SIZE];
    
    for (int i = 4; i <= 128; i+=4){        
        for (int j = 4; j <= 128; j+=4){
            
            directoryDim(dir_dim, i, j);
            
            for (int n = 1; n <= 10; n++){
                directoryIn(dir_in, dir_dim, n);
                directoryOut(dir_out, dir_dim, n);
                directoryOutGold(dir_out_gold, dir_dim, n);
                
                printf("%d\n", x_size);///
                
                imageRead(data3D, x_size, y_size, z_size, dir_in);
                
                printf("%d\n", x_size);///
                
                //dwt3D(data3D, x_size, y_size, z_size, ITERATIONS);    

                printToFile(data3D, x_size, y_size, z_size, dir_out);
                
                compStr(dir_out, dir_out_gold, comp_str);
                
                if (system(comp_str)) {

                    fprintf(stdout, "*******************************************\n");
                    fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
                    fprintf(stdout, "*******************************************\n");
                     return 1;
              } else {
                    fprintf(stdout, "*******************************************\n");
                    fprintf(stdout, "PASS: The output matches the golden output!\n");
                    fprintf(stdout, "*******************************************\n");
              }
                
            }
            return 0;
        }
        
    }
    
    /*printf ("Comparing against output data \n");
    if (system("diff --brief -w out.dat out.gold.dat")) {

	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
	fprintf(stdout, "*******************************************\n");
     return 1;
  } else {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "PASS: The output matches the golden output!\n");
	fprintf(stdout, "*******************************************\n");
     return 0;
  }*/
    //return 0;
}

