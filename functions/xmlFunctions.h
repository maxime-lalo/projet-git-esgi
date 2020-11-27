#define TAILLE_MAX 100

int checkXMLVersion(FILE* f);
void lireElementDansXML(FILE* xml, int nbElementDTD, char** tabNameElement, char** tabAttributElement, int profondeur);