
#include "raccordeur_recursif.h"
#include <utility>
#include<algorithm>
using namespace std; 

Node* Mat[hauteur][largeur];

Node * MeilleurParent(MatInt2* distances,int i,int j,int largeur){
Node * x=new Node();
Node minNode;
 int min=9999999;
 for(int jj=j-1;jj<=j+1;jj++){
   if(jj<0 || jj>=largeur)
    continue;
  if(Mat[i-1][j]->dist<min){
    min=Mat[i-1][j]->dist;
    minNode=new Node(Mat[i-1][j]);
  }
}
return new Node(j,minNode->dist+distances->get(i,j),minNode);

}

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  
  
  
  for(int j=0;j<largeur;j++){
    Mat[0][j]=new Node(j,distances.get(0,j),NULL)
  }
 
  for(int i=1;i<hauteur;i++){
    for(int j=0;j<largeur;j++){
      Mat[i][j]=MeilleurParent(Mat,distances,i,j,largeur);
    }
  }
  
  Node* minNode;
  int min=99999999;
 for(int j=0;j<largeur;j++){
  if(Mat[hauteur-1][j]->dist<min){
    min=Mat[hauteur-1][j]->dist;
    minNode=Mat[hauteur-1][j];
  }
 }

  int y=0;
  while(1){
    coupe[y++]=minNode->x;
    if(minNode->pere==NULL)
      break;
    minNode=minNode->pere;
  }

  return min;
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}
