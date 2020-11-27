#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions/xmlFunctions.h"
#include "functions/verifyDtd.h"

int main(){
    //DTD
    char* nomFichierDTD = "dtd1.dtd" ;
    char** tabNameElement = malloc(sizeof(char*)*TAILLE_MAX);
    char** tabAttributElement = malloc(sizeof(char*)*TAILLE_MAX);

    int nbElementDTD = lireDTD(nomFichierDTD, tabNameElement, tabAttributElement);

    return 0 ;
}
