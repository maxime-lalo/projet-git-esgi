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

char* lectureFinElementDTD(FILE* xml){
    char* buffer = malloc(sizeof(char)*TAILLE_MAX);
    char c = fgetc(xml);
    int i = 0 ;
    while (c != '>'){
        buffer[i] = c ;
        c = fgetc(xml);
        if (i == TAILLE_MAX){
            printf("ERREUR : '>' NON PRESENT OU NOM D'ELEMENT TROP GRAND\n");
            exit(1);
        }
        i++;
    }
    return buffer ;
}

char* getNomDTD(FILE* f){
    char* buffer = malloc(sizeof(char)*TAILLE_MAX);
    int i = 0 ;
    char c = fgetc(f) ;
    int save = 0 ;
    while (c != '['){
        if (i == TAILLE_MAX){
            printf("NOM TROP LONG OU CARACTERE '[' NON PRESENT");
            exit(1) ;
        }
        if(c == ' '){
            save ++ ;
            if (save > 1 ){
                printf("ERREUR : TROP D'ESPACES DANS LE NOM") ;
                exit(1);
            }
        }
        if (save < 1){
            buffer[i] = c ;
        }

        c = fgetc(f) ;
        i++ ;
    }
    return buffer ;
}

int finDeDTD(FILE* f){
    char c = fgetc(f);
    if (c == ']'){
        c = fgetc(f);
        if (c == '>'){
            printf("FIN DE DTD\n\n");
            return 0 ;
        } else {
            printf("ERREUR : CARACTERE INNATENDU");
            exit(1);
            return 0 ;
        }
    } else {
        fseek(f,-1,SEEK_CUR);
        return 1 ;
    }
}

int lireDTD(char* nomFichierDTD, char** tabNameElement, char** tabAttributElement){
    FILE* dtd = fopen(nomFichierDTD, "r+");
    if (dtd == NULL ){
        exit(1);
    }

    if(verifierDoctype(dtd)){
        exit(1);
    }
    char* nomDTD = getNomDTD(dtd);
    printf("Nom de la DTD : %s\n\n",nomDTD);

    sauterLigne(dtd);

    int i = 0 ;

    while(finDeDTD(dtd) == 1 ){
        getElement(i, tabNameElement, tabAttributElement, dtd) ;
        i++ ;
    }

    fclose (dtd);
    return i ;
}