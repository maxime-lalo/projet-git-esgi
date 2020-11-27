#define TAILLE_MAX 100

void sauterLigne(FILE* f);
int checkFinElementDTD(int indexElement, char** tabAttributElement);
char* lectureFinElementDTD(FILE* xml);
char* getNomDTD(FILE* f);
int finDeDTD(FILE* f);
int lireDTD(char* nomFichierDTD, char** tabNameElement, char** tabAttributElement);
int checkElementInDTD(int nbElementDTD, char** tabNameElement, char* buffer, int n);
int verifierDoctype(FILE* f);
void getElement(int i, char** tabNameElement, char** tabAttributElement, FILE* f);
void enleverEspaces(FILE* f);