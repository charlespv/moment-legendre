#include "bin_image.h"

void binarisation_image(char* bmpName, unsigned char **Mat){ // fonction transformant une image bmp en matrice binaire
int  i,j,taille;
BmpImg mon_im;
unsigned int x,y;

mon_im = readBmpImage(bmpName); //charge les paramètres de l'image (tel que sa taille, ses composantes RGB)
x=mon_im.dimX;
y=mon_im.dimY;
taille = x*y;
Mat=calloc(x, sizeof(unsigned int));


for (i=0; i<taille; i++)
{
    Mat[i]=calloc(y, sizeof(int));
}

Mat = mon_im.imgR;  // on charge les composantes rouge de l'image qui sont à 0 et 255 car l'image est en noir et blanc

for (i=0; i<x; i++)                                 //Boucle pour passer d'une plage de 0 à 255 au binaire. 0 ou 1
{
    for (j=0; j<y; j++)
    {
        if(Mat[i][j] > 90)                          //Nous avons mis > 90 car il y a avait de légères variation (1 à 10)
        {
            Mat[i][j] = 1;
        }
        else
        {
            Mat[i][j] = 0;
        }
        printf("%d ", Mat[i][j]);
    }
    printf("\n");
}

freeMat(Mat,x);

}
