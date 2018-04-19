//MELLAH Kamel

#include "imagerec1_2.h"
#include <stdio.h>
#include <stdlib.h>

void scan(char* nomim, unsigned int* a, unsigned int* b,unsigned char** img){ // fonction qui permet, ? partir de l'adresse de l'image, d'obtenir ses dimensions X et Y

    BmpImg mon_im;
    //pmon_im=malloc(sizeof(BmpImg));
    unsigned int x,y;

    mon_im = readBmpImage(nomim);
    x=mon_im.dimX;
    y=mon_im.dimY;
    img=mon_im.imgR;
    a=&x;b=&y;

}


image* newIm(char* nom, int p, int q){

	image* pnew;
	pnew=malloc(sizeof(image)) ;
	if(pnew == NULL)  {
		printf("Erreur lors de l'allocation memoire\n");
		return NULL;
	}
	unsigned int* dimX;
	unsigned int* dimY;
	unsigned char** img;
	scan(nom, dimX,dimY,img);
	pnew->dimx=*dimX;printf("raa\n");
	pnew->dimy=*dimY;
	pnew->img=img;
    int** buffer; // matrice de int temporaire pour la conversion
    buffer=char2int(img,*dimX,*dimY);
	pnew->momg=matricemoment(buffer,pnew->dimx,pnew->dimy,p,q);
	//pnew->momleg=
	pnew->isuiv=NULL;

	return pnew;
}


image* entete(image* liste, image* new_im){


	new_im->isuiv=liste;

	return new_im;
}

image* initialisation_liste(int p, int q){

image* img2;
image* fin;
image* liste;
fin=newIm("lettre_i.bmp",p,q);
img2=newIm("lettre_k.bmp",p,q);
img2=entete(fin,img2);
liste=newIm("lettre_j.bmp",p,q);
liste=entete(img2,liste);
return liste;
}


void freeimage(image* pim){

	pim->isuiv=NULL;
	free(pim);
}


/*Pol_Legendre mis en commentaire pour éviter le doublon avec Legendre.c*/
/*float Pol_Legendre(int ordre, int n){

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
}*/

float puissance(int x, int P ) {

    int pX = 1;
    int i;
    for( i = 1; i <= P; i++ )
        pX *= x;
    return pX;
}





void afficherimagebin(int** image,int dimx, int dimy){
    int i,j;
    for(i=0;i<dimx;i++){
        for(j=0;j<dimy;j++){
            printf("%d",image[i][j]);
        }
        printf("\n");
    }
}

double** construire_imagebin(int N){
	// N est la dimension de l'image binaire
	double** image;
	int i = 0;
	int j = 0;
    image = calloc( N, sizeof( double*) );
    for(i=0;i<N;i++){
        image[i] = calloc( N , sizeof( double ) );
        for(j=0;j<N;j++){
            if(i<3*N/4 && i>N/4 && j<3*N/4 && j>N/4){


                image[i][j]=1 ;
            }
            else
                image[i][j]=0;
        }
    }
    return image;
}

void afficherimage(float** image,int dimx, int dimy){
    int i,j;
    for(i=0;i<dimx;i++){
        for(j=0;j<dimy;j++){
            printf("%f\t",image[i][j]);
        }
        printf("\n");
    }
}

int** char2int (unsigned char** image, int dimx, int dimy){
int x,y,i,j;
x=dimx;
y=dimy;

int** mat= calloc (dimx, sizeof(int));

for (i = 0; i<x; i++)
    {
        mat[i] = calloc(dimy, sizeof(int));
        for(j=0; j<y; j++)
        {
            if(image[i][j] == '0'){   //erreur de segmentation car on fait un free a la fin de conversion binaire
              mat[i][j]=0;
            }
            else{
              mat[i][j]=1;
            }
            // image[i][j]=1;// a supprimer apr�s test
           // printf("%c", Bin[i][j]);
        }
         //printf("\n");
    }

return mat;

}



int calcul_moment(int **image,int dimX, int dimY,int p,int q){
    int x,y,intgr=0,inty;
    for(x=0; x<dimX; x++)
    {
        inty=0;
        for(y=0; y<dimY; y++)
        {
            inty+=puissance(x,p)*puissance(y,q)*image[x][y];
        }
        intgr+=inty;
    }
    return intgr;
}

float** matricemoment(int** image,int dimX,int dimY,int p, int q){
int i,j;
float M=2*(p+q);
float** mat=calloc(M, sizeof(float*));
for(i=0;i<M;i++){
    mat[i]=calloc(M , sizeof( float ));
}
for(i=0;i<M;i++){
    for(j=0;j<M;j++){
            if((i+j)>(p+q)){
                mat[i][j]=0;
            }else{
            mat[i][j]=calcul_moment(image,dimX,dimY,i,j);
            }
    }

}
    afficherimage(mat,M,M); //affichage de la matrice des moments

return mat;
}

int diffmom(double** mom1, double** mom2,int ordre){ //fonction qui fait la distance entre deux matrices et renvoit la distance maximale calculée
	int max=0, i, j;
	int M=2*ordre;
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			if(abs(mom1[i][j]-mom2[i][j])>max){
				max=mom1[i][j]-mom2[i][j];
			}
		}
	}
	return max;
}

int mini(int tab[], int N){ //fonction qui trouve la valeur minimale d'un tableau et renvoie l'indice correspondant à sa case dans le tableau
	int min=0, i, ind;
	for(i=0;i<N;i++){
		if(tab[i]<min){
			min=tab[i];
			ind=i;
		}
	}
	return ind;
}

char compare(image* imgu, image* list, int nbIR){ //image est une structure, imgu est un pointeur sur la structure de l'image entrée par l'utilisateur, et list correspond à la liste chainée d'images de référence, nbIR correspond au nombre d'images dans la base de donnée
	int k=0, min, i;//k est un compteur qui permet de remplir le tableau
	int tab[nbIR];
	image* clist; //copie de list
	while(clist->isuiv != NULL) { // on parcourt la liste chainée
		tab[k]=diffmom(imgu->img,clist->img,nbIR); //on remplit le tableau des distances maximum calculées entre deux images, pour chaque image référencée dans la liste chainée
		k++;
		clist=clist->isuiv; // on parcourt la liste chainée
	}
	min=mini(tab,k); // on trouve le maximum le plus petit, il correspondra donc à l'image la plus proche de celle entrée par l'utilisateur
	for(i=0;i<min;i++){ //on parcourt la liste chainée pour aller trouver l'image correspondant à l'indice retournée par la fonction mini
		list=list->isuiv;
	}
	return list->lettre; //on retourne l'image référencée qui a la distance maximale la moins élevée
}
