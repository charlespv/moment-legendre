#include "imagerec1_2.h"
#include "Legendre.h"
#include "myLibBmp.h"
#include <stdlib.h>

int main(){
image* database;
char res;
int p,q;

/*phase d'initialisation du "savoir" concernant la reconnaissance de caractères*/
printf("L'ordre noté O correspond à O=p+q.\nSaisissez p\n");
scanf("%d",&p);
printf("Saisissez q\n");
scanf("%d",q);
database=initialisation_liste(p,q);

/* Demande de l'image test à l'utilisateur*/
char chemin;
printf("Entrez le chemin menant vers votre image\n");
scanf("%c",&chemin);
image* pu;
pu=newIm(&chemin,p,q);

/* Analyse puis réponse du programme à la requete de l'utilisateur*/
res=compare(pu,database,3);
printf("Votre image contient le(s) caractère(s) suivants %c\n",res);

return 0;
}
