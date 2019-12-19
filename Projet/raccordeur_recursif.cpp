
#include "raccordeur_recursif.h"
#include <utility>
#include<algorithm>
using namespace std; 

Node* Memo[100][100];


Node * RaccordeurRecursif::MinChild(int choice,int y, int x){
  if(choice==0){
    int min1=min(Memo[y-1][x]->cout,min(Memo[y-1][x-1]->cout,Memo[y-1][x+1]->cout));
    for(int i=x-1;i<x+2;i++)
        if(Memo[y-1][i]->cout==min1)
          return Memo[y-1][i];
  }else if(choice==1){
    int min1=min(Memo[y-1][x]->cout,Memo[y-1][x-1]->cout);
    for(int i=x-1;i<x+1;i++)
        if(Memo[y-1][i]->cout==min1)
          return Memo[y-1][i];
  }
  else if(choice==2){
    int min1=min(Memo[y-1][x]->cout,Memo[y-1][x+1]->cout);
    for(int i=x;i<=x+1;i++)
        if(Memo[y-1][i]->cout==min1)
          return Memo[y-1][i];
  }
  return NULL;

}
Node* RaccordeurRecursif::CoupeOptimale(MatInt2* distances,int y,int x){


  if(Memo[y][x]!=NULL)
    return Memo[y][x];

  
  if(y==0){
    Memo[y][x]=new Node(x,distances->get(y,x),NULL);
    return Memo[y][x];
  }


  if(x-1>=0  && x+1<=distances->nColonnes()-1)
  Memo[y][x]=new Node(x,
    distances->get(y,x)+
    min(CoupeOptimale(distances,y-1,x)->cout,min(CoupeOptimale(distances,y-1,x-1)->cout,
      CoupeOptimale(distances,y-1,x+1)->cout))
    , MinChild(0,y,x) );

  else if (x-1>=0)
  {
    Memo[y][x]=new Node(x,distances->get(y,x)+
    min(CoupeOptimale(distances,y-1,x)->cout,CoupeOptimale(distances,y-1,x-1)->cout),MinChild(1,y,x));

  }
  else if (x+1<=distances->nColonnes()-1)
  {
    Memo[y][x]=new Node(x,distances->get(y,x)+
    min(CoupeOptimale(distances,y-1,x)->cout,CoupeOptimale(distances,y-1,x+1)->cout),MinChild(2,y,x));

  }else
      Memo[y][x]=new Node(x,distances->get(y,x)+
    CoupeOptimale(distances,y-1,x)->cout,CoupeOptimale(distances,y-1,x));



 return Memo[y][x];
}
  

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  int min=99999999;
  
  for(int i=0;i<hauteur;i++)
    for(int j=0;j<largeur;j++)
      Memo[i][j]=NULL;

  Node* minNode=new Node();
  Node* resultat=new Node();
  
  for(int x=0;x<largeur;x++){
   resultat=new Node(CoupeOptimale(distances,hauteur-1,x));
   if (resultat->cout<min){
    min=resultat->cout;
    minNode=new Node(resultat);
    }
 }
  int y=0;
  while(1){
    coupe[(hauteur-1)-y++]=minNode->x;
    if(minNode->child==NULL)
      break;
    minNode=minNode->child;
  }

  return min;
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}
