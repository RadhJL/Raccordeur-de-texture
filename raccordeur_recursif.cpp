
#include "raccordeur_recursif.h"


/*
 MinChild() retourne le Node qui contient le cout minimal parmis les colonnes x-1 x x+1 de la ligne y-1
 PS:Ici on est sur que les Memo de ces 3 colonnes sont deja calculé 
*/

Node * RaccordeurRecursif::MinChild(Node* **Memo,int min,int y, int x,int l){
    
    for(int i=x-1;i<=x+1;i++){
      //si on depasse les bornes
        if(i<0 || i>l-1)
          continue;
        if(Memo[y-1][i]->cout==min){
          return Memo[y-1][i];
        }
      }
        //la fonction ne sera jamais arrivé ici
        return NULL;
}



Node* RaccordeurRecursif::CoupeOpt(Node* **Memo,MatInt2* dist,int y,int x,int l){
  
  //Retourner le Node qui contient le chemin le plus court s'il est deja calculé
  if(Memo[y][x]!=NULL)
    return Memo[y][x];
  
  //Si on est arrivé au premiere ligne, le chemin minimal est la case lui meme  
  if(y==0){
    return Memo[y][x]=new Node(x,dist->get(y,x),NULL);
  }
     
        
    int val=CoupeOpt(Memo,dist,y-1,x,l)->cout;
    int mini=min(val,
                 min(x-1 >= 0   ? CoupeOpt(Memo,dist,y-1,x-1,l)->cout:val,
                     x+1 <= l-1 ? CoupeOpt(Memo,dist,y-1,x+1,l)->cout:val));
   
   return Memo[y][x]=new Node(x,mini+dist->get(y,x),MinChild(Memo,mini,y,x,l));

}
  
s
int RaccordeurRecursif::calculerRaccord(MatInt2* distances, int* coupe)
{
  //Matrice de memorisation
  Node* **Memo;
  int hauteur = distances->nLignes();
  int largeur = distances->nColonnes();
  int cout=INT_MAX;
  Node* minNode=new Node();
  
  //Inialisation de la matrice Memo
  Memo = new Node* *[hauteur];
  for(int y = 0; y <hauteur; y++)
    Memo[y] = new Node*[largeur];
  
  for(int i=0;i<hauteur;i++)
   for(int j=0;j<largeur;j++)
      Memo[i][j]=NULL;


  //Lancer l'algoritme CoupeOpt pour chaqu'une des colonnes de la derniere ligne de la matrice distances
  Node* resultat=new Node();
  for(int x=0;x<largeur;x++){
   resultat=new Node(CoupeOpt(Memo,distances,hauteur-1,x,largeur));
  //Comparer le resultat pour stocker le node qui contient le chemin le plus court
   if (resultat->cout<cout){
    cout=resultat->cout;
    minNode=new Node(resultat);
    }
 }
  
  //remplissage du tableau coupe avec les colonnes de chaque ligne du plus court chemin (stocké dans minNode)
  int y=0;
  while(1){
    coupe[(hauteur-1)-y++]=minNode->x;
    if(minNode->child==NULL)
      break;
    minNode=minNode->child;
  }

  return cout;
}

RaccordeurRecursif::~RaccordeurRecursif()
{
  
}
