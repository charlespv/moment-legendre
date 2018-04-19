// Fonction MOMENT de Legendre
#include <stdio.h>
#include "bin_image.h"

float Pol_Legendre(float ordre, int n)  // calcule Pn(X), ou x = ordre
{

    int i;
    float p[n];
    p[0]=1;
    p[1]=ordre;

    for (i=1; i<n; i++)
    {

        p[i+1] = ((2*i+1)*ordre*p[i]) - (i*p[i-1]);
        p[i+1] = p[i+1]/(i+1);

    }
    return p[n];
}


float moment_legendre(unsigned char **Mat_bin, int dimX, int dimY, int ordre_moment){

    float cst;
    float x, y, moment = 0;
    float p,q, hx, hy, ax, ay, b,Pp, Pq;
    int i,j, cpt = 0;
    float** legendre;
    float** Px; // matrice normaliser Px
    float** Py; // matrice normaliser Py
    int N = 10;  // ordre de ma matrice


    /*************Allocation de memoire**********************************************/
    legendre = calloc(x,sizeof(float));
    Px = calloc(x,sizeof(float));
    Py = calloc(x,sizeof(float));

    for (i=0; i<x; i++)
    {
        Px[i] = calloc(N+1,sizeof(float));
        Py[i] = calloc(y,sizeof(float));
        legendre[i]=calloc(y, sizeof(float));

    }


    ax=2/(x-1);
    ay=2/(y-1);
    b=-1;

    /************** Linearisation des X *******************************************/
    for(i=0; i<x; i++)   // i = p;
    {
        for(j=0; j<(N-i); j++)  //j = ordre;
        {
            hx = ax*i + b;
            Px[i][j] = Pol_Legendre(hx,j);   //Modif a realiser sur le polynome de legendre
        }
    }

    /************** Linearisation des y *******************************************/
    for(i=0; i<y; i++)   // i = y;
    {

        for(j=0; j<(N-i); j++)  //j = ordre;
        {

            hy = ay*i + b;
            Py[i][j] = Pol_Legendre(hy,j);   //Modif a realiser sur le polynome de legendre

        }

    }

    /********************CALCUL DU POLYNOME DE LEGENDRE************************/

    for(i = 0; i<N; i++)
    {

        for(j=0; j<(N - i); j++)
        {

            cst = (((2*i) + 1)*((2*j) +1))/4;

            legendre[i][j] =cst*(Px[i][j]*Py[i][j])*Mat_bin[i][j];

            moment = moment + legendre[i][j];

        }

     }



    /************************************ Desallocation des espaces mémoire  **************************************/
    for (i=0; i<x; i++)
    {
        free(Px[i]);
    }
    for (i=0; i<N; i++)
    {
        free(legendre[i]);
    }

    for (i=0; i<y; i++)
    {
        free(Py[i]);
    }

return moment;

}
