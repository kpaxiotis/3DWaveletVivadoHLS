#ifndef MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif


#ifndef DIRECTORIES_OUT_GOLD
#define DIRECTORIES_OUT_GOLD

void directoryOutGold(char *dir_out_gold, char *dir_dim, int n){

    /*
    Creating the directory where the input data are
    */
    
    char i[3], temp[200] = "out_gold_images/";
    
    sprintf(i, "%d", n);
    strcat(temp, dir_dim);    
    strcat(temp, "_");
    strcat(temp, i);
    strcat(temp, ".dat");
    
    sprintf(dir_out_gold, "%s", temp);
    
}

#endif

#ifndef MAIN

int main(){
    
    char dir_out_gold[200];
    char dir_dim[200] = "128x128x24";
    
    for (int n = 1; n <= 10; n++){
            
        directoryOutGold(dir_out_gold, dir_dim, n);
        printf("%s\n", dir_in);

    }
    
    return 0;
}

#endif