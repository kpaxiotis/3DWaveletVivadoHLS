#ifndef MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif


#ifndef COMP_STR
#define COMP_STR

void compStr(char *dir_out, char *dir_out_gold, char *comp_str){

    /*
    Creating the comparison argument
    */
    
    char temp[400] = "diff --brief -w "; 
    
    strcat(temp, dir_out);
    strcat(temp, " ");
    strcat(temp, dir_out_gold);
    
    sprintf(comp_str, "%s", temp);

    
}

//"diff --brief -w out.dat out.gold.dat"

#endif

#ifndef MAIN

int main(){
    
    char comp_str[200];
    char dir_out[200] = 
    "out_images/128x128x24/10/out.dat";
    char dir_out_gold[400] = 
    "out_gold_images/128x128x24/10/out.gold.dat";
    
    for (int n = 1; n <= 10; n++){
            
        compStr(dir_out, dir_out_gold, comp_str);
        printf("%s\n", comp_str);

    }
    
    return 0;
}

#endif