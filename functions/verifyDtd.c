#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifyDtd.h"

void sauterLigne(FILE* f){
    char c ;
    do {
        c = fgetc(f);
        if(c != ' ' && c != '\n'){
            printf("ERREUR : CARACTERE INNATENDU");
            exit(1);
        }
    } while (c != '\n') ;
}

int checkFinElementDTD(int indexElement, char** tabAttributElement){
    if( tabAttributElement[indexElement][strlen(tabAttributElement[indexElement])-1] == '+') {
        return 1 ;
    } else {
        return 0 ;
    }
}