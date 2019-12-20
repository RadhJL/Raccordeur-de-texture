#ifndef _RACCORDEUR_ITERATIF_H
#define	_RACCORDEUR_ITERATIF_H
#include "raccordeur.h"
#include <climits>
using namespace std; 

/*
Classe pour la matrice Mat qu'on va remplir iterativement
*/
class Node_i{
public:
 int x;//la colonne de ce Node_i dans la matrice distance
 int cout;// == le cout de y,x dans la matrice distances + le cout minimal pour arrivé à y,x
 Node_i *pere;// pour suivre le chemin miminal
 
 Node_i(int x,int cout,Node_i* pere){
 	this->x=x;
 	this->cout=cout;
 	this->pere=pere;
 		
 }
 Node_i(Node_i* n){
 	this->x=n->x;
 	this->cout=n->cout;
 	this->pere=n->pere;
 }

};

class RaccordeurIteratif : public Raccordeur {

  virtual Node_i* MeilleurParent(Node_i* **Mat,MatInt2* distances, int y,int x,int largeur);
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurIteratif(); 

};

#endif	

