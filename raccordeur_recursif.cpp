
#include "raccordeur_recursif.h"
#include <utility>
#include<algorithm>
using namespace std; 


struct Node(){
 int x;
 int y;
 int cout;
 Node *pere;
}


Node RaccordeurRecursif::CoupeOptimale(MatInt2* distances,Node n){

  if(n.y<0)
    return n;
  
  Node aa= {n.x,n.y-1,n.cout,n};
  Node a= CoupeOptimale(distances,aa);
  Node b=a;
  Node c=a;
  
  if(n.x-1>=0){
    Node bb= {n.x-1,n.y-1,n.cout,n};
    b= CoupeOptimale(distances,bb);}
  if(n.x+1<=(distances->nColonnes()-1)){
    Node cc= {n.x+1,n.y-1,n.cout,n};
    c= CoupeOptimale(distances,cc);}
  
  n.cout=distances->get(n.y, n.x)+ min( a.cout, min(b.cout , c.cout));

  return n;
}
  

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  
  Node minNode;

  for(int x=0;x<largeur;x++){
   Node tmp={x,hateur-1,0,null}
   Node resultat=CoupeOptimale(distances,tmp);
   
   if (resultat.cout<min)
    minNode=resultat
 
 }
 int y=0;
  while(minNode!=null){
    coupe[y]=minNode.x;
    minNode=minNode.pere;
  }  


  return minNode.cout;
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}
