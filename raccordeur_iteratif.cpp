
#include "raccordeur_iteratif.h"

/*
 *
Cette fonction retourne un Node_i avec:

x:: sa colonne dans la matrice distances
dist:: sa valeur dans la matrice distances + la valeur minimum des colonnes x-1 x x+1 de la ligne y-1
pere:: assigner le Node_i qui contient la valeur min comme pere (pour pouvoir tracer la meilleure coupe)
 
 *
 */

Node_i * RaccordeurIteratif::MeilleurParent(Node_i* **Mat,MatInt2* distances,int y,int x,int largeur){
 
 Node_i* minNode;
 int min=INT_MAX;

 for(int xx=x-1;xx<=x+1;xx++){
  
  //si la colonne depasse les bornes de la matrice distances
   if(xx<0 || xx>=largeur)
    continue;
 
  if(Mat[y-1][xx]->dist<min){
    min=Mat[y-1][xx]->dist;
    minNode=new Node_i(Mat[y-1][xx]);
  }
}

return new Node_i(x,minNode->dist+distances->get(y,x),minNode);
}

int RaccordeurIteratif::calculerRaccord(MatInt2* distances, int* coupe)
{
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  int cout=INT_MAX;

  Node_i* **Mat;
  Node_i* minNode;
  
  //Initialisation de la matrice
  Mat = new Node_i* *[hauteur];
  for(int y = 0; y <hauteur; y++)
    Mat[y] = new Node_i*[largeur];
  
  //Remplissage du premier ligne de la matrice
  for(int x=0;x<largeur;x++)
    Mat[0][x]=new Node_i(x,distances->get(0,x),NULL);
  
  //remplissage de la matrice, chaque colonnes prend sa valeur + la valeur min entre colonnes x-1 x x+1 du ligne y-1
  for(int y=1;y<hauteur;y++)
    for(int x=0;x<largeur;x++)
      Mat[y][x]=MeilleurParent(Mat,distances,y,x,largeur);
   
 //Chercher la valeur minimum du dernier ligne, il s'agit forcement du plus court chemin
 for(int x=0;x<largeur;x++){
  if(Mat[hauteur-1][x]->dist<cout){
    cout=Mat[hauteur-1][x]->dist;
    minNode=Mat[hauteur-1][x];
  }
}
 
  //remplissage du tableau coupe avec les colonnes de chaque ligne du plus court chemin
  int y=0;
  while(1){
    coupe[hauteur-1-y++]=minNode->x;
    if(minNode->pere==NULL)
      break;
    minNode=minNode->pere;
  }

  //le cout minimal
  return cout;
}

RaccordeurIteratif::~RaccordeurIteratif()
{
  
}
