#define TAILLE_MAX 100

void sauterLigne(FILE* f);
int checkFinElementDTD(int indexElement, char** tabAttributElement);
char* lectureFinElementDTD(FILE* xml);