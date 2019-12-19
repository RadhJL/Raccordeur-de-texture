#ifndef _RACCORDEUR_ITERATIF_H
#define	_RACCORDEUR_ITERATIF_H
#include "raccordeur.h"
#include <utility>
using namespace std; 

class Node{
public:
 int x;
 int dist;
 Node *pere;

 Node(int x,int dist,Node* pere){
 	this->x=x;
 	this->dist=pere;
 	this->pere=pere;
 		
 }
 Node(){
 	this->x=0;
 	this->dist=0;
 	this->pere=NULL;
 		
 }
 Node(Node* n){
 	this->x=n->x;
 	this->dist=n->dist;
 	this->pere=n->pere;
 		
 }

};

class RaccordeurIteratif : public Raccordeur {

  virtual Node* MeilleurParent(MatInt2* distances, int y,int x,int largeur);
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurIteratif(); // destructeur
};

#endif	

