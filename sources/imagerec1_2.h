//MELLAH Kamel

#ifndef _imagerec1_2_h_
#define _imagerec1_2_h_

#include "myLibBmp.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct image image ;

struct image {
	unsigned int dimx ;
	unsigned int dimy ;
	unsigned char** img ;
	float** momg;
	double** momleg;
	char lettre;
	image* isuiv ;
	//image* iprec ;

};


/*Fonction initialisation de la liste chaine*/
image* initialisation_liste(int p, int q);

/*Fonction ajout d'un nouvel element à la liste*/
image* newIm(char* nomim, int p, int q);

/*Fonction définition de l'entete de la liste*/
image* entete(image* liste, image* new_im);

/*Fonction liberation de mémoire issue d'une image*/
void freeimage(image* pim);


/*Fonction de traduction de type dans un tableau 2D char -> int*/
int** char2int (unsigned char** image, int dimx, int dimy);

void afficherimagebin(int** image,int dimx, int dimy);

void afficherimage(float** image,int dimx, int dimy);

/*Fonction construisant une image binaire basique afin de répondre à des tests*/
double** construire_imagebin(int N);


/*Fonction calcul de moment géometrique (MG) */
int calcul_moment(int **image,int dimX, int dimY,int p,int q);

/*Fonction calcul et disposition sur une matrice triangulaire des MG*/
float** matricemoment(int** image,int dimX,int dimY,int p, int q);

/*image est une structure, imgu est un pointeur sur la structure de l'image entrée par l'utilisateur, et list correspond à la liste chainée d'images de référence, nbIR correspond au nombre d'images dans la base de donnée*/
char compare(image* imgu, image* list, int nbIR);

//fonction qui fait la distance entre deux matrices et renvoit la distance maximale calculée
int diffmom(double** mom1, double** mom2, int ordre);

//fonction qui trouve la valeur minimale d'un tableau et renvoie l'indice correspondant à sa case dans le tableau
int mini(int tab[], int N);

// fonction qui permet, ? partir de l'adresse de l'image, d'obtenir ses dimensions X et Y
void scan(char* nomim, unsigned int* a, unsigned int* b, unsigned char** img);

//float Pol_Legendre(int ordre, int n); mis en commentaire pour éviter un doublon avec Legendre.c

#endif


