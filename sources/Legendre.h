// Charles PV

#ifndef _Legendre_h_
#define _Legendre_h_


#include <stdio.h>
#include "bin_image.h"

/*Fonction de calcul des polynome de Legendre*/
float Pol_Legendre(float ordre, int n);

/*Fonction de calcul (grace à la fonction Pol_Legendre) et de disposition des moments*/
float moment_legendre(unsigned char **Mat_bin, int dimX, int dimY, int ordre_moment);

#endif