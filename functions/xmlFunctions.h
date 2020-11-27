#define TAILLE_MAX 100

int checkXMLVersion(FILE* f);
char* getElementXML(FILE* xml);
void lireContenuElementXML(FILE* xml);
void lireElementDansXML(FILE* xml, int nbElementDTD, char** tabNameElement, char** tabAttributElement, int profondeur);