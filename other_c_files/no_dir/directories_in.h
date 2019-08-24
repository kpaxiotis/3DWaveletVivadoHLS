#ifndef MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif


#ifndef DIRECTORIES_IN
#define DIRECTORIES_IN

void directoryIn(char *dir_in, char *dir_dim, int n){

    /*
    Creating the directory where the input data are
    */
    
    char i[3], temp[200] = "in_images/";
    
    sprintf(i, "%d", n);
    strcat(temp, dir_dim);    
    strcat(temp, "_");
    strcat(temp, i);
    strcat(temp, ".dat");
    
    sprintf(dir_in, "%s", temp);
    
}

#endif

#ifndef MAIN

int main(){
    
    char dir_in[200];
    char dir_dim[200] = "128x128x24";
    
    for (int n = 1; n <= 10; n++){
            
        directoryIn(dir_in, dir_dim, n);
        printf("%s\n", dir_in);

    }
    
    return 0;
}

#endif