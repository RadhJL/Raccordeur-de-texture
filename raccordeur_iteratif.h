#ifndef _RACCORDEUR_ITERATIF_H
#define	_RACCORDEUR_ITERATIF_H
#include "raccordeur.h"
#include <climits>

using namespace std; 

class Node_i{
public:
 int x;
 int dist;
 Node_i *pere;
 
 Node_i(int x,int dist,Node_i* pere){
 	this->x=x;
 	this->dist=dist;
 	this->pere=pere;
 		
 }
 Node_i(Node_i* n){
 	this->x=n->x;
 	this->dist=n->dist;
 	this->pere=n->pere;
 }

};

class RaccordeurIteratif : public Raccordeur {

  virtual Node_i* MeilleurParent(Node_i* **Mat,MatInt2* distances, int y,int x,int largeur);
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurIteratif(); // destructeur

};

#endif	

