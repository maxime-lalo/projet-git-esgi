#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xmlFunctions.h"

int checkXMLVersion(FILE* f){
    char* buffer = malloc(sizeof(char)*TAILLE_MAX);
    fgets(buffer, 22, f);
    if (strcmp("<?xml version=\"1.0\"?>", buffer) == 0){
        printf("XML VERSION CORRECT\n\n");
        free(buffer);
        return 1 ;
    } else {
        free(buffer);
        printf("XML VERSION INCORRECT\n");
        return 0 ;
    }

}