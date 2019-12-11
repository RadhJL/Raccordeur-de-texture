
#include "raccordeur_recursif.h"
#include <utility>
#include<algorithm>
using namespace std; 


pair<int,int*> RaccordeurRecursif::CoupeOptimale(MatInt2* distances,int x,int y,int tab[]){

    if(x<0 || x>distances->nColonnes()-1){
      pair<int,int*> result;
      result.first = 9999999;
      result.second=tab;
      return result;
    }
    
    if(y<0){
      pair<int,int*> result;
      result.first = 0;
      result.second=tab;
      return result;
    }

    tab[y]=x;

    pair<int,int*> a= CoupeOptimale(distances,y-1,x-1,tab);
    pair<int,int*> b= CoupeOptimale(distances,y-1,x,tab);
    pair<int,int*> c= CoupeOptimale(distances,y-1,x+1,tab);
    pair<int,int*> result;
    result.first=distances->get(y, x)+ min( a.first, min(b.first , c.first));
    result.second=tab;
    return  result;
}
  

int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  
  int tab[hauteur]; 
  int min=99999999;
  
  for(int x=0;x<largeur;x++){

    pair<int,int*> tmp =CoupeOptimale(distances,x,hauteur-1,tab);
    
    if(tmp.first<min){
        min=tmp.first;
      for (int y = 0; y < hauteur; y++) 
        coupe[y] = tmp.second[y];
      
    }

}

  return min;
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  // pas de ressources a liberer
}
