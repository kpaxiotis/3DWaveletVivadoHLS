#ifndef MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif


#ifndef DIRECTORIES
#define DIRECTORIES

void directoryDim(char *dir_dim, int i ,int j){

    /*
    Creating the image dimentions directories
    */
    
    char y[3], temp[200];
    
    sprintf(temp, "%d", i);
    sprintf(y, "%d", j);
    strcat(temp, "x");
    strcat(temp, y);
    strcat(temp, "x24");
    
    sprintf(dir_dim, "%s", temp);

}

#endif

#ifndef MAIN

int main(){
    
    char dir_dim[200];
    
    for (int i = 4; i <= 128; i+=4){
        for (int j = 4; j <= 128; j+=4){
            
            directoryDim(dir_dim, i, j);
            printf("%s\n", dir_dim);

        }
    }
    
    return 0;
}

#endif